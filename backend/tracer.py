
import urllib.request
import json
import os
import sys
    
class PackageTrace:

    def __init__(self, num=None, carrier=None, name=None):
        self.package_num = num
        self.package_carrier_id = carrier
        self.package_name = name 

        self.package_response_result = {}
        self.carriers = {"carriers": []}
        self.database = {"traces":[]}

        self.database_exist = False
        self.database_counter = [0,0,0]

        self._carriers_load()
        self._database_load()


    def _database_load(self):
        """
        return None

        database.json을 class 변수에 할당하는 작업을 합니다.\n
        만약 database.json을 찾지 못한다면, 새로운 파일을 생성합니다. 

        """

        if os.path.isfile('database.json'):
            try:
                with open('database.json', 'r', encoding='utf-8') as f:
                    self.database = json.load(f)
                    f.close()
                    self.database_exist = True 
            except Exception as e:
                sys.exit(f"IO error. {e}")
        else:
            try:
                with open('database.json', 'w', encoding='utf-8') as f:
                    f.write(json.dumps(self.database, ensure_ascii=False, indent='\t'))
                    f.close()
                    self.database_exist = True 
            except Exception as e:
                sys.exit(f"IO error. {e}")
        
        
    def _carriers_load(self):
        """
        return None

        API로부터 carriers 관련 정보를 받아, carriers.json에 직렬화 합니다.\n
        만약 carriers.json을 찾지 못한다면, 새로운 파일을 생성하여 carriers.json에 직렬화 합니다.

        """
        get_carriers = "https://apis.tracker.delivery/carriers"


        try:
            req = urllib.request.Request(get_carriers)
            with urllib.request.urlopen(req) as response:
                if response.status == 200:
                    self.carriers['carriers'] = json.loads(response.read().decode('utf-8'))
                else:
                    raise ConnectionError
            
            
            with open('carriers.json', 'w', encoding='utf-8') as f:
                f.write(json.dumps(self.carriers, ensure_ascii=False, indent='\t'))
                f.close()

        except ConnectionError as e:
            print(e)


    def _request_api_track(self):
        """
        return None

        class 변수의 값을 바탕으로 API GET 요청을 하여 dictonary 형태로 할당합니다.
        
        """

        try:
            package_num = self.package_num.replace("-", "")
            get_parcel = f"https://apis.tracker.delivery/carriers/{self.package_carrier_id}/tracks/{package_num}"
            
            req = urllib.request.Request(get_parcel)
            with urllib.request.urlopen(req) as response:
                if response.status == 200:
                    self.package_response_result = json.loads(response.read().decode('utf-8'))
                else:
                    raise ConnectionError

            self.package_response_result["id"] = {"num": self.package_num, "carrier_id": self.package_carrier_id, "name": self.package_name}
            
        except ConnectionError as e:
            sys.exit(f"null data, raised http code: {respones.status}")


    def _database_commit(self):
        """
        return None

        역직렬화된 데이터베이스에서 충돌, 합병, 삽입을 수행합니다.

        """

        try:
            flag = 0
            for i in range(0,len(self.database['traces'])):
                if self.database['traces'][i]['id']['num'] == self.package_num and self.database['traces'][i]['id']['carrier_id'] == self.package_carrier_id:
                    # colision
                    if self.database['traces'][i] == self.package_response_result:
                        # pass
                        flag = 1
                        self.database_counter[1] += 1
                        break
                    else:
                        # merge
                        flag = 2
                        self.database['traces'][i] = self.package_response_result
                        self.database_counter[2] += 1
                        break
                else:
                    pass
                
            if flag == 0:
                self.database['traces'].append(self.package_response_result)
                self.database_counter[0] += 1
            else:
                pass 
        
        except Exception as e:
            sys.exit(f"database commit error. {e}")


    
    def _database_push(self):
        """
        return None

        데이터베이스를 저장합니다. 
        """

        if (self.database_counter[0] != 0 or self.database_counter[2] != 0) and self.database_exist == True:
            with open('database.json', 'w', encoding='utf-8') as f:
                f.write(json.dumps(self.database, ensure_ascii=False, indent='\t'))
                f.close()

                print(f"{self.database_counter[0]} Row(s) Pushed, {self.database_counter[2]} Row(s) Merged, {self.database_counter[1]} Row(s) Passed.")

        else:
            print("no to do")




    def request(self):
        """
        return None

        입력된 arguments 를 바탕으로 택배 정보를 불러옵니다.
        """
        self._request_api_track()
        self._database_commit()
        self._database_push()


    def refresh(self):
        """
        return None

        택배 정보를 업데이트 합니다. 
        """
        if len(self.database['traces']) == 0:
            sys.exit("no item.")
        else:
            for i in self.database['traces']:
                self.package_carrier_id = i['id']['carrier_id']
                self.package_num = i['id']['num']
                self.package_name = i['id']['name']

                self._request_api_track()
                self._database_commit()
                
            self._database_push()
        

if len(sys.argv) == 4:
    # run command argument 
    parsel_company = sys.argv[1]
    parsel_num = sys.argv[2]
    parsel_name = sys.argv[3]
    # python3 tracer.py "carriers_id" "parsel_num" "parsel_name"      
    app = PackageTrace(parsel_num, parsel_company, parsel_name)
    app.request()

elif len(sys.argv) == 1:
    app = PackageTrace()
    app.refresh()

else:
    print("Arguments Error.")
    sys.exit()

import requests
import json
import os
import sys

class PackageTrace:

    def __init__(self, num, carrier):
        self.carriers = {}
        self.package_num = num
        self.package_carrier_id = carrier
        self.package_response_result = {}
        self.database = []

        self.request_api_carriers()
        self.request_api_track()
        self.database_commit()


    
    def request_api_carriers(self):
        get_carriers = "https://apis.tracker.delivery/carriers"
        
        if os.path.isfile('carriers.json'):
            try:
                with open('carriers.json', 'r', encoding='utf-8') as f:
                    self.carriers = json.load(f)
                    f.close()
            except IOError as e:
                print(e)
                
        else:
            try:
                respones_carriers = requests.get(get_carriers)
                if respones_carriers.status_code != 200:
                    raise ConnectionError
                self.carriers = respones_carriers.json()

                with open('carriers.json', 'w', encoding='utf-8') as f:
                    f.write(json.dumps(self.carriers, ensure_ascii=False, indent='\t'))
                    f.close()

            except ConnectionError as e:
                print(e)


    def request_api_track(self):

        try:
            get_parcel = f"https://apis.tracker.delivery/carriers/{self.package_carrier_id}/tracks/{self.package_num}"

            respones_parsel = requests.get(get_parcel)

            if respones_parsel.status_code != 200:
                raise ConnectionError

            self.package_response_result = respones_parsel.json().copy()

            self.package_response_result["id"] = {"num": self.package_num, "carrier_id": self.package_carrier_id}
            
            

        except ConnectionError as e:
            print(e)
            sys.exit("null data")


    def database_commit(self):

        if os.path.isfile('database.json'):
            try:
                with open('database.json', 'r', encoding='utf-8') as f:
                    self.database = json.load(f)
                    f.close()

            except FileNotFoundError as e:
                print(e)
        else:
            try:
                with open('database.json', 'w', encoding='utf-8') as f:
                    f.close()
            except Exception as e:
                print(e)

        try:
            flag = 0
            for i in range(0,len(self.database)):
                if self.database[i]["id"]["num"] == self.package_num and self.database[i]["id"]["carrier_id"] == self.package_carrier_id:
                    # colision
                    if self.database[i] == self.package_response_result:
                        # pass
                        flag = 1
                        break
                    else:
                        # merge
                        flag = 2
                        self.database[i] = self.package_response_result
                        break
                else:
                    pass
            
            
            if flag == 0:
                # data exists. appending
                self.database.append(self.package_response_result)
                with open('database.json', 'w', encoding='utf-8') as f:
                    f.write(json.dumps(self.database, ensure_ascii=False, indent='\t'))
                    f.close()
                print("ok")

            elif flag == 1:
                print("not to do")
                pass

            elif flag == 2:
                with open('database.json', 'w', encoding='utf-8') as f:
                    f.write(json.dumps(self.database, ensure_ascii=False, indent='\t'))
                    f.close()
                print("merged")
            
        
        except Exception as e:
            print(e)
            
                

if len(sys.argv) != 3:
    print("Arguments Error.")
    sys.exit()

# run command argument 
parsel_company = sys.argv[1]
parsel_num = sys.argv[2]
# python3 tracer.py "carriers_id" "parsel_num"        

app = PackageTrace(parsel_num, parsel_company)
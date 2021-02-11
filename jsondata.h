#ifndef JSONDATA_H
#define JSONDATA_H

#include <QString>
#include <list>
#include <QJsonObject>
#include <mainwindow.h>

using namespace std;

namespace JsonData
{
    struct From { public: QString name,time; };

    struct To { public: QString name,time; };

    struct Progresses { public: QString time,location,status,description; };


    class TraceData
    {
        private:
        QJsonObject jsonobj;
        QPixmap icon;
        QString name,number,companycode,company,status; //좌측 항목 디스플레이용
        From from;
        To to;
        list<Progresses> progresses;
        public:
        TraceData(MainWindow *pWnd);
    };

    QString IndexToCompanyCode(int index);


}



#endif // JSONDATA_H

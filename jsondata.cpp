#include "jsondata.h"
#include "clientvariable.h"
#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>


JsonData::TraceData::TraceData(MainWindow *pWnd)
{
    QString ApplicationPath = QCoreApplication::applicationDirPath();

    QFile jsonfile(ApplicationPath + "/database.json");

    if(!jsonfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("database.json 파일을 열지 못했습니다.");
        return;
    }

    QString jsondata = jsonfile.readAll();

    QJsonDocument jsondoc(QJsonDocument::fromJson(jsondata.toUtf8()));

    jsonobj = jsondoc.object();

    jsonfile.close();

    QJsonValue jsonvalue = jsonobj.value("traces");

    QJsonArray jsonarray = jsonvalue.toArray();

    foreach (const QJsonValue &value , jsonarray)
    {
        this->name = value.toObject()["id"].toObject()["name"].toString();
        this->number = value.toObject()["id"].toObject()["num"].toString();
        this->status = value.toObject()["state"].toObject()["text"].toString();
        this->companycode = value.toObject()["id"].toObject()["carrier_id"].toString();
        this->icon = *(ClientVariable::CompanycodeToIcon(&(this->companycode)));
        pWnd->CreateNewTraceItem(&(this->name),&(this->number),&(this->icon),&(this->status));
    }

}

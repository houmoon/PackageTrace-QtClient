#ifndef CLIENTVARIABLE_H
#define CLIENTVARIABLE_H

#include <QString>
#include <QPixmap>

namespace  ClientVariable
{
    QString IndexToCompanycode(int index = 0);
    QString IndexToIcon(int index = 0);
    QPixmap *CompanycodeToIcon(QString *companycode = nullptr);
};

#endif // CLIENTVARIABLE_H

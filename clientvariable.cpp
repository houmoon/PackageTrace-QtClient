#include "clientvariable.h"

QString ClientVariable::IndexToCompanycode(int index)
{
    switch (index)
    {
        case 0: //킹체국
        return "kr.epost";
        break;
        case 1: //대한통운
        return "kr.cjlogistics";
        break;
        case 2: //롯데택배
        return "kr.lotte";
        break;
        case 3: //로젠택배
        return "kr.logen";
        break;
        case 4: //CU 택배
        return "kr.cupost";
        break;
        case 5: //GS 택배
        return "kr.cvsnet";
        break;
        default:
        return " ";
        break;
    }
}

QString ClientVariable::IndexToIcon(int index)
{
    switch (index)
    {
        case 0: //킹체국
        return ":/icons/icon_epost.png";
        break;
        case 1: //대한통운
        return ":/icons/icon_cj.png";
        break;
        case 2: //롯데택배
        return ":/icons/icon_lotte.png";
        break;
        case 3: //로젠택배
        return ":/icons/icon_logen.png";
        break;
        case 4: //CU 택배
        return ":/icons/icon_cu.png";
        break;
        case 5: //GS 택배
        return ":/icons/icon_gs.png";
        break;
        default:
        return ":/icons/icon_epost.png";
        break;
    }
}

QPixmap *ClientVariable::CompanycodeToIcon(QString *companycode)
{
    QPixmap *pixmap;
    if(companycode->contains("kr.epost"))
        pixmap = new QPixmap(":/icons/icon_epost.png");
    else if(companycode->contains("kr.cjlogistics"))
        pixmap = new QPixmap(":/icons/icon_cj.png");
    else if(companycode->contains("kr.lotte"))
        pixmap = new QPixmap(":/icons/icon_lotte.png");
    else if(companycode->contains("kr.logen"))
        pixmap = new QPixmap(":/icons/icon_logen.png");
    else if(companycode->contains("kr.cupost"))
        pixmap = new QPixmap(":/icons/icon_cu.png");
    else if(companycode->contains("kr.cvsnet"))
        pixmap = new QPixmap(":/icons/icon_gs.png");
    else
        pixmap = new QPixmap(":/icons/icon_epost.png");
    return pixmap;
}

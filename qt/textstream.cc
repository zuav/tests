#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <QString>

int main()
{
    QString s;
    QTextStream out(&s, QIODevice::WriteOnly);
    out << 1 << ", " << 2 << ", " << 3;
    qDebug() << s;

    std::cout << s.toLocal8Bit().constData() << std::endl;

    QString s2("4, 5, 6");
    qDebug() << s2;

    std::cout << s2.toLocal8Bit().constData() << std::endl;

    qDebug() << "8, 9, 10";


    return 0;
}

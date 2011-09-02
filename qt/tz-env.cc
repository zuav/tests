#include <stdlib.h>
#include <iostream>
#include <QTextCodec>
#include <QString>
#include <QDateTime>

int main(int, char *[])
{
    const char *tz[] = {
        "Europe/Kaliningrad",
        "Europe/Moscow",
        "Asia/Vladivostok",
        0
    };

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    setenv("LANG", "C", 1);

    for (const char **p=tz; *p; ++p) {
        setenv("TZ", *p, 1);
        std::cout << "date: " << QDateTime::currentDateTime().toString().toLocal8Bit().constData()
                  << "; TZ: " << *p
                  << std::endl;
    }

    return 0;
}

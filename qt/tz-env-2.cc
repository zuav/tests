#include <stdlib.h>
#include <iostream>
#include <QTextCodec>
#include <QProcess>
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
        QProcess proc;
        QProcessEnvironment env;
        env.insert("LANG", "C");
        env.insert("TZ", *p);
        proc.setProcessEnvironment(env);
        QStringList args("-Iseconds");
        proc.start("/bin/date", args);
        proc.waitForFinished();
        if (proc.exitCode() != 0) {
            QByteArray err = proc.readAllStandardError();
            std::cerr << "/bin/date failed: " << QString(err).toLocal8Bit().constData();
            return 1;
        }
        QString output = QString(proc.readAllStandardOutput()).trimmed();
        QDateTime d = QDateTime::fromString(output, Qt::ISODate);
        std::cout << "TZ:        " << *p                                     << std::endl
                  << "read date: " << output.toLocal8Bit().constData()       << std::endl
                  << "qt date:   " << d.toString().toLocal8Bit().constData() << std::endl
                  << "current:   " << QDateTime::currentDateTime().toString().toLocal8Bit().constData() << std::endl
                  << std::endl;
    }

    return 0;
}

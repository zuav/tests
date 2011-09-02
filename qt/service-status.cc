#include <iostream>
#include <QProcess>
#include <QStringList>

int main()
{
    QStringList args;
    args << "-c" << QString("/etc/init.d/proftpd status");
    QProcess p;
    p.start("/bin/bash", args);
    p.waitForFinished();

    std::cout << "exit code: " << p.exitCode() << std::endl
              << "output:    " << QString(p.readAllStandardOutput()).toLocal8Bit().constData() << std::endl
              << "error:     " << QString(p.readAllStandardError()).toLocal8Bit().constData() << std::endl;

    return 0;
}

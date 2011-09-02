#include <iostream>
#include <QProcess>
#include <QProcessEnvironment>
#include <QStringList>

int main()
{
    QProcess p;
    QProcessEnvironment sysenv = QProcessEnvironment::systemEnvironment();
    p.setProcessEnvironment(sysenv);
    QProcessEnvironment env = p.processEnvironment();
    QStringList l = env.toStringList();

    for (int i=0; i<l.size(); ++i)
        std::cout << l.at(i).toLocal8Bit().constData() << std::endl;

    return 0;
}

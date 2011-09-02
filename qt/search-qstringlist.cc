#include <iostream>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

int main(int, char *argv[])
{
    QFile file(argv[1]);
    if (!file.open(QFile::ReadOnly))
        return 1;

    QTextStream os(&file);
    QString data = os.readAll();
    QStringList lines = data.split("\n");

    for (int i=0; i<lines.size(); ++i)
        std::cout << lines.at(i).toLocal8Bit().constData() << std::endl;

    return 0;
}

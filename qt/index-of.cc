#include <iostream>
#include <QRegExp>
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


    QRegExp regex(argv[2]);
    int index = lines.indexOf(regex);
    QString l = lines.at(index).simplified();
    QStringList keyval = l.split(' ', QString::SkipEmptyParts);
    int numparts = keyval.size();

    std::cout << "regex:    " << argv[2] << std::endl
              << "index of: " << index << std::endl
              << "line:     " << l.toStdString() << std::endl
              << "numparts: " << numparts << std::endl;


    return 0;
}

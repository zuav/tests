#include <iostream>
#include <QFile>
#include <QFileInfo>

int main(int, char *argv[])
{
    QFile file(argv[1]);

    std::cout << "got file:               " << argv[1] << std::endl
              << "file name if QFile:     " << QFile(argv[1]).fileName().toLocal8Bit().constData() << std::endl
              << "file name if QFileInfo: " << QFileInfo(argv[1]).fileName().toLocal8Bit().constData() << std::endl;

    return 0;
}

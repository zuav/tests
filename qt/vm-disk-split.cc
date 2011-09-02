// disk=['file:/images/internetvm.img,hda,w','phy:/dev/cdrom,hdb:cdrom,r']
// disk=['file:/images/internetvm.img,hda,w','file:/images/img.iso,hdb:cdrom,r']

#include <iostream>
#include <QString>
#include <QStringList>

int main(int, char *[])
{
    QString     s1 = "['file:/images/internetvm.img,hda,w','phy:/dev/cdrom,hdb:cdrom,r']";
    QStringList p1 = s1.split('\'', QString::SkipEmptyParts);

    std::cout << "s1: " << s1.toLocal8Bit().constData() << std::endl << std::endl;
    for (int i=0; i<p1.size(); ++i)
        std::cout << i << " : " << p1.at(i).toLocal8Bit().constData() << std::endl;

    std::cout << std::endl << std::endl;

    QString imfile1 = p1.at(1).split(':', QString::SkipEmptyParts).at(1).split(',', QString::SkipEmptyParts).at(0);
    QString cddev1  = p1.at(3).split(':', QString::SkipEmptyParts).at(1).split(',', QString::SkipEmptyParts).at(0);

    std::cout << "imfile1: " << imfile1.toLocal8Bit().constData() << std::endl
              << "cddev1:  " << cddev1.toLocal8Bit().constData()  << std::endl;

    std::cout << std::endl << std::endl;

    QString     s2 = "['file:/images/internetvm.img,hda,w','file:/images/img.iso,hdb:cdrom,r']";
    QStringList p2 = s2.split('\'', QString::SkipEmptyParts);

    std::cout << "s2: " << s2.toLocal8Bit().constData() << std::endl << std::endl;
    for (int i=0; i<p2.size(); ++i)
        std::cout << i << " : " << p2.at(i).toLocal8Bit().constData() << std::endl;

    std::cout << std::endl << std::endl;

    QString imfile2 = p2.at(1).split(':', QString::SkipEmptyParts).at(1).split(',', QString::SkipEmptyParts).at(0);
    QString cddev2  = p2.at(3).split(':', QString::SkipEmptyParts).at(1).split(',', QString::SkipEmptyParts).at(0);

    std::cout << "imfile2: " << imfile2.toLocal8Bit().constData() << std::endl
              << "cddev2:  " << cddev2.toLocal8Bit().constData()  << std::endl;

    return 0;
}

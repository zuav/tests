#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QSqlRecord>
#include <QTextStream>
#include <QFile>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    const char *dbname = argv[1];
    db.setDatabaseName(dbname);
    if (db.open())
        qDebug() << "opened database: " << dbname;
    else {
        qDebug() << "failed to open database: " << dbname;
        return 1;
    }

    QSqlQuery countquery("SELECT COUNT(*) FROM logs WHERE exported = 0;");
    if (!countquery.exec()) {
        qDebug() << "count query failed: " << db.lastError().text();
        return 1;
    }

    countquery.first();
    qDebug() << "Number of rows: " << countquery.value(0).toString();

    QSqlQuery exportquery("SELECT * FROM logs WHERE exported = 0;");
    if (!countquery.exec()) {
        qDebug() << "export query failed: " << db.lastError().text();
        return 1;
    }

    const char *fname = argv[2];
    QFile device(fname);
    if (!device.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "failed to open file: " << fname;
        return 1;
    }

    QTextStream out(&device);

    QSqlRecord rec = exportquery.record();
    int numcols = rec.count() - 1;
    qDebug() << "Number of columns: " << (numcols + 1);

    while (exportquery.next()) {
        for (int i=1; i<numcols; ++i) {
            QString comma = ((i+1) < numcols) ? ", " : "";
            out << '"' << exportquery.value(i).toString() << '"' << comma;
        }
        out << '\n';
    }

    return 0;
}

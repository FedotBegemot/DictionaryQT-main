#ifndef MYDICTIONARY_H
#define MYDICTIONARY_H

#include <QCoreApplication>
#include <QFile>
#include <QJsonArray>
#include <QStringList>
#include <QTextStream>
#include <QJsonDocument>
#include <QMap>
#include <QString>
#include <QJsonObject>

class Dictionary
{
public:
    void saveToFile(const QString& filename);
    void loadFromFile(const QString& filename);
    QMap<QString, int> getDict();
    void addWordsFromFile(const QString& fileName);
private:
    QString filePath;
    QMap<QString, int> m_dictionary;
};
#endif // MYDICTIONARY_H

#include "MyDictionary.h"

QMap<QString, int> Dictionary::getDict() {
    return m_dictionary;
}

void Dictionary::saveToFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Fail during openning file:" << fileName;
        return;
    }
    QJsonObject jsonDictionary;
    for (auto curr = m_dictionary.constBegin(); curr != m_dictionary.constEnd(); ++curr)
    {
        jsonDictionary[curr.key()] = curr.value();
    }
    QJsonDocument jsonDoc(jsonDictionary);
    file.write(jsonDoc.toJson());
    file.close();
}

void Dictionary::loadFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Fail during openning file:" << fileName;
        return;
    }
    QByteArray jsonData = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonDictionary = jsonDoc.object();
    m_dictionary.clear();
    for (auto curr = jsonDictionary.constBegin(); curr != jsonDictionary.constEnd(); ++curr)
    {
        QString currWord = curr.key();
        int wordCount = curr.value().toInt();
        m_dictionary[currWord] = wordCount;
    }
    file.close();
}

void Dictionary::addWordsFromFile(const QString& fileName)
{
    filePath = fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file:" << fileName;
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString currLine = in.readLine();
        QStringList allWords = currLine.split(" ", Qt::SkipEmptyParts);
        for (const QString& currWord : allWords)
        {
            if (!currWord.isEmpty())
                m_dictionary[currWord]++;
        }
    }
    file.close();
}

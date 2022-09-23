#include <dataserializer.h>
#include <iostream>
#include <fstream>

DataSerializer::DataSerializer(std::string initFilePath, std::vector<DataStorage::classListStructure> initClassList):
    filePath(initFilePath),
    classList(initClassList)
{
    fileModifier(filePath,classList);
}

void DataSerializer::fileModifier(std::string m_filePath, std::vector<DataStorage::classListStructure> m_classList)
{
    std::ofstream cppFile;
    cppFile.open(m_filePath);
    if(!cppFile.is_open())
    {qWarning()<<"File couldn't opened";}

//    QFile f()
}

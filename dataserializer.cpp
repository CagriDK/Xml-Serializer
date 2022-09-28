  #include <dataserializer.h>
#include <iostream>
#include <fstream>

#define mVar DataStorage::classMembers::memberType::Variable
#define mStructure DataStorage::classMembers::memberType::Struct
#define mArray DataStorage::classMembers::memberType::Array
#define mClass DataStorage::classMembers::memberType::Class
#define mFunction DataStorage::classMembers::memberType::Function

DataSerializer::DataSerializer(std::string initFilePath):
    filePath(initFilePath)
{
    t1=std::make_unique<DataStorage>(filePath);
    classList=t1->GetmClassListStorage();
    fileModifier(filePath,classList);
}

void DataSerializer::fileModifier(std::string m_filePath, std::vector<DataStorage::classListStructure> m_classList)
{
    std::ifstream xmlFile;
    xmlFile.open(m_filePath);
    if(!xmlFile.is_open())
    {qWarning()<<"File couldn't opened";}
    std::string line;

    std::ofstream fullText;
    fullText.open(m_filePath);
    std::vector<std::string> classLines;

    while(std::getline(xmlFile,line)){
        fullText << line;
        fullText << "\n";
        QString QStringLine=QString::fromStdString(line);

        for(int i=0;i<static_cast<int>(m_classList.size());i++)
        {
            if(QStringLine.contains(QString::fromStdString("class " + m_classList[i].className)))
            {
                fullText << "private:";
                fullText << "\n";
                fullText <<" \t friend class boost::serialization::access;";
                fullText << "\n";
                fullText << "\n";
                fullText <<" \t template<class Archive>";
                fullText << "\n";
                fullText << "\t void serialize(Archive & ar, const unsigned int /*version*/){";
                fullText << "\n";

                for(int j=0;j<static_cast<int>(m_classList[i].classVariables.size());j++){
                    if((m_classList[i].classVariables.at(j).variableType == mClass)  ||   (m_classList[i].classVariables.at(j).variableType == mStructure)){
                        fullText << " \t\t";
                        fullText << "ar & boost::serialization::make_nvp(";
                        fullText << m_classList[i].className;
                        fullText << ",";
                        fullText << m_classList[i].classVariables.at(j).variableName;
                        fullText << ");";
                        fullText << "\n";
                    }

                    if(m_classList[i].classVariables.at(j).variableType == mVar){
                        fullText << " \t\t";
                        fullText << "ar & BOOST_SERIALIZATION_NVP(";
                        fullText << m_classList[i].classVariables.at(j).variableName;
                        fullText << ");";
                        fullText << "\n";
                    }
                }

                fullText << "}";
                fullText << "\n";
            }
        }
    }
}

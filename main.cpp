#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <vector>

using namespace std;

class DataStorage{
public:

    struct classMembers{
        classMembers():variableName(),variableType(memberType::Variable),nestedClass(false),levelOfNest(0){}
        enum class memberType{Variable=0,Function=1,Array=2,Struct=3,Class=4};

        std::string variableName;
        memberType variableType;

        bool nestedClass;
        int levelOfNest;
    };

public:
    void readTextFile(std::string filepath){
        std::ifstream xmlFile;
        xmlFile.open(filepath);
        if(!xmlFile.is_open())
        {qWarning()<<"File couldn't opened";}
        std::string line;
        std::vector<QString> QStringLineList; //Holds QStringLines for one class
        std::vector<std::vector<QString>> classList; //Holds All the classes for QStringLinesList
        bool isNewClass=false;
        classCounter=0;

        while(std::getline(xmlFile,line)){
            QString QStringLine=QString::fromStdString(line);

            if(QStringLine.contains("class "))
            {
                classCounter++;
                isNewClass=true;
            }

            if(isNewClass)
            {
                QStringLineList.push_back(QStringLine);
            }

            if(QStringLine.contains("};"))
            {
                if(classCounter!=0){
                    classList.push_back(QStringLineList);
                }
                QStringLineList.clear();
                isNewClass=false;
            }

//            for(short i=0;i<static_cast<short>(variableTypes.size());i++)
//            {
//                getVariables(variableTypes.at(i),line);
//            };
        }


    };
    void getVariables(const std::string& n ,const std::string& m){
        QString QStringLine=QString::fromStdString(m);
        classMembers temp;

        if(QStringLine.contains(QString::fromStdString(n)))
        {
            if(QStringLine.contains("("))
            {
                QStringLine.remove("\t");
                QStringLine.remove(QString::fromStdString(n));
                QStringLine.remove(" ");
                QStringLine.remove(";");

                temp.variableName=QStringLine.toStdString();
                temp.variableType=classMembers::memberType::Function;
            }

            else if(QStringLine.contains("["))
            {
                QStringLine.remove("\t");
                QStringLine.remove(QString::fromStdString(n));
                QStringLine.remove(" ");
                QStringLine.remove(";");

                temp.variableName=QStringLine.toStdString();
                temp.variableType=classMembers::memberType::Array;
            }

            else if(QStringLine.contains("struct"))
            {
                QStringLine.remove("struct ");
                QStringLine.remove("");
                QStringLine.remove(" ");
                QStringLine.remove("{");

                temp.variableName=QStringLine.toStdString();
                temp.variableType=classMembers::memberType::Struct;
            }

            else if(QStringLine.contains("class "))
            {
                QStringLine.remove("class ");
                QStringLine.remove("");
                QStringLine.remove(" ");
                QStringLine.remove(";");
                QStringLine.remove("{");

                temp.variableName=QStringLine.toStdString();
                temp.variableType=classMembers::memberType::Class;
            }

            else {
                QStringLine.remove("\t");
                QStringLine.remove(QString::fromStdString(n));
                QStringLine.remove(" ");
                QStringLine.remove(";");

                temp.variableName=QStringLine.toStdString();
                temp.variableType=classMembers::memberType::Variable;
            }
            classVariables.push_back(temp);
        }
    }
private:
    std::vector<std::string> variableTypes={
        "void","char","bool","int","double","float",
        "unsigned long","signed long","long","short",
        "signed short","unsigned short"};
    std::string temp_className;
    int classCounter; // Kaç adet Class olduğunu tutan değişken
    std::vector<classMembers> classVariables; // Class Verileri
    std::vector<std::vector<classMembers>> classList; //Class Verilerini Tutan Class

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string filePath="C:/Users/cagri/OneDrive/Documents/untitled7/mydocument.xml";
//  std::replace(filePath.begin(), filePath.end(), '\\', '/');
    std::unique_ptr<DataStorage> t2=std::make_unique<DataStorage>();
    t2->readTextFile(filePath);
    //classList=reaDFile(filePath);

    return a.exec();
}

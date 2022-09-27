#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include<iostream>
#include<vector>
#include <QFile>
#include <fstream>
#include <QDebug>

#define GETSET(Type, MemberName, FaceName) \
           Type Get##FaceName() const { \
               return MemberName; \
         }; \
         void Set##FaceName(Type value) { \
               MemberName = value; \
         }

class DataStorage{

public:
    DataStorage(std::string filePath):mFilePath(filePath){
        readTextFile(filePath);
    };
    struct classMembers{
        classMembers():variableName(),variableType(memberType::Variable){}
        enum class memberType{Variable=0,Function=1,Array=2,Struct=3,Class=4,StructArray=5};

        std::string variableName;
        memberType variableType;
        std::string variableTypeName;
        std::string arrVariableNumber; // double var[8] // ---> 8 <---  // struct st1[7]  // ---> 7 <---  //
    };

    struct classListStructure{
        std::string className;
        std::vector<classMembers> classVariables;
    };

public:
    GETSET(std::vector<classListStructure>,classList,mClassListStorage);

    void readTextFile(std::string filepath);

    void getVariables(const std::string& n,int k,int variableTypeSize,int whichClass ,const std::string& m);



private:
    int classCounter; // Kaç adet Class olduğunu tutan değişken
     // Class Verileri
    std::vector<classListStructure> classList;
    classListStructure m_temp;
    std::vector<std::string> tempClassNames;
    std::string mFilePath;

    //std::vector<std::vector<classMembers>> classList;
};

#endif // DATASTORAGE_H

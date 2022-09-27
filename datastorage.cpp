#include<datastorage.h>

void DataStorage::readTextFile(std::string filepath){
    std::ifstream xmlFile;
    xmlFile.open(filepath);
    if(!xmlFile.is_open())
    {qWarning()<<"File couldn't opened";}
    std::string line;
    bool isNewClass=false;
    classCounter=0;
    std::vector<QString> QStringLineList; //Holds QStringLines for one class
    std::vector<std::vector<QString>> classQStringList; //Holds All the classes for QStringLinesList
    std::vector<std::string> variableTypes={
        "void","char","bool","int","double","float",
        "unsigned long","signed long","long","short",
        "signed short","struct","unsigned short"};

    while(std::getline(xmlFile,line)){
        QString QStringLine=QString::fromStdString(line);

        if(isNewClass)
        {
            QStringLineList.push_back(QStringLine);
        }

        if(QStringLine.contains("//"))
        {
            QStringLine="";
        }


        if((QStringLine.contains("class ") || QStringLine.contains("struct")) && !(QStringLine.contains(";")) && !QStringLine.contains("template"))
        {
            if(isNewClass){
                if(classCounter!=0){
                    classQStringList.push_back(QStringLineList);
                }
                QStringLineList.clear();
                isNewClass=false;
            }

            QStringLine.remove("class ");
            QStringLine.remove("struct ");
            QStringLine.remove("");
            QStringLine.remove(" ");
            QStringLine.remove(";");
            QStringLine.remove("{");
            if(QStringLine.contains(":"))
            {
                QStringLine= QStringLine.mid(0, QStringLine.indexOf(":"));
            }

            tempClassNames.push_back(QStringLine.toStdString());
            variableTypes.push_back(QStringLine.toStdString()); //Add classname to variable types, it could be a class data inside a data (Nested Classes);
            isNewClass=true;
            classCounter++;
        }


    }

    classQStringList.push_back(QStringLineList);

    for(unsigned long long i=0; i<classQStringList.size();i++)
    {
        m_temp.className=tempClassNames.at(i); //Will be used at code.

        for(unsigned long long j=0; j<classQStringList[i].size();j++)
        {
            for(short k=0;k<static_cast<short>(variableTypes.size());k++)
            {
                int variableTypeSize=variableTypes.size();
                getVariables(variableTypes.at(k),k,variableTypeSize,i,classQStringList[i][j].toStdString());
            };
        }


        classList.push_back(m_temp);
        m_temp.classVariables.clear();
        m_temp.className="";
    }
}

void DataStorage::getVariables(const std::string &n, int k, int variableTypeSize, int whichClass, const std::string &m)
{
    QString QStringLine=QString::fromStdString(m);

    if(QStringLine.contains("//"))
    {
        QStringLine="";
    }

    if(QStringLine.contains("int main("))
    {
        QStringLine="";
    }

    if(QStringLine.contains(QString::fromStdString(n)))
    {

        classMembers temp;

        if(k>=13){
            int classCount=variableTypeSize-13; // 3 gelecek

            if((variableTypeSize-classCount+whichClass)>k+1){
                //If different from predefined variable types check for class types. keyword:variableTypes {#predefinedtypes} extra means nested class present.
                QStringLine.remove(QString::fromStdString(n));
                QStringLine.remove("");
                QStringLine.remove(" ");
                QStringLine.remove(";");
                QStringLine.remove("\t");

                temp.variableName=QStringLine.toStdString();;
                temp.variableType=classMembers::memberType::Class;
                temp.variableTypeName=n;

            }
            else {
                return;
            }

        }

        else if(QStringLine.contains("("))
        {
            if(QStringLine.contains(QString::fromStdString(m_temp.className))){
                return;
            }

            QStringLine.remove("\t");
            QStringLine.remove(QString::fromStdString(n));
            QStringLine.remove(" ");
            QStringLine.remove(";");

            temp.variableName=QStringLine.toStdString();
            temp.variableType=classMembers::memberType::Function;
            temp.variableTypeName=n;
        }

        else if(QStringLine.contains("["))
        {
            QStringLine.remove("\t");
            QStringLine.remove(QString::fromStdString(n));
            QStringLine.remove(" ");
            QStringLine.remove(";");

            temp.variableName=QStringLine.toStdString();
            temp.variableType=classMembers::memberType::Array;
            temp.variableTypeName=n;
        }

        else if(QStringLine.contains("struct"))
        {
            QStringLine.remove("struct ");
            QStringLine.remove("");
            QStringLine.remove(" ");
            QStringLine.remove("{");
            QStringLine.remove("\t");

            temp.variableName=QStringLine.toStdString();
            temp.variableType=classMembers::memberType::Struct;
            temp.variableTypeName=n;
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
            temp.variableTypeName=n;
        }



        else {
            QStringLine.remove("\t");
            QStringLine.remove(QString::fromStdString(n));
            QStringLine.remove(" ");
            QStringLine.remove(";");

            temp.variableName=QStringLine.toStdString();
            temp.variableType=classMembers::memberType::Variable;
            temp.variableTypeName=n;
        }
        m_temp.classVariables.push_back(temp);
        //classVariables.push_back(temp);
    }
}

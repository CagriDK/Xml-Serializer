#include <QCoreApplication>
#include <QDomDocument>
#include <QDebug>
#include <dataserializer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string filePath="C:/Projects/Xml-Serializer/QtSerialized_output.cpp";
//  std::replace(filePath.begin(), filePath.end(), '\\', '/');
    std::unique_ptr<DataStorage> t1=std::make_unique<DataStorage>();
    t1->readTextFile(filePath);

    std::string modifyFile="C:/Projects/Xml-Serializer/QtSerialized_output.cpp";
    std::unique_ptr<DataSerializer> t2=std::make_unique<DataSerializer>(modifyFile,t1->GetmClassListStorage());

    return a.exec();
}

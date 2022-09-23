#include <QCoreApplication>
#include <QDomDocument>
#include <QDebug>
#include <dataserializer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string filePath="C:/Projects/Xml-Serializer/mydocument.xml";
//  std::replace(filePath.begin(), filePath.end(), '\\', '/');
    std::unique_ptr<DataStorage> t1=std::make_unique<DataStorage>();
    t1->readTextFile(filePath);

    std::string modifyFile="C:/Users/cagri/OneDrive/Documents/pugi_example/test.cpp";
    std::unique_ptr<DataSerializer> t2=std::make_unique<DataSerializer>(modifyFile,t1->GetmClassListStorage());
    //t2->SetmClassListSerializer(t1->GetmClassListStorage());


    return a.exec();
}

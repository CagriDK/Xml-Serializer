#include <QCoreApplication>
#include <QDebug>
#include <dataserializer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const std::string filePath="C:/Projects/Xml-Serializer/QtSerialized_output.cpp";
//  std::replace(filePath.begin(), filePath.end(), '\\', '/');

    std::unique_ptr<DataSerializer> t2=std::make_unique<DataSerializer>(filePath);

    return a.exec();
}

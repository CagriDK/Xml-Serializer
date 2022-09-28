#ifndef DATASERIALIZER_H
#define DATASERIALIZER_H
#include <QDomDocument>
#include <datastorage.h>

#define GETSET(Type, MemberName, FaceName) \
           Type Get##FaceName() const { \
               return MemberName; \
         }; \
         void Set##FaceName(Type value) { \
               MemberName = value; \
         }

class DataSerializer{
public:
    DataSerializer(std::string initFilePath);

public:
    void fileModifier(std::string m_filePath,std::vector<DataStorage::classListStructure> m_classList);

    GETSET(std::vector<DataStorage::classListStructure>,classList,mClassListSerializer);

private:

    const std::string filePath;
    std::vector<DataStorage::classListStructure> classList;

    std::unique_ptr<DataStorage> t1;
};

#endif // DATASERIALIZER_H

#include <QCoreApplication>
#include <iostream>
#include <boost/archive/xml_oarchive.hpp>
#include <fstream>

class Data
{
public:
    int Degrees;
    int Minutes;
    float Seconds;
//private:
//
//    friend class boost::serialization::access;
//
//    template<class Archive>
//    void serialize(Archive & ar, const unsigned int /*version*/){
//        ar & BOOST_SERIALIZATION_NVP(Degrees);
//        ar & BOOST_SERIALIZATION_NVP(Minutes);
//        ar & BOOST_SERIALIZATION_NVP(Seconds);
//    }

};

class Position
{

public:
    // every serializable class needs a constructor
    Position() {
        Degrees = 0;
        Minutes = 0;
        Seconds = 0;
    };
    Position(int degrees, int minutes, float seconds){
        Degrees = degrees;
        Minutes = minutes;
        Seconds = seconds;
    };
    int Degrees;
    int Minutes;
    float Seconds;
    Data data;
    Data data2;

//private:
//    friend class boost::serialization::access;
//
//    template<class Archive>
//    void serialize(Archive & ar, const unsigned int /*version*/){
//        ar & BOOST_SERIALIZATION_NVP(Degrees);
//        ar & BOOST_SERIALIZATION_NVP(Minutes);
//        ar & BOOST_SERIALIZATION_NVP(Seconds);
//        ar & boost::serialization::make_nvp("data", data);
//        ar & boost::serialization::make_nvp("data", data2);
//    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Position position;
        position.Degrees = 1;
        position.Minutes = 2;
        position.Seconds = 3;
        position.data = {1,2,3};
        position.data2 = {4,5,6};

        {
            std::ofstream ofs("C:/Users/cagri/OneDrive/Documents/pugi_example/output.xml");
            boost::archive::xml_oarchive oa(ofs);

            oa << BOOST_SERIALIZATION_NVP(position);
        }

    return a.exec();
}




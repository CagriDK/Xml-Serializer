struct tuale{
	int tuale_int;
};

class Myclass{
private:
 	 friend class boost::serialization::access;

 	 template<class Archive>
	 void serialize(Archive & ar, const unsigned int /*version*/){
 		ar & BOOST_SERIALIZATION_NVP(iTest);
 		ar & BOOST_SERIALIZATION_NVP(bTest);
 		ar & BOOST_SERIALIZATION_NVP(sTest);
}
public:
	Myclass();
	~Myclass();
private:
	struct viaMine[4];
	int iTest;
	bool bTest;
	short sTest;
};

class Furious: public Myclass {
private:
 	 friend class boost::serialization::access;

 	 template<class Archive>
	 void serialize(Archive & ar, const unsigned int /*version*/){
 		ar & boost::serialization::make_nvp(Furious,a1);
 		ar & BOOST_SERIALIZATION_NVP(fInt);
}
public:
	Myclass a1;
	Furious()=default;
	~Furious();
	void Function();
	bool Literature(int a,int b);
private:
	int fInt;
};

class test{
private:
 	 friend class boost::serialization::access;

 	 template<class Archive>
	 void serialize(Archive & ar, const unsigned int /*version*/){
 		ar & boost::serialization::make_nvp(test,ses);
 		ar & boost::serialization::make_nvp(test,test);
 		ar & boost::serialization::make_nvp(test,st1;);
 		ar & BOOST_SERIALIZATION_NVP(lTest);
}
	Furious ses();
	test();
	~test();
public:
	Furious test;
	struct st1;
	void test();
	long lTest;
};

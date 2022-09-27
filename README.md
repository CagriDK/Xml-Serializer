# Xml-Serializer
Automating C++ Class objects to Xml Document via Boost &amp; Qt Framework

The need of project is required due to a request.

Request:
  Giving an undefined .cpp file that takes several classes,structs and objects that holds datas inside theirselves.
  The undefined objects should be converted to xml file to get a representive schematic look at the designs.
  It should be in c++ because it would be working in the same executable as it compiled in c++. Also it should be working in runtime.
  
Solution:
  C++ dont have any special ability such as reflection and cpp files couldn't be changed in runtime or neither add any new function to objects in runtime.
  Knowing of this makes me think, Writing a script that first start an executable or call a library that reads the giving argument of .cpp files. 
  Second modify the file by ostream class and write a template serialization function via boost framework for xml.
  Build the modified .cpp file with a new lib or executable.
  Create the xml file in run time.
  
My Thoughts:
  It is easier with Java or .Net because it gives control in runtime. 
  Could be easier if any access given to .cpp files. So we can create a template for classes before build.
  
Working in progress ...

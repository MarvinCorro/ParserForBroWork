#ifndef CONTAINER
#define CONTAINER

#include "csvParser.h"
#include <vector>

class container:public CsvParser
{
protected:
   vector<personInstance> dataBase;
   vector<personInstance> noneSfJazz;
   vector<string> findGroupMember;
   
public:

   container():CsvParser(){};
   container( string fileName ):CsvParser( fileName ){};
   ~container();


   string getEmailAddress( string );
   void readFile();
   void createDataBase();
   void compareAddressToVec( string, string );
   void findbyGroup( string );
   void printFindBy( string );
   void writeToFileFind( string, int );
   void findAllNonSFJazz();
   void writeToFile();
   void printData( int );
};

#endif
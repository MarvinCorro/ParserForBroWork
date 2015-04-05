#ifndef CSV_PARSER
#define CSV_PARSER

#include <string>
#include "personInstance.h"
using namespace std;

class CsvParser   
{  
protected:
   string fileName;
   string groupName;
public:

   CsvParser();
   CsvParser( string );

   string getFileName();

   void setFileName( string );
   
   int countFileLines();
   personInstance parsedObject( string );
   bool hasData();

};
#endif
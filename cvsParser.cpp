#include "stdafx.h"
#include "csvParser.h"
#include "personInstance.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

CsvParser::CsvParser(){;}

CsvParser::CsvParser( string fileName ) { this->fileName = fileName; }

string CsvParser::getFileName() { return this->fileName; }

void CsvParser::setFileName( string fileName ) { this->fileName = fileName; }

personInstance CsvParser::parsedObject( string line )
{
   string emailAddress = strtok( (char *)line.c_str(), "," );
   string firstName    = strtok( 0, "," );
   string lastName     = strtok( 0, "," );
   string lastLogin    = strtok( 0, "," );
   string firstLogin   = strtok( 0, "," );
   int quota           = atoi( strtok( 0, "," ) );  

   personInstance temp( emailAddress, firstName, lastName, lastLogin, firstLogin, quota );
   return temp;
}

int CsvParser::countFileLines()
{
   fstream in( fileName.c_str(), ios::in );
   int counter = 0;
   string line = "";

   while( !in.eof() )
   {
      getline( in, line );
      counter++;
   }

   return counter;
}

bool CsvParser::hasData()
{
   int counter = countFileLines();
   return ( counter >= 2 ) ? true:false;
}
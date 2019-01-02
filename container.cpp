#include "stdafx.h"
#include "container.h"
#include "csvParser.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <regex>
using namespace std;


#define ALL_GROUP_FLAG 0
#define FIND_BY_ADDRESS_FLAG 1
#define NOT_SF_JAZZ 2

container::~container(){};

void container::writeToFile()
{
   ofstream  myFile;
   myFile.open("List.txt");
   vector<personInstance>::iterator it;
   vector<string>::iterator stringIt;

   for( it = dataBase.begin(); it != dataBase.end(); it++ )
   {
      myFile << "email: " << it->getEmailAddress() << " groups: ";
      vector<string> temp = it->groupMember;
      for( stringIt = temp.begin(); stringIt != temp.end(); stringIt++ )
         myFile << *stringIt << ", ";
      myFile << endl;
   }
   myFile.close();
}

void container::writeToFileFind( string groupName, int flag )
{
   
   string fName;
   ofstream  myFile;
   cout << "Enter the name of the file you wish to save: " << endl;
   cout << "NOTE: DO NOT ENTER EXTENTION FILE WILL AUTOMATICLY SAVE AS .txt : "; 
   cin >> fName;
   fName.append(".txt");
   myFile.open( fName );
   vector<string>::iterator stringIt;

   if( flag == FIND_BY_ADDRESS_FLAG )
   {
      myFile << "Group Name: " << groupName << endl;
      myFile << "Emails: " << endl; 
      for( stringIt = findGroupMember.begin(); stringIt != findGroupMember.end(); stringIt++ )
         cout << (*stringIt) << endl;
   }

   if( flag == NOT_SF_JAZZ )
   {
      vector<personInstance>::iterator it;
      for( it = noneSfJazz.begin(); it != noneSfJazz.end(); it++ )
      {
         myFile << "Email: " << it->getEmailAddress() << endl; 
         myFile << "Groups: ";
         vector<string> temp = it->groupMember;
         for( stringIt = temp.begin(); stringIt != temp.end(); stringIt++ )
            myFile << *stringIt << ", ";
         myFile << endl;
      }
   }

   myFile.close();
}

void container::printData( int flag )
{
   vector<personInstance>::iterator it;
   vector<string>::iterator stringIt;

   if( flag == ALL_GROUP_FLAG )
      for( it = dataBase.begin(); it != dataBase.end(); it++ )
      {
         cout << "email: " << it->getEmailAddress() << " groups: ";
         vector<string> temp = it->groupMember;
         for( stringIt = temp.begin(); stringIt != temp.end(); stringIt++ )
            cout << *stringIt << ",";
         cout << endl;
      }
   
      if( flag == NOT_SF_JAZZ )
         for( it = noneSfJazz.begin(); it != noneSfJazz.end(); it++ )
         {
            cout << "email: " << it->getEmailAddress() << " groups: ";
            vector<string> temp = it->groupMember;
            for( stringIt = temp.begin(); stringIt != temp.end(); stringIt++ )
               cout << *stringIt << ",";
            cout << endl;
         }
}

/*
*  Fix in next version update orginal print function use flags
*/
void container::printFindBy( string groupName )
{

   vector<string>::iterator stringIt;

   cout << "GROUP NAME: " << groupName << endl;
   cout << "EMAILS: " << endl;
   for( stringIt = findGroupMember.begin(); stringIt != findGroupMember.end(); stringIt++ )
      cout << (*stringIt) << ", ";
}

void container::findAllNonSFJazz()
{
   vector<personInstance>::iterator it;
   regex compare("(.*)(@sfjazz.org)");

   for( it = dataBase.begin(); it != dataBase.end(); it++ )
      if( !regex_match( it->getEmailAddress(), compare ) );
         noneSfJazz.push_back(*it);
   
}

string container::getEmailAddress( string line )
{
   string emailAddress = strtok( (char *)line.c_str(), ",");
   return emailAddress;
}

void container::readFile(  )
{
   personInstance temp;
   fstream in( fileName.c_str(), ios::in );
   string line = "";

   getline( in, groupName ); // save the group name;
   getline( in, line ); // skip the first line collect the rest of the data
   

   if( !hasData() )
      return;

   while( !in.eof() )
   {
      getline( in, line );
      string emailAddress = getEmailAddress( line );
      compareAddressToVec( emailAddress, groupName );
      
   }
   in.close();
}

void container::compareAddressToVec( string line, string groupName )
{
   vector<personInstance>::iterator it;
   personInstance temp;
   string tempEmail = "";
   for( it = dataBase.begin(); it != dataBase.end(); it++ )
   {
      tempEmail = it->getEmailAddress();
      if( tempEmail == line )
      {
         it->groupMember.push_back(groupName);
         return;
      }
   }
}


/*
*  TERRIBLE SOLUTION NEXT VERSION UPDATE WITH REGEX
*/
void container::findbyGroup( string groupName )
{
   vector<personInstance>::iterator it;
   vector<string>::iterator stringIt;
   personInstance temp;
   string appendMe = "Members for group ";
   appendMe.append(groupName);
   for( it = dataBase.begin(); it != dataBase.end(); it++ )
   {
      vector<string> temp = it->groupMember;
      for( stringIt = temp.begin(); stringIt != temp.end(); stringIt++ )
         if( (*stringIt) == appendMe )
            findGroupMember.push_back(it->getEmailAddress());
   }
}

void container::createDataBase()
{
   personInstance temp;

   fstream in( fileName.c_str(), ios::in );
   string line = "";
   getline( in, line ); // skip the first line collect the rest of the data
   while( !in.eof() )
   {
      getline( in, line );
      if( line == "" )
         break;
      temp = parsedObject( line );
      dataBase.push_back( temp );
   }
   in.close();
   
}

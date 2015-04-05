// brainCorroParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "personInstance.h"
#include "csvParser.h"
#include "container.h"
using namespace std;

#define ALL_GROUP_FLAG 0
#define FIND_BY_ADDRESS_FLAG 1
#define NOT_SF_JAZZ 2

void menu();
void about();

void about()
{
   cout << "***********************************************************" << endl;
   cout << "Author: Marvin Corro"                                        << endl;
   cout << "Version 1.1, added a menu and now you are able to search"    << 
      "by groups by and find emails associated with it."                 << endl;
   cout << "Do what ever you want with this program."                    << endl;
   cout << "***********************************************************" << endl;
}

void menu()
{
   cout << "***************************MENU****************************" << endl;
   cout << "\tList (Prints out entire List)"       << endl;
   cout << "\tFind (Search by group)"              << endl;
   cout << "\tNon (Find users not part of SFJAZZ)" << endl;
   cout << "\tAbout (about this program)"          << endl;
   cout << "\tQuit"                                << endl;
   cout << "***************************END****************************" << endl;
}

int main()
{
   cout << "PROGRAM IS STARTING..." << endl;
   string firstFile  = "UserData-sfjazz.org-20140425.csv";
   string fileList   = "fileList.txt";
   string line       = "";
   string command    = "";
   string findMe     = "";
   fstream in( firstFile.c_str(), ios::in );
   fstream fileListIn( fileList.c_str(), ios::in );
   
   container obj( firstFile );
   obj.createDataBase();
   while( !fileListIn.eof() )
   {
      getline( fileListIn, line );
      obj.setFileName( line );
      obj.readFile(  );
   }
   cout << "Welocme!" << endl;

   do
   {
      menu();
      cout << "Command: ";
      cin >> command;
      if( command == "List" || command == "list" )
      {
         obj.printData( ALL_GROUP_FLAG );
         obj.writeToFile();
         continue;
      }
      if( command == "Find" || command == "find")
      {
         cout << "Please enter the group you wish to look for " << endl;
         cout << "NOTE CASE IS VERY IMPORTANT: ";
         cin >> findMe;
         obj.findbyGroup( findMe );
         obj.printFindBy( findMe );
         cout << "Save this list? <yes/no> " << endl;
         cin >> command;
         if( command == "yes" || command == "Yes" )
            obj.writeToFileFind( findMe, FIND_BY_ADDRESS_FLAG );
         continue;
      }
      if( command == "Non" || command == "non" )
      {
         obj.findAllNonSFJazz();
         obj.printData( NOT_SF_JAZZ );
         cout << "Save this list? <yes/no> " << endl;
         cin >> command;
         if( command == "yes" || command == "Yes" )
            obj.writeToFileFind( "", NOT_SF_JAZZ );
         continue;
      }
      if( command == "about" || command == "About" )
      {
         about();
         continue;
      }

   }while( command != "Quit" && command != "quit" );

   

   
   

   in.close();
   fileListIn.close();

   system("pause");
}


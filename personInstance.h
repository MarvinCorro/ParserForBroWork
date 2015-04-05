#ifndef PERSON_INSTANCE_H
#define PERSON_INSTANCE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class personInstance
{
protected:
   string emailAddress;
   string firstName;
   string lastName;
   string lastLogin;
   string firstLogin;
   int quota;
   

public:
   
   personInstance()
   {
      this->emailAddress = "";
      this->firstName    = "";
      this->lastName     = "";
      this->lastLogin    = "";
      this->firstLogin   = "";
      this->quota        = 0;

   }

   personInstance( string emailAddress, string firstName, string lastName, string lastLogin, string firstLogin, int quota )
   {
      this->emailAddress = emailAddress;
      this->firstName    = firstName;
      this->lastName     = lastName;
      this->lastLogin    = lastLogin;
      this->firstLogin   = firstLogin;
      this->quota        = quota;
   }
   vector<string> groupMember;


   //friend std::ostream& operator<<(std::ostream& os, const personInstance& obj )
   //{
   //   vector<string>::iterator it;
   //   os << "email: " << obj.emailAddress << " ";
   //}

   
   string getEmailAddress() { return this->emailAddress; }
   string getFirstName() { return this->firstName; }
   string getLastName() { return this->lastName; }
   string getLastLogin() { return this->lastLogin; }
   string getFirstLogin() { return this->firstLogin; }
   int getQuota() { return this->quota; }

   void setEmailAddress( string emailAddress ) { this->emailAddress = emailAddress; }
   void setFirstName( string firstName ) { this->firstName = firstName; }
   void setLastName( string lastName ) { this->lastName = lastName; }
   void setLastLogin( string lastLogin ) { this->lastLogin = lastLogin; }
   void setFirstLogin( string firstLogin ) { this->firstLogin = firstLogin; }
   void setQuota( int quota ) { this->quota = quota; }

};
#endif
#pragma once
#include <iostream>


using namespace std;

class ClsPerson {

private:
    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:
    //Set Property
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmail(string Email);
    void setPhone(string Phone);

    //Get Property
    string getFirstName()const;
    string getLastName()const;
    string getEmail()const;
    string getPhone()const;




    ClsPerson(string FirstName, string LastName, string Email, string Phone);
    ClsPerson(string FirstName, string LastName, string Phone);

    string getFullName()const;
    void print()const;
    void sendEmail(string Subject, string Body);
    void sendSMS(string TXTMessage);











};
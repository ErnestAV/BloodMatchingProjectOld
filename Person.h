//
// Created by tombo on 2020/06/24.
//
#include <iostream>
#ifndef BLOOD_TYPE_PROJECT_PERSON_H
#define BLOOD_TYPE_PROJECT_PERSON_H

using std::string;
class Person
{
private:
    Person * matchStatus;
    string time;
    string registeredAs;
    string firstNames;
    string lastNames;
    string bloodType;
    string sexType;
    string phoneNumber;
    string emailAdress;
    string personAge;
    string city;
    string department;
public:
    const string &getTime() const;
    const string &getRegisteredAs() const;
    const string &getFirstNames() const;
    const string &getLastNames() const;
    const string &getBloodType() const;
    const string &getSexType() const;
    const string &getPhoneNumber() const;
    const string &getEmailAdress() const;
    const string &getPersonAge() const;
    const string &getCity() const;
    const string &getDepartment() const;

    void setTime(const string &time);
    void setRegisteredAs(const string &registeredAs);
    void setFirstNames(const string &firstNames);
    void setLastNames(const string &lastNames);
    void setBloodType(const string &bloodType);
    void setSexType(const string &sexType);
    void setPhoneNumber(const string &phoneNumber);
    void setEmailAdress(const string &emailAdress);
    void setPersonAge(const string &personAge);
    void setCity(const string &city);
    void setDepartment(const string &department);

    string ToString() const;
    Person();
    Person(const string &time, const string &registeredAs, const string &firstNames, const string &lastNames,
           const string &bloodType, const string &sexType, const string &phoneNumber, const string &emailAddress,
           const string &personAge, const string &city, const string &department);

    Person *getMatchStatus() const;

    void setMatchStatus(Person *matchStatus);
};


#endif //BLOOD_TYPE_PROJECT_PERSON_H

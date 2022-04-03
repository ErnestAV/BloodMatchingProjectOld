
#include "Person.h"
const string &Person::getTime() const
{
    return time;
}

const string &Person::getRegisteredAs() const
{
    return registeredAs;
}

const string &Person::getFirstNames() const
{
    return firstNames;
}

const string &Person::getLastNames() const
{
    return lastNames;
}

const string &Person::getBloodType() const
{
    return bloodType;
}

const string &Person::getSexType() const
{
    return sexType;
}

const string &Person::getPhoneNumber() const
{
    return phoneNumber;
}

const string &Person::getEmailAdress() const
{
    return emailAdress;
}

const string &Person::getPersonAge() const
{
    return personAge;
}

const string &Person::getCity() const
{
    return city;
}

const string &Person::getDepartment() const
{
    return department;
}

Person::Person(const string &time, const string &registeredAs, const string &firstNames, const string &lastNames,
               const string &bloodType, const string &sexType, const string &phoneNumber, const string &emailAddress,
               const string &personAge, const string &city, const string &department) : time(time),
                                                                                        registeredAs(registeredAs),
                                                                                        firstNames(firstNames),
                                                                                        lastNames(lastNames),
                                                                                        bloodType(bloodType),
                                                                                        sexType(sexType),
                                                                                        phoneNumber(phoneNumber),
                                                                                        emailAdress(emailAdress),
                                                                                        personAge(personAge),
                                                                                        city(city),
                                                                                        department(department),
                                                                                        matchStatus(NULL)
{}

Person::Person() : matchStatus(NULL)
{}

Person *Person::getMatchStatus() const
{
    return matchStatus;
}

void Person::setMatchStatus(Person *matchStatus)
{
    Person::matchStatus = matchStatus;
}

void Person::setTime(const string &time)
{
    Person::time = time;
}

void Person::setRegisteredAs(const string &registeredAs)
{
    Person::registeredAs = registeredAs;
}

void Person::setFirstNames(const string &firstNames)
{
    Person::firstNames = firstNames;
}

void Person::setLastNames(const string &lastNames)
{
    Person::lastNames = lastNames;
}

void Person::setBloodType(const string &bloodType)
{
    Person::bloodType = bloodType;
}

void Person::setSexType(const string &sexType)
{
    Person::sexType = sexType;
}

void Person::setPhoneNumber(const string &phoneNumber)
{
    Person::phoneNumber = phoneNumber;
}

void Person::setEmailAdress(const string &emailAdress)
{
    Person::emailAdress = emailAdress;
}

void Person::setPersonAge(const string &personAge)
{
    Person::personAge = personAge;
}

void Person::setCity(const string &city)
{
    Person::city = city;
}

void Person::setDepartment(const string &department)
{
    Person::department = department;
}

string Person::ToString() const
{
    return string("Person info\n") +
           "--------------\n" +
           "Name: " + firstNames + " " + lastNames + "\n" +
           "Gender: " + sexType + "\n" +
           "Age: " + personAge + "\n" +
           "Blood type: " + bloodType + "\n" +
           "Phone number: " + phoneNumber + "\n" +
           "Status: " + registeredAs + "\n" +
           "Location: " + city + " " + department + "\n";
}

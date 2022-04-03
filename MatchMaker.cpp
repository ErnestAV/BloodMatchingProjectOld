//
// Created by tombo on 2020/06/28.
//

#include "MatchMaker.h"
enum labels{
    TIME, STATUS, FIRST_NAME, LAST_NAME, GENDER, PERSON_AGE, BLOOD_TYPE, PHONE_NUMBER, EMAIL, CITY, DEPARTMENT
};

void MatchMaker::PopulatePeople(std::ifstream &in)
{
    std::string line;
    getline(in, line); //TO IGNORE FIRST ROW
    while(getline(in, line))
    {
        std::istringstream iss(line);
        Person * person = new Person;
        for(int i = 0; i < NUM_ATTRIBUTES; i++)
        {
            string element;
            getline(iss, element, ',');
            SetAttribute(person, i, element);
        }
        allPeople.push_back(person);
    }
}

void MatchMaker::SetAttribute(Person * person, int i, string element)
{
    switch(i)
    {
        case (TIME):
            person->setTime(element);
            break;
        case (STATUS):
            person->setRegisteredAs(element);
            break;
        case (FIRST_NAME):
            person->setFirstNames(element);
            break;
        case (LAST_NAME):
            person->setLastNames(element);
            break;
        case (GENDER):
            person->setSexType(element);
            break;
        case (PERSON_AGE):
            person->setPersonAge(element);
            break;
        case (BLOOD_TYPE):
            person->setBloodType(element);
            break;
        case (PHONE_NUMBER):
            person->setPhoneNumber(element);
            break;
        case (EMAIL):
            person->setEmailAdress(element);
            break;
        case (CITY):
            person->setCity(element);
            break;
        case (DEPARTMENT):
            person->setDepartment(element);
            break;
        default:
            break;
    }
}

MatchMaker::MatchMaker(std::string fileName)
{
    std::ifstream fileToRead(fileName);
    if(!fileToRead.is_open())
    {
        std::cout << "Error file could not be opened" << std::endl;
    }
    else
    {
        PopulatePeople(fileToRead);
    }
    fileToRead.close();
}

void MatchMaker::Print()
{
    for(Person * x: allPeople)
    {
        std::cout << x->ToString() << std::endl;
    }
}

MatchMaker::~MatchMaker()
{
    for(Person * x: allPeople)
    {
        delete x;
    }
}

void MatchMaker::ClassifyPairs(const string fileName)
{

    std::ofstream fileToWrite(fileName);
    PopulateDonorReceiver();
    MatchPairs();
    fileToWrite << "Matches\n-------------------\n";
    for(Person * i: donors)
    {
        if(i->getMatchStatus() != NULL)
        {
            fileToWrite << "Donor Name: " << i->getFirstNames() << " " << i->getLastNames() << std::endl;
            fileToWrite << "Reciever Name: " << i->getMatchStatus()->getFirstNames() << " "
                << i->getMatchStatus()->getLastNames() << std::endl;
            fileToWrite << "Donor Location: " << i->getCity() << ", " << i->getDepartment() << std::endl;
            fileToWrite << "Reciever Location: " << i->getMatchStatus()->getCity() << ", "
                << i->getMatchStatus()->getDepartment() << std::endl;
            fileToWrite << "Blood type donor: " << i->getBloodType() << std::endl;
            fileToWrite << "Blood type receiver: " << i->getMatchStatus()->getBloodType() << std::endl;
            fileToWrite << "Donor phone number: " << i->getPhoneNumber() << std::endl;
            fileToWrite << "Receiver phone number: " << i->getMatchStatus()->getPhoneNumber() << std::endl;
            fileToWrite << "\n\n";
        }
    }
    fileToWrite.close();
}

void MatchMaker::PopulateDonorReceiver()
{
    for(Person * x: allPeople)
    {
        if(x->getRegisteredAs() == "Donante")
        {
            donors.push_back(x);
        }
        else
        {
            receivers.push_back(x);
        }
    }
}

void MatchMaker::MatchPairs()
{
    for(Person * i: donors)
    {
        for(Person * j: receivers)
        {
            if((i->getBloodType() == j->getBloodType()) && (j->getMatchStatus() == NULL))
            {
                i->setMatchStatus(j);
                j->setMatchStatus(i);
                break;
            }
        }
    }
}

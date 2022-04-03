//
// Created by tombo on 2020/06/28.
//

#ifndef BLOOD_TYPE_PROJECT_MATCHMAKER_H
#define BLOOD_TYPE_PROJECT_MATCHMAKER_H
#include <vector>
#include "Person.h"
#include <sstream>
#include <fstream>
#include <string>
const int NUM_ATTRIBUTES = 13;


class MatchMaker
{
private:
    std::vector<Person*> allPeople;
    std::vector<Person*> donors;
    std::vector<Person*> receivers;
    void SetAttribute(Person * person, int i, string element);
public:
    void PopulatePeople(std::ifstream &in);
    MatchMaker(std::string fileName);

    virtual ~MatchMaker();

    void Print();

    void ClassifyPairs(const string fileName);

    void PopulateDonorReceiver();

    void MatchPairs();
};


#endif //BLOOD_TYPE_PROJECT_MATCHMAKER_H

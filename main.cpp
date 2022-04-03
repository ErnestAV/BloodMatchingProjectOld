#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include "Person.h"
#include "MatchMaker.h"

using namespace std;

int main(int argc, char ** argv){
    const int NUM_ATTRIBUTES = 13;
    string fileName = "";
    if(argc > 0)
    {
        fileName = argv[1];
    }
    else
    {
        return 0;
    }
    MatchMaker matchMaker("../Formulario.csv");
    //matchMaker.Print();
    matchMaker.ClassifyPairs("Matches.txt");
    return 0;
}


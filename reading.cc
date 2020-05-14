#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"

std::vector<std::string> splitString(std::string s, std::string delimiter){
    std::vector <std::string> temp;
    size_t position=0;
    std::string token;

    while( (position = s.find(delimiter)) != std::string::npos){
        token = s.substr(0, position);
        temp.push_back(token);
        s.erase(0, position + delimiter.length());
    }
    temp.push_back(s);

    return temp;
}

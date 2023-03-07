#pragma once
#include <iostream>
using namespace std;
#include "GlobalFile.h"
#include <map>
#include <fstream>

class order
{
    public:
    order();

    void updateorder();

    int size_;
    map<int,map<string,string>> orderdata;




    
};
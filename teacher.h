#pragma once
#include <string>
#include <iostream>
#include "identity.h"
using namespace std;

class teacher:public Identity
{
    public:
    //构造
    teacher();

    teacher(int Tid, string Tname,string Tpwd);
    //
    virtual void OperMenu();

    void CheckOrder();


 

    void ShowAllOrder();



    int TID_;

};

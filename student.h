#pragma once
#include <string>
#include <iostream>
#include "identity.h"
using namespace std;

class student:public Identity
{
    public:
    //构造
    student();

    student(int id, string name,string pwd);
    //
    virtual void OperMenu();

    void ApllyOrder();


    void ShowMyOrder();

    void ShowAllOrder();

    void CancelOrder();

    int SID_;
};

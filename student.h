#pragma once
#include <string>
#include <fstream>
#include "identity.h"
#include <vector>
#include "GlobalFile.h"
#include "computer.h"
#include <algorithm>
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

    vector<computer> vRoom;
};

#pragma once
#include <string>
#include <iostream>
#include "identity.h"
#include <fstream>
#include "GlobalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computer.h"
using namespace std;

class admin : public Identity
{
public:
    //构造
    admin();

    admin(int Aid, string Aname, string Apwd);
    //
    virtual void OperMenu();

    void CreateAccount();

    void ShowAccount();

    void ShowComputer();

    void AddRoom();

    void ClearOrder();

    void InitDatabase();

    bool Checkrepeat(int id, int type);



    int AID_;
    vector<student> vStu;
    vector<teacher> vTea;
    vector<computer> vRoom;
    
};

#pragma once
#include <iostream>
#include <string>

using namespace std;

class computer
{
    public:
    computer(int Id, int volume):RoomId_(Id),ComputerNum_(volume){};

    bool operator==(const int & id)
    {
        if (this->RoomId_==id)
        {
            return true;
        }
        return false;
    }

    int RoomId_;

    int ComputerNum_;
};
#include "order.h"

void truncstr(string rec, string &key, string &value)
{
    int pos = rec.find(":");
    key = rec.substr(0, pos);
    value = rec.substr(pos + 1, rec.size() - pos - 1);
}

order::order(){
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);

    string data;
    string timeslot;
    string stuId;
    string stuName;
    string roomId;
    string status;

    this->size_=0;

    while (ifs>>data && ifs>>timeslot && ifs>>stuId && ifs>>stuName && ifs>>roomId && ifs>>status)
    {
        string key;
        string value;
        map<string,string> m;

        truncstr(data,key,value);
        m.insert(make_pair(key,value));
        truncstr(timeslot,key,value);
        m.insert(make_pair(key,value));
        truncstr(stuId,key,value);
        m.insert(make_pair(key,value));
        truncstr(stuName,key,value);
        m.insert(make_pair(key,value));                
        truncstr(roomId,key,value);
        m.insert(make_pair(key,value));
        truncstr(status,key,value);
        m.insert(make_pair(key,value));

        this->orderdata.insert(make_pair(this->size_,m)) ;
        this->size_++;       
    }
    
    ifs.close();
}

void order::updateorder(){
    if (this->size_==0)
    {
        return;
    }
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::trunc);
    for (size_t i = 0; i < this->size_; i++)
    {
        ofs<<"data:"<<this->orderdata[i]["data"]<<" ";
        ofs<<"timeslot:"<<this->orderdata[i]["timeslot"]<<" ";   
        ofs<<"roomId:"<<this->orderdata[i]["roomId"]<<" ";
        ofs<<"stuId:"<<this->orderdata[i]["stuId"]<<" ";
        ofs<<"stuName:"<<this->orderdata[i]["stuName"]<<" ";
        ofs<<"status:"<<this->orderdata[i]["status"]<<endl;    
    
    }
    ofs.close();
}
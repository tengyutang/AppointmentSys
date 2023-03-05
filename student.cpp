#include "student.h"


student::student(int id, string name,string pwd)
{
    this->SID_=id;
    this->Name_=name;
    this->Pwd_=pwd;

    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    
    computer com(0,0);
    while(ifs>>com.RoomId_&&ifs>>com.ComputerNum_)
    {
        this->vRoom.push_back(com);
    }
    ifs.close();
}
//
void student::OperMenu()
{
    cout << "欢迎学生" << this->Name_ << "登陆" << endl;
    cout << "\t\t --------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.申请预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看我的预约        |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看所有预约        |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.取消预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t --------------------------------\n";

    cout << "请输入你的选择：" << endl;

}

void student::ApllyOrder()
{
    cout<<"机房开放时间为周一到周五！"<<endl;
    cout<<"请输入申请预约的时间"<<endl;
    cout<<"1.周一"<<endl;
    cout<<"2.周二"<<endl;
    cout<<"3.周三"<<endl;
    cout<<"4.周四"<<endl;
    cout<<"5.周五"<<endl;

    int data=0;
    int timeslot=0;
    int roomid=0;

    while (true)
    {
        cin>>data;
        if (data>=1||data<=5)
        {
            break;
        }
        cout<<"输入有误，请重新输入！"<<endl;
        
    }

    cout<<"请输入预约时段"<<endl;
    cout<<"1. 上午"<<endl;
    cout<<"2. 下午"<<endl;
    while (true)
    {
        cin>>timeslot;
        if (timeslot>=1||timeslot<=2)
        {
            break;
        }
        cout<<"输入有误，请重新输入！"<<endl;
        
    }    

    cout<<"请输入机房编号"<<endl;
    cout<<"目前可用机房为："<<endl;
    for (auto room:this->vRoom)
    {
        cout<<"机房"<<room.RoomId_<<" 容量"<<room.ComputerNum_<<endl;
    }

    while (true)
    {
        cin>>roomid;
        vector<computer>::iterator it=find(vRoom.begin(),vRoom.end(), roomid);
        if (it!=vRoom.end())
        {
            break;
        }
      
        cout<<"输入有误，请重新输入！"<<endl;
       
    }    
    cout<<"预约成功！"<<endl;
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::app);
    ofs<<"data: "<<data<<" ";
    ofs<<"timeslot: "<<timeslot<<" ";   
    ofs<<"RoomId: "<<roomid<<" ";
    ofs<<"sutId: "<<this->SID_<<" ";
    ofs<<"sutName: "<<this->Name_<<" ";
    ofs<<"satus: "<<1<<endl;    

    ofs.close();
    system("pause");
    system("cls");
}


void student::ShowMyOrder()
{


}

void student::ShowAllOrder()
{

}

void student::CancelOrder()
{

}
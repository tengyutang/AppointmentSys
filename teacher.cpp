#include "teacher.h"


teacher::teacher(int id, string name,string pwd)
{
    this->TID_=id;
    this->Name_=name;
    this->Pwd_=pwd;
}
//
void teacher::OperMenu()
{
    cout << "欢迎学生" << this->Name_ << "登陆" << endl;
    cout << "\t\t --------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.查看所有预约        |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.审核预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t --------------------------------\n";

    cout << "请输入你的选择：" << endl;


}

void teacher::CheckOrder()
{
    order od;
    if (od.size_ == 0)
    {
        cout << "无预约记录！" << endl;
        system("pause");
        system("cls");
        return;
    }    

    while (true)
    {
        vector<int> v;
        cout<<"目前待审核申请如下："<<endl;
        int index=0;
        for (size_t i = 0; i < od.size_; i++)
        {
            if (od.orderdata[i]["status"] == "1")
            {
                v.push_back(i);
                cout << ++index << "、 ";
                cout << " 预约日期： 周" << od.orderdata[i]["data"];
                cout << " 时段： " << (od.orderdata[i]["timeslot"] == "1" ? "上午" : "下午");
                cout << " 机房： " << od.orderdata[i]["roomId"];
                cout << " 学号： " << od.orderdata[i]["stuId"];
                cout << " 姓名： " << od.orderdata[i]["stuName"];
                string status = "状态： ";
                if (od.orderdata[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (od.orderdata[i]["status"] == "2")
                {
                    status += "预约成功！";
                }
                else if (od.orderdata[i]["status"] == "-1")
                {
                    status += "申请驳回！";
                }
                else
                {
                    status += "预约取消！";
                }
                cout << status << endl;
            }
        }
            cout<<"请输入审核的预约记录，0代表返回"<<endl;
            int sel;
            int ret=0;


            cin>>sel;
            if (sel>=0 && sel<=v.size())
            {
                if (sel==0)
                {
                    break;
                }
                else
                {
                    cout<<"请输入审核结果"<<endl;
                    cout<<"1. 通过"<<endl;
                    cout<<"2. 不通过"<<endl;
                    cin>>ret;
                    if (ret==1)
                    {
                        od.orderdata[v[sel-1]]["status"]="2";
                    }
                    else
                    {
                        od.orderdata[v[sel-1]]["status"]="-1";
                    }
                    od.updateorder();
                    cout<<"审核完毕"<<endl;
                }
            }
        system("pause");
        system("cls");    
    }

}


void teacher::ShowAllOrder()
{
    order od;
    if (od.size_ == 0)
    {
        cout << "无预约记录！" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (size_t i = 0; i < od.size_; i++)
    {
        cout << i + 1;
        cout << " 预约日期： 周" << od.orderdata[i]["data"];
        cout << " 时段： " << (od.orderdata[i]["timeslot"] == "1" ? "上午" : "下午");
        cout << " 学号： " << od.orderdata[i]["stuId"];
        cout << " 姓名： " << od.orderdata[i]["stuName"];
        cout << " 机房： " << od.orderdata[i]["roomId"];

        string status = "状态： ";
        if (od.orderdata[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (od.orderdata[i]["status"] == "2")
        {
            status += "预约成功！";
        }
        else if (od.orderdata[i]["status"] == "-1")
        {
            status += "申请驳回！";
        }
        else
        {
            status += "预约取消！";
        }

        cout << status << endl;
    }
    system("pause");
    system("cls");
    return;

}


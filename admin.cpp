#include "admin.h"
#include <algorithm>

admin::admin()
{
}

admin::admin(int Aid, string Aname, string Apwd)
{
    this->AID_ = Aid;
    this->Name_ = Aname;
    this->Pwd_ = Apwd;

    this->InitDatabase();
}

//////////////////////////////////////////////////////////////////////////
void admin::OperMenu()
{
    cout << "欢迎管理员" << this->Name_ << "登陆" << endl;
    cout << "\t\t --------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          5.添加机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t --------------------------------\n";

    cout << "请输入你的选择：" << endl;
}
//////////////////////////////////////////////////////////////////////////////////
void admin::CreateAccount()
{
    cout << "请选择账号类型" << endl;
    cout << "1：添加学生" << endl;
    cout << "2：添加老师" << endl;
    cout << "3：添加管理员" << endl;

    string filename;
    string tip;
    string errtip;

    ofstream ofs;
    int sle;
    cin >> sle;

    if (sle == 1)
    {
        filename = STUDENT_FILE;
        tip = "请输入学号";
        errtip="学号重复请重新输入：";
    }
    else if (sle == 2)
    {
        filename = TEACHER_FILE;
        tip = "请输入工号";
        errtip="工号重复请重新输入：";
    }
    else if (sle == 3)
    {
        filename = ADMIN_FILE;
        tip = "请输入管理员帐号";
        
    }
    else
    {
        filename = STUDENT_FILE;
        tip = "请输入学号";
        errtip="学号重复请重新输入：";
    }

    string name;
    string pwd;

    ofs.open(filename, ios::out | ios::app);

    cout << tip << endl;
    int id;
    while (true)
    {
        cin >> id;
        if (Checkrepeat(id,sle))
        {
            cout<<errtip<<endl;

        }
        else
        {
            break;
        }
    }
 
    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功！" << endl;

    switch (sle)
    {
        case 1:
            this->vStu.push_back(student (id,name,pwd));
            break;
        case 2:
            
            this->vTea.push_back(teacher (id,name,pwd));
            break;    
        default:
            break;
    }
    
    system("cls");
    ofs.close();
}

void printstudent(student &s)
{

    cout<<"学号"<<s.SID_<<" 姓名"<<s.Name_<<" 密码"<<s.Pwd_<<endl;
}

void printteacher(teacher &t)
{

    cout<<"工号"<<t.TID_<<" 姓名"<<t.Name_<<" 密码"<<t.Pwd_<<endl;
}

void printRoom(computer &r)
{

    cout<<"机房名"<<r.RoomId_<<" 容量"<<r.ComputerNum_<<endl;
}

void admin::ShowAccount()
{
    cout<<"请选择查看内容："<<endl;
    cout<<"1.查看所有学生："<<endl;
    cout<<"2.查看所有老师"<<endl;
    cout<<"3.查看所有管理员"<<endl;

    int sel=0;
    cin>>sel;

    if (sel==1)
    {
        cout<<"所有学生信息如下："<<endl;
        cout<<"-----------------------------------"<<endl;
        for_each(vStu.begin(),vStu.end(),printstudent);
        cout<<"-----------------------------------"<<endl;
    }
    else if (sel==2)
    {
        cout<<"所有老师信息如下："<<endl;
        cout<<"-----------------------------------"<<endl;
        for_each(vTea.begin(),vTea.end(),printteacher);
        cout<<"-----------------------------------"<<endl;
    }
    system("pause");
    system("cls");
  
        
}

void admin::ShowComputer()
{
    cout<<"所有机房信息如下："<<endl;
    cout<<"-----------------------------------"<<endl;
    for_each(vRoom.begin(),vRoom.end(),printRoom);
    cout<<"-----------------------------------"<<endl;
    system("pause");
    system("cls");
}

void admin::ClearOrder()
{ 
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    //vOrder.clear();
    cout<<"清空成功"<<endl;
    system("pause");
    system("cls");
    
}

void admin::InitDatabase()
{   
    vStu.clear();
    vTea.clear();
    vRoom.clear();
    //读入学生数据
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }



    student s(0,"","");
    while (ifs >> s.SID_ && ifs >> s.Name_ && ifs >> s.Pwd_)
    {
        vStu.push_back(s);
    }

    cout << "当前学生数量为：" << vStu.size() << endl;
    ifs.close();
    //读入老师数据
    ifs.open(TEACHER_FILE, ios::in);

    teacher t(0,"","");
    while (ifs >> t.TID_ && ifs >> t.Name_ && ifs >> t.Pwd_)
    {
        vTea.push_back(t);
    }
    cout << "当前老师数量为：" << vTea.size() << endl;
    ifs.close();

    ifs.open(COMPUTER_FILE, ios::in);
    //读入机房数据
    computer r(0,0);
    while (ifs >> r.RoomId_&& ifs >> r.ComputerNum_)
    {
        vRoom.push_back(r);
    }
    cout << "当前机房数量为：" << vRoom.size() << endl;
    ifs.close();
}

bool admin::Checkrepeat(int id, int type)
{
    switch (type)
    {
    case 1:
        for (vector<student>::iterator it = vStu.begin(); it!=vStu.end(); it++)
        {
            if (id==it->SID_)
            {
                return true;
            }
            
        } 
        break;
    case 2:
        for (vector<teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->TID_)
            {
                return true;
            }
        }
        break;
    case 4:
        for (vector<computer>::iterator it = vRoom.begin(); it != vRoom.end(); it++)
        {
            if (id == it->RoomId_)
            {
                return true;
            }
        }
        break;               
    default:
        break;
    }
    return false;
}

void admin::AddRoom()
{
    cout << "请输入加入的机房数量：" << endl;
    int num=0;
    cin>>num;
    int roomid;
    int volume;
    ofstream ofs;
    ofs.open(COMPUTER_FILE, ios::out | ios::app);

    for (size_t i = 0; i < num; i++)
    {
        while (true)
        {
            cout<<"请输入机房名："<<endl;
            cin>>roomid;
            if (Checkrepeat(roomid,4))
            {
                cout<<"机房名重复，请重新输入："<<endl;
            }
            else
            {
                break;
            }
        }
        cout<<"请输入机房容量："<<endl;
        cin>>volume;
        ofs << roomid << " " <<  volume<< endl;
        cout << "添加成功！" << endl;
        this->vRoom.push_back(computer (roomid,volume));
    }
    system("cls");
    ofs.close();

}
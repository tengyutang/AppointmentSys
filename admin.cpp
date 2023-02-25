#include "admin.h"

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

void admin::ShowAccount()
{
}

void admin::ShowComputer()
{
}

void admin::ClearOrder()
{
}

void admin::InitDatabase()
{
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    vStu.clear();
    vTea.clear();

    student s(0,"","");
    while (ifs >> s.SID_ && ifs >> s.Name_ && ifs >> s.Pwd_)
    {
        vStu.push_back(s);
    }

    cout << "当前学生数量为：" << vStu.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);

    teacher t(0,"","");
    while (ifs >> t.TID_ && ifs >> t.Name_ && ifs >> t.Pwd_)
    {
        vTea.push_back(t);
    }
    cout << "当前老师数量为：" << vTea.size() << endl;
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
           
    default:
        break;
    }
    return false;
}
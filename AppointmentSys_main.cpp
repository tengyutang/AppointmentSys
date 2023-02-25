#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "identity.h"
#include "admin.h"
#include "student.h"
#include "teacher.h"
#include "GlobalFile.h"

using namespace std;

void AdminMenu(Identity *&person)
{
    while ((true))
    {

        person->OperMenu();
        admin *Man = (admin *)person;

        int select = 0;
        cin >> select;

        switch (select)
        {
        case 1:
            Man->CreateAccount();

            break;
        case 2:
            Man->ShowAccount();
            break;
        case 3:
            Man->ShowComputer();
            break;
        case 4:
            Man->ClearOrder();
            break;
        default:
            delete Man;
            cout << "注销成功" << endl;

            return;
        }
        system("cls");
    }
}

void TeacherMenu(Identity *&person)
{
    while ((true))
    {

        person->OperMenu();
        teacher *Man = (teacher *)person;

        int select = 0;
        cin >> select;

        switch (select)
        {
        case 1:
            Man->CheckOrder();

            break;
        case 2:
            Man->ShowAllOrder();
            break;
        default:
            delete Man;
            cout << "注销成功" << endl;
            return;
        }
        system("cls");
    }
}

void login(string filename, int type)
{ //父类指针，用于多态创建子类对象
    Identity *Person = NULL;

    ifstream ifs;
    ifs.open(filename, ios::in);

    //
    if (!ifs.is_open())
    {
        cout << "文件不存在，请创建文件" << endl;
        ifs.close();
        return;
    }
    //
    int id = 0;
    string name;
    string pwd;

    switch (type)
    {
    case 1:
        cout << "请输入你的学号：" << endl;
        cin >> id;
        break;
    case 2:
        cout << "请输入你的职工号：" << endl;
        cin >> id;
        break;
    case 3:
        cout << "请输入你的账号：" << endl;
        cin >> id;
        break;

    default:
        cout << "输入错误，请重新输入！" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    int fid;
    string fname;
    string fpwd;

    switch (type)
    {
    case 1:
        while ((ifs >> fid) && (ifs >> fname) && (ifs >> fpwd))
        {
            if ((fid == id) && (string(fname) == name) && (string(fpwd) == pwd))
            {
                cout << "学生账号验证成功" << endl;
                system("pause");
                system("cls");
                Person = new student(id, name, pwd);
                //进入学生界面

                return;
            }
        }

        break;
    case 2:
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd == pwd)
            {
                cout << "教师账号验证成功" << endl;
                system("pause");
                system("cls");
                Person = new teacher(id, name, pwd);
                //进入教师界面

                return;
            }
        }
        break;
    case 3:
        if (id == 0 && name == "000" && pwd == "000")
        {
            cout << "管理员账号验证成功" << endl;
            system("pause");
            system("cls");
            Person = new admin(id, name, pwd);
            //进入管理员界面
            AdminMenu(Person);

            return;
        }

        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd == pwd)
            {
                cout << "管理员账号验证成功" << endl;
                system("pause");
                system("cls");
                Person = new admin(id, name, pwd);
                //进入管理员界面
                AdminMenu(Person);

                return;
            }
        }
        cout << "账号或密码不对！" << endl;
        system("pause");
        system("cls");
        break;
    default:
        cout << "输入错误，请重新输入！" << endl;
        system("pause");
        system("cls");
        return;
    }
}

int main()
{

    while (1)
    {
        system("cls");
        cout << "=================欢迎来到机房预约系统===================" << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t --------------------------------\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          1.学生代表            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          2.老师                |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          3.管理员              |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          0.退出                |\n";
        cout << "\t\t --------------------------------\n";
        int select = 0;
        cin >> select;

        switch (select)
        {
        case 1:
            login(STUDENT_FILE, 1);
            break;
        case 2:
            login(TEACHER_FILE, 2);
            break;
        case 3:
            login(ADMIN_FILE, 3);
            break;
        case 0:
            cout << "欢迎再次使用！" << endl;
            system("pause");
            return 0;

        default:
            cout << "输入错误，请重新输入" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
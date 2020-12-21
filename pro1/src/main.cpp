#include <iostream>
#include <stdlib.h>

#include "course.hpp"
#include "list.hpp"

using namespace std;

using namespace demo;

mList<Course> course_list;

void printFunctionMenu(){
    cout<<"功能菜单"<<endl;
    cout<<"请输入对应功能号选择需要使用的功能"<<endl;
    cout<<"1.添加课堂"<<endl;
    cout<<"2.删除课堂"<<endl;
    cout<<"3.录入学生成绩"<<endl;
    cout<<"4.删除学生成绩"<<endl;
    cout<<"5.查询学生成绩"<<endl;
    cout<<"6.计算课堂平均分"<<endl;
    cout<<"0.退出系统"<<endl;
}

int main(){
    cout<<"\twelcome\t"<<endl;
    cout<<"学生成绩成绩管理系统"<<endl;
    char op;
    cin>>op;
    system("cls");
    while(cin>>op){
        int op_number = op - '0';
        switch(op){
            case 0:
                system("cls");
                cout<<"感谢使用"<<endl;
                return 0;
            case 1:{
                cout<<"请输入需要添加的课堂id 名称"<<endl;
                string id,name;
                cin>>id>>name;
                course_list.emplace_back(Course(id,name));
                break;
            }
            default:
                break;
                break;
        }
    }
    return 0;
}
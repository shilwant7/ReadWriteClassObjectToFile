#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Emp
{

public:
    int id;
    string name;
    void getData()
    {
        cout<<"Enter id :";
        cin>>id;
        cout<<"Enter Name : ";
        cin>>name;
    }
    void disp()
    {
        cout<<id<<"  "<<name<<endl;
    }
};

int main()
{
    fstream file;
    file.open("employee.DAT", ios::in | ios::out);//input and output
    Emp E[2];
    for(int i=0; i< 2; ++i){
        E[i].getData();
        file.write((char*)&E[i], sizeof(E[i]));
    }

    file.seekg(0);

    for(int i=0; i< 2; ++i){
        file.read((char*)&E[i], sizeof(E[i]));
        E[i].disp();
    }

    file.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int student();
int teacher();
int admin();
int utility();
void clear();
int main(int argc, char** argv) {
 student();
}
int student(){
 char s_choice[10];
 cout<<""<<endl;
 S1:
 cout<<"[1] Add"<<endl;
 cout<<"[2] Search"<<endl;
 cout<<"[3] back"<<endl;
 cout<<"choose : ";cin>>s_choice[0];
 switch(s_choice[0])
 {
 case '1' :{
 char id[50],name[50],age[25],year[25],section[25];
 fstream stud;
 stud.open("student.txt",ios::app);
 cin.ignore();
 cout<<"ID number :";
 cin.getline(id,50);
 cout<<"name :";
 cin.getline(name,50);
 cout<<"age :";
 cin.getline(age,25);
 cout<<"year :";
 cin.getline(year,25);
 cout<<"section";
 cin.getline(section,25);
 stud<<id<<'|'<<name<<'|'<<age<<'|'<<year<<'|'<<section<<endl;
 cout<<"student successfully added /n";
 stud.close();
 break;
 }
 case '2':{
 char id[50],name[50],age[25],year[25],section[25],a[50];
 int flag=0;
 fstream stud;
 stud.open("student.txt",ios::in);
 cout<<"enter student ID :";
 cin.ignore();
 cin.getline(a,50);
 while(!stud.eof()){
 stud.getline(id,50,'|');
 stud.getline(name,50,'|');
 stud.getline(age,25,'|');
 stud.getline(year,50,'|');
 stud.getline(section,50);
 if(strcmp(id,a)==0)
 {
 cout<<"ID: \t"<<"name \t"<<"age \t"<<"year \t"<<"section"<<endl;
 cout<<id<<" \t"<<name<<" \t"<<age<<" \t"<<year<<" \t"<<section<<endl;
 char choice1;
 cout<<"[1] update"<<endl;
 cout<<"[2] delete"<<endl;
 cin>>choice1;
 if(choice1=='1'){
 fstream stud1;
                         fstream temp;
 char id[50],name[50],age[25],year[25],section[25];
 cin.ignore();
 stud1.open("student.txt",ios::in);
     temp.open("temp.txt",ios::out);
     while(!stud1.eof()){
         stud1.getline(id,50,'|');
 stud1.getline(name,50,'|');
 stud1.getline(age,25,'|');
 stud1.getline(year,50,'|');
 stud1.getline(section,50);
 if(strcmp(id,a)==0){
 cout<<"enter new data"<<endl;
 cout<<"ID number :";
 cin.getline(id,50);
 cout<<"name :";
 cin.getline(name,50);
 cout<<"age :";
 cin.getline(age,25);
 cout<<"year :";
 cin.getline(year,25);
 cout<<"section";
 cin.getline(section,25);
 temp<<id<<'|'<<name<<'|'<<age<<'|'<<year<<'|'<<section<<endl; 
 break;
 }
 }
 temp.close();
 stud1.close();
  stud1.open("student.txt",ios::out);
      temp.open("temp.txt",ios::in);
      while(!temp.eof()){
     temp.getline(id,50,'|');
 temp.getline(name,50,'|');
 temp.getline(age,25,'|');
 temp.getline(year,50,'|');
 temp.getline(section,50);
 stud1<<id<<'|'<<name<<'|'<<age<<'|'<<year<<'|'<<section<<endl; 
  }
 temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"data updated";
 }
 else if(choice1=='2'){
 fstream stud1;
                         fstream temp;
 char id[50],name[50],age[25],year[25],section[25];
 cin.ignore();
 stud1.open("student.txt",ios::in);
     temp.open("temp.txt",ios::out);
     cout<<"enter ID number again to confirmed :";
     cin.getline(a,25);
     while(!stud1.eof()){
         stud1.getline(id,50,'|');
 stud1.getline(name,50,'|');
 stud1.getline(age,25,'|');
 stud1.getline(year,50,'|');
 stud1.getline(section,50);
 if(strcmp(id,a)==0){
 continue;
               }
 else {
 temp<<id<<'|'<<name<<'|'<<age<<'|'<<year<<'|'<<section<<endl;
 }
 }
 temp.close();
 stud1.close();
  stud1.open("student.txt",ios::out);
      temp.open("temp.txt",ios::in);
      while(!temp.eof()){
     temp.getline(id,50,'|');
 temp.getline(name,50,'|');
 temp.getline(age,25,'|');
 temp.getline(year,50,'|');
 temp.getline(section,50);
 stud1<<id<<'|'<<name<<'|'<<age<<'|'<<year<<'|'<<section<<endl; 
  }
 temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"data deleted";
 }
 flag=1;
 break;
 }
 }
 if(flag==0){
 cout<<"data not found"<<endl;
 student();
 }
 stud.close();
 break;
 }
 case '3':{
 break;
 }
 default:{
 cout<<"invalid input"<<endl;
 clear();
 goto S1;
 break;
 }
}
}
void clear(){
 cout<<endl<<endl;
 system("pause");
 system("cls");
}

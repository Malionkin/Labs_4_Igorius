#include <iostream>
#include "Data_list.h"
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;






int main(){
  string title = "C:\\Users\\Xiaomi\\untitled27\\L1_ANSI (2).txt";
  Data_list data(title);
  data.Parse();
  data.Filter_Course();
  data.Sort_by_Surname();
  data.Vivod();
  data.Vec_to_Set();
  while(true)
  {
    string Surname;
    string Name;
    string FatherName;
    cout << "Please, enter your surname, name and fathername!"<<endl;
    cin>> Surname>>Name>>FatherName;
    int ID = data.Is_in_Set(make_shared<Student>(Surname, Name, FatherName, "", 0, 0));
    if (ID)
    {
      cout << "Access permitted! Id is "<< ID<<endl;
    }
    else
    {
      cout << "Access BAAAAAAAAAAAAAAAAAAAAAAN!!!!!!!!!!!! THIS IS WRONG "
              "PERSON!!!!!!!!!!!!!! HE IS IMPOSTOR!!!!"<< endl;
    }

  }
  return 0;
}
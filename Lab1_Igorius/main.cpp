#include <iostream>
#include "Data_list.h"
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;




class Person
{
 public:
  string Name;
  double Score;

  Person(string name, double score)
  {
    this->Name = name;
    this->Score = score;
  }
};

int main(){
  string title = "C:\\Users\\Xiaomi\\untitled27\\L1_ANSI (2).txt";
  Data_list data(title);
  data.Parse();
  data.Filter_Course();
  data.Sort_by_Surname();
  data.Vivod();

  return 0;
}
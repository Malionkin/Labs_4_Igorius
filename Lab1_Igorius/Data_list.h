#ifndef UNTITLED27__DATA_LIST_H_
#define UNTITLED27__DATA_LIST_H_
using namespace std;
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <regex>
class Data_list{
 public:
  Data_list(const string& title);
  void Parse();
  void Vivod();
  void Filter_Course();
  void Sort_by_Surname();
 private:
  vector<shared_ptr<Student>> finish_data;
  vector<string> start_data;
  string Name;
  void Read();

};

#endif

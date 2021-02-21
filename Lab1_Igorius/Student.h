#ifndef UNTITLED27__STUDENT_H_
#define UNTITLED27__STUDENT_H_
#include <string>
using namespace std;

class Data_list;
class Student
{
 public:
  friend Data_list;
  friend bool operator<(const Student& stud1, const Student& stud2);
  friend ostream& operator<<(ostream& out, const Student*);
  Student(string Surname, string Name, string FatherName, string Status, int Course, int ID );
 private:
  string Surname;
  string Name;
  string FatherName;
  string Status;
  int Course;
  int ID;
};
#endif

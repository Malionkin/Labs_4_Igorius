#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string Surname, string Name, string FatherName, string Status, int Course, int ID)
{
  this->Name = Name;
  this->FatherName = FatherName;
  this->Surname = Surname;
  this->Course = Course;
  this->ID = ID;
  this->Status = Status;
}
ostream& operator<<(ostream& out, const Student* stud)
{
  out<<stud->Surname <<" "<<stud->Name<<" "<<stud->FatherName<<" "<<stud->Status<<" "<<stud->Course<<" kursa "<<stud->ID;
  return out;
}
bool operator<(const Student& stud1, const Student& stud2)
{
  if(stud1.Surname!=stud2.Surname)
  {
  return stud1.Surname<stud2.Surname;
  }
  if(stud1.Name!=stud2.Name)
  {
    return stud1.Name<stud2.Name;
  }
  return stud1.FatherName<stud2.FatherName;
}


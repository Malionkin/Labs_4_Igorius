#include "Data_list.h"
using namespace  std;
Data_list::Data_list(const string& title)
{
  this->Name = title;
  Read();
}
void Data_list::Read()
{
  ifstream fin(Name);
  copy(istream_iterator<string>(fin), istream_iterator<string>(), inserter(start_data, start_data.end()));
}


void Data_list::Parse()
{

  regex Line_to_parse(R"(^(\D+)\d+(\D+)\d+(\D+)\d+(\D+)\d+(\d)\D+(kursa)\d+(\d{8})$)");
  for(int i = 0; i < start_data.size(); ++i)
  {
    string Surname;
    string Name;
    string FatherName;
    string Status;
    string Course;
    string ID;
    regex_replace(back_inserter(Surname), start_data[i].begin(),start_data[i].end(), Line_to_parse, "$1");
    regex_replace(back_inserter(Name), start_data[i].begin(),start_data[i].end(), Line_to_parse, "$2");
    regex_replace(back_inserter(FatherName), start_data[i].begin(),start_data[i].end(), Line_to_parse, "$3");
    regex_replace(back_inserter(Status), start_data[i].begin(),start_data[i].end(), Line_to_parse, "$4");
    regex_replace(back_inserter(Course), start_data[i].begin(),start_data[i].end(), Line_to_parse, "$5");
    regex_replace(back_inserter(ID), start_data[i].begin(),start_data[i].end(), Line_to_parse, "$7");
    finish_data.push_back(make_shared<Student>(Surname, Name,  FatherName,  Status,  stoi(Course),  stoi(ID) ));
  }
}

void Data_list::Vivod()
{
//  for (int i = 0; i < finish_data.size(); i++)
//  {
//    cout<< finish_data[i];
//  }
 copy(finish_data.begin(),finish_data.end(),ostream_iterator<shared_ptr<Student>>(cout, "\n"));
}

void Data_list::Filter_Course()
{
  cout<<"Please, enter the number of minimal passed course!"<<endl;
  int min;
  cin>>min;
  finish_data.erase(remove_if(finish_data.begin(), finish_data.end(),
                              [min](const shared_ptr<Student>& stud){return stud->Course<min && stud->Status == "student";}),
                    finish_data.end());
}

void Data_list::Sort_by_Surname()
{
  std::sort(finish_data.begin(), finish_data.end(),
            [](const shared_ptr<Student>& stud1, const shared_ptr<Student>& stud2)
            {return *stud1<*stud2;});
}
void Data_list::Vec_to_Set()
{
  for (int i = 0; i < finish_data.size(); i++)
  {
    uset_data.insert(finish_data[i]);
  }
}

int Data_list::Is_in_Set(const shared_ptr<Student>& stud)
{
  auto res = uset_data.find(stud);
  if (res == uset_data.end())
  {
    return 0;
  }
  else
  {
    return (*res)->ID;
  }
}
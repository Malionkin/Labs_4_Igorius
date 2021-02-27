#include <memory>
#include "Student.h"
#include "Hash.h"
int Hash::operator()(const std::shared_ptr<Student>& chel) const
{
  string FIO = chel->GetFIO();
  int result = 0;
  for (int i = 0; i < FIO.size();i++ )
  {
    result += FIO[i]+i;
  }
  return result;
    }

#ifndef UNTITLED27__HASH_H_
#define UNTITLED27__HASH_H_
#include "Student.h"
#include <memory>
class Hash
{
public:
  int operator()(const std::shared_ptr<Student>&) const;
};
#endif

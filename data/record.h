#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
#include "date.h" // using custom Date class
#include "data_structure.h"
using namespace std;

class Record
{
private:
  static int nextId;
  int id;
  int amount;
  Date date;
  string description;
  int type1;
  int type2;

  // function
  bool validateDate() { return date.isValid(); }
  bool validateAmount();

public:
  Record();
  Record(DataStructure &data);

  void setAmount(int amount) { this->amount = amount; }
  void setDate(string date) { this->date = Date(date); }
  void setDescription(string description) { this->description = description; }
  void setType1(int type1) { this->type1 = type1; }
  void setType2(int type2) { this->type2 = type2; }
  int getId() { return id; }
  void setId(int id) { this->id = id; }
  int getAmount() { return amount; }
  static int getNewId() { return nextId++; }
  static void setNextId(int id) { nextId = id; }
  string getDate() { return date.getDate(); }
  string getDescription() { return description; }
  int getType1() { return type1; }
  int getType2() { return type2; }
  virtual DataStructure getData();
  virtual bool isValid();
};

int Record::nextId = 1;
Record::Record()
{
  id = 0;
  amount = 0;
  date = Date("");
}

Record::Record(DataStructure &data)
{
  this->id = data.id;
  this->type1 = data.type1;
  this->type2 = data.type2;
  this->amount = data.amount;
  this->description = data.description;
  this->date = Date(data.date);
}

bool Record::isValid()
{
  if (!validateAmount())
  {
    return false;
  }
  if (!validateDate())
  {
    return false;
  }
  return true;
}

bool Record::validateAmount()
{
  if (amount < 0)
  {
    cout << "Amount cannot be less than 0" << endl;
    return false;
  }
  return true;
}

DataStructure Record::getData()
{
  DataStructure data;
  data.id = id;
  data.type1 = type1;
  data.type2 = type2;
  data.amount = amount;
  data.description = description;
  data.date = date.getDate();
  return data;
}

#endif
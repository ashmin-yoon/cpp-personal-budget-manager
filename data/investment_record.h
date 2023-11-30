#ifndef INVESTMENT_RECORD_H
#define INVESTMENT_RECORD_H
#include "record.h"

class InvestmentRecord : public Record
{
private:
  double interestRate;
  string category;

public:
  InvestmentRecord(DataStructure &data) : Record(data)
  {
    this->interestRate = data.interestRate;
    this->category = data.category;
  }

  double getInterestRate() { return interestRate; }
  string getCategory() { return category; }
  void setInterestRate(int interestRate) { this->interestRate = interestRate; }
  void setCategory(string category) { this->category = category; }

  virtual DataStructure getData()
  {
    DataStructure data = Record::getData();
    data.interestRate = interestRate;
    data.category = category;
    return data;
  }
};

#endif
#ifndef LOAN_RECORD_H
#define LOAN_RECORD_H
#include "record.h"

class LoanRecord : public Record
{
private:
  double interestRate;
  string borrower;
  int loanDuration; // years

  bool validateLoanDuration()
  {
    if (loanDuration < 0)
    {
      return false;
    }
    return true;
  }

public:
  LoanRecord(DataStructure &data) : Record(data)
  {
    this->interestRate = data.interestRate;
    this->borrower = data.borrower;
    this->loanDuration = data.duration;
  }

  double getInterestRate() { return interestRate; }
  string getBorrower() { return borrower; }
  int getLoanDuration() { return loanDuration; }
  void setInterestRate(double interestRate) { this->interestRate = interestRate; }
  void setBorrower(string borrower) { this->borrower = borrower; }
  void setLoanDuration(int loanDuration) { this->loanDuration = loanDuration; }

  virtual bool isValid()
  {
    if (!Record::isValid())
    {
      return false;
    }
    if (!validateLoanDuration())
    {
      return false;
    }
    return true;
  }

  virtual DataStructure getData()
  {
    DataStructure data = Record::getData();
    data.interestRate = interestRate;
    data.borrower = borrower;
    data.duration = loanDuration;
    return data;
  }
};

#endif
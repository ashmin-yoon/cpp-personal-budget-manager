#ifndef RECORD_MANAGER_H
#define RECORD_MANAGER_H

#include <iostream>
#include "record.h"
#include "loan_record.h"
#include "investment_record.h"
#include "string"
#include "data_converter.h"
#include "data_structure.h"
#include "../types/record_types.h"
using namespace std;

class RecordCreator
{
private:
  DataConverter converter;

public:
  Record *createRecordFromData(DataStructure &data); // Make appropriate records.
};

// Make appropriate records from the content.
Record *RecordCreator::createRecordFromData(DataStructure &data)
{
  if (data.type1 == INCOME)
  {
    if (data.type2 == EARNED_INCOME)
    {
      return new Record(data);
    }
    else if (data.type2 == LOAN)
    {
      return new LoanRecord(data);
    }
  }
  if (data.type1 == EXPENSE)
  {
    if (data.type2 == REGULAR_EXPENSE)
    {
      return new Record(data);
    }
    else if (data.type2 == INVESTMENT)
    {
      return new InvestmentRecord(data);
    }
  }
  return new Record();
}

#endif
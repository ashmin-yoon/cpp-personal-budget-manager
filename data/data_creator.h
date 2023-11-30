#ifndef DATA_CREATOR_H
#define DATA_CREATOR_H

#include <iostream>
#include <string>
#include "../types/record_types.h"
#include "data_structure.h"

class DataCreator
{
private:
  void getUserInputCommonData(DataStructure &data, string title = "");
  void createEarnedIncomeData(DataStructure &data);
  void createLoanRecordData(DataStructure &data);
  void createInvestmentRecordData(DataStructure &data);
  void createRegularExpenseData(DataStructure &data);

public:
  DataStructure createData(int type1, int type2);
};

DataStructure DataCreator::createData(int type1, int type2)
{
  DataStructure data;
  data.type1 = type1;
  data.type2 = type1;
  if (type1 == INCOME)
  {
    if (type2 == EARNED_INCOME)
    {
      createEarnedIncomeData(data);
    }
    else if (type2 == LOAN)
    {
      createLoanRecordData(data);
    }
  }
  if (type1 == EXPENSE)
  {
    if (type2 == REGULAR_EXPENSE)
    {
      createRegularExpenseData(data);
    }
    else if (type2 == INVESTMENT)
    {
      createInvestmentRecordData(data);
    }
  }
  return data;
}

void DataCreator::getUserInputCommonData(DataStructure &data, string title)
{
  cout << "Enter the " << title << " amount: ";
  cin >> data.amount;
  cout << "Enter the date (YYYY-MM-DD): ";
  cin >> data.date;
  cout << "Enter a brief description: ";
  cin.ignore();
  getline(cin, data.description);
}

void DataCreator::createEarnedIncomeData(DataStructure &data)
{
  getUserInputCommonData(data);
  data.type1 = static_cast<int>(INCOME);
  data.type2 = static_cast<int>(EARNED_INCOME);
}

void DataCreator::createLoanRecordData(DataStructure &data)
{
  getUserInputCommonData(data, "loan");
  cout << "Enter the interest rate (%): ";
  cin >> data.interestRate;
  cout << "Enter the borrower's name: ";
  cin.ignore();
  getline(cin, data.borrower);
  cout << "Enter the loan duration (years): ";
  cin >> data.duration;
  data.type1 = static_cast<int>(INCOME);
  data.type2 = static_cast<int>(LOAN);
}

void DataCreator::createInvestmentRecordData(DataStructure &data)
{
  getUserInputCommonData(data, "investment");
  cout << "Enter the annual interest rate (%): ";
  cin >> data.interestRate;
  cout << "Enter the investment category: ";
  cin >> data.category;
  data.type1 = static_cast<int>(EXPENSE);
  data.type2 = static_cast<int>(INVESTMENT);
}

void DataCreator::createRegularExpenseData(DataStructure &data)
{
  getUserInputCommonData(data);
  data.type1 = static_cast<int>(EXPENSE);
  data.type2 = static_cast<int>(REGULAR_EXPENSE);
}

#endif
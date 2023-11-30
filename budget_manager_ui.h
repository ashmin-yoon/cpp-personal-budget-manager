#ifndef BUDGET_MANAGER_UI_H
#define BUDGET_MANAGER_UI_H

#include "data/data_structure.h"
#include "types/record_types.h"
#include <cstdio>
using namespace std;

class BudgetManagerUI
{
private:
  string getTypeName(int type1, int type2)
  {
    string type;
    if (type1 == INCOME && type2 == EARNED_INCOME)
      type = "Earned Income";
    else if (type1 == INCOME && type2 == LOAN)
      type = "Loan";
    else if (type1 == EXPENSE && type2 == REGULAR_EXPENSE)
      type = "Expense";
    else if (type1 == EXPENSE && type2 == INVESTMENT)
      type = "Investment";
    return type;
  }

public:
  void viewData(DataStructure data)
  {
    string type = getTypeName(data.type1, data.type2);

    // default information output
    // id, type, amount, date, description
    printf("%5d, %s, $%d, %s, %s",
           data.id, type.c_str(), data.amount, data.date.c_str(), data.description.c_str());

    if (data.type1 == INCOME && data.type2 == LOAN)
    {
      // interest rate, borrower, duration(year)
      printf(", %.2f%%, %s, %d",
             data.interestRate, data.borrower.c_str(), data.duration);
    }
    if (data.type1 == EXPENSE && data.type2 == INVESTMENT)
    {
      // interest rate, category
      printf(", %.2f%%, %s", data.interestRate, data.category.c_str());
    }
    printf("\n");
  }

  void viewBudgetSummary(int income, int expense, int netBalance)
  {
    cout << "Total Income: $" << income << endl;
    cout << "Total Expense: $" << expense << endl;
    cout << "Net Balance: $" << netBalance << endl;
    cout << endl;
  }
};

#endif
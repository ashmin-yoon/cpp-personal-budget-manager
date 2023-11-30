#ifndef PERSONAL_BUDGET_MANAGER_UI_H
#define PERSONAL_BUDGET_MANAGER_UI_H

#include <iostream>
#include "types/menu_type.h"
#include "types/record_types.h"
using namespace std;

class PersonalBudgetManagerUI
{
private:
  void printMenuInputRangeMessage();
  void printRecordInput();
  void printEarnedIncomeInput();
  void showMenusSelection();
  void showRecordTypeSelection();
  void showIncomeTypeSelection();
  void showExpenseTypeSelection();

public:
  bool validateInputMenu(int menuInput);
  MenuType getUserInputMenu();
  RecordType getUserInputRecordType();
  IncomeType getUserInputIncomeType();
  ExpenseType getUserInputExpenseType();
  void printExitMessage();
  void viewAddRecordResult(int id);
  void viewDeleteResult(bool result);
  void viewUpdateResult(bool result);
  int getDeleteId();
  int getUpdateId();
};

void PersonalBudgetManagerUI::showMenusSelection()
{
  cout << "1. Add Record" << endl;
  cout << "2. View Budget Summary" << endl;
  cout << "3. View All Records" << endl;
  cout << "4. Update Record" << endl;
  cout << "5. Delete Record" << endl;
  cout << "6. Exit" << endl;
  cout << endl;
  cout << "Enter your choice: [User inputs a number]" << endl;
}

void PersonalBudgetManagerUI::showRecordTypeSelection()
{
  cout << "Select the type of record" << endl;
  cout << INCOME << ". Income" << endl;
  cout << EXPENSE << ". Expense" << endl;
  cout << endl;
  cout << "Enter your choice: [User inputs a number for record type]" << endl;
}

void PersonalBudgetManagerUI::showIncomeTypeSelection()
{
  cout << "Select the type of income" << endl;
  cout << EARNED_INCOME << ". Earned Income" << endl;
  cout << LOAN << ". Loan" << endl;
  cout << endl;
  cout << "Enter your choice: [User inputs a number for input type]" << endl;
}

void PersonalBudgetManagerUI::showExpenseTypeSelection()
{
  cout << "Select the type of expense" << endl;
  cout << REGULAR_EXPENSE << ". Regular Expense" << endl;
  cout << INVESTMENT << ". INVESTMENT" << endl;
  cout << endl;
  cout << "Enter your choice: [User inputs a number for input type]" << endl;
}

bool PersonalBudgetManagerUI::validateInputMenu(int menuInput)
{
  if (ADD_RECORD <= menuInput && menuInput <= EXIT)
  {
    return true;
  }
  return false;
}

MenuType PersonalBudgetManagerUI::getUserInputMenu()
{
  int userInput;
  bool isValid = false;
  showMenusSelection();

  while (!isValid)
  {
    cout << "Enter your choice: ";
    cin >> userInput;

    isValid = validateInputMenu(userInput);
    if (!isValid)
    {
      printMenuInputRangeMessage();
    }
  }

  return static_cast<MenuType>(userInput);
}

void PersonalBudgetManagerUI::printExitMessage()
{
  cout << "Thank you for using the Personal Budget Manager. "
       << "Goodbye!" << endl;
}

void PersonalBudgetManagerUI::printMenuInputRangeMessage()
{
  cout << "User input value must be between "
       << ADD_RECORD << " and "
       << EXIT << ".\n";
}

RecordType PersonalBudgetManagerUI::getUserInputRecordType()
{
  int userInput;
  showRecordTypeSelection();
  while (true)
  {
    cout << "Enter your choice: ";
    cin >> userInput;
    switch (userInput)
    {
    case INCOME:
      return INCOME;
    case EXPENSE:
      return EXPENSE;
    default:
      cout << "The input is not valid" << endl;
    }
  }
}

IncomeType PersonalBudgetManagerUI::getUserInputIncomeType()
{
  int userInput;
  showIncomeTypeSelection();
  while (true)
  {
    cout << "Enter your choice: ";
    cin >> userInput;
    switch (userInput)
    {
    case EARNED_INCOME:
      return EARNED_INCOME;
    case LOAN:
      return LOAN;
    default:
      cout << "The input is not valid" << endl;
    }
  }
}

ExpenseType PersonalBudgetManagerUI::getUserInputExpenseType()
{
  int userInput;
  showExpenseTypeSelection();
  while (true)
  {
    cout << "Enter your choice: ";
    cin >> userInput;
    switch (userInput)
    {
    case REGULAR_EXPENSE:
      return REGULAR_EXPENSE;
    case INVESTMENT:
      return INVESTMENT;
    default:
      cout << "The input is not valid" << endl;
    }
  }
}

void PersonalBudgetManagerUI::viewAddRecordResult(int id)
{
  if (id != -1)
  {
    cout << "Record added Successfully!" << endl;
    cout << "Record ID: " << id << endl;
    cout << endl;
    return;
  }
  cout << "Record save failed!" << endl;
  cout << endl;
}

int PersonalBudgetManagerUI::getDeleteId()
{
  int deleteId = 0;
  cout << "Enter the record ID to delete: ";
  cin >> deleteId;
  return deleteId;
}

void PersonalBudgetManagerUI::viewDeleteResult(bool result)
{
  if (result)
  {
    cout << "Record deleted successfully! " << endl;
    cout << endl;
    return;
  }
  cout << "Record deletion failed" << endl;
  cout << endl;
}

int PersonalBudgetManagerUI::getUpdateId()
{
  int id;
  cout << "Enter the record ID to update: ";
  cin >> id;
  return id;
}

void PersonalBudgetManagerUI::viewUpdateResult(bool result)
{
  if (result)
  {
    cout << "Record updateed successfully! " << endl;
    cout << endl;
    return;
  }
  cout << "Record renewal failed" << endl;
  cout << endl;
}

#endif
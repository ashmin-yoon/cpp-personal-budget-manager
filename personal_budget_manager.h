#ifndef PERSONAL_BUDGET_MANAGER_H
#define PERSONAL_BUDGET_MANAGER_H
#include "personal_budget_manager_ui.h"
#include "budget_manager.h"
#include "types/menu_type.h"
#include "types/record_types.h"
#include "data/data_creator.h"
using namespace std;

class PersonalBudgetManager
{
private:
  PersonalBudgetManagerUI ui;
  BudgetManager budgetManager;
  DataCreator dataCreator;

  MenuType getUserInputMenu() { return ui.getUserInputMenu(); }
  void selectMenu(MenuType menuType);

  // function
  void addRecord();
  void viewBudgetSummary();
  void viewAllRecords();
  void updateRecord();
  void deleteRecord();
  void exitProgram();

  DataStructure makeData();

public:
  PersonalBudgetManager() {}
  void run(); // run a personal budget manager program
};

void PersonalBudgetManager::run()
{
  while (!budgetManager.isExit())
  {
    selectMenu(getUserInputMenu());
  }
}

void PersonalBudgetManager::selectMenu(MenuType menuType)
{
  switch (static_cast<int>(menuType))
  {
  case ADD_RECORD:
    addRecord();
    break;
  case VIEW_BUDGET_SUMMARY:
    viewBudgetSummary();
    break;
  case VIEW_ALL_RECORDS:
    viewAllRecords();
    break;
  case UPDATE_RECORD:
    updateRecord();
    break;
  case DELETE_RECORD:
    deleteRecord();
    break;
  case EXIT:
    exitProgram();
    break;
  }
  cout << endl;
}

void PersonalBudgetManager::addRecord()
{
  DataStructure data = makeData();
  int id = budgetManager.addRecord(data);
  ui.viewAddRecordResult(id);
}

void PersonalBudgetManager::viewBudgetSummary()
{
  budgetManager.viewBudgetSummary();
}

void PersonalBudgetManager::viewAllRecords()
{
  budgetManager.viewAllRecords();
}

void PersonalBudgetManager::updateRecord()
{
  int id = ui.getUpdateId();
  DataStructure updatedData = makeData();
  bool result = budgetManager.updateRecord(id, updatedData);
  ui.viewUpdateResult(result);
}

void PersonalBudgetManager::deleteRecord()
{
  int deleteId = ui.getDeleteId();
  bool result = budgetManager.deleteRecord(deleteId);
  ui.viewDeleteResult(result);
}

void PersonalBudgetManager::exitProgram()
{
  ui.printExitMessage();
  budgetManager.exit();
}

DataStructure PersonalBudgetManager::makeData()
{
  RecordType recordType = ui.getUserInputRecordType();
  int type2;

  if (recordType == INCOME)
  {
    type2 = ui.getUserInputIncomeType();
  }
  if (recordType == EXPENSE)
  {
    type2 = ui.getUserInputExpenseType();
  }

  return dataCreator.createData(recordType, type2);
}

#endif
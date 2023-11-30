#ifndef BUDGET_MANAGER_H
#define BUDGET_MANAGER_H

#include <iostream>
#include "files/file_manager.h"
#include "data/record_creator.h"
#include "data/data_converter.h"
#include "budget_manager_ui.h"
using namespace std;

const int NOT_FOUND = -1;

class BudgetManager
{
private:
  FileManager *fileManager;
  vector<Record *> records;
  RecordCreator recordCreator;
  DataConverter converter;
  BudgetManagerUI ui;
  bool exitFlag;

  void loadData();                 // Used when a constructor is called
  void saveData();                 // Used when data changes (additions, modifications,and erases) occur.
  int findIndexById(int recordId); // if the ID is found, return the corresponding index
                                   // and return -1 if not.

public:
  BudgetManager()
  {
    fileManager = new FileManager("my_data.txt");
    exitFlag = false;

    loadData();
  }
  ~BudgetManager() { delete fileManager; }
  int addRecord(DataStructure &data); // return id, if record addition failed return -1
  void viewBudgetSummary();
  void viewAllRecords();
  bool updateRecord(int id, DataStructure &data);
  bool deleteRecord(int id);
  bool isExit() { return exitFlag; }
  void exit() { exitFlag = true; }
};

int BudgetManager::addRecord(DataStructure &data)
{
  Record *record = recordCreator.createRecordFromData(data);
  if (!record->isValid())
  {
    return -1;
  }
  record->setId(Record::getNewId());
  records.push_back(record);
  saveData();
  return record->getId();
}

void BudgetManager::viewBudgetSummary()
{
  int totalIncome = 0;
  int totalExpense = 0;
  for (int i = 0; i < records.size(); i++)
  {
    int type = records[i]->getType1();
    int amount = records[i]->getAmount();
    if (type == INCOME)
    {
      totalIncome += amount;
    }
    else if (type == EXPENSE)
    {
      totalExpense += amount;
    }
  }
  int netBalance = totalIncome - totalExpense;
  ui.viewBudgetSummary(totalIncome, totalExpense, netBalance);
}

void BudgetManager::viewAllRecords()
{
  cout << "==================== View All Records ====================\n";
  for (int i = 0; i < records.size(); i++)
  {
    ui.viewData(records[i]->getData());
  }
  cout << "\n";
}

bool BudgetManager::updateRecord(int id, DataStructure &data)
{
  int index = findIndexById(id);
  if (index == NOT_FOUND)
  {
    return false;
  }

  Record *findRecord = records[index];
  Record *newRecord = recordCreator.createRecordFromData(data);
  newRecord->setId(findRecord->getId());
  if (!newRecord->isValid())
  {
    return false;
  }
  records[index] = newRecord;
  saveData();
  return true;
}

bool BudgetManager::deleteRecord(int deleteId)
{
  int index = findIndexById(deleteId);
  if (index == NOT_FOUND) // Delete Failed
  {
    return false;
  }

  // Delete Successful
  delete records[index]; // free memory
  records.erase(records.begin() + index);
  saveData();
  return true;
}

// Used when a constructor is called
void BudgetManager::loadData()
{
  vector<string> contents = fileManager->readContents();
  int lastId = 0;
  for (int i = 0; i < contents.size(); i++)
  {
    DataStructure data = converter.convertSaveFormatToData(contents[i]);
    records.push_back(recordCreator.createRecordFromData(data));
    lastId = max(lastId, data.id);
  }

  Record::setNextId(lastId + 1);
}

// Used when data changes
// (additions, modifications,and erases) occur.
void BudgetManager::saveData()
{
  vector<string> temps;
  for (int i = 0; i < records.size(); i++)
  {
    string content = converter.convertToSaveFormat(records[i]->getData());
    temps.push_back(content);
  }
  fileManager->saveContents(temps);
}

// if the ID is found, return the corresponding index
// and return -1 if not.
int BudgetManager::findIndexById(int recordId)
{
  for (int index = 0; index < records.size(); index++)
  {
    if (records[index]->getId() == recordId)
    {
      return index;
    }
  }
  return NOT_FOUND;
}
#endif
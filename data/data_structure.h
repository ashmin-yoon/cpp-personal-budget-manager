#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <vector>
#include <string>
using namespace std;

struct DataStructure
{
  int id;
  int type1;
  int type2;
  int amount;
  string date;
  string description;
  // addition item
  int duration;
  double interestRate;
  string category;
  string borrower;

  DataStructure()
  {
    id = 0;
    type1 = 0;
    type2 = 0;
    amount = 0;
    date = "";
    description = "";
    duration = 0;
    interestRate = 0;
    category = "";
    borrower = "";
  }
  string toString()
  {
    string output = "";
    output += "id: " + to_string(id) + "\n";
    output += "type1: " + to_string(type1) + "\n";
    output += "type2: " + to_string(type2) + "\n";
    output += "amount: " + to_string(amount) + "\n";
    output += "date: " + date + "\n";
    output += "description: " + description + "\n";
    output += "duration: " + to_string(duration) + "\n";
    output += "interestRate: " + to_string(interestRate) + "\n";
    output += "category: " + category + "\n";
    output += "borrower: " + borrower + "\n";
    return output;
  }
};

enum DataStructureIndex
{
  ID = 0,
  TYPE1 = 1,
  TYPE2 = 2,
  AMOUNT = 3,
  DATE = 4,
  DESCRIPTION = 5,
  // addition - common (loan, investment)
  INTEREST_RATE = 6,

  // addition
  CATEGORY = 7, // investment
  BORROWER = 7, // loan
  DURATION = 8,
};

#endif
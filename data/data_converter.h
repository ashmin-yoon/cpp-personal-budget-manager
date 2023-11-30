#ifndef DATA_CONVERTER_H
#define DATA_CONVERTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../types/record_types.h"
#include "data_structure.h"
using namespace std;

class DataConverter
{
public:
  vector<string> separateStringByComma(string string);
  string convertToSaveFormat(DataStructure data);
  string concatenateStringWithComma(vector<string> &strings);
  DataStructure convertSaveFormatToData(string saveFormat);
};

vector<string> DataConverter::separateStringByComma(string content)
{
  istringstream csvStream(content);
  vector<string> csvColumn;
  string csvElement;

  while (getline(csvStream, csvElement, ','))
  {
    csvColumn.push_back(csvElement);
  }
  return csvColumn;
}

string DataConverter::convertToSaveFormat(DataStructure data)
{
  vector<string> strings;
  // set common information
  strings.push_back(to_string(data.id));
  strings.push_back(to_string(data.type1));
  strings.push_back(to_string(data.type2));
  strings.push_back(to_string(data.amount));
  strings.push_back(data.date);
  strings.push_back(data.description);

  // add necessary information
  if (data.type1 == INCOME && data.type2 == LOAN)
  {
    strings.push_back(to_string(data.interestRate));
    strings.push_back(data.borrower);
    strings.push_back(to_string(data.duration));
  }
  if (data.type1 == EXPENSE && data.type2 == INVESTMENT)
  {
    strings.push_back(to_string(data.interestRate));
    strings.push_back(data.category);
  }

  return concatenateStringWithComma(strings);
}

string DataConverter::concatenateStringWithComma(vector<string> &strings)
{
  string result = "";
  if (strings.size() > 0)
  {
    result = strings[0];
  }
  for (int i = 1; i < strings.size(); i++)
  {
    result += ",";
    result += strings[i];
  }
  return result;
}

DataStructure DataConverter::convertSaveFormatToData(string saveFormat)
{
  vector<string> columns = separateStringByComma(saveFormat);
  DataStructure data;
  data.id = stoi(columns[ID]);
  data.type1 = stoi(columns[TYPE1]);
  data.type2 = stoi(columns[TYPE2]);
  data.amount = stoi(columns[AMOUNT]);
  data.date = columns[DATE];
  data.description = columns[DESCRIPTION];

  // additional necessary information
  if (data.type1 == INCOME && data.type2 == LOAN)
  {
    data.interestRate = stod(columns[INTEREST_RATE]);
    data.borrower = columns[BORROWER];
    data.duration = stoi(columns[DURATION]);
  }
  if (data.type1 == EXPENSE && data.type2 == INVESTMENT)
  {
    data.interestRate = stod(columns[INTEREST_RATE]);
    data.category = columns[CATEGORY];
  }
  return data;
}

#endif
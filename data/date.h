#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
using namespace std;

// General days of months
const int days[13] = {
    0,
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31};

// Date string format
// YYYY-MM-DD
class Date
{
private:
  string date;
  int year;
  int month;
  int day;

  int parseYear(string date);
  int parseMonth(string date);
  int parseDay(string date);
  bool validate();
  bool validateYear(); // year range from 1900 to 2100
  bool validateMonthAndDay();
  bool isCharNumber(char ch);

public:
  Date()
  {
    date = "";
    year = -1;
    month = -1;
    day = -1;
  }
  Date(string date)
  {
    year = parseYear(date);
    month = parseMonth(date);
    day = parseDay(date);
    this->date = date;
  }
  bool isValid() { return validate(); }
  string getDate() { return date; }
};

bool Date::validate()
{
  // YYYY-MM-DD
  if (date[4] != '-' || date[7] != '-')
  {
    return false;
  }
  if (!validateYear())
  {
    return false;
  }
  if (!validateMonthAndDay())
  {
    return false;
  }
  return true;
}

int Date::parseYear(string date)
{
  // format: YYYY-MM-DD
  // index:  0123456789
  int ret = 0;
  for (int i = 0; i < 4; i++)
  {
    char ch = date[i];
    if (!isCharNumber(ch))
    {
      return -1;
    }
    ret *= 10;
    ret += ch - '0';
  }
  return ret;
}

int Date::parseMonth(string date)
{
  // format: YYYY-MM-DD
  // index:  0123456789
  int ret = 0;
  if (!isCharNumber(date[5]) || !isCharNumber(date[6]))
  {
    return -1;
  }
  ret = (date[5] - '0') * 10 + (date[6] - '0');
  return ret;
}

int Date::parseDay(string date)
{
  // format: YYYY-MM-DD
  // index:  0123456789
  int ret = 0;
  if (!isCharNumber(date[8]) || !isCharNumber(date[9]))
  {
    return -1;
  }
  ret = (date[8] - '0') * 10 + (date[9] - '0');
  return ret;
}

bool Date::isCharNumber(char ch)
{
  if ('0' <= ch && ch <= '9')
  {
    return true;
  }
  return false;
}
#endif

// year range from 1900 to 2100
bool Date::validateYear()
{
  if (year < 1900 || year >= 2100)
  {
    return false;
  }
  return true;
}

bool Date::validateMonthAndDay()
{
  if (month < 1 || month > 12)
  {
    return false;
  }
  if (day < 1 || day > days[month])
  {
    return false;
  }
  return true;
}
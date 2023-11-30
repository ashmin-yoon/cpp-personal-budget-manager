#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class FileManager
{
private:
  string fileName;
  ifstream readFile;
  ofstream saveFile;

public:
  FileManager(string fileName = "default_file.txt");
  void saveContents(vector<string> contents);
  vector<string> readContents();
};

FileManager::FileManager(string fileName)
{
  this->fileName = fileName;
}

void FileManager::saveContents(vector<string> contents)
{
  saveFile.open(fileName);
  if (!saveFile)
  {
    return;
  }

  for (int i = 0; i < contents.size(); i++)
  {
    saveFile << contents[i] << "\n";
  }

  saveFile.close();
}

vector<string> FileManager::readContents()
{
  vector<string> contents;
  string content;

  readFile.open(fileName);
  if (!readFile)
  {
    return contents;
  }

  while (getline(readFile, content))
  {
    contents.push_back(content);
  }

  readFile.close();
  return contents;
}

#endif
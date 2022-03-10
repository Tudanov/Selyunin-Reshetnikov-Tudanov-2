#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void DataInitialization();
void DataEntry();
void DataReading();
void Print();
bool DataCleaning();
void DataChange();
void Copy();
int AmountOfData();
void DeleteData();
void AddData();
void SaveData(string fileName); 

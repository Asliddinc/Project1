#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;
extern void reg();
extern bool login(bool a);
extern void regadmin();
extern bool loginadmin(bool b);
extern int check(int a);
extern void readtable();
extern void buy();
extern void showticket();
extern void changeadmin();
extern void changeuser();
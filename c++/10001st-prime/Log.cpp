#include <iostream>
#include <unordered_map>
#include "HeaderFunctions.h"
using namespace std;

void InitLog() {
    Log("My Loggggggggg");
}

void Log(const char* message)
{
    cout << message << endl;
}
// ------------------------------------------------------ //
// Perception Learning Algorithm for ECE548 Project 1 # 8
// Code written by Lia Murphy, Julio, Khaled
// on 9/15/2021
// ------------------------------------------------------ //

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

#include "model.h"

using namespace std;

struct Example
{
    int id;
    int age;
    int deliveryNum;
    int deliveryType;
    int blood;
    int heart;
    int csection;
};

vector<Example> ReadFile(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<Example> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
    {
        Example e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.id = stoi(token);

        getline(iss, token, ',');
        e.age = stoi(token);

        getline(iss, token, ',');
        e.deliveryNum = stoi(token);

        getline(iss, token, ',');
        e.deliveryType = stoi(token);

        getline(iss, token, ',');
        e.blood = stoi(token);

        getline(iss, token, ',');
        e.heart = stoi(token);

        getline(iss, token, ',');
        e.csection = stoi(token);

        v.push_back(e);
    }
    return v;
}

int main()
{
    string path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.csv";

    vector<Example> v;

    v = ReadFile(path);

    PLA model;

    for (int i = 0; i < v.size(); i++)
        cout << v[i].id << ' ' << v[i].age << ' ' << v[i].deliveryNum << ' ' << v[i].deliveryType << ' ' << v[i].blood << ' '
        << v[i].heart << ' ' << v[i].csection << '\n';
}

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

vector<int> readFile(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    //vector<Example> v;
    vector<int> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
    {
        Example e;
        int i;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.id = stoi(token);


        getline(iss, token, ',');
        e.age = stoi(token);
        i = stoi(token);

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

        v.push_back(i);
    }
    return v;
}

int main()
{
    string path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.csv";

    vector<int> v;

    vector<int> train;
    vector<int> test;

    for (int i = 0; i < v.size() + 1; i++)
    {
        if (i < v.size() / 2)
            train.push_back(v[i]);
        else
            test.push_back(v[i]);
    }

    v = readFile(path);

    PLA model;

    model.loadData(train, test);

    model.runModel(10, 0.1);

    //for (int i = 0; i < v.size(); i++)
    //    cout << v[i].id << ' ' << v[i].age << ' ' << v[i].deliveryNum << ' ' << v[i].deliveryType << ' ' << v[i].blood << ' '
    //    << v[i].heart << ' ' << v[i].csection << '\n';
}

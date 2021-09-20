// ------------------------------------------------------ //
// Perception Learning Algorithm for ECE548 Project 1 # 8
// Code written by Lia Murphy, Julio, Khaled
// on 9/18/2021
// ------------------------------------------------------ //

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class DataRead
{
    // structure definitions
    struct csection
    {
        int id;
        int age;
        int deliveryNum;
        int deliveryType;
        int blood;
        int heart;
        int csection;
    };
    
    struct bankdone
    {
        double variance, skewness, curtosis, entropy;
        int class;
    }

protected:


public:
    DataRead(); // constructor

    template <typename T>
    vector<T> readFile(string path)
    {
        ifstream inputFile(path);
        if (!inputFile.is_open())
        {
            cout << "failed to open file\n";
            exit(1);
        }

        vector<T> v;

        string out;
        string str;

        getline(inputFile, str); // skip first line

        while (getline(inputFile, str))
        {
            if (typeid(T)::name == "csection")
            {
                csection e;
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
        }
        return v;
    }
    
};


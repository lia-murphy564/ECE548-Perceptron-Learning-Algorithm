#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class data
{
protected:
    struct caesarian
    {
        int id;
        int age;
        int deliveryNum;
        int deliveryType;
        int blood;
        int heart;
        int csection;
    };

    struct person
    {
        int age;
        int sex;
    };

public:

    vector<caesarian> ReadFile(string path)
    {
        ifstream inputFile(path);
        if (!inputFile.is_open())
        {
            cout << "failed to open file\n";
            exit(1);
        }

        vector<caesarian> v;

        string out;
        string str;

        getline(inputFile, str); // skip first line

        while (getline(inputFile, str))
        {
            caesarian e;
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

    vector<person> ReadFile(string path)
    {
        ifstream inputFile(path);
        if (!inputFile.is_open())
        {
            cout << "failed to open file\n";
            exit(1);
        }

        vector<personn> v;

        string out;
        string str;

        getline(inputFile, str); // skip first line

        while (getline(inputFile, str))
        {
            caesarian e;
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


};


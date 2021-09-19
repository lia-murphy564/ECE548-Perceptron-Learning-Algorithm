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
#include "data.h"

using namespace std;

struct example
{
    int id;
    int age;
    int deliveryNum;
    int deliveryType;
    int blood;
    int heart;
    int csection;
};

vector<example> readFile(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    //vector<Example> v;
    vector<example> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
    {
        example e;
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

        v.push_back(e);
    }
    return v;
}

int main()
{

    DataRead dR;
    //dR.path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.csv";
    

    struct csection;

    v = dR.readFile(path)

    //v = readFile(path);

    //string path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.csv";
    string path = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/caesarian.csv";


    vector<example> v;
    //vector<int> x;
    vector<vector<int>> attributes; // input vector
    vector<int> y; // output vector

    v = readFile(path);


    // parse into input vector
    vector<int> temp = { 0,0,0,0,0 };
    for (int i = 0; i < v.size(); i++)
    {
        //x.push_back(v[i].age);
        temp[0] = v[i].age;
        temp[1] = v[i].deliveryNum;
        temp[2] = v[i].deliveryType;
        temp[3] = v[i].blood;
        temp[4] = v[i].heart;
        attributes.push_back(temp);
    }

    // parse into output vector
    for (int i = 0; i < v.size(); i++)
    {
        y.push_back(v[i].csection);
    }

    PLA model;

    model.loadData(attributes, y);

    int epochs = 10;
    double eta = 0.2;
    model.runModel(epochs, eta);

   // model.optimizeModel(1, 10, 0.05, 0.5);

    //for (int i = 1; i <= 20; i++)
    //{
    //    for (double j = 0.05; j < 0.2; j += 0.01)
    //    {
    //        cout << "epochs = " << i << "  eta = " << j << " ";
    //        model.runModel(i, j);
    //    }
    //}


    //model.runModel(25, 0.1);

    //for (int i = 0; i < v.size(); i++)
    //{
    //    cout << "Age: " << x[i] << " | Csection " << y[i] << "\n";
    //}

    //cout << "x size = " << x.size() << "\n";

    //for (int i = 0; i < v.size(); i++)
    //{
    //    if (i < v.size() / 2)
    //        train.push_back(v[i]);
    //    else
    //        test.push_back(v[i]);
    //}

    //cout << "v size = " << v.size() << "\n";
    //cout << "train size = " << train.size() << "\n";
    //cout << "test size = " << test.size() << "\n";




    //model.loadData(x., y);

    //cmodel.runModel(20, 0.1);

    //for (int i = 0; i < v.size(); i++)
    //    cout << v[i].id << ' ' << v[i].age << ' ' << v[i].deliveryNum << ' ' << v[i].deliveryType << ' ' << v[i].blood << ' '
    //    << v[i].heart << ' ' << v[i].csection << '\n';
}

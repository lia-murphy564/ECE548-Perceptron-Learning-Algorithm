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

struct banknote
{
    double variance, skewness, curtosis, entropy;
    int truth;
};

struct iris {
    double slength, swidth, plength, pwidth;
    string sFlower;
    int flower;
};

struct happyex
{
    int happy; // 0 = no, 1, yes
    int information;
    int cost;
    int quality;
    int trust;
    int maintenance;
    int social;
    string test;
};

struct balloon {
    int color, size, act, age, inflated;
};


vector<csection> readFileIntoCsection(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<csection> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
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
    return v;
}

vector<banknote> readFileIntoBanknote(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<banknote> v;

    string out;
    string str;

    while (getline(inputFile, str))
    {
        banknote e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.variance = stod(token);

        getline(iss, token, ',');
        e.skewness = stod(token);

        getline(iss, token, ',');
        e.curtosis = stod(token);

        getline(iss, token, ',');
        e.entropy = stod(token);

        getline(iss, token, ',');
        e.truth = stoi(token);

        v.push_back(e);
    }
    return v;
}

vector<iris> readFileIntoIris(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<iris> v;

    string out;
    string str;

    while (getline(inputFile, str))
    {
        iris e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.slength = stod(token);

        getline(iss, token, ',');
        e.swidth = stod(token);

        getline(iss, token, ',');
        e.plength = stod(token);

        getline(iss, token, ',');
        e.pwidth = stod(token);

        getline(iss, token, ',');
        e.sFlower = token;
        if (e.sFlower == "Iris-setosa")
            e.flower = 1;
        else
            e.flower = 0;

        v.push_back(e);
    }
    return v;
}

vector<happyex> readFileIntoHappy(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    //vector<Example> v;
    vector<happyex> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
    {
        happyex e;
        istringstream iss(str);
        string token;

        getline(iss, token, '4');
        //e.happy = stoi(token);

        getline(iss, token, ',');
        //e.information = stoi(token);

        getline(iss, token, ',');
        //e.cost = stoi(token);

        getline(iss, token, ',');
        //e.quality = stoi(token);

        getline(iss, token, ',');
        //e.trust = stoi(token);

        getline(iss, token, ',');
        //e.maintenance = stoi(token);

        getline(iss, token, ',');
       // e.social = stoi(token);

        v.push_back(e);
    }
    return v;
}

vector<balloon> readFileIntoBalloon(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<balloon> v;

    string out;
    string str;

    while (getline(inputFile, str))
    {
        balloon e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        if (token == "YELLOW")
            e.color = 0;
        else
            e.color = 1;

        getline(iss, token, ',');
        if (token == "SMALL")
            e.size = 0;
        else
            e.size = 1;

        getline(iss, token, ',');
        if (token == "DIP")
            e.act = 0;
        else
            e.act = 1;

        getline(iss, token, ',');
        if (token == "ADULT")
            e.age = 0;
        else
            e.age = 1;

        getline(iss, token, ',');
        if (token == "F")
            e.inflated = 0;
        else
            e.inflated = 1;

        v.push_back(e);
    }
    return v;
}

int main()
{
    string in;
    cout << "Input type of data (banknote, csection, iris, happy, balloon): ";
    cin >> in;
    //in = "iris";
    cout << "\n";

    string csectionPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/caesarian.csv";
    string bankNotePath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/data_banknote_authentication.txt";
    string irisPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/iris.data";
    string happyPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/SomervilleHappinessSurvey2015.csv";
    string balloonPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/balloons/adult+stretch.data";

    //string path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.cs";


    vector<vector<double>> attributes; // input vector
    vector<int> classifier; // output vector


    //vector<int> x;
    //vector<vector<int>> attributes; // input vector
    //vector<int> y; // output vector

    //cs = readFileIntoCsection(path);
    //bn = readFileIntoBanknote(path);
    
    
    if (in == "csection")
    {
        vector<csection> cs = readFileIntoCsection(csectionPath);
        vector<double> temp = { 0,0,0,0,0 };
        for (int i = 0; i < cs.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = cs[i].age;
            temp[1] = cs[i].deliveryNum;
            temp[2] = cs[i].deliveryType;
            temp[3] = cs[i].blood;
            temp[4] = cs[i].heart;
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(cs[i].csection);
        }
    }
    
    else if (in == "banknote")
    {
        vector<banknote> bn = readFileIntoBanknote(bankNotePath);
        vector<double> temp = { 0,0,0,0 };
        for (int i = 0; i < bn.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = bn[i].variance;
            temp[1] = bn[i].skewness;
            temp[2] = bn[i].curtosis;
            temp[3] = bn[i].entropy;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(bn[i].truth);
        }
    }

    else if (in == "iris")
    {
        vector<iris> ir = readFileIntoIris(irisPath);
        vector<double> temp = { 0,0,0,0 };
        for (int i = 0; i < ir.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = ir[i].slength;
            temp[1] = ir[i].swidth;
            temp[2] = ir[i].plength;
            temp[3] = ir[i].pwidth;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(ir[i].flower);
        }
    }

    else if (in == "happy")
    {
        vector<happyex> hp = readFileIntoHappy(happyPath);
        vector<double> temp = { 0,0,0,0,0,0 };
        for (int i = 0; i < hp.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = hp[i].information;
            temp[1] = hp[i].cost;
            temp[2] = hp[i].quality;
            temp[3] = hp[i].trust;
            temp[4] = hp[i].maintenance;
            temp[5] = hp[i].social;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(hp[i].happy);
        }
    }

    else if (in == "balloon")
    {
        vector<balloon> bp = readFileIntoBalloon(balloonPath);
        vector<double> temp = { 0,0,0,0 };
        for (int i = 0; i < bp.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = bp[i].color;
            temp[1] = bp[i].size;
            temp[2] = bp[i].act;
            temp[3] = bp[i].age;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(bp[i].inflated);
        }
    }
    else {
        cout << in << " is not a valid input\n";
        exit(0);
    }

    PLA model;

    model.loadData(attributes, classifier);

    int epochs = 100;
    double eta = 0.6;
    //model.runModel(epochs, eta);
    model.optimizeModel(1, 10, 0.1, 0.9, 0.01);



    // parse into input vector

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

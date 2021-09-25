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

struct ttt {
    int tl, tm, tr, ml, mm, mr, bl, bm, br, cla;
};

struct haberman {
    int age, year, num, sur;
};

struct house {
    int party, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen;
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

vector<ttt> readFileIntoTTT(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<ttt> v;

    string out;
    string str;

    while (getline(inputFile, str))
    {
        ttt e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        if (token == "x")
            e.tl = 1;
        else if (token == "o")
            e.tl = 2;
        else
            e.tl = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.tm = 1;
        else if (token == "o")
            e.tm = 2;
        else
            e.tm = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.tr = 1;
        else if (token == "o")
            e.tr = 2;
        else
            e.tr = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.ml = 1;
        else if (token == "o")
            e.ml = 2;
        else
            e.ml = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.mm = 1;
        else if (token == "o")
            e.mm = 2;
        else
            e.mm = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.mr = 1;
        else if (token == "o")
            e.mr = 2;
        else
            e.mr = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.bl = 1;
        else if (token == "o")
            e.bl = 2;
        else
            e.bl = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.bm = 1;
        else if (token == "o")
            e.bm = 2;
        else
            e.bm = 3;

        getline(iss, token, ',');
        if (token == "x")
            e.br = 1;
        else if (token == "o")
            e.br = 2;
        else
            e.br = 3;

        getline(iss, token, ',');
        if (token == "positive")
            e.cla = 1;
        else
            e.cla = 0;

        v.push_back(e);
    }
    return v;
}

vector<haberman> readFileIntoHaberman(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<haberman> v;

    string out;
    string str;

    while (getline(inputFile, str))
    {
        haberman e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.age = stoi(token);

        getline(iss, token, ',');
        e.year = stoi(token);

        getline(iss, token, ',');
        e.num = stoi(token);

        getline(iss, token, ',');
        e.sur = stoi(token);

        v.push_back(e);
    }
    return v;
}

vector<house> readFileIntoHouse(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<house> v;

    string out;
    string str;

    while (getline(inputFile, str))
    {
        house e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        if (token == "republican")
            e.party = 1;
        else
            e.party = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.one = 2;
        else if (token == "n")
            e.one = 1;
        else
            e.one = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.two = 2;
        else if (token == "n")
            e.three = 1;
        else
            e.three = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.four = 2;
        else if (token == "n")
            e.four = 1;
        else
            e.four = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.five = 2;
        else if (token == "n")
            e.five = 1;
        else
            e.five = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.six = 2;
        else if (token == "n")
            e.six = 1;
        else
            e.six = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.seven = 2;
        else if (token == "n")
            e.seven = 1;
        else
            e.seven = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.eight = 2;
        else if (token == "n")
            e.eight = 1;
        else
            e.eight = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.nine = 2;
        else if (token == "n")
            e.nine = 1;
        else
            e.nine = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.ten = 2;
        else if (token == "n")
            e.ten = 1;
        else
            e.ten = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.eleven = 2;
        else if (token == "n")
            e.eleven = 1;
        else
            e.eleven = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.twelve = 2;
        else if (token == "n")
            e.twelve = 1;
        else
            e.twelve = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.thirteen = 2;
        else if (token == "n")
            e.thirteen = 1;
        else
            e.thirteen = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.fourteen = 2;
        else if (token == "n")
            e.fourteen = 1;
        else
            e.fourteen = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.fifteen = 2;
        else if (token == "n")
            e.fifteen = 1;
        else
            e.fifteen = 0;

        getline(iss, token, ',');
        if (token == "y")
            e.sixteen = 2;
        else if (token == "n")
            e.sixteen = 1;
        else
            e.sixteen = 0;

        v.push_back(e);

    }
    return v;
}

int main()
{
    string in;
    cout << "Input type of data (banknote, csection, iris, happy, balloon, ttt, haberman, house): ";
    cin >> in;
    //in = "iris";
    cout << "\n";

    string csectionPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/caesarian.csv";
    string bankNotePath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/data_banknote_authentication.txt";
    string irisPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/iris.data";
    string happyPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/SomervilleHappinessSurvey2015.csv";
    string balloonPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/balloons/adult+stretch.data";
    string tttPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/tic-tac-toe.data";
    string habermanPath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/haberman.data";
    string housePath = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/house-votes-84.data";

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

    else if (in == "ttt")
    {
        vector<ttt> tt = readFileIntoTTT(tttPath);
        vector<double> temp = { 0,0,0,0,0,0,0,0,0 };
        for (int i = 0; i < tt.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = tt[i].tl;
            temp[1] = tt[i].tm;
            temp[2] = tt[i].tr;
            temp[3] = tt[i].ml;
            temp[4] = tt[i].mm;
            temp[5] = tt[i].mr;
            temp[6] = tt[i].bl;
            temp[7] = tt[i].bm;
            temp[8] = tt[i].br;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(tt[i].cla);
        }
    }

    else if (in == "haberman")
    {
        vector<haberman> hm = readFileIntoHaberman(habermanPath);
        vector<double> temp = { 0,0,0 };
        for (int i = 0; i < hm.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = hm[i].age;
            temp[1] = hm[i].year;
            temp[2] = hm[i].num;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(hm[i].sur);
        }
    }

    else if (in == "house")
    {
        vector<house> hs = readFileIntoHouse(housePath);
        vector<double> temp = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        for (int i = 0; i < hs.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = hs[i].one;
            temp[1] = hs[i].two;
            temp[2] = hs[i].three;
            temp[3] = hs[i].four;
            temp[4] = hs[i].five;
            temp[5] = hs[i].six;
            temp[6] = hs[i].seven;
            temp[7] = hs[i].eight;
            temp[8] = hs[i].nine;
            temp[9] = hs[i].ten;
            temp[10] = hs[i].eleven;
            temp[11] = hs[i].twelve;
            temp[12] = hs[i].thirteen;
            temp[13] = hs[i].fourteen;
            temp[14] = hs[i].fifteen;
            temp[15] = hs[i].sixteen;
            // need to change attributes to double
            attributes.push_back(temp);
            // parse into output vector
            classifier.push_back(hs[i].party);
        }
    }

    else {
        cout << in << " is not a valid input\n";
        exit(0);
    }

    PLA model;

    model.loadData(attributes, classifier);

    int epochs = 10;
    double eta = 0.6;
    //model.runModel(epochs, eta);
    model.optimizeModel(1, 10, 0.1, 0.9, 0.1);



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

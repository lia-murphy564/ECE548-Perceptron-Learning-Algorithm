#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

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

//template<typename T> 
//vector<example> ReadFile(string path)
//{
//    ifstream inputFile(path); // stream;
//    if (!inputFile.is_open())
//    {
//        cout << "failed to open file\n";
//        exit(1);
//    }
//
//    string line;
//
//    vector<example> v;
//
//    while (getline(inputFile, line))
//    {
//        if (!inputFile.eof())
//        {
//            example m(line);
//            v.push_back(m);
//        }
//    }
//    return v;
//}

//vector<string> 
void ReadFile(string path)
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

        //if (!inputFile.eof())
        //{

        //    line += " ";
        //    //cout << line;
        //    //out += line;
        //    v.push_back(line);
        //}
    }



    for (int i = 0; i < v.size(); i++)
        cout << v[i].id << ' ' << v[i].age << ' ' << v[i].deliveryNum << ' ' << v[i].deliveryType << ' ' << v[i].blood << ' '
        << v[i].heart << ' ' << v[i].csection << '\n';
}

int main()
{
    string path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.csv";

    ReadFile(path);

    //example e[80];

    //int i = 1;
    //while (true)
    //{
    //    inputFile >> e[i].id >> e[i].age >> e[i].deliveryNum >> e[i].deliveryType >> e[i].blood >> e[i].heart >> e[i].csection;
    //    cout << e[i].id << "\n";
    //    i++;
    //    if (inputFile.fail())
    //        break;
    //}
      
    
    //vector<example> examples = ReadFile(path);

}

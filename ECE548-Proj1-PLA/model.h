// ------------------------------------------------------ //
// Perception Learning Algorithm for ECE548 Project 1 # 8
// Code written by Lia Murphy, Julio, Khaled
// on 9/15/2021
// ------------------------------------------------------ //

#pragma once

#include <vector>

using namespace std;

class PLA
{
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

protected:

	double learningRate;
	int epochs;
	vector<double> weights;
	vector<int> y; // testing set
	vector<int> x; // training set
	vector<int> out; // classified data


public:
	PLA(); // constructor

	void loadData(vector<int> _x, vector<int> y);

	void setLearningRate(double n);

	void setEpochs(double e);

	void updateWeights();

	void runModel(double epochs, double learningRate);

	void classifyData();

	void optimizeModel(int epoch_min, int epoch_max, double eta_min, double eta_max);

	//int hypothesis(vector<int> vec);
	int sign(double x);

	int hypothesis(vector<int> train);
};


//{
//	train = _train;
//	test = _test;
//	cout << "Loading data...\n";
//}


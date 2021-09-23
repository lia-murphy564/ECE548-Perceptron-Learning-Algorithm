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

	};

protected:

	double learningRate;
	int epochs;
	vector<double> weights;

	vector<int> out; // classified data

	vector<int> y;
	vector<vector<int>> attributes;


public:
	PLA(); // constructor

	void loadData(vector<vector<int>> _x, vector<int> y);

	void setLearningRate(double n);

	void setEpochs(int e);

	void updateWeights();

	void runModel(int epochs, double learningRate);

	void classifyData();

	void classifyData();

	void optimizeModel(int epoch_min, int epoch_max, double eta_min, double eta_max);

	//int hypothesis(vector<int> vec);
	int sign(double x);

	int hypothesis(vector<int> train);

	void modifyWeights(vector<int> train, vector<int> test);

	void doTrain(vector<int> train, int target);

	void classify(vector<int> input);

	double DotProduct(vector<double> x, vector<int> y);
};


//{
//	train = _train;
//	test = _test;
//	cout << "Loading data...\n";
//}


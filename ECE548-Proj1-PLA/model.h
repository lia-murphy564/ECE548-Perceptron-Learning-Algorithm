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
	vector<int> y;
	vector<int> x;

public:
	PLA(); // constructor

	void loadData(vector<int> _x, vector<int> y);

	void setLearningRate(double n);

	void setEpochs(double e);

	void updateWeights();

	void runModel(double epochs, double learningRate);

	//int hypothesis(vector<int> vec);
	int sign(double x);

	int hypothesis(vector<int> train);

	void modifyWeights(vector<int> train, vector<int> test);

	void doTrain(vector<int> train, int target);

	void classify(vector<int> input);
};


//{
//	train = _train;
//	test = _test;
//	cout << "Loading data...\n";
//}


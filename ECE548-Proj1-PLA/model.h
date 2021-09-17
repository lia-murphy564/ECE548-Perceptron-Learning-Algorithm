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

protected:

	double learningRate;
	int epochs;
	vector<double> weights;
	vector<int> train;
	vector<int> test;

public:
	PLA(); // constructor

	template<typename T> void loadData(vector<T> _train, vector<T> _test);

	void setLearningRate(double n);

	void setEpochs(double e);

	void updateWeights();

	void runModel(double epochs, double learningRate);

	//int hypothesis(vector<int> vec);
	int sign(double x);

	int hypothesis(vector<int> train);

	void modifyWeights(vector<int> train, vector<int> test);

	void trainSet(vector<int> train, int target);
};

template<typename T>
inline void PLA::loadData(vector<T> _train, vector<T> _test)
{
	train = _train;
	test = _test;
	cout << "Loading data...\n";
}


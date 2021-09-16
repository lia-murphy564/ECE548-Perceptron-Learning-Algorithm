// ------------------------------------------------------ //
// Perception Learning Algorithm for ECE548 Project 1 # 8
// Code written by Lia Murphy, Julio, Khaled
// on 9/15/2021
// ------------------------------------------------------ //

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

#include "model.h"

using namespace std;

PLA::PLA() // constructor
{
	PLA::setLearningRate(0.1); // default learning rate to 0.1
}

void PLA::setLearningRate(double n)
{
	learningRate = n;
	//cout << "Set learning rate to " << n << "\n";
}

void PLA::setEpochs(double e)
{
	epochs = e;
	//cout << "Set epochs to " << e << "\n";
}

void PLA::updateWeights()
{
	cout << "UpdateWeights";
}

void PLA::runModel(double epochs, double learningRate)
{
	PLA::setEpochs(epochs);
	PLA::setLearningRate(learningRate);

	PLA::modifyWeights(train, test);

}

//template<typename T> void loadData(vector<T> _train, vector<T> _test)
//{
//	PLA::train = _train;
//	PLA::test = _test;
//}

int PLA::hypothesis(int x, double w)
{
	//double p = weights[0];
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	p += vec[i] * weights[i + 1];
	//}
	
	double p = x * w;
	double theta = 0.5;
	if (p > theta)
		return 1;
	else
		return -1;
}

void PLA::modifyWeights(vector<int> train, vector<int> test)
{
	for (int i = 0; i < train.size() + 1; i++)
		weights.push_back(0);

	for (int i = 0; i < epochs; i++)
	{
		cout << "Epoch: " << i << " | " << "Train:" << train[i] << " | ";
		cout << "Test: " << test[i] << " | ";
		cout << "Hypothesis: " << hypothesis(train[i], weights[i]) << " | ";

		for (int j = 0; j < train.size(); j++)
		{
			double x_i = learningRate * (test[j] - hypothesis(train[j], weights[j]));

			for (int k = 0; k < weights.size(); k++)
			{
				weights[k] += x_i * train[j];
			}
			weights[0] = x_i;
		}

		cout << "Weight = " << weights[i] << " | " "\n";
	}
}




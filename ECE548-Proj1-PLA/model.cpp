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

int PLA::sign(double x) //activation function
{
	//double p = weights[0];
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	p += vec[i] * weights[i + 1];
	//}
	
	//double p = x * w;
	//double theta = 0.5;
	if (x > 0)
		return 1;
	else
		return -1;
}

int PLA::hypothesis(vector<int> train)
{
	double w_s = 0; //weighted sum
	for (int i = 0; i < weights.size(); i++)
	{
		w_s += weights[i] * train[i];
	}
	return sign(w_s);
}

void PLA::trainSet(vector<int> train, int target)
{
	int h = PLA::hypothesis(train);
	int error = target - h;

	//for (int i = 0; i < weights.size(); i++)
	//{
	//	//weights[i] += error * train[i] * learningRate;
	//	//cout << weights[i] << "\n";
	//}
}

void PLA::modifyWeights(vector<int> train, vector<int> test)
{
	cout << "Initializing weights \n";
	for (int i = 0; i < train.size() + 1; i++)
	{
		weights.push_back(0);
	}

	trainSet(train, 1);


	// Iterate through epochs
	//for (int i = 0; i < epochs; i++)
	//{
	//	cout << "Epoch: " << i << " | " ;

	//	// Iterate through
	//}

	//for (int i = 0; i < epochs; i++)
	//{
	//	cout << "Epoch: " << i << " | " << "Train:" << train[i] << " | ";
	//	cout << "Test: " << test[i] << " | ";
	//	cout << "Hypothesis: " << hypothesis(train[i]) << " | ";

	//	/*for (int j = 0; j < train.size(); j++)
	//	{
	//		double x_i = learningRate * (test[j] - hypothesis(train[j]));

	//		for (int k = 0; k < test.size(); k++)
	//		{
	//			weights[k] += x_i * test[k];
	//		}
	//		weights[0] = x_i;
	//	}*/

	//	cout << "Weight = " << weights[i] << " | " "\n";
	//}
}




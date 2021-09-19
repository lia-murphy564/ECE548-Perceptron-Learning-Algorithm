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
#include <cstdlib>

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

void PLA::setEpochs(int e)
{
	epochs = e;
	//cout << "Set epochs to " << e << "\n";
}

double fRand(double fMin, double fMax) {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void PLA::updateWeights()
{


	for (int i = 0; i < attributes[0].size(); i++)
	{
		double rand = fRand(-1, 1);
		weights.push_back(rand);
		//cout << weights[i];
	}

	for (int i = 0; i < epochs; i++)
	{
		//cout << "\n\n" << "----- Epoch: " << i << " ----- " << "\n";
		//cout << "Example: " << train[i] << " | ";
		//cout << "Hypothesis: " << hypothesis(train) << " | ";

		for (int i = 0; i < attributes.size(); i++)
		{
			int h = hypothesis(attributes[i]);
			int error = y[i] - h;
			for (int j = 0; j < weights.size(); j++) {
				weights[j] += (error * learningRate) * attributes[i][j];
			}

			//weights[i] += error * train[i] * learningRate;
			//cout << i << "   Example: " << x[i];
			//cout << "   Hypothesis: " << h;
			//cout << "   Output: " << y[i];
			//cout << "   Weight: " << weights[i] << "\n";
		}
		for (int i = 0; i < weights.size(); i++) {
			cout << "Weights[" << i << "] = " << weights[i] << "\n";
		}
		cout << "\n";
	}

}

void PLA::runModel(int epochs, double learningRate)
{
	PLA::setEpochs(epochs);
	PLA::setLearningRate(learningRate);
	PLA::updateWeights();

	cout << "epochs = " << epochs << "\neta = " << learningRate << "\n";

	//PLA::modifyWeights(train, test);
	//PLA::doTrain(x, 1);

	//cout << "Initializing weights \n";



	//vector<int> h = PLA::hypothesis(x);

	//Iterate through epochs and calculate weights

	classifyData();

}

void PLA::classifyData() {
	vector<double> out;
	int amtCorrect = 0; // amount of correct values

	// multiply inputs by weights
	for (int i = 0; i < attributes.size(); i++)
	{
		int result = hypothesis(attributes[i]);
		if (result > 0)
			result = 1;
		else
			result = 0;

		if (result == y[i])
			amtCorrect += 1;

		//cout << "Guess: " << result << "  Real: " << y[i] << "\n";

		out.push_back(result);
	}

	double pctGuessed = 100 * (double)amtCorrect / attributes.size();
	cout << "Percent Guessed = " << pctGuessed << " % \n";
}

int PLA::sign(double x) //activation function
{
	if (x > 0)
		return 1;
	else
		return 0;
}

int PLA::hypothesis(vector<int> train) // weighted sum
{
	double b = 0;
	double w_s = DotProduct(weights, train) + b;
	//cout << "weighted sum = " << w_s;
	return sign(w_s);
}


void PLA::loadData(vector<vector<int>> _x, vector<int> _y)
{
	y = _y;
	attributes = _x;
	cout << "Loading data...\n";
}

double PLA::DotProduct(vector<double> x, vector<int> y) {
	double res = 0;
	for (int i = 0; i < x.size(); i++) {
		res += x[i] * (double)y[i];
	}
	return res;
}

void PLA::doTrain(vector<int> train, int target)
{
	
}



//void PLA::modifyWeights(vector<int> train, vector<int> test)
//{
//	cout << "Initializing weights \n";
//	//cout << train.size();
//	for (int i = 0; i < train.size() + 1; i++)
//	{
//		weights.push_back(0.1);
//		//cout << weights[i];
//	}
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





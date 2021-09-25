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
}

void PLA::setEpochs(int e)
{
	epochs = e;
}

double fRand(double fMin, double fMax) 
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
  
void PLA::updateWeights()
{
	// clear weights vector
	weights.clear();

	//int size = 2;

	// Init weights to random
	for (int i = 0; i < attributes[1].size(); i++)
	{
		double rand = fRand(-1, 1);
		weights.push_back(rand);
		//cout << weights[i];
	}

	// Iterate through epochs and calculate weights
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

// handler of all model functions
double PLA::runModel(int epochs, double learningRate)
{
	PLA::setEpochs(epochs);
	PLA::setLearningRate(learningRate);
	PLA::updateWeights();
	cout << "epochs = " << epochs << "\neta = " << learningRate << "\n";
	return PLA::classifyData();
}


double PLA::classifyData() {
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
	//cout << out.size();

	double pctGuessed = 100 * (double)amtCorrect / attributes.size();
	cout << "Percent Guessed = " << pctGuessed << " % \n";
	return pctGuessed;
}

void PLA::optimizeModel(int epoch_min, int epoch_max, double eta_min, double eta_max, double eta_interval)
{
	//PLA::runModel(1, 0.5); // base run to generate output vectors
	int amtCorrect = 0;
	double pctGuessed = 0.0;
	int epochs = 0;
	double eta = 0.0;

	// iterate through all epochs and learning rates
	// run the model at that point
	// calculate the accuracy and save best epoch and learning rate pair
	for (int i = epoch_min; i <= epoch_max; i++)
	{
		for (double j = eta_min; j <= eta_max; j += eta_interval)
		{
			//cout << "epochs = " << i << "  eta = " << j << " ";
			double _pctGuessed = PLA::runModel(i, j);
			if (_pctGuessed > pctGuessed)
			{
				pctGuessed = _pctGuessed;
				epochs = i;
				eta = j;
			}
		}
	}

	cout << "Model optimized at (epochs=" << epochs << ", eta=" << eta << ") \n";
	cout << "Percent Guessed = " << pctGuessed << " % \n";
}
*/
int PLA::sign(double x) //activation function
{
	if (x > 0)
		return 1;
	else
		return 0;
}

int PLA::hypothesis(vector<double> train) // weighted sum
{
	double b = 0;
	double w_s = DotProduct(weights, train) + b;
	//cout << "weighted sum = " << w_s;
	return sign(w_s);
}


//void PLA::loadData(vector<vector<int>> _x, vector<int> _y)
//{
//	y = _y;
//	attributes = _x;
//	cout << "Loading data...\n";
//}

void PLA::loadData(vector<vector<double>> _x, vector<int> _y)
{
	y = _y;
	attributes = _x;
	cout << "Loading data...\n";
}

double PLA::DotProduct(vector<double> x, vector<double> y) {
	double res = 0;
	for (int i = 0; i < x.size(); i++) {
		res += x[i] * y[i];
	}
	return res;
}



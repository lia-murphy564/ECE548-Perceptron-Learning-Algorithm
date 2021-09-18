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
	// Init weights to 0
	for (int i = 0; i < x.size() + 1; i++)
	{
		weights.push_back(0);
		//cout << weights[i];
	}

	//Iterate through epochs and calculate weights
	for (int i = 0; i < epochs; i++)
	{
		//cout << "\n\n" << "----- Epoch: " << i << " ----- " << "\n";
		//cout << "Example: " << train[i] << " | ";
		//cout << "Hypothesis: " << hypothesis(train) << " | ";

		for (int i = 0; i < x.size(); i++)
		{
			int h = hypothesis(x);
			int error = y[i] - h;

			weights[i] = learningRate * error * x[i];

			//weights[i] += error * train[i] * learningRate;
			//cout << i << "   Example: " << x[i];
			//cout << "   Hypothesis: " << h;
			//cout << "   Output: " << y[i];
			//cout << "   Weight: " << weights[i] << "\n";
		}
	}
}

void PLA::runModel(double epochs, double learningRate)
{
	PLA::setEpochs(epochs);
	PLA::setLearningRate(learningRate);
	PLA::updateWeights();

	cout << "epochs = " << epochs << "\neta = " << learningRate << "\n";

	PLA::classifyData();

	
}

void PLA::classifyData()
{
	int amtCorrect = 0; // amount of correct values

	// multiply inputs by weights
	for (int i = 0; i < x.size(); i++)
	{
		int result = x[i] * weights[i];
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

	double pctGuessed = 100 * amtCorrect / x.size();
	cout << "Percent Guessed = " << pctGuessed << " % \n";
}

void PLA::optimizeModel(int epoch_min, int epoch_max, double eta_min, double eta_max)
{
	//PLA::runModel(1, 0.5); // base run to generate output vectors

	int amtCorrect = 0;
	double pctGuessed = 0.0;
	int epochs = 0;
	double eta = 0.0;
	for (int i = epoch_min; i <= epoch_max; i++)
	{
	    for (double j = eta_min; j <= eta_max; j += 0.01)
	    {
	        //cout << "epochs = " << i << "  eta = " << j << " ";
	        runModel(i, j);
			for (int i = 0; i < out.size(); i++)
			{
				if (out[i] == y[i])
					amtCorrect += 1;
			}
			double _pctGuessed = 100 * amtCorrect / x.size();
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
	double w_s = 0; //weighted sum
	for (int i = 0; i < train.size(); i++)
	{
		w_s += weights[i] * train[i] + b;
	}
	//cout << "weighted sum = " << w_s;
	return sign(w_s);
}


void PLA::loadData(vector<int> _x, vector<int> _y)
{
	y = _y;
	x = _x;
	cout << "Loading data...\n";
}





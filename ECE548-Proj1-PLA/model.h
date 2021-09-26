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
	vector<vector<double>> attributes;

	vector<double> pctGuessedVec;


public:
	PLA(); // constructor

	void loadData(vector<vector<double>> _x, vector<int> y);

	void setLearningRate(double n);

	void setEpochs(int e);

	void updateWeights();

	double runModel(int epochs, double learningRate);

	double classifyData();

	void optimizeModel(int epoch_min, int epoch_max, double eta_min, double eta_max, double eta_interval);

	//int hypothesis(vector<int> vec);
	int sign(double x);

	int hypothesis(vector<double> train);

	double DotProduct(vector<double> x, vector<double> y);

	void outputPctVsEpochs(string path)
	{
		std::ofstream of;
		of.open(path);
		of << "Epochs, PctGuessed\n";
		for (int i = 0; i < epochs; i++)
		{
			of << i + 1 << ',' << pctGuessedVec[i] << endl;
		}
	}

	//void clearData()
	//{
	//	weights.clear();
	//	attributes.clear();
	//	y.clear();
	//	pctGuessedVec.clear();
	//}
};



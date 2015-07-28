
#ifndef ADABOOST_H
#define ADABOOST_H

#include "HaarFeatures.h"
#include "Feature.h"

#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <complex>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace cv;
using namespace std;

class AdaBoost
{
/*
public:
	AdaBoost(vector<Eventpoint> P, vector<Eventpoint> N, vector<HaarFeatures> F);
	AdaBoost();
	~AdaBoost();
	


	void Threasholdsetter();
	void NormalizeWeight();
	void InitializeWeights();
	vector<HaarFeatures> applyAdaBoost(int steps);
	double SumPositiveWeights();
	double SumNegativeWeights();
	void writeFeatures(vector<HaarFeatures>);
	void readinnegatives();
	void readinpositives();


	void printResultsWeakClass();
	void printStats();
	vector<Eventpoint> positive;
	vector<Eventpoint> negative;
	
	vector<double> weights;
	vector<HaarFeatures> haarfeatures;
	int totalimages;
	int* alphas;
*/
};

#endif
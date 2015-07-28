#ifndef CASCADE_H
#define CASCADE_H

#include "HaarFeatures.h"
#include "AdaBoost.h"
#include "Feature.h"

#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <utility>
#include <vector>

using namespace cv;
using namespace std;

class Cascade
{
	/*
public:
	Cascade(vector<Mat> P, vector<Mat> N,vector<HaarFeatures> F);
	~Cascade();


	vector< vector < HaarFeatures> > createCascade(double f, double d, double targetF);
	void evaluateOnTrainNegative(vector<Mat> N);
	void decraseThreshold(int ith, double minD);
	bool evaluate(Mat image);
	pair<double,double> evaluateOnTest();

	vector<int> levelThreshold;
	vector<Mat> positive;
	vector<Mat> negative;
	vector<HaarFeatures> haarfeatures;
	vector< vector < HaarFeatures> > cascaded;
	*/
};

#endif
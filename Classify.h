#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <fstream>
#include "IntegralImage.h"
#include "HaarFeaturesNew.h"
#ifndef CLASSIFY_H
#define CLASSIFY_H

using namespace cv;
using namespace std;

class Classify
{

public:
	Classify(vector < HaarFeatures> W);
	~Classify();
	int DisplayImg(Mat Img);

	vector < HaarFeatures> WeakClassifier;
	int stepper;
	int scale;



};

#endif
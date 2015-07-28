#include "Classify.h"
/*
Classify::Classify(vector < HaarFeatures> W){

	WeakClassifier = W;


}
Classify::~Classify(){


}

int Classify::DisplayImg(Mat Img){
	Mat resized;

	Size size(24,24);

	resize(Img,resized,size);
	double sum = 0;
	for (int i = 0; i < WeakClassifier.size(); i++){
		
		//cout << WeakClassifier[i].error << WeakClassifier[i].applyhaarfeatures(resized) << endl;
		//cerr << "Here" << endl;
		sum += (WeakClassifier[i].error * WeakClassifier[i].applyhaarfeatures(resized));
	}
	cout << sum << endl;
	//This Number here is only temp I did not have time to find the perfect number for here
	if (sum >= 850){
		return 1;
	}
	else 
		return 0;

}
*/
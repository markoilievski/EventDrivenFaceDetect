#include "AdaBoost.h"
/*
bool mysort(pair<int, pair<int, bool> > myFirst, pair<int, pair<int, bool> > mySecond)
{
	return(myFirst.second.first < mySecond.second.first); 

}
AdaBoost::AdaBoost(vector<Eventpoint> P, vector<Eventpoint> N, vector<Feature> F)
{
	positive = P;
	negative = N;
	weights.resize(P.size()+N.size()+100);
	haarfeatures = F;
	totalimages = positive.size() + negative.size();
	cout << "Positive set size " << P.size()  << " Negative set size " << N.size() << " Feature set size " << F.size() << endl; 
	

}
AdaBoost::AdaBoost()
{
	readinnegatives();
	readinpositives();
	weights.resize(300);
	
	haarfeatures.resize(100);
	totalimages = positive.size() + negative.size() - 1;

}
AdaBoost::~AdaBoost()
{
	

}

vector<HaarFeatures> AdaBoost::applyAdaBoost(int steps){
	//Do thing
	
	//srand(time(NULL));
	
	//cerr << "where" << endl;
	InitializeWeights();
	//cerr << "where" << endl;
	vector<HaarFeatures> returnFeatures;
	vector < vector < pair <int, pair <int,bool> > > > featureValue;
	

	for(int i = 0; i < haarfeatures.size(); i++){
		
		vector < pair <int, pair <int,bool> > > temp;
		for (int j = 0; j < positive.size(); j++){
			//int val = (rand() % 100) * 20;
			
			int val = haarfeatures[i].applyhaarfeaturesIntImage(positive[j]);
			//cout << "i:" << i << "j:" << j << "val" << val << endl;
			temp.push_back(make_pair(j,make_pair(val,true)));
		}
		for (int j = 0; j < negative.size(); j++){
			//int val = (rand() % 100) * 20;
			int val = haarfeatures[i].applyhaarfeaturesIntImage(negative[j]);
			//cout << val << endl;
			//cout << "i:" << i << "j:" << j << "val" << val << endl;
			temp.push_back(make_pair(j,make_pair(val, false)));
		}
		featureValue.push_back(temp);
		sort(featureValue[i].begin(),featureValue[i].end(),mysort);
		cout << "Finished the ith feature: " << i << endl;
	}
	cout << "Finished" << endl;

	for (int i = 0; i < steps; i++){
		NormalizeWeight();
		int bestFeature = -1, p = 0;
		float error = 1e9, treshold = 0.0;
		//cerr << "HERE" << endl;
		// This is selecting the best weak classifier
		for(int j = 0; j < haarfeatures.size(); j++){
			double totalpositive = SumPositiveWeights();
			double totalnegative = SumNegativeWeights();
			double currfirst = 0.0;
			double currsecond = 0.0;
			for (int k = 0; k < featureValue[j].size(); k++){
				//cout << "HERE2" << endl;
				int index = featureValue[j][k].first;
				int value = featureValue[j][k].second.first;
				double val1 = currfirst + (totalnegative - currsecond );
				double val2 = currsecond + (totalpositive - currfirst );
				//cout << val1 << ' ' << val2 << endl;
				double curErr = min( val1, val2 );

				if (featureValue[j][k].second.second == true){
				 	currfirst += weights[ index ];
				}
				else{
					currsecond += weights[positive.size()+index];
				}


				if (curErr < error) {
					if (k == 0){
					 treshold = featureValue[j][k].second.first;
					}
					else 
						{
					treshold = (featureValue[j][k-1].second.first + featureValue[j][k].second.first) / 2;
					}

					if (val1 < val2){
					p = -1;
					}
					else {
					p = 1;
					}

					error = curErr;
					bestFeature = j;
				}

			}


		}
		cout << error << endl;
		cout << bestFeature << endl;
		double beta = error / (1-error);
		double alpha = log ( 1 / beta);
		cout << alpha << ' ' << beta << endl;

		for (int k = 0; k < featureValue[ bestFeature ].size(); k++){
			//cout << "HERE3" << endl;
			int val = featureValue[bestFeature][k].second.first;
			int index = featureValue[bestFeature][k].first;
			bool correct = featureValue[bestFeature][k].second.second;

			if (correct == (p* val < p * treshold)){
				if (correct)
					weights[index] *= beta;
				else
					weights[index+positive.size()] *= beta;
			}
		}
		haarfeatures[bestFeature].threshold = treshold;
		haarfeatures[bestFeature].error = alpha;
		returnFeatures.push_back(haarfeatures[bestFeature]);
		cout << "Finished Step # " << i << " treshold is " << treshold << " and alpha is " << alpha << endl;

	}
	return returnFeatures;

}

void AdaBoost::InitializeWeights()
{
	size_t i;


	for(i=0;i<positive.size();i++) weights[i] = 0.5/positive.size();

	for(i=positive.size();i<totalimages;i++) weights[i] = 0.5/(negative.size());
}

double AdaBoost::SumPositiveWeights(){
	double sum = 0;
	for (int i = 0; i < positive.size();i++){
		sum += weights[i];
	}
	return sum;
}
double AdaBoost::SumNegativeWeights(){
	double sum = 0;
	for (int i = positive.size(); i < totalimages;i++){
		sum += weights[i];
	}
	return sum;
}

void AdaBoost::NormalizeWeight()
{
	double sum = 0;

	
	for(int i=0;i<totalimages;i++){
	 sum += weights[i];
	}
	for(int i=0;i<totalimages;i++){
	 weights[i] /= sum;
	}

}
void AdaBoost::writeFeatures(vector<HaarFeatures>){
	
}

void AdaBoost::readinnegatives(){
	/*VideoCapture cap("Faces/0.jpg");
  
   int count = 0;
    for (;;)
    {
    	cout << "N" << count << endl;
    	Mat frame;
        cap >> frame;
        negative.push_back(frame);
    }
    */

}
void AdaBoost::readinpositives(){
	/*VideoCapture cap("Faces/0.jpg");
  
   	int count = 0;
    for (;;)
    {
    	cout << "P" << count++ << endl;
    	Mat frame;
        cap >> frame;
       positive.push_back(frame);
    }
    
}
*/
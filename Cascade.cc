#include "Cascade.h"

Cascade::Cascade(vector<Mat> P, vector<Mat> N, vector <HaarFeatures> F){
	positive = P;
	negative = N;
	haarfeatures = F;
	levelThreshold.resize(P.size()+N.size());
	for (int i = 0; i< levelThreshold.size(); i++)
		levelThreshold[i] = 100;
}
Cascade::~Cascade(){


}
/*For this section I used the following website as reference 
http://en.wikipedia.org/wiki/Viola%E2%80%93Jones_object_detection_framewoRrk
http://stackoverflow.com/questions/5808434/how-does-the-viola-jones-face-detection-method-work
*/
vector< vector < HaarFeatures> > Cascade::createCascade(double f, double d, double targetF){

	vector<Mat> P = positive;
	vector<Mat> N = negative;
	double tmpF=1.0;  
	double lastF=1.0;  
	double tmpD=1.0;  
	double lastD=1.0;  
	pair<double, double> tmpRet;
	int count = 0;
	
	while(tmpF > targetF){
		count++;
		int n = 0;

		tmpF = lastF;

		while (tmpF>f*lastF){
			n++;
			AdaBoost HEHEH(positive,negative,haarfeatures);
			vector<HaarFeatures> temp = HEHEH.applyAdaBoost(n);
			//vector<HaarFeatures> temp;
			//temp.push_back(haarfeatures[0]);
			cascaded.push_back(temp);
			
			tmpRet=evaluateOnTest();

			tmpF=tmpRet.first;
			tmpD=tmpRet.second;
			

			decraseThreshold(count,d*lastD);
			//cout << "Done with this" << endl;

		}

		N.clear();
		if(tmpF>targetF) 
			evaluateOnTrainNegative(N);

	}
	return cascaded;
}
pair<double,double> Cascade::evaluateOnTest() {
	int misclassifiedPossitives=0;
	int misclassifiedNegatives=0;  
	
	for(int i=0;i<positive.size();i++)
		if(!evaluate(positive[i])) misclassifiedPossitives++;
	
	for(int i=0;i<negative.size();i++)
		if(evaluate(negative[i])) misclassifiedNegatives++;
	
	
	return make_pair(misclassifiedNegatives/positive.size(),misclassifiedPossitives/negative.size());
}

bool Cascade::evaluate(Mat image) {
	double sum;
	//cout << "Start with this" << endl;
	for(int i=0;i<cascaded.size();i++) {
		sum=0;  
		
		//cerr << "Failed" << endl;
		for(int j=0;j<cascaded[i].size();j++) {
			
			sum += cascaded[i][j].applyhaarfeaturesIntImage(image) * cascaded[i][j].error;
			
						

		}
		//cerr << "Failed" << endl;
		if(sum<levelThreshold[i]) return false;  
		//cerr << "Failed" << endl;
	}
	
	return true;
}
void Cascade::evaluateOnTrainNegative(vector<Mat> N) {
	for(int i=0;i<negative.size();i++)
		if(evaluate(negative[i])) 
			N.push_back(negative[i]);
}

void Cascade::decraseThreshold(int ith, double minD) {
	int errP;  
	double tmpD;  
	
	int down=0,mid,up=100100;  
	
	while(down<=up) {
		mid=levelThreshold[ith]=(down+up)/2;
		
		errP=0;
		for(int i=0;i<positive.size();i++)
			if(!evaluate(positive[i])) errP++;
		tmpD=errP/negative.size();
		
		if(tmpD<minD+1e-9) up=mid-1;
		else down=mid;
	}
}


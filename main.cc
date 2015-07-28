//EDIT!!!!!!!!!!
#include "FeaturesNew.h"
#include "Feature.h"
#include "AdaBoost.h"
#include "Cascade.h"
#include "Classify.h"

#include <iostream>
#include <ostream>

#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Thread.h>
#include <yarp/os/Time.h>
#include <yarp/os/Mutex.h> 

using namespace std;
using namespace yarp::os;

/*
vector<Eventpoint> returnEventsFile(string str){
    ifstream fin;
    fin.open(str);
    vector<Eventpoint> ImageSet;
    while (!fin.eof( ))      
    {

        int x, y, pol, timing; 
        fin >> x >> y >> pol >> timing;  
        Eventpoint tempEvent(x,y,pol,timing);
        ImageSet.push_back(tempEvent);

    }


    cout << "Done returnEventsFile" << endl;
    fin.close();
    return ImageSet;
}

vector<Feature> loadFeature(string str, int n){
    vector<Feature> FeatureSet;
    ifstream fin;
    fin.open(str);
    for(int i = 0; i < n; i++){
        int type;
        int iix, iiy, ddx, ddy;
        double threshold = 0;
        double error = 0;
        int pol;
        fin >> type >> iix >> iiy >> ddx >> ddy >> threshold >> pol >> error;
        switch(type){
        case 0:{
            egdeFeatureHor AFeature(iix, iiy, ddx, ddy, threshold, pol, error);
            break;
        }
        case 1:{
            egdeFeatureVer AFeature(iix, iiy, ddx, ddy, threshold, pol, error);
            break;
        }
        case 2:{
            lineFeaturesHor AFeature(iix, iiy, ddx, ddy, threshold, pol, error);
            break;
        }
        case 3:{
            lineFeaturesVer AFeature(iix, iiy, ddx, ddy, threshold, pol, error);
            break;
        }
        case 4:{
            checkerFeatures AFeature(iix, iiy, ddx, ddy, threshold, pol, error);
            break;
        }
    }

        FeatureSet.push_back(AFeature);
    }
    //cout << "Done FeatureSet" << endl;
    fin.close();
    return FeatureSet;
    
}

void writeFeature( vector<Feature> Features, string str){
    
    for (int i = 0; i < Best.size(); i++){  
        Features->print(str);
    }


}

void writeCascade(vector< vector <Features> > CascadeClassifier){
    ofstream fout("CascadeSet.txt");
    for (int i = 0; i < CascadeClassifier.size();i++){
        fout << CascadeClassifier[i].size() << "\n";
        for(int j = 0; j < CascadeClassifier[i].size();j++){
            fout << CascadeClassifier[i][j].ix << " " <<  CascadeClassifier[i][j].iy << " " <<  CascadeClassifier[i][j].dx << " " <<  CascadeClassifier[i][j].dy << " " <<  CascadeClassifier[i][j].type << " " <<  CascadeClassifier[i][j].threshold << " " <<  CascadeClassifier[i][j].parity << " " <<  CascadeClassifier[i][j].error << endl; 
        }
    }


}
*/
class WorkerThread : public yarp::os::Thread {
public:
    WorkerThread(unsigned int id) {
      myID = id;
    }

    bool threadInit() {
        cout<<"Initializing..."<<endl;
        return true;
    }

    void run() {
        while(!isStopping()) {
            
            key.lock();
            cout<<"Worker "<<myID<<" says Hi!"<<endl;
            key.unlock();

            Time::delay(0.2);
        }
    }
private:
    unsigned int myID;
};



class MyModule:public RFModule
{
    int count;

public:

    double getPeriod() {
        return 1; //module periodicity (seconds)
    }

    /*
    * This is our main function. Will be called periodically every getPeriod() seconds.
    */
    bool updateModule()
    {


    }
    
    /* 
    * Configure function. Receive a previously initialized
    * resource finder object. Use it to configure your module.
    * Open port and attach it to message handler.
    */
    bool configure(yarp::os::ResourceFinder &rf)
    {        

    }

    /*
    * Interrupt function.
    */
    bool interruptModule()
    {
        cout<<"Interrupting your module to stop the worker thread..."<<endl;

    }

    /*
    * Close function, to perform cleanup.
    */
    bool close()
    {
        cout<<"Calling close function\n";

    }
};

int main(int argc, char * argv[])
{
    Network yarp;

    MyModule module;
    ResourceFinder rf;
    rf.configure(argc, argv);
    // rf.setVerbose(true);

    cout<<"Configure module..."<<endl;
    module.configure(rf);
    cout<<"Start module..."<<endl;
    module.runModule();

    cout<<"Main returning..."<<endl;
    return 0;
}

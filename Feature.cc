#include "Feature.h"
 /*
Eventpoint::Eventpoint()
{

}
void Eventpoint::loadEvent()
{

}
void setEvent()
{}
int getEventX()
{
	return x;
}
int getEventY()
{
	return y;
}
int getEventPolarity()
{
	return polarity;
}
double getEventTime()
{
	return timing;
}

//______________________________________________________________________________________//
int Feature::setPeramiters(int inix, int iniy, int finx, int finy)
{
	ix = inix;
	iy = inty;
	dx = finx;
	dy = finy;
}

int Feature::getFeatureIX()
{
	return ix;
}
int Feature::getFeatureIY()
{
	return iy;
}
int Feature::getFeatureDX()
{
	return dx;
}
int Feature::getFeatureDY()
{
	return dy;
}
long double Feature::getFeatureError()
{
	return error;
}
long double Feature::getFeatureThreshold()
{
	return threshold;
}
int Feature::getFeatureParity()
{
	return parity
}

int egdeFeatureHor::countArea(vector Events < Eventpoint >)
{

	int increase, decrease;
	for (size_t i = 0; i < Events.size(); i++)
	{
		//Current Implementation
		//Looking into replacing with kd-trees
		if ((ix <= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (iy + ((dy - iy)/2) >= Events.getEventY())){
				increase++;
			}

		}
		if ((ix<= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy + ((dy - iy)/2)+1 <= Events.getEventY()) && (dy >= Events.getEventY())){
				decrease++;
			}

		}

	}
	return (increase - decrease);



}
int egdeFeatureVer::countArea(vector Events < Eventpoint >)
{
	int increase, decrease;
	for (size_t i = 0; i < Events.size(); i++)
	{
		//Current Implementation
		//Looking into replacing with kd-trees
		if ((ix <= Events.getEventX()) && (ix+((dx-ix)/2) >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (dy >= Events.getEventY())){
				increase++;
			}

		}
		if ((ix+((dx-ix)/2)+1 <= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (dy >= Events.getEventY())){
				decrease++;
			}

		}

	}
	return (increase - decrease);
	return ( (calcArea(ix,iy,half,dy)-calcArea(half+1,iy,dx,dy)));

}
int lineFeaturesHor::countArea(vector Events < Eventpoint >)
{
	
	int increase, decrease;
	for (size_t i = 0; i < Events.size(); i++)
	{
		//Current Implementation
		//Looking into replacing with kd-trees
		if ((ix <= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (iy + ((dy - iy)/3) >= Events.getEventY())){
				decrease++;
			}

		}
		if ((ix<= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy + ((dy - iy)/3)+1 <= Events.getEventY()) && (iy + ((dy - iy)2/3) >= Events.getEventY())){
				increase;
			}

		}
		if ((ix<= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy + ((dy - iy)2/3)+1 <= Events.getEventY()) && (dy >= Events.getEventY())){
				decrease++;
			}

		}


	}
	return (increase - decrease);
}
int lineFeaturesVer::countArea(vector Events < Eventpoint >)
{
	int increase, decrease;
	for (size_t i = 0; i < Events.size(); i++)
	{
		//Current Implementation
		//Looking into replacing with kd-trees
		if ((ix <= Events.getEventX()) && (ix+((dx-ix)/3) >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (dy >= Events.getEventY())){
				decrease++;
			}

		}
		if ((ix+((dx-ix)/3)+1 <= Events.getEventX()) && (ix+((dx-ix)2/3) >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (dy >= Events.getEventY())){
				increase++;
			}

		}
		if ((ix+((dx-ix)2/3)+1 <= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (dy >= Events.getEventY())){
				decrease++;
			}

		}

	}
	return (increase - decrease);

}
//Not finished

int checkerFeatures::countArea(vector Events < Eventpoint >)
{

	int increase, decrease;
	for (size_t i = 0; i < Events.size(); i++)
	{
		//Current Implementation
		//Looking into replacing with kd-trees
		if ((ix <= Events.getEventX()) && (ix+((dx-ix)/2) >= Events.getEventX()))
		{
			if ((iy <= Events.getEventY()) && (iy + ((dy - iy)/2) >= Events.getEventY())){
				increase++;
			}

		}
		if ((ix+((dx-ix)/2)+1 <= Events.getEventX()) && (dx >= Events.getEventX()))
		{
			if ((iy + ((dy - iy)/2)+1 <= Events.getEventY()) && (dy >= Events.getEventY())){
				decrease++;
			}

		}

	}
	return (increase - decrease);
}
*/
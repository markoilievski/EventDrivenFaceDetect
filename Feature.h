/* 
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Author: Fouzhan Hosseini
 * email:  fouzhan.hosseini@iit.it
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

#ifndef FEATURE_H
#define FAETURE_H

#include <iostream>
#include <vector>
 

#define ABS(a) ((a) > (0) ? (a) : (-a))


class Eventpoint {

public:
	Eventpoint();
	void loadEvent();
	void setEvent();
	int getEventX();
	int getEventY();
	int getEventPolarity();
	double getEventTime();
private:
	int x, y;
	int polarity;
	double timing;

};

/**
 * @brief The vDraw class is the base class from which all vDrawers should
 * inherit. It contains the draw and getTag functions which must be overloaded,
 * and the sensor size for reference.
 */
class Feature {

public:
	///
    /// \brief setLimits sets the maximum possible values of the position of
    /// events that could be drawn (mostly governed by the sensor size).
    /// \param Xlimit is the maximum x value (width)
    /// \param Ylimit is the maximium y value (height)
    ///
	Feature (int inix, int iniy, int finx, int finy) : ix(inix), iy(inty), dx(finx), dy(finy), threshold(0) = 0, error(0) = 0, parity(0) = true {}
	///
    /// \brief setLimits sets the maximum possible values of the position of
    /// events that could be drawn (mostly governed by the sensor size).
    /// \param Xlimit is the maximum x value (width)
    /// \param Ylimit is the maximium y value (height)
    ///
	virtual int countArea(vector Events < Eventpoint >) = 0;

	//setters
	void setPeramiters(int inix, int iniy, int finx, int finy);
	
	//getters
	int getFeatureIX();
	int getFeatureIY();
	int getFeatureDX();
	int getFeatureDY();
	long double getFeatureError();
	long double getFeatureThreshold();
	int getFeatureParity();

private:
	long double threshold;
	long double error;
	bool parity;
	int ix,iy,dx,dy;
};

/**
 * @brief 
 */
class egdeFeatureHor : public Feature {

public:
	int countArea(vector Events < Eventpoint >);
private:

};

/**
 * @brief 
 */
class egdeFeatureVer : public Feature {

public:
	int countArea(vector Events < Eventpoint >);
private:

};

/**
 * @brief 
 */
class lineFeaturesHor : public Feature {

public:
	int countArea(vector Events < Eventpoint >);
private:

};

/**
 * @brief 
 */
class lineFeaturesVer : public Feature {

public:
	int countArea(vector Events < Eventpoint >);
private:

};

/**
 * @brief 
 */
class checkerFeaturess : public Feature{

public:
	int countArea(vector Events < Eventpoint >);
private:

};


#endif

/*
A scene is a ROI whithin which blobs will be processed in the algorithm

SCENE:
________________________________
|				|				|
|				|				|
|				|				|
|				|				|
|				|				|
|_______________|_______________|
*/

#pragma once
#ifndef SCENE_HPP
#define SCENE_HPP

#include <fstream>
#include <sstream>
#include "Tracker.hpp"


#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\video\background_segm.hpp>

using namespace cv;


class Scene {

public:
	Scene(int tsx, int tsy, int tex, int tey, Mat ROI);
	~Scene();
	int LSCheck(Tracker t);			//Line-side check, checks on which side of the line an object is
	bool WRCheck(Tracker t);		//Within ROI check, checks if the tracked blob is within the ROI defined by the user


private:
	//Entry/Exit-line in ROI
	int sx;							//Start X koordinate
	int sy;							//Start Y koordinate
	int ex;							//End X koordinate
	int ey;							//End Y koordinate

	Mat ROI;						//Defines the ROI where objects will be processed

};

#endif

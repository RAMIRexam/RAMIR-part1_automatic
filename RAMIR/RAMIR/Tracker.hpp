#pragma once
#ifndef TRACKER_HPP
#define TRACKER_HPP

#include <fstream>
#include <sstream>
#include "Blob.hpp"

#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\video\background_segm.hpp>

using namespace cv;
using namespace std;

class Tracker {

public:

	Tracker(Rect rect);
	~Tracker();

	void incrementTracks();
	void init();
	Rect getLastRect();
	void setLastRect(Rect r);
	void setLastHist(Mat h);
	Mat getLastHist();
	bool survivalTest();
	void fillWithBlob(Blob b);
	void fillWithEmptyBlob();


	bool processed;					//true if the tracker is processed this iteration


private:
	vector<Blob> blobvector;		//contains all detected blobs in order
	int numberTracks;
	Rect lastRect;
	Mat lastHist;


};

#endif // !SETTINGS_HPP

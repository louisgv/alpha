#include <vector>
#include <string>

#include "ros/ros.h"
#include <nav_msgs/Odometry.h>

#include <location_monitor/LandmarkDistance.h>

using namespace location_monitor;
using std::string;
using std::vector;

#ifndef __LANDMARK_INCLUDED__
#define __LANDMARK_INCLUDED__
class Landmark {
private:
	/* data */
public:
	string name;
	double x;
	double y;
	Landmark (string name, double x, double y);
};
#endif

#ifndef __LANDMARK_MONITOR_INCLUDED__
#define __LANDMARK_MONITOR_INCLUDED__
class LandmarkMonitor {
private:
	/* data */
	vector<Landmark> landmarks_;
	void InitLandmarks();
	LandmarkDistance FindClosest(double x, double y);

public:
	LandmarkMonitor ();
	void OdomCallback(const nav_msgs::OdometryConstPtr& msg);
};

#endif

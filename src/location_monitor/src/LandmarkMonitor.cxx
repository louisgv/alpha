#include <vector>
#include <string>
#include "ros/ros.h"
#include "math.h"
#include <nav_msgs/Odometry.h>
#include <location_monitor/LandmarkMonitor.hxx>

using namespace location_monitor;
using std::string;
using std::vector;

Landmark :: Landmark (string name, double x, double y):
	name(name), x(x), y(y) {
}

LandmarkMonitor :: LandmarkMonitor() : landmarks_(){
	InitLandmarks();
}

void LandmarkMonitor :: InitLandmarks(){
	landmarks_.push_back(Landmark("Post", -3.68, -0.28));
	landmarks_.push_back(Landmark("Table", -2.31, -2.44));
	landmarks_.push_back(Landmark("Trash", 0.88, -0.70 ));
}

void LandmarkMonitor :: OdomCallback(const nav_msgs::OdometryConstPtr& msg){
	double x = msg->pose.pose.position.x;
	double y = msg->pose.pose.position.y;

	LandmarkDistance ld = FindClosest(x, y);

	ROS_INFO("name: %s, d: %f", ld.name.c_str(), ld.distance);
}

LandmarkDistance LandmarkMonitor :: FindClosest(double x, double y) {
	LandmarkDistance result;
	result.distance = -1;

	for (size_t i = 0; i < landmarks_.size(); i++) {
		/* code */
		const Landmark& landmark = landmarks_[i];

		double xd = landmark.x - x;
		double yd = landmark.y - y;

		double distance = sqrt(xd*xd + yd*yd);

		if (result.distance < 0 || distance < result.distance) {
			/* code */
			result.name = landmark.name;
			result.distance = distance;
		}
	}

	return result;
}

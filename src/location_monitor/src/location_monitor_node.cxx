#include <vector>
#include <string>

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

#include <location_monitor/LandmarkMonitor.hxx>

int main(int argc, char const *argv[]) {
	char** argvm = const_cast<char**>(argv);

	ros::init(argc, argvm, "location_monitor");

	ros::NodeHandle nh;

	LandmarkMonitor monitor;
	ros::Subscriber sub = nh.subscribe("odom", 10,
		&LandmarkMonitor::OdomCallback, &monitor);

	ros::spin();

	return 0;
}

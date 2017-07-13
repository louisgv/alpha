#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

void OdomCallback(const nav_msgs::OdometryConstPtr& msg){
	double x = msg->pose.pose.position.x;
	double y = msg->pose.pose.position.y;
	ROS_INFO("x: %f, y: %f", x, y);
}

int main(int argc, char const *argv[]) {
	char** argvm = const_cast<char**>(argv);

	ros::init(argc, argvm, "location_monitor");

	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("odom", 10, OdomCallback);

	ros::spin();

	return 0;
}

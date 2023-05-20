#include "ros/ros.h"
#include "std_msgs/String.h"
#include "turtlesim/Pose.h"

void chatterCallback(const turtlesim::PoseConstPtr &msg)
{
  ROS_INFO("I heard theta: [%f]", msg->theta);
  ROS_INFO("I heard x  pos : [%f]", msg->x) ;
  ROS_INFO("I heard y  pos : [%f]", msg->y) ;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("turtle1/pose", 1000, chatterCallback);
  ros::Rate wait(10000000000);
  wait.sleep();
  ros::spin();

  return 0;
}

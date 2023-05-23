#include "ros/ros.h"
#include "std_msgs/String.h"
#include "topic_subscriber_pkg/Age.h"

void chatterCallback(topic_subscriber_pkg::Age msg)
{
  ROS_INFO("I heard days: [%f]", msg.days);
  ROS_INFO("I heard year : [%f]", msg.years) ;
  ROS_INFO("I heard month : [%f]", msg.months) ;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "age_pub");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("age_chatter", 1000, chatterCallback);
  ros::Rate wait(10000000000);
  wait.sleep();
  ros::spin();

  return 0;
}

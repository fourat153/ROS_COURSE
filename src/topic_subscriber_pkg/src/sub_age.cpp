#include "ros/ros.h"
#include "std_msgs/String.h"
#include "topic_subscriber_pkg/Age.h"
topic_subscriber_pkg::Age age_msg;
void chatterCallback(topic_subscriber_pkg::Age msg)
{
  ROS_INFO("I heard days: [%f]", msg.days);
  ROS_INFO("I heard year : [%f]", msg.years) ;
  ROS_INFO("I heard month : [%f]", msg.months) ;
  
}
ros::Publisher  age_pub2;
int main(int argc, char **argv)
{
  topic_subscriber_pkg::Age age_msg;
  ros::init(argc, argv, "age_pub");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("age_chatter", 1000, chatterCallback);
  age_pub2 = n.advertise<topic_subscriber_pkg::Age>("age2_chatter", 1000);
  

  age_pub2.publish(age_msg);
 

  ros::Rate wait(10000000000);
  wait.sleep();
  ros::spin();

  return 0;
}

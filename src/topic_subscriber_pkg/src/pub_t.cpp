#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  ros::Rate loop_rate(10);

 
  
  while ((ros::ok()))
  {

    geometry_msgs::Twist msg;

    msg.linear.x = 0.5;

    ROS_INFO("%F", msg.linear.x);


    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
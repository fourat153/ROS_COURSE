#include "ros/ros.h"
#include "std_msgs/Float32.h"
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("chatter", 1000);
  ros::Rate loop_rate(10);

 
  int count = 20;
  while ((ros::ok()) && (count <= 100))
  {

    std_msgs::Float32 msg;

    msg.data = count;

    ROS_INFO("%F", msg.data);


    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
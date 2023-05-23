#include "ros/ros.h"
#include "topic_subscriber_pkg/Age.h"


  ros::Publisher  age_pub;
int main(int argc, char **argv)
{

  ros::init(argc, argv, "int_publisher");


  ros::NodeHandle n;

  
 age_pub = n.advertise<topic_subscriber_pkg::Age>("age_chatter", 1000);

  ros::Rate loop_rate(10);



  while (ros::ok())
  {

    topic_subscriber_pkg::Age age_msg;

    age_msg.years=1991;
    age_msg.months=12;
    age_msg.days=24;


    age_pub.publish(age_msg);

    ros::spinOnce();

    loop_rate.sleep();

  }


  return 0;
}
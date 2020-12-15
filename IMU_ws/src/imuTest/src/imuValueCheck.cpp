// ラズパイから来たIMUの値を表示する通信確認用

#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"
#include <geometry_msgs/Twist.h>

int mfgetcnt = 0;
float eulerval[10] = {0.0f};
const float Pi = 3.1415;
float gyro_coefficient = (float)500 / 32768;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "imuValueCheck");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("array", 1000, chatterCallback);
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

    ros::AsyncSpinner spinner(1);
    spinner.start();
    ros::Rate rate(256);
    
    while (ros::ok())
    {
        n.subscribe("array", 1000, chatterCallback);
        geometry_msgs::Twist twist;
        twist.linear.x = 0.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = eulerval[0];
        twist.angular.y = eulerval[1];
        twist.angular.z = eulerval[2];
        if (mfgetcnt % 500 == 0)
        {
            ROS_INFO("I published!");
        }
        pub.publish(twist);
        mfgetcnt++;
        rate.sleep();
    }
    spinner.stop();
    return 0;
}
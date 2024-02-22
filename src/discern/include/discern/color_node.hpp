#ifndef COLOR_NODE_HPP
#define COLOR_NODE_HPP
//ROS2
#include <rclcpp/rclcpp.hpp>
#include<sensor_msgs/msg/image.hpp>
//interfaces 
#include "ros2_interfaces/msg/imfor.hpp"
namespace Identify
{
    class Id_node: public rclcpp::Node
    {
     public:
     explicit Id_node(const rclcpp::NodeOptions & options);
    
     private:

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr Sub_;

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr Pub_;
    
    rclcpp::Publisher<ros2_interfaces::msg::Imfor>::SharedPtr Pub_;

    void sub_callback(const sensor_msgs::msg::Image::SharedPtr msg);

    };
}
#endif
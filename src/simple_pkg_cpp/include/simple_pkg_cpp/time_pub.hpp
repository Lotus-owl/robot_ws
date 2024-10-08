#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

class TimePublisher : public rclcpp::Node
{
public:
    TimePublisher();
    
private:
    int _i;
    rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr _pub;
    rclcpp::TimerBase::SharedPtr _timer;
    //clock
    rclcpp::Clock _clock;
    void publish_time_msg();
};

#endif  //PUBLISHER_HPP
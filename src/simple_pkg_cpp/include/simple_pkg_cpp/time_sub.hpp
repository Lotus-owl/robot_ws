#ifndef TIME_SUB_HPP
#define TIME_SUB_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class TimeSubscriber : public rclcpp::Node
{
public:
    TimeSubscriber();

private:
    rclcpp::Subscription<std_msgs::msg::Header>::SharedPtr _sub;
    void sub_time_msg(const std_msgs::msg::Header::SharedPtr msg);
};

#endif // TIMESUBSCRIBER_HPP
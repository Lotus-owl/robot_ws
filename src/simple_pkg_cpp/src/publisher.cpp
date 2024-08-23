#include "simple_pkg_cpp/publisher.hpp"

HelloPublisher::HelloPublisher()
: Node("hello_world"), _i(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    _pub = this->create_publisher<std_msgs::msg::String>("helloworld", 10);
    _timer = this->create_wall_timer(1s, std::bind(&HelloPublisher::publish_helloworld_msg, this));
}

void HelloPublisher::publish_helloworld_msg()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello, World!"+to_string(_i);
    _pub->publish(msg);
    _i++;
};

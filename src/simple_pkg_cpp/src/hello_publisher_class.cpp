#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

class HelloPublisher : public rclcpp::Node
{
public:
    HelloPublisher()
    : Node("hello_world"), _i(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        _pub = this->create_publisher<std_msgs::msg::String>("helloworld", 10);
        _timer = this->create_wall_timer(1s, std::bind(&HelloPublisher::publish_helloworld_msg, this));
    }
private:
    int _i;
    //std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String, std::allocator<void>>> _pub;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub;
    rclcpp::TimerBase::SharedPtr _timer;
    void publish_helloworld_msg()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Hello, World!"+to_string(_i);
        _pub->publish(msg);
        _i++;
    };
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HelloPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
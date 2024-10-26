#include <chrono>
#include <cmath>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

using namespace std::chrono_literals;

class TurtleShapes : public rclcpp::Node
{
public:
    TurtleShapes()
        : Node("turtle_shapes"),
          step_(0),
          side_length_(1.0) // 每边长度
    {
        // 发布者
        turtle1_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        turtle2_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle2/cmd_vel", 10);

        // 定时器
        timer_ = this->create_wall_timer(500ms, std::bind(&TurtleShapes::draw_shapes, this));
    }

private:
    void draw_shapes()
    {
        auto turtle1_msg = geometry_msgs::msg::Twist();
        auto turtle2_msg = geometry_msgs::msg::Twist();

        // 让第一只乌龟画圆
        turtle1_msg.linear.x = 2.0;  // 向前移动的速度
        turtle1_msg.angular.z = 1.0;  // 角速度
        turtle1_pub_->publish(turtle1_msg);

        // 让第二只乌龟画方
        if (step_ < 20) {
            if (step_ % 2 == 0) {
                // 直行
                turtle2_msg.linear.x = 1.0; // 向前移动
                turtle2_msg.angular.z = 0.0; // 不转弯
                timer_count_++;

                if(timer_count_>=8){
                    step_++;
                    timer_count_=0;
                }
            } else {
                // 转弯
                turtle2_msg.linear.x = 0.0;  // 停止
                turtle2_msg.angular.z = pi/2; // 90度转弯
                timer_count_++;
                if (timer_count_ >= 4) { 
                    step_++;
                    timer_count_ = 0; // 重置计时器
                }
            }
        } else {
            // 停止乌龟
            turtle2_msg.linear.x = 0.0; 
            turtle2_msg.angular.z = 0.0; 
        }

        turtle2_pub_->publish(turtle2_msg);

        // 控制计时器
        timer_count_++;
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle1_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle2_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    int step_; // 记录当前阶段
    int timer_count_ = 0; // 控制计时器
    double side_length_; // 每条边的长度
    double pi=M_PI;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtleShapes>());
    rclcpp::shutdown();
    return 0;
}

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"
#include <chrono>
#include <random>

class NumberPublisher : public rclcpp::Node{

    public:
        NumberPublisher() : Node("number_publisher"){
            publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("input_numbers", subsciber_queue);
            
            timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(
                &NumberPublisher::timer_callback, this
            ));

            generator_ = std::mt19937(random_());
            distribution_ = std::uniform_real_distribution<double>(1.0, 100.0);
        }

    private:
        void timer_callback(){
            tutorial_interfaces::msg::Num numbers;
            numbers.num1 = randomNumber();
            numbers.num2 = randomNumber();
            RCLCPP_INFO(this->get_logger(), "Publishing: num1 = %.2f, num2 = %.2f", numbers.num1, numbers.num2);
            publisher_->publish(numbers);
        }

        double randomNumber(){
            return distribution_(generator_);
        }

        const int subsciber_queue = 10;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;

        std::random_device random_;
        std::mt19937 generator_;
        std::uniform_real_distribution<double> distribution_;
    };


int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);

    //creates an isntance of simple publisher and enters a loop to get communications running

    rclcpp::spin(std::make_shared<NumberPublisher>());
    //shutdown ros2 comms
    rclcpp::shutdown();
    return 0;
    
    /*tutorial_interfaces::msg::Num msg;
    msg.num1 = 1.23;
    msg.num2 = 3.45;

    std::cout << "Test publish message: " << msg.num1 << ", " << msg.num2 << std::endl;

    rclcpp::shutdown();

    return 0;*/
}
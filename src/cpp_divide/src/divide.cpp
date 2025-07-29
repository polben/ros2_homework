#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"
#include "std_msgs/msg/float64.hpp"


class NumberDivider : public rclcpp::Node{
    public:
        NumberDivider() : Node("number_divider"){
            subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
                "input_numbers", subsciber_queue, std::bind(&NumberDivider::topic_callback, this, std::placeholders::_1));

            resultPublisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("division_result", subsciber_queue);
        }
    private:
        void topic_callback(const tutorial_interfaces::msg::Num &numbers) {
            RCLCPP_INFO(this->get_logger(), "I heard: %.2f, num2 = %.2f", numbers.num1, numbers.num2);

            if (numbers.num2 != 0.0){
                double result = numbers.num1 / numbers.num2;
                tutorial_interfaces::msg::Num result_msg;
                result_msg.result = result;
                result_msg.num1 = numbers.num1;
                result_msg.num2 = numbers.num2;
                result_msg.error = false;
                result_msg.error_message = "";

                RCLCPP_INFO(this->get_logger(), "Publishing result: %.2f", result_msg.result);
                resultPublisher_->publish(result_msg);
            }else{

                tutorial_interfaces::msg::Num result_msg;
                result_msg.result = -1;
                result_msg.num1 = numbers.num1;
                result_msg.num2 = numbers.num2;
                result_msg.error = true;
                result_msg.error_message = "Denominator was 0";
                RCLCPP_INFO(this->get_logger(), "Denominator was 0!");
                resultPublisher_->publish(result_msg);
            }
        }
        rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
        rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr resultPublisher_;
        
        const int subsciber_queue = 10;
        
};



int main(int argc, char * argv[])
{

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NumberDivider>());
    rclcpp::shutdown();
    return 0;
    /*rclcpp::init(argc, argv);

    tutorial_interfaces::msg::Num received;
    received.num1 = 10.0;
    received.num2 = 2.0;

    double result = received.num1 / received.num2;
    std::cout << "Dividing: " << received.num1 << " / " << received.num2 << " = " << result << std::endl;

    rclcpp::shutdown();
    return 0;*/
    }
#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

class DivisionOutput : public rclcpp::Node{
    public:
        DivisionOutput() : Node("division_output"){
            subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
                "division_result", subsciber_queue, std::bind(&DivisionOutput::topic_callback, this, std::placeholders::_1));

        }
    private:
        void topic_callback(const tutorial_interfaces::msg::Num &divisionResult) {
            if (!divisionResult.error){
                RCLCPP_INFO(this->get_logger(), "Result was: %.2f", divisionResult.result);
            }else{
                RCLCPP_INFO(this->get_logger(), "Error occured: '%s'", divisionResult.error_message.c_str());
            }


            
        }
        rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
        
        const int subsciber_queue = 10;
        
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DivisionOutput>());
    rclcpp::shutdown();
    return 0;

    /*rclcpp::init(argc, argv);
    std::cout << "Output node running." << std::endl;
    rclcpp::shutdown();
    return 0;*/
}
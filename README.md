Documentation for the ROS2 homework

Installation guide

Install WSL for windows: 
https://learn.microsoft.com/en-us/windows/wsl/setup/environment#set-up-your-linux-username-and-password
https://learn.microsoft.com/en-us/windows/wsl/install

Get VSCode: https://code.visualstudio.com/
Install CMake and WSL extentions

Install Ubuntu 22.04 Jammy distribution in WSL
Distributor ID: Ubuntu
Description:    Ubuntu 22.04.4 LTS
Release:        22.04
Codename:       jammy

22.04 jammy is important, ROS 2 Humble only supports Ubuntu 22.04 (Jammy).

Setup Git and Colcon for build: https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html
sudo apt install python3-colcon-common-extensions

Install Humble Ros: https://docs.ros.org/en/humble/Installation.html
Don't forget ro source ros: source /opt/ros/humble/setup.bash, add this to your .bashrc file

Run ros2 to see if its working.

Clone my repository: git clone https://github.com/polben/ros2_homework.git
Build my ros packages:

colcon build --packages-select tutorial_interfaces (once, contains a custom message structure)
colcon build --packages-select cpp_divide (once, contains actual nodes)
source install/setup.bash (all terminals)

Run my ros2 packages:
	ros2 run cpp_divide numbers
	ros2 run cpp_divide divide
	ros2 run cpp_divide output

You can test the case for a zero denominator with the following command:

ros2 topic pub --once /input_numbers tutorial_interfaces/msg/Num "{num1: 10.0, num2: 0.0, result: 0.0, error: false, error_message:""}"	

For more details and commands, please see my ros_comms.txt file where I took notes.

Whats in the homework?


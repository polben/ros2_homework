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

Video overview: https://www.youtube.com/watch?v=HJAE5Pk8Nyw&t

Whats in the homework?

This repository contains a simple ros2 implementation that reflects the base structure of a ros system. Three nodes are present in the implementation numbers, divide and output.
The numbers node generates two random numbers, and publishes them in a custom message structure.
The divide node is a listener subscribed to the /input_numbers topic, where the numbers node publishes the nominator and denominator. The divide node then carries out the division, handling the division by zero error, then publishes the results again onto the /division_result topic.
A third node, output, is subscibed to this topic, and displays the result of the division. Division by zero errors are logged and propagated trough node 2 and 3. Use rqt_graph (command) to show the topics and nodes.
You can send a division by zero message with the custom command I provided.


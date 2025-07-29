cmake_minimum_required(VERSION 3.8)
project(cpp_divide)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

## ADDED -------
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tutorial_interfaces REQUIRED)

# for publisher
add_executable(numbers src/numbers.cpp)
ament_target_dependencies(numbers rclcpp std_msgs tutorial_interfaces)

# for subsciber
add_executable(divide src/divide.cpp)
ament_target_dependencies(divide rclcpp std_msgs tutorial_interfaces)

# for output
add_executable(output src/output.cpp)
ament_target_dependencies(output rclcpp std_msgs tutorial_interfaces)

install(TARGETS
	numbers # for publisher
	divide # for sub
  output
	DESTINATION lib/${PROJECT_NAME})
## END ADDED -------

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

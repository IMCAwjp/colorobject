cmake_minimum_required(VERSION 3.8)
project(discern)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

########
##find##
########

find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rclcpp_components REQUIRED)

#######
#build#
#######

include_directories(${PROJECT_NAME} include)

 add_library(talker_component SHARED
   src)

 ament_target_dependencies(
   "rclcpp"
   "rclcpp_components"
   "OpenCV"
   "cv_bridge"
   "sensor_msgs")

 rclcpp_components_register_node(talker_component "Identify::Id_node")

######
#test#
######

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
 
  set(ament_cmake_copyright_FOUND TRUE)
  
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

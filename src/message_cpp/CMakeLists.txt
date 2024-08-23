cmake_minimum_required(VERSION 3.8)
project(message_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# include directories
include_directories(include)

# add executable
add_executable(mpub src/mpub.cpp)
ament_target_dependencies(mpub rclcpp std_msgs)

add_executable(msub src/msub.cpp)
ament_target_dependencies(msub rclcpp std_msgs)

add_executable(msub2 src/msub2.cpp)
ament_target_dependencies(msub2 rclcpp std_msgs)

add_executable(tpub src/tpub.cpp)
ament_target_dependencies(tpub rclcpp std_msgs)

add_executable(mtsub src/mtsub.cpp)
ament_target_dependencies(mtsub rclcpp std_msgs)

#install
install(TARGETS
  mpub
  msub
  msub2
  tpub
  mtsub
  DESTINATION lib/${PROJECT_NAME})
  
install(DIRECTORY
  launch
  param
  DESTINATION share/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

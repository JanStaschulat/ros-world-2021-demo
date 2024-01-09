cmake_minimum_required(VERSION 3.5)

project(ros_world_2021_demo)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(NOT TRACETOOLS_DISABLED)
  # Set TRACETOOLS_LTTNG_ENABLED if we can find lttng-ust
  find_package(PkgConfig)
  if(PkgConfig_FOUND)
    pkg_check_modules(LTTNG lttng-ust)
    if(LTTNG_FOUND)
      set(TRACETOOLS_LTTNG_ENABLED TRUE)
      message("LTTng found: tracing enabled")
    endif()
  endif()
endif()

add_executable(ping
  src/ping.cpp
)
ament_target_dependencies(ping
  rclcpp
  std_msgs
)

add_executable(pong
  src/pong.cpp
)

target_include_directories(pong PUBLIC include)

ament_target_dependencies(pong
  rclcpp
  std_msgs
)

if(TRACETOOLS_LTTNG_ENABLED)
  target_link_libraries(pong ${LTTNG_LIBRARIES})
endif()

install(TARGETS
  ping
  pong
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

install(
  DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

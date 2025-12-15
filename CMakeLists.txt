cmake_minimum_required(VERSION 4.0)
project(homework_shu)
set(CMAKE_CXX_STANDARD 17)

# 每个实验一个可执行文件
add_executable(quadraticequations
        quadraticequations/main.cpp
        quadraticequations/SolveEquations.cpp
)

add_executable(time_class
        time_class/main.cpp
        time_class/TIME.cpp
)

add_executable(MyString
        MyString/main.cpp
        MyString/MyString.cpp
)

add_executable(static_test
        static_test/Counter.cpp
)
add_executable(friend friend/friend.cpp)
add_executable(Vector Vector/Vector.cpp)
add_executable(251126
        251126/Currency.cpp
        251126/shape.cpp
        251126/window.cpp
)
add_executable(Shape_with_other_functions
        Shape_with_other_functions/Shape_inheritence.cpp
)
add_executable(linked_list_template linked_list_template/custom_linked_list_template.cpp)

cmake_minimum_required(VERSION 3.20)
project(LogiFinManage C)

set(CMAKE_C_STANDARD 99)

# 添加可执行文件，目标名不要用 .c 后缀
add_executable(LogiFinManage
        main.c
        employee.c
        utils.c  # 如果您有的话
)

# 如果需要链接库
# target_link_libraries(LogiFinManage some_library)
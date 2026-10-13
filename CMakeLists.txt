cmake_minimum_required(VERSION 3.20)

# Подключаем vcpkg (ОБЯЗАТЕЛЬНО первой строчкой после версии)
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(PostureChecker CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(onnxruntime REQUIRED)

# Если файла yolov8-pose.cpp пока нет в папке, оставь только PostureChecker.cpp
add_executable(PostureChecker PostureChecker.cpp)

target_link_libraries(PostureChecker PRIVATE 
    ${OpenCV_LIBS}
    onnxruntime::onnxruntime
)
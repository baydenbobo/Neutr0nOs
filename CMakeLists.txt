# Минимальная версия CMake
cmake_minimum_required(VERSION 3.15)

# Имя проекта
project(NeutronOS VERSION 1.0 LANGUAGES CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем исполняемый файл
add_executable(NeutronOS
    src/main.cpp
    src/Snake.cpp
    src/Calculator.cpp
    src/Usermenu.cpp
    src/Filemanager.cpp
    src/Clock.cpp
)

# Добавляем include директорию для заголовочных файлов
target_include_directories(NeutronOS PRIVATE include)

# Установка настроек для дебага
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Build type: Debug")
    add_compile_definitions(DEBUG)
else()
    message(STATUS "Build type: Release")
endif()

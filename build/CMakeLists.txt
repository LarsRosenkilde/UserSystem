cmake_minimum_required(VERSION 3.20)
project(EnhancedUserSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(UserSystem ../src/main.cpp ../src/Encryption.cpp ../src/Encryption.h ../src/UserPage.cpp ../src/UserPage.h ../src/ProfileData.cpp ../src/ProfileData.h)

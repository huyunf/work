cmake_minimum_required(VERSION 2.6)

set(MY_PROJ thread_c11_test)
project(${MY_PROJ})

if(MSVC)
  set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT thread_c11_test)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D_CRT_SECURE_NO_WARNINGS")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W3 /wd4996 /wd4101 /wd4244")
  string (REPLACE "/D_WINDOWS" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
  string (REPLACE "/DWIN32" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}) 
elseif(NOT MSVC)
  set(CMAKE_C_COMPILER gcc)
  set(CMAKE_C_FLAGS "-m32 -std=c99 -fno-strict-aliasing -fno-builtin -fno-common -g -ffloat-store -Wno-multichar -Wimplicit-function-declaration")
  set(CMAKE_CXX_COMPILER g++)
  set(CMAKE_CXX_FLAGS "-m32 -std=c++11 -pthread -fno-strict-aliasing -fno-builtin -fno-common -g -ffloat-store -Wno-multichar")
endif()

include_directories(
  src
  )
  
set(SRC
  src/thread_test.cpp
  )

add_executable(${MY_PROJ} ${SRC})

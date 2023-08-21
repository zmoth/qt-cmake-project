cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# 添加版本号
set(PROJECT_VERSION_MAJOR 0) # 主版本号
set(PROJECT_VERSION_MINOR 0) # 子版本号
set(PROJECT_VERSION_PATCH 1) # 阶段版本号
set(PROJECT_VERSION_TWEAK 0) # build
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK})
set(PROJECT_DESCRIPTION "hello cmake")
set(PROJECT_HOMEPAGE_URL "https://zmoth.top")

# 工程名称
project(
  showlogo
  VERSION ${PROJECT_VERSION}
  DESCRIPTION ${PROJECT_DESCRIPTION}
  HOMEPAGE_URL ${PROJECT_HOMEPAGE_URL}
  LANGUAGES CXX
)

message(STATUS "[${PROJECT_NAME}] Project ${PROJECT_NAME} v${PROJECT_VERSION}")

# 选项
option(BUILD_DEBUG_POSTFIX_D "Append d suffix to debug libraries" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)

# Compiler set
message(STATUS "[${PROJECT_NAME}] C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "[${PROJECT_NAME}] cmake system is: ${CMAKE_SYSTEM_NAME}")

# qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 后缀
if(BUILD_DEBUG_POSTFIX_D)
  # 这个就是定义各个版本对应的后缀，例如d，debug版本后缀，当然你想定义为其他，自己修改这块就可以了。
  set(CMAKE_DEBUG_POSTFIX "d")
  set(CMAKE_RELEASE_POSTFIX "")
  set(CMAKE_RELWITHDEBINFO_POSTFIX "rd")
  set(CMAKE_MINSIZEREL_POSTFIX "s")
endif()

include(GNUInstallDirs)

message(STATUS "[${PROJECT_NAME}] Project will be installed to ${CMAKE_INSTALL_PREFIX}")
message(STATUS "[${PROJECT_NAME}] Project is top? ${PROJECT_IS_TOP_LEVEL}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) # data

# add_subdirectory(3rdparty) # 第三方库
add_subdirectory(src) # 主程序


# install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# install(DIRECTORY examples DESTINATION .)
# install(FILES ${CMAKE_SOURCE_DIR}/LICENSE.txt DESTINATION .)

# Pack
include(${CMAKE_SOURCE_DIR}/cmake/CPack.cmake)

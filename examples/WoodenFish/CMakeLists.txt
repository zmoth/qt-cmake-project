project(WoodenFish)

message(STATUS "[example] 项目名称 ${PROJECT_NAME}")

# qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets) # 识别是Qt6还是Qt5
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE INCS *.hpp *.h)
file(GLOB_RECURSE RESOURCES *.qrc *.ui)

add_executable(${PROJECT_NAME} ${SRCS} ${INCS} ${RESOURCES})

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  PRIVATE $<BUILD_INTERFACE:${knock_SOURCE_DIR}/include>
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE knock
  PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
)

# 设置编译器选项
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

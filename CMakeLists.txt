

cmake_minimum_required(VERSION 3.16)

project(MinecraftUtil VERSION 1.0.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(Qt6_DIR "/Users/robertbruckart/Qt/6.2.4/")


# set(CMAKE_PREFIX_PATH "/Users/robertbruckart/Qt/5.15.2/ios/")
set(CMAKE_PREFIX_PATH "/Users/robertbruckart/Qt/6.3.0/macos/")
# set(CMAKE_MODULE_PATH "/Users/robertbruckart/Qt/6.2.4/ios/lib/cmake/Qt6")

# set(Qt6CoreTools_DIR    "/Users/robertbruckart/Qt/6.2.4/ios/lib/cmake/Qt6Core")
# set(Qt6WidgetsTools_DIR "/Users/robertbruckart/Qt/6.2.4/ios/lib/cmake/Qt6Widgets")


# set(CMAKE_SYSTEM_NAME "iOS")
# set(CMAKE_OSX_ARCHITECTURES "x86_64")


# set(CMAKE_PREFIX_PATH "/Users/robertbruckart/Qt/6.2.4/ios/lib/cmake/Qt6")
# set(CMAKE_MODULE_PATH "/Users/robertbruckart/Qt/6.2.4/ios/lib/cmake/Qt6")

# set(CMAKE_FIND_ROOT_PATH "/Users/robertbruckart/Qt/5.15.2/ios/")


# find_package(Qt5Widgets REQUIRED)
# find_package(Qt5Core REQUIRED)
# find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts DataVisualization)
# find_package(Qt6 REQUIRED COMPONENTS Core)

# find_package(Qt5OpenGL REQUIRED)
# find_package(OpenGL REQUIRED)
# find_package(GLUT REQUIRED)

# qt_standard_project_setup()

# Find includes in corresponding build directories.
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


qt_standard_project_setup()




set(_INCLUDE_DIRS
    # GL
    # /usr/include
    # Qt5
    # ${Qt5Widgets_INCLUDES}
    # 
    # Qt6
    # ${Qt6Widgets_INCLUDES}
    # 
    # local
    ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(${_INCLUDE_DIRS}
                    # ${PROJECT_SOURCE_DIR}
                    ${PROJECT_BINARY_DIR}
                    ${CMAKE_CURRENT_LIST_DIR}/include
                    # QWT Includes
                    # /opt/homebrew/Cellar/qwt/6.2.0_1/include
                    # /opt/homebrew/Cellar/qwt/6.2.0_1/lib/qwt.framework/Versions/6/Headers
                    # ${OPENGL_INCLUDE_DIRS} 
                    # ${GLUT_INCLUDE_DIRS})
)


set(_MINECRAFT_OBSERVER_UI
    # ${CMAKE_CURRENT_LIST_DIR}/src/MinecraftObserver.ui
)

set(_MINECRAFT_OBSERVER_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/include/MinecraftObserverWidget.h
)

set(_MINECRAFT_OBSERVER_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/MinecraftObserverWidget.cpp

)


set(_MINECRAFT_COMMANDER_UI
    ${CMAKE_CURRENT_LIST_DIR}/src/MinecraftCommanderWidget.ui
)

set(_MINECRAFT_COMMANDER_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/include/MinecraftCommanderWidget.h
)

set(_MINECRAFT_COMMANDER_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/MinecraftCommanderWidget.cpp
)

qt6_wrap_cpp(minecrafter_header_moc
    ${_MINECRAFT_COMMANDER_HEADERS}
    ${_MINECRAFT_OBSERVER_HEADERS}
    ${CMAKE_CURRENT_LIST_DIR}/include/ChangeDetectionWidget.h
    ${CMAKE_CURRENT_LIST_DIR}/include/HistogramWidget.h
)

qt6_wrap_ui(minecrafter_ui_moc
    ${_MINECRAFT_COMMANDER_UI}
    ${_MINECRAFT_OBSERVER_UI}
)

add_executable(minecrafter
    ${minecrafter_header_moc}
    ${minecrafter_ui_moc}
    ${_MINECRAFT_COMMANDER_SOURCES}
    ${_MINECRAFT_OBSERVER_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/src/HistogramWidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/ChangeDetectionWidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)

target_link_libraries(minecrafter
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::DataVisualization
    Qt6::Charts
    # /opt/homebrew/lib/
    # qwt-qt6
    # Qt5::Gui
    # Qt5::Widgets
    pthread
    # ssl
    stdc++
    # glut
    # GLU
    # GL
)


# target_include_directories(shield.ai PUBLIC ${_INCLUDE_DIRS})
# target_link_libraries(shield.ai 
    # dl
    # nsl
    # m
    # rt
    # pthread
    # ssl
    # stdc++
    # glut
    # GLU
    # GL
    # Qt5::OpenGL
    # ${OPENGL_LIBRARY}
    # ${GLUT_LIBRARY}
    # ${Qt5Widgets_LIBRARIES}
    # Qt5::Core
    # Qt5::Gui
    # Qt5::Widgets)
# )


# set_target_properties(minecraftFisher PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
# )


# if (CMAKE_TESTING_ENABLED)
#     add_subdirectory(test)
# endif()
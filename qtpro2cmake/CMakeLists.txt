cmake_minimum_required(VERSION 3.9)

#define prj name
project(demo)
# open qt function
# set(CMKAE_PREFIX_PATH 'C:/Qt/Qt5.9.6/5.9.6/mingw53_32')
# set(CMAKE_BUILD_TYPE "Debug") # Debug or Release, same as cmd 'cmake .. -DCMAKE_BUILD_TYPE=Release' 
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(RESOURCE_FILES imgs.qrc)

# find qt lib and headers
find_package(Qt5 COMPONENTS Widgets Gui Core PrintSupport REQUIRED)

# find all files
FILE(GLOB SRC_FILES "./*.cpp")
FILE(GLOB HEAD_FILES "./*.h")
FILE(GLOB UI_FILES "./*.ui")

# process ui and moc action
#qt5_wrap_cpp(MOC ${HEAD_FILES})
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
# qt5_add_resources(RCC res.qrc) # ${RESOURCE_DIR}

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${WRAP_FILES} ${RESOURCE_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::PrintSupport)

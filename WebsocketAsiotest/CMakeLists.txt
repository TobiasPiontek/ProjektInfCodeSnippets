cmake_minimum_required (VERSION 2.6)
project (Test)
add_executable(Test SampleWebServer.cpp)

#include Websocketpp
option (USE_WEBSOCKETPP 
        "Use Websocketpp to create Websockets" ON)

# add the Websocketpp library?
#

if (USE_WEBSOCKETPP)
	
	ADD_DEFINITIONS(-DASIO_STANDALONE )
	ADD_DEFINITIONS(-D_WEBSOCKETPP_CPP11_RANDOM_DEVICE_)
	ADD_DEFINITIONS(-D_WEBSOCKETPP_CPP11_TYPE_TRAITS_)
	
	Include(ExternalProject)
	ExternalProject_Add(extwebsocketpp
		GIT_REPOSITORY https://github.com/TobiasPiontek/websocketpp.git)
	ExternalProject_Add(extasio
		GIT_REPOSITORY https://github.com/tobiasrau/asio.git
		GIT_TAG cmake)
#	ExternalProject_Add(extbase64
#		GIT_REPOSITORY https://gist.github.com/tomykaira/f0fd86b6c73063283afe550bc5d77594)
	
	
  
  
  
  
  include_directories(${EXTERNAL_INSTALL_LOCATION}/include "build/extwebsocketpp-prefix/src/extwebsocketpp/install/include" "build/extasio-prefix/src/extasio/include")
  target_link_libraries(Test ${CMAKE_SOURCE_DIR}/build/extasio-prefix/src/extasio/lib/asio.lib)
#  add_library(${PROJECT_NAME} SHARED ${public_header_files} ${header_files} ${source_files})
#  target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
  
#  link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
#  add_library(Asiolib "build\extasio-prefix\src\extasio-build\asio\Debug\asio.lib")
#  target_link_libraries(Asiolib)
endif (USE_WEBSOCKETPP)

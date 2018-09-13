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
	ExternalProject_Add(extasio
		GIT_REPOSITORY https://github.com/tobiasrau/asio.git
		GIT_TAG cmake)
	ExternalProject_Add(extwebsocketpp
		GIT_REPOSITORY https://github.com/TobiasPiontek/websocketpp.git)
	add_dependencies(Test extasio)
	add_dependencies(extwebsocketpp extasio)
    include_directories(${EXTERNAL_INSTALL_LOCATION}/include "build/extwebsocketpp-prefix/src/extwebsocketpp/install/include" "build/extasio-prefix/src/extasio/include")
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/build/extasio-prefix/src/extasio/lib/asio.lib)

  
  
endif (USE_WEBSOCKETPP)

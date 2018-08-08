// NeuerWebsocketTest.cpp : Defines the entry point for the console application.
//

//#include <../include/asio_no_tls_client.hpp>
//#include <../include/client.hpp>
//#include <../include/thread.hpp>
//#include <../include/memory.hpp>

//#include <../include/asio_client.hpp>
#include <client.hpp>
//#include <D:\Git\websocketpp\websocketpp\roles\client_endpoint.hpp>

#include <cstdlib>
#include <map>

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>


int main()
{
	bool done = false;
	std::string input;

	while (!done) {
		std::cout << "Enter Command: ";
		std::getline(std::cin, input);

		if (input == "quit") {
			done = true;
		}
		else if (input == "help") {
			std::cout
				<< "\nCommand List:\n"
				<< "help: Display this help text\n"
				<< "quit: Exit the program\n"
				<< std::endl;
		}
		else {
			std::cout << "Unrecognized Command" << std::endl;
		}
	}

	return 0;
}


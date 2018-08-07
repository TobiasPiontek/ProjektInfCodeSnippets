// NeuerWebsocketTest.cpp : Defines the entry point for the console application.
//

#include <../include/asio_client.hpp>
#include <../include/client.hpp>

#include "stdafx.h"
#include <string>
#include <iostream>


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


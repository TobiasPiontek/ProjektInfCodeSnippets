// NewTestProject.cpp : Defines the entry point for the console application.

#include <../websocketpp/config/asio_client.hpp>
#include <../websocketpp/client.hpp>

#include <iostream>
#include <string>
#include "stdafx.h"



int main()
{
	int test = 0;
	bool wahr = false;
	std::string wort = "bla";
	
	//std::string testwort("bla");

	/*
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
	*/
    return 0;
}


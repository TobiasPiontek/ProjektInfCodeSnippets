#include "stdafx.h"

//includes for fileteset
#include <fstream>	//for opening files 
#include <vector>	//for reading pictures in as bytes
#include <streambuf> //for reading html as string
#include <iterator> 
#include <string>   

#include <iostream>

//#include <windows.h>

//websocket includes
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/base64/base64.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

std::vector<char> buf; 	 //vector um ein bmp


						 // pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

void on_message(server* s, websocketpp::connection_hdl hdl, server::message_ptr msg) {
	/*
	std::cout << "on_message called with hdl: " << hdl.lock().get()
	<< " and message: " << msg->get_payload()
	<< std::endl;
	*/

	if (msg->get_payload() == "Hello there.") {
		s->send(hdl, "General Kenobi!", msg->get_opcode());
	}
	//"D:\\Git\\ProjektInfCodeSnippets\\ConsoleApplication2\\Bidirectional Test\\world.png"
	else if (msg->get_payload() == "image") {
		std::basic_ifstream<char> file("../../BidirectionalTest/mandelbrot.bmp", std::ios::binary); //opens bitstream to source
		buf = std::vector<char>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); // reads in data to the vector
		//std::cout << "sizeof buf: " << buf.size() << std::endl;

		//s->send(hdl, buf.data(), buf.size(), websocketpp::frame::opcode::binary);

		//String sample code conversion
		std::string str(buf.begin(), buf.end());
		//std::cout << "size of converted string: " << str.length() << std::endl;

		std::string alternate = websocketpp::base64_encode(str);

		double compress_time;
		clock_t recieve_start = clock();
		s->send(hdl, alternate, msg->get_opcode());
		compress_time = clock() - recieve_start;
		//std::cout /*<< "sending the image took: " */ << compress_time << std::endl;

	}
	else if (msg->get_payload() == "framebuffer") {
		std::basic_ifstream<char> file("../../BidirectionalTest/color_buf.txt", std::ios::binary); //opens bitstream to source
		buf = std::vector<char>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); // reads in data to the vector
		std::cout << "sizeof buf: " << buf.size() << std::endl;
		//String sample code conversion
		
		/*
		BITMAPFILEHEADER bitmapFileHeader;
		BITMAPINFOHEADER bitmapInfoHeader;

		bitmapFileHeader.bfType = 0x4D42;
		bitmapFileHeader.bfSize = 1280*720*3;
		bitmapFileHeader.bfReserved1 = 0;
		bitmapFileHeader.bfReserved2 = 0;
		bitmapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

		bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfoHeader.biWidth = 1280 - 1;
		bitmapInfoHeader.biHeight = 720 - 1;
		bitmapInfoHeader.biPlanes = 1;
		bitmapInfoHeader.biBitCount = 24;
		bitmapInfoHeader.biCompression = BI_RGB;
		bitmapInfoHeader.biSizeImage = 0;
		bitmapInfoHeader.biXPelsPerMeter = 0; // ?
		bitmapInfoHeader.biYPelsPerMeter = 0; // ?
		bitmapInfoHeader.biClrUsed = 0;
		bitmapInfoHeader.biClrImportant = 0;
		*/


		std::string data(buf.begin(), buf.end());
		
		std::string alternate = websocketpp::base64_encode(data);

		//std::string header(&bitmapFileHeader);

		s->send(hdl, alternate, msg->get_opcode());

	}
	else {
		s->send(hdl, "It's treason then!", msg->get_opcode());
	}

	//s->send(hdl, msg->get_payload(), msg->get_opcode());
}



//HTTP Handler that reads a html file
void on_http(server * s, websocketpp::connection_hdl hdl) {
	server::connection_ptr con = s->get_con_from_hdl(hdl);

	//nach https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
	std::ifstream t("../../index.html");
	std::string html((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

	std::stringstream output;
	output << html;



	// Set status to 200 rather than the default error code
	con->set_status(websocketpp::http::status_code::ok);
	// Set body text to the HTML created above
	con->set_body(output.str());
}

int main() {
	// Create a server endpoint

	server print_server;

	//disables all logs 
	print_server.clear_access_channels(websocketpp::log::alevel::all);


	// Register our message handler
	print_server.set_message_handler(bind(&on_message, &print_server, ::_1, ::_2));

	print_server.set_http_handler(bind(&on_http, &print_server, ::_1));

	//print_server.set_message_handler(&on_message);

	// Initialize Asio
	print_server.init_asio();

	// Listen on port 9002
	print_server.listen(9002);

	// Start the server accept loop
	print_server.start_accept();

	// Start the ASIO io_service run loop
	print_server.run();

}

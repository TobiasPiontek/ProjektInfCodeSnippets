// ConsoleApplication1.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "../include/snappy.h"
#include <string>
#include <sstream>
#include <algorithm>

/*
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";


*/

using namespace std;

int main()
{
	int length = 100;
	string output;
	string decompressed;
	string outputresult;



	auto randchar = []() -> char
	{
		const char charset[] =
			"01";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);


	
	snappy::Compress(str.data(), str.size(), &output);
	cout <<"Eingegebener String: " << endl <<  str << endl;
	cout << "Eingabe groese: " << str.size() << endl;
	cout << "Komprimierte Daten: " << output << endl;
	cout << "Ausgabe groese: " << output.size() << endl;

	snappy::Uncompress(output.data(), output.size(), &outputresult);

	cout << "Dekomprimiert: " << endl << outputresult << endl;
	cout << "Dekomprimiert groese" << outputresult.size() << endl;

	cout << str << endl << outputresult << endl;

	cout << "-----------------------------" << endl;
	cout << "mit charset" << endl;

	unsigned char unconverted[100];
	char converted[100];
	char snappycompressed[sizeof(converted)];
	char snappyuncompressed[sizeof(converted)];
	unsigned char convertedback[100];
	
	//for testing purpose filling with random 1/0
	for (size_t i = 0; i < sizeof(unconverted); i++)
	{
		const char charset[] = "01";
		const size_t max_index = (sizeof(charset) - 1);
		unconverted[i] = charset[rand() % max_index];
		cout << unconverted[i];
	}
	cout << endl;
	
	//convert for Snappy unsigned charset --> signed charset
	for (size_t i = 0; i < sizeof(unconverted); i++)
	{
		converted[i] = static_cast<char>(unconverted[i]);
	}
	
	//for experimental purpose
	size_t expected_compressed_length = snappy::MaxCompressedLength(sizeof(converted));
	cout << "size_t= " << expected_compressed_length << endl;
	
	cout << " size of converted_array: " << sizeof(converted)  << endl;
	
	cout << "converted: " << endl ;
		//Print to Console
		for (size_t i = 0; i < sizeof(converted); i++)
		{
			cout << converted[i];
		}
		cout << endl;

	//Compression of char array
	snappy::RawCompress(converted, size(converted), snappycompressed, &expected_compressed_length);
	cout << "compressed data by snappy:" << endl;
		//Print to Console
		for (size_t i = 0; i < sizeof(snappycompressed); i++)
		{
			cout << snappycompressed[i];
		}
		cout << endl;

	//Decompression of char array
		snappy::RawCompress(snappycompressed, sizeof(snappycompressed), snappyuncompressed,&expected_compressed_length);
		cout << "uncompresssed data from snappy" << endl;
		for (size_t i = 0; i < sizeof(snappycompressed); i++)
		{
			cout << snappyuncompressed[i];
		}
		cout << endl;
		
	cout << "converted back: " << endl;
	for (size_t i = 0; i < sizeof(convertedback); i++)
	{
		cout << convertedback[i];
	}

	for (size_t i = 0; i < sizeof(converted); i++)
	{
		convertedback[i] = static_cast<unsigned char>(converted[i]);
	}
	
	system("PAUSE");

    return 0;

}



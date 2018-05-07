// ConsoleApplication1.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <C:\Informatik Programme\Visual Studio Repos\ConsoleApplication1\include\snappy.h>
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

	cout << "------------------" << endl;
	cout << "mit charset" << endl;

	unsigned char unconverted[100];
	char converted[100];
	unsigned char convertedback[100];
	
	
	for (size_t i = 0; i < sizeof(unconverted); i++)
	{
		const char charset[] ="01";
		const size_t max_index = (sizeof(charset) - 1);
		unconverted[i]= charset[rand() % max_index];
		cout << unconverted[i];
	}
	cout << endl;
	
	for (size_t i = 0; i < sizeof(unconverted); i++)
	{
		converted[i] = static_cast<char>(unconverted[i]);
	}
	
	//cout << "normales Array(konvertiert in signed): " << endl << converted << endl;

	size_t expected_compressed_length = snappy::MaxCompressedLength(sizeof(converted));
	char snappycompressed[sizeof(converted)];
	cout << " size of converted_array: " << sizeof(converted)  << endl;
	
	cout << "converted: " << endl ;
	for (size_t i = 0; i < sizeof(converted); i++)
	{
		cout << converted[i];
	}
	cout << endl;

	for (size_t i = 0; i < sizeof(converted); i++)
	{
		convertedback[i] = static_cast<unsigned char>(converted[i]);
	}

	cout << "converted back: " << endl ;
	for (size_t i = 0; i < sizeof(convertedback); i++)
	{
		cout << convertedback[i];
	}
	cout << endl;
	cout << "size_t= " << expected_compressed_length << endl;

	snappy::RawCompress(converted, size(converted), snappycompressed, &expected_compressed_length);
	cout << "komprimierte Daten von Snappy:" << endl;
	for (size_t i = 0; i < sizeof(snappycompressed); i++)
	{
		cout << snappycompressed[i];
	}


	//snappy::Compress(converted, 100, &outputvalues);



	// reading in file length
	/*
	char buffer[1000];
	ifstream infile("sample.mp4");
	infile.seekg(0, infile.end);
	size_t angabe = infile.tellg();
	infile.seekg(0, infile.beg);
	long laenge = static_cast<long>(angabe);
	cout << "laenge: " << laenge << endl;
	
	//corrects buffer size in case too small
	if (laenge > sizeof(buffer)) {
		laenge = sizeof(buffer);
	}

	infile.read(buffer, length);
	 
	cout << "Buffer: " << buffer << endl;
	*/
	/*
	stringstream buffer;



	buffer << t.rdbuf();
	snappy::Compress(buffer.str().data(), buffer.str().size(), &output);
	cout << "Uncompressed size " << buffer.str().size() << endl << "Compressed Size: " << output.size() << endl;
	cout << buffer.str() << endl;



	//outfile.close();
	*/
	
	/*
	char data[110000];
	ifstream infile;
	infile.open("sample.mp4");
	cout << "test.txt" << endl;
	infile >> data;
	cout << data << endl;
	
	infile.close();
	system("PAUSE");
	*/

	system("PAUSE");


    return 0;

}



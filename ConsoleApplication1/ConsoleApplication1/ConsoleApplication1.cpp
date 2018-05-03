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

	unsigned char testvalue[100];
	
	for (size_t i = 0; i < sizeof(testvalue); i++)
	{
		const char charset[] ="01";
		const size_t max_index = (sizeof(charset) - 1);
		testvalue[i]= charset[rand() % max_index];
		cout << testvalue[i];
	}
	cout << endl;
	char converted_array[100];

	converted_array = testvalue;

	/*
	for (size_t i = 0; i < sizeof(testvalue); i++)

	{
		converted_array[i] = reinterpret_cast<char>(testvalue[i]);
	}
	*/

	//cout << "converted:" << konvertierung << endl;
	//char komprimiert[100];
	//size_t maximum_output_length = snappy::MaxCompressedLength((reinterpret_cast<char *>(testvalue)).length());
	//snappy::RawCompress((reinterpret_cast<char *>(testvalue)), (reinterpret_cast<char *>(testvalue)).length(), komprimiert, &maximum_output_length);
	size_t expected_compressed_length = snappy::MaxCompressedLength(sizeof(converted_array));
	cout << sizeof(converted_array) << " size of converted_array" << endl;
	
	//cout << "converted chars->" << endl ;
	for (size_t i = 0; i < sizeof(converted_array); i++)
	{
		cout << converted_array[i];
	}
	cout << endl;



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



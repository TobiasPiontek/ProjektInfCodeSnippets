// ConsoleApplication1.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "../include/snappy.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>

/*
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

*/

using namespace std;

int main()
{

	/*
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

	cout << "-----------------------------------------------" << endl;
	cout << "mit charset" << endl;

	unsigned char unconverted[100];
	char converted[100];
	
	char snappyuncompressed[sizeof(converted)];
	unsigned char convertedback[100];
	std::vector<unsigned char> color_buf;
	

	color_buf.resize(10, 10);
	cout << "Colorbuff size" <<color_buf.size() << endl;



	


	//for testing purpose filling with random 1/0
	for (size_t i = 0; i < sizeof(unconverted); i++)
	{
		const char charset[] = "01";
		const size_t max_index = (sizeof(charset) - 1);
		unconverted[i] = charset[rand() % max_index];
		cout << unconverted[i];
	}
	cout << endl;

	/*************************
	**************************
	Dummy Code for Transmitter begin
	**************************
	*************************/

	//convert for Snappy unsigned charset --> signed charset
	/*
	for (size_t i = 0; i < sizeof(unconverted); i++)
	{
		converted[i] = static_cast<char>(unconverted[i]);
	}
	cout << "converted: " << endl;
		//Print to Console
		
	for (size_t i = 0; i < sizeof(converted); i++)
		{
			cout << converted[i];
		}
		cout << endl;

	//for experimental purpose
	size_t expected_compressed_length = snappy::MaxCompressedLength(sizeof(converted));
	//Compression of char array
	char snappycompressed[sizeof(converted)];
	
	//snappy::RawCompress(&color_buf[], &color_buf.size(),)


	/*
	for (size_t i = 0; i < sizeof(converted); i++)
	{
		snappycompressed[i] = 'a';
	}
	
	snappy::RawCompress(converted, size(converted), snappycompressed, &expected_compressed_length);
	cout << "compressed data by snappy:" << endl;
		//Print to Console
		for (size_t i = 0; i < sizeof(snappycompressed); i++)
		{
			cout << snappycompressed[i];
		}
		cout << endl;
	cout << "size compressed: " << sizeof(snappycompressed) << endl;

	/*************************
	**************************
	Dummy Code for Transmitter end
	**************************
	*************************/


	/*************************
	**************************
	Dummy Code for Compositor begin
	**************************
	*************************/
	/*
	//Decompression of char array
		snappy::RawUncompress(snappycompressed, sizeof(snappycompressed), snappyuncompressed);
		cout << endl << "neue Debugnachrichten" << endl;
		cout  << "sizeof snappy compressed" << sizeof(snappycompressed) << endl; 
		cout << "size of size t" << expected_compressed_length;



		cout << "uncompresssed data from snappy" << endl;
		for (size_t i = 0; i < sizeof(snappycompressed); i++)
		{
			cout << snappyuncompressed[i];
		}
		cout << endl <<  "size decompressed: " << sizeof(snappyuncompressed) << endl;
		

	for (size_t i = 0; i < sizeof(converted); i++)
	{
		convertedback[i] = static_cast<unsigned char>(snappyuncompressed[i]);
	}



	cout << "Result of reconverted Array: " << endl;
	
	for (size_t i = 0; i < sizeof(converted); i++)
	{
		cout << convertedback[i];

	}
	/*************************
	**************************
	Dummy Code for Compositor end
	**************************
	*************************/

	/*
	cout << "size_t verlgleich" << endl;
	size_t compressed_length_color_buf;

	cout << "size_t deklaiert ohne wert" << sizeof(compressed_length_color_buf) << endl;
	cout << "normaler size_t" <<  sizeof(size_t) << endl;
	//cout << "vergleich" << (long)(sizeof(size_t)) == (long)(sizeof(compressed_length_color_buf));
	cout << endl;

	cout << "test von size:t" << endl;


	char konvertiert[100];
	size_t konvertiertgroese= sizeof(konvertiert);
	cout << "konvertiert groese= " << sizeof(konvertiert) << ", size_t davon= " << konvertiertgroese << endl;
	std::vector<char> konvertieren;
	konvertieren.resize(konvertiertgroese);
	cout << "bla" << endl;
	cout << "groese von konvertiert: " + konvertieren.size() << endl;
	size_t wasisthier = konvertieren.size();
	cout << "size_t vom Vektor= " << wasisthier << endl;
	cout << "bla" << endl;
	cout << "test kommt das an?" << endl;

	*/
	//size_t length = 100; //Testdataset size
	std::vector<char> to_be_compressed;
	bool show_read_Data = false;


	//"D:\\Git\\ProjektInfCodeSnippets\\SnappyTest\\x64\\Debug\\TestTextDatei.txt"
	std::basic_ifstream<char> file("D:\\Git\\ProjektInfCodeSnippets\\SnappyTest\\x64\\Debug\\200xA.txt", std::ios::binary); //opens bitstream to source
	to_be_compressed = std::vector<char>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); // reads in data to the vector


	//to_be_compressed.resize(length);
	std::vector<char> done_uncompressing;
	done_uncompressing.resize(to_be_compressed.size());
	
	cout << "uncompressed Dataset mit " << to_be_compressed.size() << " Bytes: " << endl;
	//data to be tested
	
	if (show_read_Data) {

	
	for (size_t i = 0; i < to_be_compressed.size(); i++)
	{
		cout << to_be_compressed[i] << ",";
	}
	cout << endl;
	}

	std::vector<char> compressed;
	
	size_t compressed_size;//ablage der eigentlichen groese der Kompression

	compressed.resize(snappy::MaxCompressedLength(to_be_compressed.size()));
	//cout << "Obergrenze: " << snappy::MaxCompressedLength(to_be_compressed.size()) << endl;
	
	snappy::RawCompress(&to_be_compressed[0], to_be_compressed.size(), compressed.data(), &compressed_size);
	compressed.resize(compressed_size);
	cout << endl;
	cout << "Size of Snappy encoded Data: " << compressed_size << "Bytes " << endl;

	if(show_read_Data){
	cout << "komprimierte Daten: " << endl;
	for (size_t i = 0; i < compressed.size(); i++)
	{
		cout << compressed[i] << ",";
	}
	cout << endl;
	}


	snappy::RawUncompress(&compressed[0], compressed.size() ,done_uncompressing.data());

	cout << endl;
	
	if(show_read_Data){
	cout << "Pruefen ob Eingangsdaten gleich Ausgangsdaten entsprechen: " << endl;
	for (size_t i = 0; i < done_uncompressing.size(); i++)
	{
		cout << done_uncompressing[i] << ",";
	}
	cout << endl;
	}


	if (to_be_compressed == done_uncompressing) {
		cout << "Dekodierung entspricht Eingangsdaten!" << endl;
	}
	else {
		cout << "Fehler bei Dekodierung (Daten ungleich Eingabe)" << endl;
	}


	system("PAUSE");

    return 0;

}



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
#include <chrono>


using namespace std;

int main()
{

	std::vector<char> to_be_compressed;
	bool show_read_Data = false;

	clock_t read_in_start = clock();

	std::basic_ifstream<char> file("D:\\Git\\ProjektInfCodeSnippets\\SnappyTest\\x64\\Debug\\color_buf.txt", std::ios::binary); //opens bitstream to source
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
	//hier ist einlesen abgeschlossen
	double readin_time = (double)(clock() - read_in_start) / CLOCKS_PER_SEC * 1000.0;
	cout << "readin took: " << readin_time << " ms" << endl;


	//Begin der Kompression
	clock_t compress_start = clock();
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
	//Kompression ist hier abgeschlossen
	double compress_time = (double)(clock() - compress_start) / CLOCKS_PER_SEC * 1000.0;
	cout << "compression took: " << compress_time << " ms" << endl;

	//Start der Dekompression
	clock_t decompression_start = clock();

	snappy::RawUncompress(&compressed[0], compressed.size() ,done_uncompressing.data());

	cout << endl;
	
	//Ende der Dekompression
	double decompress_time = (double)(clock() - decompression_start) / CLOCKS_PER_SEC * 1000.0;
	cout << "decompression took: " << decompress_time << " ms" << endl;

	//Werteüberprüfung
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
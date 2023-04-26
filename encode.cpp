#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>


#include "schemes.h"


using namespace std;
//compile program: g++ encode.cpp schemes.cpp -o encode
//Program is executed as: ./encode INPUTDATA.txt schemecode
//Schemecode: NRZ-L = 0 ; NRZ-I = 1; B-AMI = 2; Manchester = 3; D-Manchester = 4;

int main(int argc, char *argv[])
{
	//Declaration of variables
	int code;
	string data;
	ifstream inputfile;
	ofstream outfile;
	
	inputfile.open(argv[1]);
	assert(inputfile.is_open());
	while(!inputfile.eof())
	{
		inputfile >> data;
		
	}
	cout << data<< endl;
	
	
	inputfile.close();
	
	code = stoi(argv[2]);
	cout << code << endl;
	
	outfile.open("OutputSignal.txt");
	assert(outfile.is_open());
	
	switch(code)
	{
		case 0:
			outfile << nrz_l(data) << endl;
			break;
		case 1:
			 outfile << nrz_i(data) << endl;
			break;
		case 2: 
			outfile << b_ami(data) << endl;
			break;
		case 3:
			outfile << manchester(data) << endl;
			break;
		case 4: 
			outfile << d_Manchester(data) << endl;
			break;
		default:
			cout << "Incorrect code scheme" << endl;
			break;
	
	
	}
	
	
	outfile.close();
	

return 0;
}

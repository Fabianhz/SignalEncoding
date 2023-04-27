#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>

#include "schemes.h"


using namespace std;
/*compile program:
g++ encode.cpp schemes.cpp -o encode
Program is executed as: 
./encode inputdata.txt schemecode
Schemecode: NRZ-L = 0 ; NRZ-I = 1; B-AMI = 2; Manchester = 3; D-Manchester = 4;
*/
int main(int argc, char *argv[])
{
	//Declaration of variables
	int code; //save scheme code from user argument
	string data; //save input data from inputdata.txt
	ifstream inputfile; //input file
	ofstream outfile;// output file
	
	inputfile.open(argv[1]); //open inputdata.txt
	assert(inputfile.is_open());
	while(!inputfile.eof())
	{
		inputfile >> data; //store data
		
	}
	
	
	inputfile.close();
	
	code = stoi(argv[2]);
	
	outfile.open("Outputfile.txt"); //create output file
	assert(outfile.is_open());
	outfile << "Input: " << data << endl;
	
	//cases for each encoding scheme
	switch(code)
	{
		case 0:
			outfile << "NRZ-L" << endl;
			outfile << nrz_l(data) << endl;
			break;
		case 1:
			outfile <<"NRZ-I" << endl;
			 outfile << nrz_i(data) << endl;
			break;
		case 2: 
			outfile << "B-AMI" << endl;
			outfile << b_ami(data) << endl;
			break;
		case 3:
			outfile << "Manchester" << endl;
			outfile << manchester(data) << endl;
			break;
		case 4: 
			outfile << "Differential Manchester" << endl;
			outfile << d_Manchester(data) << endl;
			break;
		default:
			cout << "Incorrect code scheme" << endl;
			break;
	
	
	}
	
	
	outfile.close();
	

return 0;
}

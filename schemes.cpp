#include "schemes.h"

string nrz_l(string data)
{
	string output;
	for(int i =0; i < data.length();i++)
	{
		if(data[i] == '1')
		{
			output += "|-V|";
		}
		else if(data[i] == '0')
		{
			output += "|+V|";
		}
	}
	return output;
}
string nrz_i(string data)
{
	string output;
	for(int i =0; i < data.length();i++)
	{
		if(data[i] == '1')
		{
			output += "";
		}
		else if(data[i] == '0')
		{
			output += "";
		}
	}
	return output;
}
string b_ami(string data)
{
	string output = "b_ami";
	return output;
}
string manchester(string data)
{
	string output = "manchester";

	return output;
}
string d_Manchester(string data)
{

	string output = "d_manchester";
	return output;

}

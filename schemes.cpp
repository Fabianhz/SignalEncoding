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
	string last_itr;
	for(int i =0; i < data.length();i++)
	{
		if(i == 0){
			if(data[i] == '1')
			{
				output += "|+V|";
				last_itr = "|+V|";
			}
			else if(data[i] == '0')
			{
				output += "|-V|";
				last_itr = "|-V|";
			}
		}
		else
		{
			if(data[i] == '1')
			{
				if(last_itr == "|-V|")
				{
					output += "|+V|";
					last_itr = "|+V|";
				}
				else
				{
					output += "|-V|";
					last_itr = "|-V|";
				}
			}
			else if(data[i] == '0')
			{
				output += last_itr;
			}
		}
	}
	return output;
}
string b_ami(string data)
{
	string output;
	string last_onebit_transition;
	for(int i =0; i < data.length();i++)
	{
		
		if(i == 0)
		{
			if(data[i] == '1')
			{
				output += "|-V|";    //starting bit could be either positive or negative(+V , -V )
				last_onebit_transition = "|-V|";
			}
			else if(data[i] == '0')
			{
				output += "|0V|"; //if starting bit is zero, that is zero voltage
				
			}
		}
		else
		{
			if(data[i] == '1')
			{
				if(last_onebit_transition == "|+V|")
				{
					output += "|-V|";
					last_onebit_transition = "|-V|";
				}
				else if(last_onebit_transition == "|-V|")
				{
					output += "|+V|";
					last_onebit_transition = "|+V|";
				}
			}
			else if(data[i] == '0')
			{
				output += "|0V|";
			}
		}
	}
	return output;
}
string manchester(string data)
{
	string output;
		for (int i = 0; i < data.length(); i++)
		{
			if (data[i] == '1') {
				output += "|-V +V|";
			}
			else if (data[i] == '0') {
					output += "|+V -V|";
			}
		}
	return output;
}
string d_Manchester(string data)
{

	string output;
	return output;

}

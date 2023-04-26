#include "schemes.h"

string nrz_l(string data) // nonreturn to zero level
{
	string output;
	for(int i =0; i < data.length();i++)
	{	//either positive or negative can be set for "1" input as long as "0" input has opposite polarity
		if(data[i] == '1')
		{
			output += "|-V";
		}
		else if(data[i] == '0')
		{
			output += "|+V";
		}
	}
	return output + "|";
}
string nrz_i(string data) //nonreturn to zero inverted
{
	string output;
	string lastbit;
	for(int i =0; i < data.length();i++)
	{
		if(i == 0){
			if(data[i] == '1')
			{
				output += "|+V";
				lastbit = "|+V";
			}
			else if(data[i] == '0')
			{
				output += "|-V";
				lastbit = "|-V";
			}
		}
		else
		{
			if(data[i] == '1')
			{
				if(lastbit == "|-V")
				{
					output += "|+V";
					lastbit= "|+V";
				}
				else
				{
					output += "|-V";
					lastbit = "|-V";
				}
			}
			else if(data[i] == '0')
			{
				output += lastbit;
			}
		}
	}
	return output + "|";
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
				output += "|-V";    //starting bit could be either positive or negative(+V , -V )
				last_onebit_transition = "|-V";
			}
			else if(data[i] == '0')
			{
				output += "|0V"; //if starting bit is zero, that is zero voltage
				
			}
		}
		else
		{
			if(data[i] == '1')
			{
				if(last_onebit_transition == "|+V")
				{
					output += "|-V";
					last_onebit_transition = "|-V";
				}
				else if(last_onebit_transition == "|-V")
				{
					output += "|+V";
					last_onebit_transition = "|+V";
				}
			}
			else if(data[i] == '0')
			{
				output += "|0V";
			}
		}
	}
	return output + "|";
}
string manchester(string data) //manchester encoding technique
{
	string output;
		for (int i = 0; i < data.length(); i++)
		{
			if (data[i] == '1') { //if bit is equal to 1, then output -V +V (low to high)
				output += "|-V +V";
			}
			else if (data[i] == '0') { //if bit is equal to 0, then output +V -V (high to low)
					output += "|+V -V";
			}
		}
	return output + "|";
}
string d_Manchester(string data) //differential manchester technique
{

	string output;
	string lastbit; //save the last bit output
    for (int i = 0; i < data.length(); i++)
    {
        if (i == 0) { //first bit
            if (data[i] == '1') { //if first bit is equal to 1, then output +V -V (high to low) and save to lastbit
                output += "|+V -V";
                lastbit = "|+V -V";
            }
            else if (data[i] == '0') { //if first bit is equal to 0, then output -V +V (low to high) and save to lastbit
                output += "|-V +V";
                lastbit = "|-V +V";
            }
        }
        else { //rest of bits

            if (data[i] == '1') { 
                if (lastbit == "|+V -V") { //if bit is equal to 1 and if lastbit is equal to +V -V (high to low), then output and save -V +V (low to high) 
                    output += "|-V +V";
                    lastbit = "|-V +V";
                }
                else if (lastbit == "|-V +V") { //if bit is equal to 1 and if lastbit is equal to -V +V (low to high), then output and save +V -V (high to low)
                    output += "|+V -V";
                    lastbit = "|+V -V";
                }
            }
            else if (data[i] == '0') { 
                if (lastbit == "|-V +V") { //if bit is equal to 0 and if lastbit is equal to -V +V (low to high), then output -V +V (low to high)
                    output += "|-V +V";
                }
                else if (lastbit == "|+V -V") { //if bit is equal to 0 and if lastbit is equal to +V -V (high to low), then output +V -V (high to low)
                    output += "|+V -V";
                }
            }
        }
    }
    return output + "|";

}

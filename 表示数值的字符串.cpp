
#include<iostream>

using namespace std;

class Solution 
{
public:
	bool isNumeric(char* string);

};
bool Solution::isNumeric(char* string)
{
	int decimal(0), integer(0),point(0),exponential(0);
	int ptr(0),ptr_old(0);
	while (string[ptr] != '\0')
	{
		if (string[ptr] == 'e' || string[ptr] == 'E')
		{
			if (exponential == 1)
				return false;
			else if (exponential == 0)
			{
				exponential++;
				if (string[ptr + 1] == '+' || string[ptr + 1] == '-')
					ptr += 2;
				else
					ptr++;
			}
		}

		if (ptr == 0 && (string[ptr] == '+'||string[ptr] == '-'))
			ptr++;

		if (string[ptr] == '.'&&point == 0 && exponential == 0)
		{
			point++;
			ptr++;
		}

		if (string[ptr]<'0' || string[ptr]>'9')
			return false;
		else
			ptr++;
	}

	return true;
}

int main(int argc, char *argv[])
{
	Solution Sol;

	cout << Sol.isNumeric("12e+4.3");




	return 0;
}


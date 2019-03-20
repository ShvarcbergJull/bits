#pragma once
#include <iostream>
#include <fstream>
#include <locale.h>
#include <cmath>

using namespace std;

const int STR_LENGHT = 10;

bool readLine(ifstream& in, char* buffer)
{
	buffer[0] = 0;
	in.getline(buffer, STR_LENGHT + 1, '\n');
	if (in.fail())
	{
		if (buffer[0] > 0)
			cout << "Слишком длинная строка во входном файле" << endl;
		return false;
	}
	return true;
}

double translate(char* c)
{
	double n = 0;
	double m = 0.1;
	bool ch = false;
	while (isdigit(*c) || *c == '.')
	{
		if (*c == '.')
		{
			ch = true;
			c++;
			continue;
		}
		if (!ch)
		{
			n *= 10;
			n += (*c - '0');
		}
		else
		{
			n += ((*c - '0') * m);
			m *= 0.1;
		}
		c++;
	}
	return n;
}

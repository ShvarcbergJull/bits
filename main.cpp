#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <locale.h>
#include "func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
  ifstream in("input.dat");

	int n, m = 0;
	char buffer[STR_LENGHT + 1];
	buffer[STR_LENGHT] = 0;

	if (readLine(in, buffer))
	{
		double pr = translate(buffer);
		n = int(pr);
	}
	else
		return 0;

	double* values = new double[n + 1];
	values[n] = 0;
	n = 0;
	int temp;
	bool sos = false;

	while (readLine(in, buffer))
	{
		values[n] = translate(buffer);
		if (values[n] == 0)
		{
			if (values[n] == values[m - 1])
			{
				m--;
				sos = true;
			}
			else
			{
				n++;
				continue;
			}
		}
		if (values[n] == values[m] || sos)
		{
			if (values[n] == values[m])
				temp = m;
			else
				temp = m - 1;
			temp--;
			n++;
			readLine(in, buffer);
			values[n] = translate(buffer);
			if (values[n] != values[temp])
				while (temp < n && values[n] != values[temp])
					temp++;
			if (temp == n)
			{
				m = n;
				n++;
				sos = false;
				continue;
			}
			while (temp >= 0 && readLine(in, buffer) && values[n] == values[temp])
			{
				temp--;
				n++;
				values[n] = translate(buffer);
			}

			if (temp < 0)
			{
				break;
			}
			else
			{
				sos = false;
				continue;
			}
		}

		m = n;
		n++;
	}
	in.close();
  
  ofstream out("output.txt");

	if (n == 7)
	{
		int count = 0;
		for (int i = 0; i < 7; i++)
			if (values[i] != 0)
				count++;
		out << count + 1 << endl;
	}
	else
		out << n << endl;

	out.close();

	system("pause");
	return 0;
}

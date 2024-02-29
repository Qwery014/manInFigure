#include <iostream>
#include "classes.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	Area area(20, 20);

	// Add square on area
	Square s;

	for (int i = s.getA(0); i < s.getC(0); i++)
	{
		for (int j = s.getA(1); j < s.getC(1); j++)
		{
			area.setCell(i, j, 's');
		}
	}

	// add trinagle on area
	Triangle t(area);

	area.setCell(t.getC(0), t.getC(1), 't');

	int start;
	int end;
	t.startAndEndIdentyification(&start, &end);

	for (int i = t.getC(0) + 1; i < t.getA(0); i++)
	{
		int y0 = i;
		
		for (start; start <= end; start++)
		{
			int x0 = start;

			if (t.isInTriangle(y0, x0))
			{
				area.setCell(i, start, 't');
			}
		}
	}

	// add circle on area
	Circle c(area);

	for (int i = c.getA(0) - c.getR(); i <= c.getA(0) + c.getR(); i++)
	{
		for (int j = c.getA(1) - c.getR(); j <= c.getA(1) + c.getR(); j++)
		{
			if (pow(j - c.getA(1), 2) + pow(i - c.getA(0), 2) <= pow(c.getR(), 2))
			{
				area.setCell(i, j, 'c');
			}
		}
	}

	// adding man on area
	Man m(area);

	// Showing the area
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << area.getArea()[i][j];
		}
		cout << endl;
	}

	cout << m.position << endl;
	return 0;
};
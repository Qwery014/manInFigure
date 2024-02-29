#pragma once
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int randNum(int up, int down);

class Cell
{
private:
	int x;
	int y;
	char content;

public:
	Cell(int, int);

	void setContent(char) { this->content = content; };
};


class Area
{
private:
	int rows;
	int cols;
	char** area;

public:
	Area(int rows, int cols) : rows(rows), cols(cols) {
		area = new char* [rows];
		for (int i = 0; i < rows; ++i) {
			area[i] = new char[cols];
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				area[i][j] = ' ';

				if (j != 0 && j != 19 && (i == 0 || i == 19))
				{
					area[i][j] = '-';
				}
				if (i != 0 && i != 19 && (j == 0 || j == 19))
				{
					area[i][j] = '|';
				}
			}
		}
	}

	~Area() {
		for (int i = 0; i < rows; ++i) {
			delete[] area[i];
		}
		delete[] area;
	}

	vector<vector<char>> getArea() {
		std::vector<std::vector<char>> tempArea(rows, std::vector<char>(cols));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				tempArea[i][j] = area[i][j];
			}
		}
		return tempArea;
	}

	void setCell(int x, int y, char c) const
	{
		area[x][y] = c;
	}

	char getCell(int x, int y) const
	{
		return area[x][y];
	}
};

class Circle
{
	int a[2];
	int b[2];
	int r;

public:
	int getA(int ind)
	{
		return this->a[ind];
	};

	void setA(int ind, int cords)
	{
		this->a[ind] = cords;
	};

	int getB(int ind)
	{
		return this->a[ind];
	};

	void setB(int ind, int cords)
	{
		this->b[ind] = cords;
	};

	int getR()
	{
		return this->r;
	};

	void setR(int rValue)
	{
		this->r = rValue;
	};

	Circle(const Area& area);
	void construct(const Area& area);
};


class Square
{
	int a[2];
	int b[2];
	int c[2];
	int d[2];
public:

	int getA(int ind)
	{
		return this->a[ind];
	};

	void setA(int ind, int cords)
	{
		this->a[ind] = cords;
	};

	int getB(int ind)
	{
		return this->b[ind];
	};

	void setB(int ind, int cords)
	{
		this->b[ind] = cords;
	};

	int getC(int ind)
	{
		return this->c[ind];
	};

	void setC(int ind, int cords)
	{
		this->c[ind] = cords;
	};

	int getD(int ind)
	{
		return this->d[ind];
	};

	void setD(int ind, int cords)
	{
		this->d[ind] = cords;
	};

	Square();

};

class Triangle 
{
	int a[2];
	int b[2];
	int c[2];

public:

	int getA(int ind)
	{
		return this->a[ind];
	};

	void setA(int ind, int cords)
	{
		this->a[ind] = cords;
	};

	int getB(int ind)
	{
		return this->b[ind];
	};

	void setB(int ind, int cords)
	{
		this->b[ind] = cords;
	};

	int getC(int ind)
	{
		return this->c[ind];
	};

	void setC(int ind, int cords)
	{
		this->c[ind] = cords;
	};

	void constructor(const Area& area);

	void startAndEndIdentyification(int* startPtr, int* endPtr)
	{

		if (this->getC(1) <= this->getA(1))
		{
			*startPtr = this->getC(1);
			*endPtr = this->getB(1);
		}
		else if (this->getC(1) >= this->getB(1))
		{
			*startPtr = this->getA(1);
			*endPtr = this->getC(1);
		}
		else if (this->getC(1) > this->getA(1) && this->getC(1) < this->getB(1))
		{
			*startPtr = this->getA(1);
			*endPtr = this->getB(1);
		}
	}

	bool isInTriangle(int y0, int x0)
	{

		int x1 = this->getA(1) - 1;
		int x2 = this->getB(1) + 1;
		int x3 = this->getC(1);

		int y1 = this->getA(0) - 1;
		int y2 = this->getB(0) + 1;
		int y3 = this->getC(0) - 1;

		if (
			(
				(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0) > 0 &&
				(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0) > 0 &&
				(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0) > 0
				) ||
			(
				(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0) < 0 &&
				(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0) < 0 &&
				(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0) < 0
				) ||
			(
				(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0) == 0 &&
				(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0) == 0 &&
				(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0) == 0
				)
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	Triangle(const Area& area)
	{
		constructor(area);
	};

};

class Man
{
public:
	int a[2];
	string position;
	Man(const Area& area)
	{
		int x = randNum(1, 18);
		int y = randNum(1, 18);

		this->a[0] = y;
		this->a[1] = x;

		if (area.getCell(y, x) == ' ')
		{
			this->position = "Человек не стоит на фигуре";
		}
		else if (area.getCell(y, x) == 'c')
		{
			this->position = "Человек стоит на круге";
		}
		else if (area.getCell(y, x) == 't')
		{
			this->position = "Человек стоит на треугольнике";
		}
		else if (area.getCell(y, x) == 's')
		{
			this->position = "Человек стоит на квадрате";
		}

		area.setCell(y, x, 'M');
	};

};
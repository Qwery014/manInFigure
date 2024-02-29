#include "classes.h";

Cell::Cell(int x, int y) {
	if (x < 20 && x >= 0)
	{
		this->x = x;
	}

	if (y < 20 && y >= 0)
	{
		this->y = y;
	}
}

int randNum(int up, int down) {
	// Создание генератора случайных чисел
	random_device rd; // устройство, генерирующее случайные числа
	mt19937 gen(rd()); // генератор Mersenne Twister с начальным значением, полученным из rd()

	int lower_bound = up;
	int upper_bound = down;
	uniform_int_distribution<> distrib(lower_bound, upper_bound);

	return distrib(gen);
}

Square::Square() {
	int x1 = randNum(4, 14);
	int x2 = randNum(4, 14);
	this->setA(0, x1);
	this->setA(1, x2);

	int len = randNum(3, (x1 > x2) ? 17 - x1 : 17 - x2);

	this->setB(0, x1);
	this->setB(1, x2 + len - 1);
	this->setC(0, x1 + len - 1);
	this->setC(1, x2 + len - 1);
	this->setD(0, x1 + len - 1);
	this->setD(1, x2);
}


void Triangle::constructor(const Area& area) {

	int a1 = randNum(7, 14);
	int a2 = randNum(7, 14);
	int len = randNum(3, 18 - a2);

	this->setA(0, a1);
	this->setA(1, a2);
	this->setB(0, a1);
	this->setB(1, a2 + len);

	int c1 = randNum(3, a1 - 4);
	int c2 = randNum(1, 18);

	this->setC(0, c1);
	this->setC(1, c2);

	int start;
	int end;

	startAndEndIdentyification(&start, &end);

	for (int i = this->getC(0) + 1; i < this->getA(0); i++)
	{
		int y0 = i;

		for (start; start <= end; start++)
		{
			int x0 = start;

			if (this->isInTriangle(y0, x0))
			{
				if (area.getCell(y0, x0) != ' ')
				{
					this->constructor(area);
					return;
				}
			}
		}
	}
}


Circle::Circle(const Area& area) {
	this->construct(area);
}

void Circle::construct(const Area& area)
{
	this->setR(randNum(2, 5));

	int a1 = randNum(this->getR() + 1, 18 - this->getR() + 1);
	int a2 = randNum(this->getR() + 1, 18 - this->getR() + 1);
	this->setA(0, a1);
	this->setA(1, a2);

	for (int i = a1 - r; i <= a1 + r; i++)
	{
		for (int j = a2 - r; j <= a2 + r; j++)
		{
			if (pow(j - a2, 2) + pow(i - a1, 2) <= pow(r, 2) && area.getCell(i, j) != ' ')
			{
				this->construct(area);
				return;
			}
		}
	}
}
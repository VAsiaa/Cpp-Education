//������.����������� ��������� ����� ������ � ���� �������� : ������� � ����������
//���������� ��������������.������� ������ ��������� ������ �����������

/*
������� ���� point.h, ���������� ����������� ��������� Point, ��������������
����� ����� �� ���������. ���������� ������ ��������� � ����� x � y.
2. ������� ���� shape.h, ���������� ����������� ������������ ������ Shape. ���� �����
������ ������������� ��������� ������:
� getArea ���������� �������
� scale ���������� ��������������� ������ ������������ � ������ � ���������
�������������
� getCenter ��������� ����� ������ ������
� getName ��������� �������� ������ (RECTANGLE, CIRCLE � �.�.), ����� ������������
��� ������
3. ����������� ����� Rectangle, ����������� �� Shape, � ������ rectangle.h �
rectangle.cpp, �������������� (��. ������ ��������).
4. ����������� ������, ��������� � �������� (��. ������ ��������).
5. ����������� �������� ��������� < ��� ������ Shape. ��������� ��������� �� �������
������.
6. ����������� �������, ����������� ������ ���������� �� ������ � ������� ����������
�� �������� (�������� ���������� �������� �� ���� ����������).
7. �������� ���������, � �������:
� ������� ������ ���������� �� ������ (�� ����� 5 �����)
� ������������� ������ �� ���������� ��������
� ������� ���������� � ������� �� ����� (���, ���������� ������, �������)
� ��������� ��������������� ���� ����� �� �������� �����������
� ������� ���������� � ������� �� ����� ��� ���

������:
� � ������ ������ ������ ���� �����������, ����������� ����������� ���������.
� ������ ������ �������������� ���� ������ � �� ��������� �������� �������� �
������������ ���������� (����� ����������� ���������� � ������� throw).
� ���������� ������ ������ ���� � ������������ ����� (.h, �� ��������� ��� header guard), �
����������� ������� � ����� ���������� (.cpp).
�������������. ����������� ��������� ��� �����: ����� ������ � ������ ������� ����.
���������, ��� ������� �������������� ����������� ���� ���������. ������� ������ ���������
����� ����������� ����������.
*/

#include "shape.h"
#include "rectangle.h"
#include "ring.h"
#include <iostream>


int main()
{
	const int SIZE = 5;
	Shape* shapes[SIZE]{ nullptr };
	
	Point x = { 0.0,0.0 }; //left bottom
	Point y = { 4.0,2.0 }; //right top

	Point x2 = { 2.0,2.0 };
	Point y2 = { 6.0,5.0 };

	Point x3 = { 2.0,-1.0 };
	Point y3 = { 2.0,2.0 };

	Point centre = { 0,0 };

	try 
	{
		shapes[0] = new Rectangle(x,y);
		shapes[1] = new Rectangle(x2,y2);
		shapes[2] = new Rectangle(x3,y3);
		shapes[3] = new Ring(centre,2.0,4.0);
		shapes[4] = new Ring(centre,2.0,3.0);

		//shapes[2] = new Rectangle(y, x);         //incorrect input value 
		//shapes[3] = new Ring(centre, 4.0, 2.0);  //incorrect input value 
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
		for (int i = 0; i < SIZE; ++i)
		{
			delete shapes[i];
			shapes[i] = nullptr;
			return 0;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		Point centre = shapes[i]->getCenter();
		std::cout << "Shape name: " << shapes[i]->getName() << " | Center: " << centre.x << "," << centre.y << " | Area: " << shapes[i]->getArea() << "\n";
	}
	std::cout << "---------------------------------------------------- \n";


	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = 0; j < SIZE - 1-i; j++)
		{
			if (*shapes[j + 1] < *shapes[j])
			{
				std::swap(shapes[j], shapes[j + 1]);
			}
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		Point centre = shapes[i]->getCenter();
		std::cout << "Shape name: " << shapes[i]->getName() << " | Center: " << centre.x << "," << centre.y << " | Area: " <<  shapes[i]->getArea() <<"\n";
	}

	std::cout << "---------------------------------------------------- \n";
	std::cout << "Scale shapoes on 2.0 \n";

	for (int i = 0; i < SIZE; i++)
	{
		try
		{
			shapes[i]->scale(2.0);
			//shapes[i]->scale(0.0);  //incorrect factor value 
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
			for (int i = 0; i < SIZE; ++i)
			{
				delete shapes[i];
				shapes[i] = nullptr;
				return 0;
			}
		}

	}

	for (int i = 0; i < SIZE; i++)
	{
		Point centre = shapes[i]->getCenter();
		std::cout << "Shape name: " << shapes[i]->getName() << " | Center: " << centre.x << "," << centre.y << " | Area: " << shapes[i]->getArea() << "\n";
	}

	for (int i = 0; i < SIZE; ++i)
	{
		delete shapes[i];
		shapes[i] = nullptr;
	}
	return 0;
}


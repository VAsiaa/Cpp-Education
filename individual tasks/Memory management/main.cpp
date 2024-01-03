/*
2. ����� ������� ������������ ���� (��������� ������ vector �� STL). ������ ������
������������� ����������� ���� ������ ��� ���������� ���������. ������ ��� ���������� � �������� ��������� �������,
��� ��������� � ���������, � ����� ��� ���������� �������. (� ������ ����� ������ ����
���������, �� ����� ������� ������ ��� ���� int)

����������� ����������, ������������ ����������� � �����������, ���������
����������� � ������������� ������������.
� ������ ������ ��������� ���������� � �������������.
� ����������� ������, ����������� ������������ ������ � ���������. (����������
���������, ��� ������� ����� ��������������)
� ��������� ������ ����� ����������� � ���� ������������� ���������� (���� ��������
�� ������).
� ����������� ������������� �������� << ��� ������ ���������� � �����.

*/
#include "vector.h"

int main()
{
	try
	{

	int a = 2;
	Vector<int> vect(a);
	Vector<int> vect2(3);
	Vector<double> vect4(3);
	vect4[0] = 2.3;
	vect4[1] = 2.7;
	vect4[2] = 2.1;


	vect[0] = 25;
	vect[1] = 20;
	std::cout << " \n --init Vect-- \n";
	for (size_t i = 0; i < vect.getSize(); i++)
	{
		std::cout << vect[i] << " ";
	}

	std::cout << " \n --pushBack-- \n";
	vect.pushBack(3);


	for (size_t i = 0; i < vect.getSize(); i++)
	{
		std::cout << vect[i] << " ";
	}



	vect.popBack();

	std::cout << "\n --popBack-- \n";

	std::cout << vect;

	std::cout << "\n --Sort-- \n";

	vect.sort();

	std::cout << vect;

	vect2 = vect;
	std::cout << "\n --vect = vect-- \n";

	std::cout << vect2;
	

	Vector<int> vect3 = vect2;
	std::cout << "\n --new vect = vect-- \n";

	std::cout << vect3;


	std::cout << " \n --init double Vect-- \n";

	std::cout << vect4;

	std::cout << "\n --double vect sort-- \n";
	vect4.sort();

	std::cout << vect4;

}
	catch (const std::exception& e)
	{
		std::cout << "error";
	}



	return 0;
}


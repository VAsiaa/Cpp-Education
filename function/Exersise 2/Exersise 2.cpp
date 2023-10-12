// Exersise 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

bool isPrimeNumber(int num);

int main()
{
	setlocale(LC_ALL, "Russian");

	int num = 0;

	std::cout << "Введите число\n";
	std::cin >> num;

	if (isPrimeNumber(num))
	{
		std::cout << "Результат - число простое\n";
	}
	else
	{
		std::cout << "Результат - число не является простым\n";
	}

	// Вывод всех простых чисел меньше введенного
	std::cout << "Список простых чисел меньше" << num << " \n";

	for (int i = num; i > 0; i--)
	{
		if (isPrimeNumber(i))
		{
			std::cout << i << "- простое\n";
		}
	}
}

/// <summary>
/// Функция определения простого числа
/// </summary>
/// <param name="num">-число, которое нужно проверить</param>
/// <returns></returns>
bool isPrimeNumber(int num)
{
	if (num < 2)
	{
		return false;
	}

	if (num % 2 == 0 && num != 2) // если введенное число четное и не является 2-ой то сразу говорим, что число не является простым
	{
		return false;
	}

	for (int i = 3; i * i <= num; i += 2) // используенм корень, тк деление на цело невозможно если знаменатель больше корня числителя => сократить операцию деления;
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}

	return true;
}

#include <iostream>

double verification(double n_max, double x, double &defaultRes, double abs_error);
inline double absolute(double n);
double findResult(double n_max, double &res, double x, double &error);

int main()
{
    setlocale(LC_ALL, "Russian");

    double x = 0.0;
    double abs_error = 0.0;
    int n_max = 0;
    double intervalStart = 0.0;
    double intervalEnd = 0.0;
    double step = 0.0;
    double defaultRes = 0.0;

    std::cout << "Введите значение x (-1 < x < 1):\n";
    std::cin >> x;
    std::cout << "Введите максимально число слогаемых:\n";
    std::cin >> n_max;
    std::cout << "Введите Абсолютную погрешность:\n";
    std::cin >> abs_error;
    std::cout << "---------- \n";
    std::cout << "Введитте начало интервала (-1 < x < 1): ";
    std::cin >> intervalStart;
    std::cout << "Введите конеч интервала (-1 < x < 1): ";
    std::cin >> intervalEnd;
    std::cout << "Enter the step size: ";
    std::cin >> step;



    try
    {
        std::cout << "Значение в заданной точке х" <<  verification(n_max, x, defaultRes, abs_error) << "\n";
        std::cout << "Значение в заданной точке х стандартным методом" << defaultRes << "\n";

        while (intervalStart + step < intervalEnd)
        {
            std::cout << "Значение в заданной точке" << intervalStart << " : " << verification(n_max, intervalStart, defaultRes, abs_error) << "\n";
            std::cout << "Значение в заданной точке" << intervalStart << " стандартным методом: " << defaultRes << "\n";
            intervalStart += step;
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << "\n";
    }

}

/// <summary>
/// Проверка введеных значений и погрешности
/// </summary>
/// <param name="n_max"></param>
/// <param name="x"></param>
/// <param name="abs_error"></param>
/// <returns></returns>
double verification(double n_max, double x, double &defaultRes, double abs_error)
{
    double error = 0.0;
    double res = 1.0;

    if (-1 < x && x < 1)
    {
        findResult(n_max, res, x, error);
        defaultRes = 1.0 / std::sqrt(1 + x);
    }
    else
    {
        throw std::runtime_error("Не корректное значение x!");
        return 0;
    }
    
    if (error > abs_error)
    {
        throw std::runtime_error("Погрешность не достигнута!");
        return 0;
    }
   
    return res;
}

/// <summary>
/// Модуль числа
/// </summary>
/// <param name="n">число</param>
/// <returns>модуль числа</returns>
inline double absolute(double n)
{
    return n < 0 ? -n : n;
}

/// <summary>
/// Нахождение результата при заданном количестве слогаемых
/// </summary>
/// <param name="n_max">- Количество слогаемых</param>
/// <param name="result">- Результат вычислений</param>
/// <param name="x">- Заданное значение</param>
/// <param name="error">- Погрешность вычислений</param>
/// <returns></returns>
double findResult(double n_max, double &result, double x, double &error)
{
    double intermRes = 1.0;
    int i = 1;

    for (i; i <= n_max; i += 2) 
    {
        intermRes *= -(double(x * i) / double(i + 1));
        result += intermRes;
       // intermRes += pow((-x), i) * ((double)i / (double)(i + 1));
    }
    error = absolute(pow((-x), (i + 2)) * ((double)(i + 2) / (double)(i + 3)));
   //result = (1 - intermRes);

    return 0;
}


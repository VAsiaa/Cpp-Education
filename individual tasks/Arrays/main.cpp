#include <iostream>
#include <ctime> 
#include <stdexcept>

/*Напишите функцию (функции), выполняющую действие в соответствии с вашим вариантом.
Напишите функцию main, в которой примените вашу функцию для нескольких массивов :
1. Для встроенных массивов, количество и значения элементов которых заданы при
инициализации 
2. Для массива, размещённого в динамической памяти, количество элементов которого
должно быть введено с клавиатуры, а значения элементов сгенерированы случайно.
Вариант:
Массив целых чисел циклически сдвинуть вправо на указанное число элементов
*/ 

int cyclArrOffset(int array[], int size, int offsetN);       
void fillArray(int array[], int size);
void printArray(int array[], const int size, char arrayN);
void reverseArr(int array[], int startIndx, const int endIndx);

int main()
{
    std::cout << "Hello World!\n"; 
    const int SIZE = 10;
    const int SIZE2 = 11;
    const int SIZE3 = 20; 
    const int SIZE4 = 1;
    int offsetN = 0;
    int staticArray[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int staticArray2[SIZE2] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10, -11 };
    int staticArray3[SIZE3] = { 100, 20, 60, 49, 54, 62, 34, 76, 32, 90, 99, 23, 4, 67, 8, 3, 2, 1, 0, 0 };
    int staticArray4[SIZE4] = { 1 };

    int dsize = 0;

    std::cout << "Enter the offset number \n";
    std::cin >> offsetN;
    if (std::cin.fail())
    {
        std::cout << "ERROR: Unsupported offset value! \n";
        return 0;
    }

    std::cout << "Enter the number of elements in the array\n";
    std::cin >> dsize;

    int *dynamicArray = new int[dsize];

    // установка генератора псевдослучайных чисел
    std::srand(std::time(0));                  

    // Заполнение динамического массива числами
    fillArray(dynamicArray, dsize);

    std::cout << "Array before offset \n";

    // Вывод  массива до смещения 
    printArray(staticArray, SIZE, '1');         
    printArray(staticArray2, SIZE2, '2');       
    printArray(staticArray3, SIZE3, '3');         
    printArray(dynamicArray, dsize, '4');        
    printArray(staticArray4, SIZE4, '5');       

    // Смещение  массива  
    try
    {
        cyclArrOffset(staticArray, SIZE, offsetN);  
        cyclArrOffset(staticArray2, SIZE2, offsetN);     
        cyclArrOffset(staticArray3, SIZE3, offsetN);     
        cyclArrOffset(dynamicArray, dsize, offsetN); 
        cyclArrOffset(staticArray4, SIZE4, offsetN); 
    }
    catch (const std::string& error_message)
    {
        std::cout << "ERROR: " << error_message << '\n';
        return 0;
    }

		


    std::cout << "Array after offset \n";
    // Вывод  массива после смещения 
    printArray(staticArray, SIZE, '1');        
    printArray(staticArray2, SIZE2, '2');        
    printArray(staticArray3, SIZE3, '3');        
    printArray(dynamicArray, dsize, '4');       
    printArray(staticArray4, SIZE4, '5');       


    delete [] dynamicArray;                     // Очистка памяти (Удаление динамического массива из памяти) 
    dynamicArray = nullptr;                     // Указатель на ноль
    return 0;
}

int cyclArrOffset(int array[], const int size, int offsetN)
{

    int fullArrayReverceN = 0;
    if (offsetN < 0)
    {
        throw  std::string{ "Unsupported offset value" };
        
    }
    else if (size == offsetN)
    {
        return 0;
    }
    else if(size < offsetN)
    {
        offsetN = offsetN % size; // вычисляем сколько раз нужно сделать смещение на длину массива
    }
    
    int maxArrayIdx = size - 1;

    reverseArr(array, size - offsetN, maxArrayIdx); //Переворачиваем смещение  - 1 2 3 4 5 6 7 | 10 9 8 
    reverseArr(array, 0, maxArrayIdx - offsetN);   //Переворачиваем оставшуюся часть  - 7 6 5 4 3 2 1 | 10 9 8
    reverseArr(array, 0, maxArrayIdx);             //Переворачиваем массив - 8 9 10 1 2 3 4 5 6 7         

    return 0;
}

void reverseArr(int array[], int startIndx, const int endIndx)
{
    int middleIndx = (startIndx + endIndx) / 2;     // Индекс элемента стоящего по середине 
    int tmp = 0;
    for (int i = startIndx; i <= middleIndx; i++)   // Переворачиваем 
    {
        tmp = array[i];
        array[i] = array[(endIndx + startIndx - i)];
        array[(endIndx + startIndx - i)] = tmp;
    }
}


void fillArray(int array[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = abs(std::rand() % 30 + 10);
    }
}

void printArray(int array[], int size, char arrayN)
{
    std::cout << "Array " << arrayN << ": \t";
    for (int i = 0; i < size; i++)
    { 
       std::cout << array[i] << " ";
    }
    std::cout << "\n";
}


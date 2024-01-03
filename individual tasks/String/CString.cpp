// ¬ариант 7 ќпределить, сколько различных букв латинского алфавита содержитс€ в строке

#include <iostream>
#include <fstream>
#include <cctype>


bool beenBefore(const char symbol,const char array[], const int idx)
{
    for (int k = 0; k < idx; k++)
    {
        if (symbol == array[k])
        {
            return false;
        }
    }
    return true;
}  


int countingLChars(char* array)
{
    int counter = 0;
    for (int i = 0; array[i] != '\0'; i++) // Ѕерем символ дл€ сравнени€ со всем массивом
    {
        if (isalpha(array[i]))
        {
            if (i == 0 || beenBefore(array[i], array, i))
            {
                counter++;
            }

        }
    }
    return counter;
}

int main()
{
    char*str = nullptr;
    int strLength = 0;
    std::ifstream file("infile.txt");

    if (!file.is_open())
    {
        std::cerr << "File can not be opened\n";
        return 1;
    }

    while (!file.eof()) 
    {
        file >> strLength; // запись длины строки
        file.ignore(); // игнорируем строчку с указанием длины массива
            
        try
        {
            char* str = new char[strLength + 1];
            file.getline(str, strLength + 1);
            std::cout << "Source string: " << str << "\n";
            std::cout << "Amount of difference symols: " << countingLChars(str) << "\n";

        }
        catch (std::bad_alloc)
        {
            std::cerr << "ERROR: can't allocate memory!";
            delete[] str;
            return 0;

        }
        delete[] str;
    }

    file.close();
    return 0;
}
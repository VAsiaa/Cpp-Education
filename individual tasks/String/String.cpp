//Определить, сколько различных букв латинского алфавита содержится в строке.
#include <iostream>
#include <fstream>
#include <string>


bool beenBefore(char symbol, std::string str, const int idx)
{
    for (int k = 0; k < idx; k++)
    {
        if (symbol == str[k])
        {
            return false;
        }
    }
    return true;
}


int countingLChars(std::string str)
{
    int counter = 0;
    for (int i=0; str[i] != '\0'; i++) // Берем символ для сравнения со всем массивом
    {
        if (isalpha(str[i])) 
        {
            if (i == 0 || beenBefore(str[i], str, i))
            {
                counter ++;
            }

        }
    }
    return counter;
}

int main()
{
    std::string str;

    std::ifstream file("outfile.txt");
    if (!file.is_open())
    {
        std::cerr << "File can not be opened\n";
        return 1;
    }

    while (getline(file, str))
    {
        std::cout << "Source string: " << str << "\n";
        std::cout << "Amount of different symbols: " << countingLChars(str) << "\n";
    }
    file.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cctype>

//ВАРИАНТ 13
//Проверить, есть ли в двух заданных строках одинаковые символы.
//Функция должна возвращать true, если есть одинаковые символы, false – в противном случае

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void outArray(char* array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i];
	}
	std::cout << std::flush << std::endl;
}

bool isSameСhar(char* cStyle_array, char* cStyle_array2)//одинаковые символы есть?
{
	for (int i = 0; cStyle_array[i] != '\0'; i++)
	{
		for (int j = 0; j < cStyle_array2[j] != '\0'; j++)
		{
			if (cStyle_array[i] == cStyle_array2[j])
			{
				return true;
			}
		}
	}
	return false;

}

bool isSameСhar(std::string& str, std::string& str2)//одинаковые символы есть?
{
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (str[i] == str2[j])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "");

	//C-style
	int size_of_cStyle;
	int size_of_cStyle2;

	try
	{
		std::ifstream stringsfile("strings.txt");

		if (!stringsfile)
		{
			throw std::exception("Файл не открыт!");
			return 1;
		}
		if (isEmpty(stringsfile))// файл пуст
		{
			throw std::exception("Файл пуст!");
			return 1;
		}

		while (!stringsfile.eof())// пробегаем пока не встретим конец файла eof
		{
			//--------------------1-----------------------------------------------
			stringsfile >> size_of_cStyle;
			if ( size_of_cStyle <= 0)
			{
				throw std::exception("Неверно указана длина строки");
				return 1;
			}

			size_of_cStyle++;
			char* cStyle_array = new char[size_of_cStyle];
			

			stringsfile.ignore(size_of_cStyle, '\n');
			stringsfile.get(cStyle_array, size_of_cStyle);
			for (int i = 0; i < size_of_cStyle - 1; i++)
			{
				if (cStyle_array[i] == '\0')
				{
					throw std::exception("Неверно указана длина строки");
					return 1;
				}
			}

			//--------------------2-----------------------------------------------
			stringsfile >> size_of_cStyle2;
			if (size_of_cStyle2 <= 0)
			{
				throw std::exception("Память не может быть выделена!");
				return 1;
			}
			size_of_cStyle2++;
			char* cStyle_array2 = new char[size_of_cStyle2];

			stringsfile.ignore(size_of_cStyle2, '\n');
			stringsfile.get(cStyle_array2, size_of_cStyle2);
			for (int i = 0; i < size_of_cStyle2 - 1; i++)
			{
				if (cStyle_array2[i] == '\0')
				{
					throw std::exception("Неверно указана длина строки");
					return 1;
				}
			}

			//----------------------строки-----------------------------

			std::cout << "МАССИВ 1: ";
			outArray(cStyle_array, size_of_cStyle);
			std::cout << "МАССИВ 2: ";
			outArray(cStyle_array2, size_of_cStyle2);
			std::cout << "Есть одинаковые элементы? " << isSameСhar(cStyle_array, cStyle_array2) << std::endl;
			std::cout << "-----------------------------------------------------------------------" << std::endl;
			std::string str = std::string(cStyle_array, size_of_cStyle);
			std::string str2 = std::string(cStyle_array2, size_of_cStyle2);

			std::cout << "СТРОКА 1: " << str << std::endl;
			std::cout << "СТРОКА 2: " << str2 << std::endl;
			std::cout << "Есть одинаковые элементы в строке? " << isSameСhar(str, str2) << std::endl;

			std::cout << "-----------------------------------------------------------------------" << std::endl;
			delete[] cStyle_array;
			delete[] cStyle_array2;
		}
		stringsfile.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

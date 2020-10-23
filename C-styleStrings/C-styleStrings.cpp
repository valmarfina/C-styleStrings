#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

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

bool isSameСhar(char* cStyle_array, const int size)//одинаковые символы есть?
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (cStyle_array[i] == cStyle_array[j])
			{
				return true;
			}
		}
	}
	return false;
}

bool isSameСhar(std::string &str)//одинаковые символы есть?
{
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i + 1; j < str.size(); j++)
		{
			if (str[i] == str[j])
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
		stringsfile >> size_of_cStyle;
		while (!stringsfile.eof())// пробегаем пока не встретим конец файла eof
		{

			if (size_of_cStyle <= 0)
			{
				throw std::exception("Память не может быть выделена!");
				return 1;
			}

			char* cStyle_array = new char[size_of_cStyle + 1];

			for (int i = 0; i < size_of_cStyle; i++)
			{
				stringsfile >> cStyle_array[i];
			}
			std::cout << "Вывод массива: - ";
			outArray(cStyle_array, size_of_cStyle);
			std::cout << "Есть одинаковые элементы? " << isSameСhar(cStyle_array, size_of_cStyle) << std::endl;

			std::string str = std::string(cStyle_array, size_of_cStyle);
			std::cout << "Вывод строки: - " << str << std::endl;
			std::cout << "Есть одинаковые элементы в строке? " << isSameСhar(str) << std::endl;

			delete[] cStyle_array;

			stringsfile >> size_of_cStyle;
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

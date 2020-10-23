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

int main()
{
	setlocale(LC_ALL, "");

	//C-style
	int size_of_cStyle = 1;

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
		stringsfile >> size_of_cStyle;

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

		delete[] cStyle_array;
	}
	stringsfile.close();

	return 0;
}

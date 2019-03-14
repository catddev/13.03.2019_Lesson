#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;
// Sourse.cpp на верху экрана вкладка - правая кнопка мыши - открыть содержащую папку - там все файлы

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			char str[20][50]; // 20 rows, 50 symbols maximum
			// error: str[0]="Hello"
			strcpy_s(str[0], "Hello");

			cout << str[0] << endl;
		}
		break;
		case 2:
			// 3. Дан массив строк. Записать их в файл, расположив каждый элемент массива на отдельной строке с сохранением порядка.
		{
			ofstream out_file("out.txt");
			char str[20][50];
			int n;
			cin >> n;
			cin.ignore(); //если cin перед cin.getline между ними обязтально ставить cin.ignore
			for (int i = 0; i < n; i++)
			{
				cin.getline(str[i], 50);
			}
			for (int i = 0; i < n; i++)
			{
				out_file << str[i] << endl;
			}
			out_file.close();
		}
		break;
		case 3:
			// 4. В конец существующего текстового файла записать строку с текстом «До свиданья люди!»
		{
			ofstream out_file("out.txt", ios::app); //append - в конец файла прикрепилась новая строка
			
			out_file << "До свидания, люди!" << endl;
		}
		break;
		case 4:
			// Дан текстовый файл. Подсчитать количество символов в нём.
		{
			ifstream in_file("out.txt");
			int k = 0;
			char ch;

			/*if (!out_file)
				cerr << "file open error" << endl;
			else*/
				while(in_file.get(ch)) // get считывает все символы подряд, и пробелы и энтеры
					k++;
			cout << k << endl;

			// Дан текстовый файл. Подсчитать количество символов - только видимых!

			//in_file.seekg(0);
			// раз seekget не работает, то надо закрыть и заново открыть файл, тогда курсор будет снова в начале файла
			in_file.close();
			in_file.open("out.txt");
			k = 0;
			while (in_file >> ch) // оператор ввода будет считывать только видимые
				k++;
			cout << k << endl;
		}
		break;
		case 5: //Дан текстовый файл. Подсчитать количество строк в нём.
		{
			ifstream in_file("out.txt");
			char buffer[50];
			int k = 0;
			while (in_file.getline(buffer, 50)) // считывает только строки, 50 - максимальное количество СИМВОЛОВ в строке (а не строк), но не обязательное количество
				k++;
			cout << k << endl;

			//Дан текстовый файл. Удалить из него последнюю строку. Результат записать в другой файл.
			in_file.close();
			in_file.open("out.txt");

			ofstream out_file("in.txt");
			for (int i = 0; i < k - 1; i++)
			{
				in_file.getline(buffer, 50);
				out_file << buffer << endl;
			}
		}
		break;
		case 6: 
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}

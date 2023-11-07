#include <fstream>
#include <iostream>

using namespace std;

int main()
{

	// Создание выходного файлового потока и связывание с ним файла, который открывается на чтение в текстовом режиме 
	// (файл должен существовать).
	ifstream in("index.html", ios::in);
	// char character;
	int openingTags = 0;
	int closingTags = 0;
	

	if (in) { // Если файл удалось открыть.

		do {

			char character = '\0';
			// Считывание текстовой информации из входного потока посимвольно.
			in.get(character);
			if (character == '<') {
				openingTags++;
			}
			else if (character == '>') {
				closingTags++;
			}

		} while (in); // Цикл продолжается до тех пор, пока не наступит конец файла.
		cout << "Count of < : " << openingTags << endl;
		cout << "Count of > : " << closingTags << endl;

		if (openingTags == closingTags) {
			cout << "All is good!" << endl;
		}
		else if (openingTags > closingTags) {
			cout << "Incorrect file. Count of incorrent tags: " << openingTags - closingTags << endl;
		}
		else if (openingTags < closingTags) {
			cout << "Incorrect file. Count of incorrent tags: " << closingTags - openingTags << endl;
		}


		// Закрытие файловых потоков.
		in.close();
	}
	else
	{
		cout << "Could not open the file" << endl;
	}

	return 0;
}
//
//int main()
//{
//    // Создание выходного файлового потока и связывание с ним файла, который открывается на запись в текстовом режиме.
//    ofstream out;
//    out.open("NewReadMe.txt", ios::out | ios::trunc);
//
//    // Создание выходного файлового потока и связывание с ним файла, который открывается на чтение в текстовом режиме 
//    // (файл должен существовать).
//    ifstream in;
//    in.open("ReadMe.txt", ios::in);
//
//    // Если файл удалось открыть.
//    if (in)
//    {
//        do
//        {
//            char character = '\0';
//
//            // Считывание текстовой информации из входного потока посимвольно.
//            in.get(character);
//
//            // Вывод считанного символа на экран.
//            cout << character;
//
//            // Запись считанного символа в выходной поток.
//            out.put(character);
//        }
//        // Цикл продолжается до тех пор, пока не наступит конец файла.
//        while (in);
//
//        // Закрытие файловых потоков.
//        out.close();
//        in.close();
//    }
//    else
//    {
//        cout << "Could not open the file" << endl;
//    }
//
//    return 0;
//}
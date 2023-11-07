#include <fstream>
#include <iostream>

using namespace std;

int main()
{

	// �������� ��������� ��������� ������ � ���������� � ��� �����, ������� ����������� �� ������ � ��������� ������ 
	// (���� ������ ������������).
	ifstream in("index.html", ios::in);
	// char character;
	int openingTags = 0;
	int closingTags = 0;
	

	if (in) { // ���� ���� ������� �������.

		do {

			char character = '\0';
			// ���������� ��������� ���������� �� �������� ������ �����������.
			in.get(character);
			if (character == '<') {
				openingTags++;
			}
			else if (character == '>') {
				closingTags++;
			}

		} while (in); // ���� ������������ �� ��� ���, ���� �� �������� ����� �����.
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


		// �������� �������� �������.
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
//    // �������� ��������� ��������� ������ � ���������� � ��� �����, ������� ����������� �� ������ � ��������� ������.
//    ofstream out;
//    out.open("NewReadMe.txt", ios::out | ios::trunc);
//
//    // �������� ��������� ��������� ������ � ���������� � ��� �����, ������� ����������� �� ������ � ��������� ������ 
//    // (���� ������ ������������).
//    ifstream in;
//    in.open("ReadMe.txt", ios::in);
//
//    // ���� ���� ������� �������.
//    if (in)
//    {
//        do
//        {
//            char character = '\0';
//
//            // ���������� ��������� ���������� �� �������� ������ �����������.
//            in.get(character);
//
//            // ����� ���������� ������� �� �����.
//            cout << character;
//
//            // ������ ���������� ������� � �������� �����.
//            out.put(character);
//        }
//        // ���� ������������ �� ��� ���, ���� �� �������� ����� �����.
//        while (in);
//
//        // �������� �������� �������.
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
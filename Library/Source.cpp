#include "list.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void welcome(); //welcome message
void menu(); //menu of choices
void credits();
void system(); //console settings
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {

	system();
	welcome();

	list l;

	int choice = 0, serial = 0, after_serial = 0;
	string title, author;

	while (choice != 10)
	{
		menu();

		cin >> choice;
		cout << "\n";
		system("color 73");
		switch (choice)
		{
		case 1:
			l.add_book(serial, title, author);
			break;

		case 2:
			l.insert_book(after_serial, serial, title, author);
			break;

		case 3:
			l.delete_serial(serial);
			break;

		case 4:
			l.delete_title(title);
			break;

		case 5:
			l.search_serial(serial);
			break;

		case 6:
			l.search_title(title);
			break;

		case 7:
			l.sort();
			break;

		case 8:
			l.display();
			break;

		case 9:
			credits();
			break;

		case 10:
			SetConsoleTextAttribute(h, 55);
			break;

		default:
			cout << "Invalid Choice\n\n";
			Sleep(2000);
			system("cls");
			break;
		}
	}
	system("Pause");

	return 0;
}

void system()
{
	system("mode con COLS=650"); //to make console fullscreen
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleTitle("Linked List Project"); //to change title of console
	system("color 73");//to change color of console
}

void welcome()
{

	SetConsoleTextAttribute(h, 113);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t********************************" << endl;
	cout << "\t\t\t\t\t\t\t\t*    Welcome to Our Library!   *" << endl;
	cout << "\t\t\t\t\t\t\t\t********************************" << endl;
	PlaySound(TEXT("welcome.wav"), NULL, SND_SYNC);	
	Sleep(1000);
	system("cls");
}

void menu() {

	SetConsoleTextAttribute(h, 116);

	cout << endl;
	cout << " Menu: Select your option\n\n";
	cout << "	1.  Add New Book\t\t     ";
	cout << "   2. Insert a Book\n\n";
	cout << "	3. Delete a Book by serial number";
	cout << "	4. Delete a Book by title\n\n";
	cout << "	5. Search for a Book by serial \t";
	cout << "	6. Search for a Book by title \n\n";
	cout << "	7. Sort all Books by title \t";
	cout << "	8. Display all Books \n\n";
	cout << "	9. Credits\t\t\t     ";
	cout << "   10. Exit\n\n";
	cout << "Enter your Choice : ";
	PlaySound(TEXT("option.wav"), NULL, SND_SYNC);
}

void credits()
{
	system("CLS");
	SetConsoleTextAttribute(h, 117);

	cout << "\t\t\t\t\t\t\t\t*****************\n";
	cout << "\t\t\t\t\t\t\t\t     Credits\n";
	cout << "\t\t\t\t\t\t\t\t*****************\n\n";

	cout << "\n  Farah Ahmed\n";
	Sleep(500);
	cout << "\n  Fares Gaber\n";
	Sleep(500);
	cout << "\n  Amira Assem\n";
	Sleep(500);
	cout << "\n  Aya Mohamed\n";
	Sleep(500);
	cout << "\n  Seif Allah Khaled\n";
	Sleep(500);
	cout << "\n  Shrouq Abd El-monem\n";

	Sleep(3000);
	system("CLS");
}
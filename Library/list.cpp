#include "list.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//global
list::list() {
	head = NULL;
	tail = NULL;
}

//add a book at the end of the list
void list::add_book(int serial, string title, string author) {
	system("CLS");

	cout << "\t\t\t\t\t\t\t\t***********************************\n";
	cout << "\t\t\t\t\t\t\t\t     Add a New Book to Library\n";
	cout << "\t\t\t\t\t\t\t\t***********************************\n\n";

	//input
	cout << " Enter Serial Number: ";
	cin >> serial;
	cout << "\n";
	cout << " Enter the Title : ";
	cin.ignore();
	getline(cin, title);
	cout << "\n";
	cout << " Enter the Author: ";
	getline(cin, author);
	cout << "\n";

	//processing
	nodePtr tmp = new node;
	tmp->serial = serial;
	tmp->title = title;
	tmp->author = author;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}

	//output
	cout << endl;
	cout << "*******************************************************\n\n";
	cout << "  You added a Book with\n";
	cout << "  Serial Number : " << tmp->serial << endl;
	cout << "  Its Title : " << tmp->title << endl;
	cout << "  Its Author : " << tmp->author << endl;
	cout << "\n*******************************************************\n";

	PlaySound(TEXT("added.wav"), NULL, SND_SYNC);
	Sleep(1000);
	system("CLS");

}

//insert a book after any serial you want
void list::insert_book(int after_serial, int serial, string title, string author) {
	system("CLS");

	cout << "\t\t\t\t\t\t\t\t**************************************\n";
	cout << "\t\t\t\t\t\t\t\t     Insert a New Book to Library\n";
	cout << "\t\t\t\t\t\t\t\t**************************************\n\n";

	//input
	cout << " Enter the Serial number of the book you want to insert after : ";
	cin >> after_serial;
	cout << "\n";
	cout << " Enter Serial Number : ";
	cin >> serial;
	cout << "\n";
	cout << " Enter the Title : ";
	cin.ignore();
	getline(cin, title);
	cout << "\n";
	cout << " Enter the Author : ";
	getline(cin, author);
	cout << "\n";

	//processing
	nodePtr tmp = head;
	nodePtr b = new node;

	while (tmp != NULL)
	{
		if (tmp->serial == after_serial)
		{
			b->next = tmp->next;
			tmp->next = b;
			break;
		}
		tmp = tmp->next;
	}

	if (b->next == NULL)
		tail = b;

	b->title = title;
	b->author = author;
	b->serial = serial;

	//output
	cout << endl;
	cout << "*******************************************************\n\n";
	cout << "  You inserted a Book with\n";
	cout << "  Serial Number : " << b->serial << endl;
	cout << "  Its Title : " << b->title << endl;
	cout << "  Its Author : " << b->author << endl;
	cout << "\n*******************************************************" << endl;

	PlaySound(TEXT("inserted.wav"), NULL, SND_SYNC);
	system("CLS");
}

//delete any book by its serial
void list::delete_serial(int serial) {
	system("CLS");

	//input
	cout << "\t\t\t\t\t\t\t\t****************************************\n";
	cout << "\t\t\t\t\t\t\t\t     Delete a Book from the Library\n";
	cout << "\t\t\t\t\t\t\t\t****************************************\n\n";
	cout << " Enter Serial Number : ";
	cin >> serial;
	cout << "\n";

	//processing
	nodePtr tmp = head;
	nodePtr del = new node;
	bool IsFound = false;

	while (tmp != NULL)
	{
		if (tmp->serial == serial)
		{
			IsFound = true;
			break;
		}
		tmp = tmp->next;
	}
	if (IsFound)
	{

		tmp = head;

		if (head->serial == serial)
		{
			del = head;
			head = head->next;
			delete del;
		}

		else
		{

			while (tmp != NULL)
			{
				if (tmp->next->serial == serial)
					break;

				tmp = tmp->next;
			}

			del = tmp->next;

			if (del->next != NULL)
				tmp->next = del->next;

			else
			{
				tmp->next = NULL;
				tail = tmp;
			}

			delete del;
		}

		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with Serial Number " << serial << " has been deleted\n";
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("delete.wav"), NULL, SND_SYNC);
	}
	else
	{
		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with Serial Number " << serial << " wasn't found\n";
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("not found.wav"), NULL, SND_SYNC);
	}

	system("CLS");
}

//delete any book by its title

void list::delete_title(string title) {
	system("CLS");

	//input
	cout << "\t\t\t\t\t\t\t\t****************************************\n";
	cout << "\t\t\t\t\t\t\t\t     Delete a Book from the Library\n";
	cout << "\t\t\t\t\t\t\t\t****************************************\n\n";
	cout << " Enter the Title : ";
	cin.ignore();
	getline(cin, title);
	cout << "\n";

	//processing
	nodePtr tmp = head;
	nodePtr del = new node;
	bool IsFound = false;

	while (tmp != NULL)
	{
		if (tmp->title == title)
		{
			IsFound = true;
			break;
		}
		tmp = tmp->next;
	}
	if (IsFound)
	{

		tmp = head;

		if (head->title == title)
		{
			del = head;
			head = head->next;
			delete del;
		}
		else
		{

			while (tmp != NULL)
			{
				if (tmp->next->title == title)
					break;

				tmp = tmp->next;
			}

			del = tmp->next;

			if (del->next != NULL)
				tmp->next = del->next;

			else
			{
				tmp->next = NULL;
				tail = tmp;
			}

			delete del;

		}

		//output
		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with title " << title << " has been deleted\n";
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("delete.wav"), NULL, SND_SYNC);
	}
	else {
		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with title " << title << " wasn't found\n";
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("not found.wav"), NULL, SND_SYNC);
	}

	system("CLS");
}

//search any book by its serial
void list::search_serial(int serial) {
	system("CLS");

	//input
	cout << "\t\t\t\t\t\t\t\t********************************************\n";
	cout << "\t\t\t\t\t\t\t\t     Search for a Book in the Library\n";
	cout << "\t\t\t\t\t\t\t\t********************************************\n\n";
	cout << " Enter Serial Number : ";
	cin >> serial;

	//processing
	nodePtr tmp = head;
	bool IsFound = false;
	while (tmp != NULL)
	{
		if (tmp->serial == serial)
		{
			IsFound = true;
			break;
		}
		tmp = tmp->next;
	}

	//output
	if (IsFound)
	{
		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with Serial Number : " << serial << " has been found" << endl;
		cout << "  Its Title : " << tmp->title << endl;
		cout << "  Its Author : " << tmp->author << endl;
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("found.wav"), NULL, SND_SYNC);
		Sleep(2000);
	}

	else
	{
		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with a serial " << serial << " wasn't found\n";
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("not found.wav"), NULL, SND_SYNC);
	}

	system("CLS");
}

//search any book by its title
void list::search_title(string title) {
	system("CLS");

	//input
	cout << "\t\t\t\t\t\t\t\t********************************************\n";
	cout << "\t\t\t\t\t\t\t\t     Search for a Book in the Library\n";
	cout << "\t\t\t\t\t\t\t\t********************************************\n\n";
	cout << " Enter the Title : ";
	cin.ignore();
	getline(cin, title);


	//processing
	nodePtr tmp = head;
	bool IsFound = false;
	while (tmp != NULL)
	{
		if (tmp->title == title)
		{
			IsFound = true;
			break;
		}
		tmp = tmp->next;
	}

	//output
	if (IsFound)
	{
		cout << endl;
		cout << "************************************************************\n";
		cout << "  A book with Title " << title << " has been found" << endl;
		cout << "  Its Serial Number : " << tmp->serial << endl;
		cout << "  Its Author : " << tmp->author << endl;
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("found.wav"), NULL, SND_SYNC);
		Sleep(1000);
	}
	else
	{
		cout << endl;
		cout << "*****************************************************************" << endl;
		cout << "  A book with a title " << title << " wasn't found\n";
		cout << "*****************************************************************" << endl;
		PlaySound(TEXT("not found.wav"), NULL, SND_SYNC);
	}

	system("CLS");
}

//sort list in alphapetical order
void list::sort() {
	system("CLS");

	cout << "\t\t\t\t\t\t\t\t***********************************\n";
	cout << "\t\t\t\t\t\t\t\t     Sorted Books in the Library\n";
	cout << "\t\t\t\t\t\t\t\t***********************************\n\n";

	bool swapped = false;
	nodePtr tmp = head;
	nodePtr tmp2 = tmp->next;

	while (tmp2 != NULL)
	{
		if (tmp->title > tmp2->title)
		{
			swap(tmp->title, tmp2->title);
			swap(tmp->author, tmp2->author);
			swap(tmp->serial, tmp2->serial);
			swapped = true;
		}
		if (swapped)
		{
			tmp = head;
			tmp2 = tmp->next;
			swapped = false;
		}
		else
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}

	//output
	tmp = head;
	int i = 1;
	while (tmp != NULL)
	{
		cout << "** Book Number " << i << " **" << endl;
		cout << "*******************************************************\n\n";
		cout << "  The serial of  the  book is : " << tmp->serial << endl;
		cout << "  The title of the book is : " << tmp->title << endl;
		cout << "  The author of the book is : " << tmp->author << endl;
		cout << "\n*******************************************************" << endl;
		cout << "\n\n";
		tmp = tmp->next;
		i++;
	}

	PlaySound(TEXT("sorted.wav"), NULL, SND_SYNC);
	Sleep(5000);
	system("CLS");
}

//display the list
void list::display() {
	system("CLS");

	cout << "\t\t\t\t\t\t\t\t*************************************\n";
	cout << "\t\t\t\t\t\t\t\t   Display all Books in the Library\n";
	cout << "\t\t\t\t\t\t\t\t*************************************\n\n";

	nodePtr tmp = head;
	int i = 1;

	while (tmp != NULL)
	{
		cout << "** Book Number " << i << " **" << endl;
		cout << "*******************************************************\n\n";
		cout << "  The serial of  the  book is : " << tmp->serial << endl;
		cout << "  The title of the book is : " << tmp->title << endl;
		cout << "  The author of the book is : " << tmp->author << endl;
		cout << "\n*******************************************************" << endl;
		cout << "\n\n";
		tmp = tmp->next;
		i++;
	}

	PlaySound(TEXT("display.wav"), NULL, SND_SYNC);

	cout << "** Total Books in the library are : " << i - 1 << " **" << endl;

	Sleep(3000);
	system("CLS");
}
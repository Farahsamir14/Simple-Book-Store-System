#ifndef list_H
#define list_H
#include <string>

class list
{
private:

	/*
	typedef struct instead of doing:
	node *nodePtr = head;
	we do:
	nodePtr head
	*/
	typedef struct node {
		int serial;
		std::string title;
		std::string author;
		node *next;
	} *nodePtr;

	nodePtr head, tail;

public: //This is where functions go
	list();
	void add_book(int serial, std::string title, std::string author);
	void insert_book(int after_serial, int serial, std::string title, std::string author);
	void delete_serial(int serial);
	void delete_title(std::string title);
	void search_title(std::string title);
	void search_serial(int serial);
	void sort();
	void display();
};

#endif
#pragma once

#include"Book.h"
#include<iostream>
#include"MyList.h"
#include"BorrowRecord.h"
using namespace std;

class Student
{
private:
	string studentId;
	string name;
public:
	Student(string studentId, string name) :studentId(studentId), name(name) {}
	void setName(string name) {
		this->name = name;
	}
	string getId() {
		return this->studentId;
	}
	string getName() {
		return this->name;
	}
	void display() {
		cout << this->studentId << "\t" << this->name << endl;
	}
	MyList<BorrowRecord> allRecord(MyList<BorrowRecord> recordList) {

	}
	void borrowBook(MyList<Book> &bookList,MyList<BorrowRecord> &recordList, string bookId) {
		Book book=bookList.search(bookId);
		book.changeStatus();
		bookList.modified(book);
		BorrowRecord record(bookId, studentId);
		recordList.add(record);
	}
	void sendBack(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, string recordId) {
		BorrowRecord record = recordList.search(recordId);
		string bookId = record.getBookId();
		Book book = bookList.search(bookId);
		book.changeStatus();
		record.changeStatus();
		bookList.modified(book);
		recordList.modified(record);

	}
};


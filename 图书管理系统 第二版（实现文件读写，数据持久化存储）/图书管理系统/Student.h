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
	Student(char* str) {
		this->studentId = strtok(str, "\t");
		this->name = strtok(NULL, "\t");
	}
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
		cout << this->toString()<<endl;
	}
	string toString(){
		return this->studentId + "\t" + this->name;
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


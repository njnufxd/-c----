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
	string password;
	MyList<BorrowRecord> recordList;
public:
	void init(MyList<BorrowRecord> &recordList) {
		Node<BorrowRecord>* pmove = recordList.head;
		while (pmove) {
			BorrowRecord* it = pmove->getDate();
			if (it->getStudentId()._Equal(this->studentId)) {
				this->recordList.add(*it);
			}
			pmove = pmove->next;
		}
	}
	Student(string studentId, string name,string password) :studentId(studentId), name(name),password(password) {}
	Student(char* str) {
		this->studentId = strtok(str, "\t");
		this->name = strtok(NULL, "\t");
		this->password = strtok(NULL, "\n");
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
	void setPassword(string password) {
		this->password = password;
	}
	string getPassword() {
		return this->password;
	}
	void display() {
		cout << this->studentId + "\t" + this->name <<endl;
	}
	string toString(){
		return this->studentId + "\t" + this->name+"\t"+this->password;
	}
	void borrowBook(MyList<Book> &bookList,MyList<BorrowRecord> &recordList, string bookId) {
		Book* book=bookList.search(bookId);
		book->changeStatus();
		bookList.modified(*book);
		BorrowRecord record(bookId, studentId);
		recordList.add(record);
	}
	void sendBack(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, string recordId) {
		BorrowRecord* record = recordList.search(recordId);
		string bookId = record->getBookId();
		Book* book = bookList.search(bookId);
		book->changeStatus();
		record->changeStatus();
		bookList.modified(*book);
		recordList.modified(*record);
	}
	MyList<BorrowRecord>* getRecordList() {
		return &(this->recordList);
	}
};


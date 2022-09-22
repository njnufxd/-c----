#pragma once
#include<iostream>
#include<sstream>
#include"Time.h"
using namespace std;
class BorrowRecord
{
private:
	static int count;
	string recordId;
	string bookId;
	string studentId;
	Time borrowTime;
	int status;//0��ʾδ����1��ʾ�ѻ���
public:	

	BorrowRecord(string bookId, string studentId) :bookId(bookId), studentId(studentId),borrowTime(Time()), status(0) {
		count++;
		stringstream ss;
		ss << count;
		ss >> recordId;
	}
	void display() {
		cout <<recordId<<"\t" << bookId << "\t" << studentId << "\t"<<borrowTime.toString()<<"\t";
		if (status == 0) {
			cout << "δ��" << endl;
		}
		else {
			cout << "�ѻ�" << endl;
		}
	}
	string getId() {
		return this->recordId;
	}
	string getBookId() {
		return this->bookId;
	}
	void setBookId(string bookId) {
		this->bookId = bookId;
	}
	string getStudentId() {
		return this->studentId;
	}
	void changeStatus() {
		if (this->status == 0) {
			this->status = 1;
		}
	}

};


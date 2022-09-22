#define _CRT_SECURE_NO_WARNINGS 1
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
	BorrowRecord(char* str) {
		this->recordId = strtok(str, "\t");
		this->bookId = strtok(NULL, "\t");
		this->studentId = strtok(NULL, "\t");
		char* borrowTime = strtok(NULL, "\t");
		string status = strtok(NULL, "\n");
		this->borrowTime = Time(borrowTime);
		if (status._Equal("�ѻ�")) {
			this->status = 1;
		}
		else {
			this->status = 0;
		}
	}
	void display() {
		cout << this->toString()<<endl;
	}
	string toString() {
		string str;
		if (this->status == 0) {
			str = "δ��";
		}
		else {
			str = "�ѻ�";
		}
		return this->recordId + "\t" + this->bookId + "\t" + this->studentId + "\t" + borrowTime.toString() + "\t" + str;
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


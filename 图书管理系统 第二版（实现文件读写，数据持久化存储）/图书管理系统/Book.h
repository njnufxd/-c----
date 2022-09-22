#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
class Book
{
private:
	string id;
	string name;
	string type;
	int status;//1表示可借阅，0表示不可借阅。
public:
	Book() :status(1) {}
	Book(string id, string name, string type) :id(id), name(name), type(type), status(1) {}
	Book(char* str) {
		this->id = strtok(str, "\t");
		this->name = strtok(NULL, "\t");
		this->type = strtok(NULL, "\t");
		string status = strtok(NULL, "\n");
		if (status._Equal("可借阅")) {
			this->status = 1;
		}
		else {
			this->status = 0;
		}
	}
	string getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getType() {
		return this->type;
	}
	int getStatus() {
		return this->status;
	}
	void setId(string id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setType(string type) {
		this->type = type;
	}
	void changeStatus() {
		if (this->status == 0) {
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
		if (this->status == 1) {
			str = "可借阅";
		}
		else {
			str = "已借出";
		}
		return this->id + "\t" + this->name + "\t" + this->type + "\t" + str ;
	}
};


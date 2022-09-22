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
		cout << this->id << "\t" << this->name << "\t" << this->type << "\t";
		if (status == 0) {
			cout << "已借出" << endl;
		}
		else {
			cout << "可借阅" << endl;
		}
	}
};


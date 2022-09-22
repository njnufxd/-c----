#pragma once
#include<iostream>
#include<sstream>
#include"Node.h"
using namespace std;
template<class T>
class MyList
{
private:
	int size = 0;
public:
	string title;
	Node<T>* head;
	Node<T>* tail = head;
	MyList<T>() :head(NULL), tail(NULL) {

	}
	MyList<T>(T t) {
		Node<T>* node = new Node<T>(t);
		this->head = node;
		this->tail = node;
	}
	bool add(T& t) {
		Node<T>* node = new Node<T>(t);
		Node<T>* pmove = head;
		while (pmove) {
			if (t.getId()._Equal(pmove->getDate().getId())) {
				cout << "唯一id已存在，请重新输入id！" << endl;
				return false;
			}
			pmove = pmove->next;
		}
		if (size == 0) {
			head = node;
			tail = head;
		}
		else {
			tail->next = node;
			node->pre = tail;
			tail = node;
		}
		size++;
		return true;
	}

	void display() {
		Node<T>* pmove = head;
		while (pmove) {
			pmove->getDate().display();
			pmove = pmove->next;
		}
	}
	T search(string id) {
		Node<T>* pmove = head;
		while (pmove) {
			if (pmove->getDate().getId()._Equal(id)) {
				return pmove->getDate();
			}
			pmove = pmove->next;
		}
	}
	void modified(T t) {
		Node<T>* pmove = head;
		while (pmove) {
			if (pmove->getDate().getId()._Equal(t.getId())) {
				pmove->setDate(t);
				return;
			}
			pmove=pmove->next;
		}
	}
	void del(string id) {
		Node<T>* pmove = head;
		while (pmove) {
			if (pmove->getDate().getId()._Equal(id)) {
				pmove->pre->next = pmove->next;
				pmove->next->pre = pmove->pre;
				delete pmove;
				return;
			}
			pmove = pmove->next;
		}
	}
	void save(string fileName) {
		fstream file;
		file.open(fileName, ios::out);
		Node<T>* pmove = head;
		while (pmove) {
			if (!pmove->next) {
				file << pmove->getDate().toString();
			}
			else {
				file << pmove->getDate().toString() << endl;
			}
			pmove = pmove->next;
		}
	}
};


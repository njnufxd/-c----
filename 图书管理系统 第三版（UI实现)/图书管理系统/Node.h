#pragma once
#include<string.h>
#include<iostream>
using namespace std;
template<class T>
class Node
{
private:
	T t;
public:
	Node* next=NULL;
	Node* pre=NULL;
	Node(T t) :t(t) {

	}
	void setDate(T t) {
		this->t = t;
	}
	T* getDate() {
		return &(this->t);
	}

};

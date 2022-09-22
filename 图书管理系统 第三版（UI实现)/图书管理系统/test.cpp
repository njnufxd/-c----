#define _CRT_SECURE_NO_WARNINGS 1
#include"Student.h"
#include<fstream>
using namespace std;
//项目启动初始化原始数据，导入三张表中数据
static void init(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	char str[256];  
	fstream file1,file2,file3;
	file1.open("book.txt", ios::in);//书目库
	while (!file1.eof())
	{
		file1.getline(str, 256, '\n');
		if (str == "\n") {
			break;
		}
		Book book(str);
		bookList.add(book);
	}
	file1.close();
	file2.open("student.txt", ios::in);//学生信息库
	while (!file2.eof())
	{
		file2.getline(str, 256, '\n');
		Student student(str);
		studentList.add(student);
	}
	file3.open("borrowRecord.txt", ios::in);//借阅记录库
	while (!file3.eof())
	{
		file3.getline(str, 256, '\n');
		if (str == "\n") {
			break;
		}
		BorrowRecord record(str);
		recordList.add(record);
	}
	Node<Student>* pmove = studentList.head;
	while (pmove) {
		pmove->getDate()->init(recordList);
		pmove = pmove->next;
	}
}
//保存数据，写入文件，实现数据持久化存储。
static void save(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	bookList.save("book.txt");
	studentList.save("student.txt");
	recordList.save("borrowRecord.txt");
}
static void test(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	/*
	学生信息表测试
	-----------------------------------
	Student s1("001", "test");
	Student s2("002", "test");
	Student s3("003", "test");
	studentList.add(s1);
	studentList.add(s2);
	studentList.add(s3);
	studentList.display();
	-----------------------------------
	*/
	/*
	图书信息表测试
	-----------------------------------
	Book b1("001", "test", "文学");
	Book b2("002", "test", "插画书");
	Book b3("003", "test", "杂志");
	bookList.add(b1);
	bookList.add(b2);
	bookList.add(b3);
	bookList.display();
	-----------------------------------
	*/
	/*
	借阅记录表测试
	-----------------------------------
	BorrowRecord r1("001", "001");
	BorrowRecord r2("002", "002");
	BorrowRecord r3("003", "003");
	borrowRecordList.add(r1);
	borrowRecordList.add(r2);
	borrowRecordList.add(r3);
	borrowRecordList.display();
	-----------------------------------
	*/
	/*
	学生借书还书测试
	-----------------------------------
	s1.borrowBook(bookList, borrowRecordList, "001");
	bookList.display();
	borrowRecordList.display();
	s1.sendBack(bookList, borrowRecordList, "1");
	borrowRecordList.display();
	bookList.display();
	-----------------------------------
	*/
	/*
	初始化测试
	-----------------------------------
	init(bookList, studentList, recordList);
	bookList.display();
	studentList.display();
	recordList.display();
	save(bookList,studentList,recordList);
	-----------------------------------
	*/

}

#include"Student.h"
using namespace std;


static void test() {
	/*
	学生信息表测试
	-----------------------------------*/
	MyList<Student> studentList;
	Student s1("001", "test");
	Student s2("002", "test");
	Student s3("003", "test");
	studentList.add(s1);
	studentList.add(s2);
	studentList.add(s3);
	studentList.display();/*
	-----------------------------------
	*/
	/*
	图书信息表测试
	-----------------------------------*/
	MyList<Book> bookList;
	Book b1("001", "test", "文学");
	Book b2("002", "test", "插画书");
	Book b3("003", "test", "杂志");
	bookList.add(b1);
	bookList.add(b2);
	bookList.add(b3);
	bookList.display();/*
	-----------------------------------
	*/
	/*
	借阅记录表测试
	-----------------------------------*/
	
	MyList<BorrowRecord> borrowRecordList;/*
	BorrowRecord r1("001", "001");
	BorrowRecord r2("002", "002");
	BorrowRecord r3("003", "003");
	borrowRecordList.add(r1);
	borrowRecordList.add(r2);
	borrowRecordList.add(r3);
	borrowRecordList.display();*//*
	-----------------------------------
*/
	s1.borrowBook(bookList,borrowRecordList,"001");
	bookList.display();
	borrowRecordList.display();
	s1.sendBack(bookList, borrowRecordList, "1");
	borrowRecordList.display();
	bookList.display();
}
#define _CRT_SECURE_NO_WARNINGS 1
#include"Student.h"
#include<fstream>
using namespace std;
//��Ŀ������ʼ��ԭʼ���ݣ��������ű�������
static void init(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	char str[256];  
	fstream file1,file2,file3;
	file1.open("book.txt", ios::in);//��Ŀ��
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
	file2.open("student.txt", ios::in);//ѧ����Ϣ��
	while (!file2.eof())
	{
		file2.getline(str, 256, '\n');
		Student student(str);
		studentList.add(student);
	}
	file3.open("borrowRecord.txt", ios::in);//���ļ�¼��
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
//�������ݣ�д���ļ���ʵ�����ݳ־û��洢��
static void save(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	bookList.save("book.txt");
	studentList.save("student.txt");
	recordList.save("borrowRecord.txt");
}
static void test(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	/*
	ѧ����Ϣ�����
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
	ͼ����Ϣ�����
	-----------------------------------
	Book b1("001", "test", "��ѧ");
	Book b2("002", "test", "�廭��");
	Book b3("003", "test", "��־");
	bookList.add(b1);
	bookList.add(b2);
	bookList.add(b3);
	bookList.display();
	-----------------------------------
	*/
	/*
	���ļ�¼�����
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
	ѧ�����黹�����
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
	��ʼ������
	-----------------------------------
	init(bookList, studentList, recordList);
	bookList.display();
	studentList.display();
	recordList.display();
	save(bookList,studentList,recordList);
	-----------------------------------
	*/

}

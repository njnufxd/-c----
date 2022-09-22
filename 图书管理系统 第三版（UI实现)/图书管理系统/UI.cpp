#define _CRT_SECURE_NO_WARNINGS 1
#include"Stu.cpp"
using namespace std;
static void AllStudents(MyList<Student>& studentList);
static void Login( MyList<Book>& bookList,MyList<Student>& studentList, MyList<BorrowRecord>& recordList);
static void Register(MyList<Student>& studentList);

static void UI(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	cout << "ͼ�����ϵͳ" << endl;
	cout << "1.�鼮�б�" << endl;
	cout << "2.ѧ����Ϣ�б�" << endl;
	cout << "3.��¼ѧ���˺�" << endl;
	cout << "4.ע��ѧ����Ϣ" << endl;
	cout << "5.����鼮��Ĭ�Ͽɽ��ģ�" << endl;
	cout << "6.�鿴���н��ļ�¼" << endl;
	cout << "0.�˳�" << endl;
	int choice;
	cout << "������ѡ��" << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
		AllBooks(bookList);
		break;
	}
	case 2: {
		AllStudents(studentList);
		break;
	}
	case 3: {
		Login(bookList, studentList, recordList);
		break;
	}
	case 4: {
		Register(studentList);
		break;
	}
	case 5: {
		AddBook(bookList);
		break;
	}
	case 6: {
		AllRecords(recordList);
		break;
	}
	case 0: {
		cout << "ϵͳ���ڱ�������......" << endl;
		save(bookList, studentList, recordList);
		cout << "������ϣ�ллʹ�á�" << endl;
		exit(0);
	}
	}
	UI(bookList, studentList, recordList);

}


static void AllStudents(MyList<Student>& studentList) {
	cout << "id\tname" << endl;
	studentList.display();
	Refresh();
}
static void Login( MyList<Book>& bookList,MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	cout << "��¼(����׶�����0�˳���" << endl;
	cout << "������id��"<<endl;
	string id;
	cin >> id;
	if (id._Equal("0")){
		system("cls");
		return;
	}
	Student* stu;
	while ((stu =studentList.search(id))==NULL) {
		cout << "id������\n����������id��" << endl;
		cin >> id;
		if (id._Equal("0")) {
			system("cls");
			return;
		}
		Refresh();
	}
	cout << "���������룺" << endl;
	string password;
	cin >> password;
	while (!stu->getPassword()._Equal(password)) {
		if (password._Equal("0")) {
			system("cls");
			return;
		}
		cout << "�������" << endl;
		cout << "����������password��" << endl;
		cin >> password;
	}
	system("cls");
	cout << "��¼�ɹ���";
	Stu(*stu, bookList, recordList);
}
static void Register(MyList<Student>& studentList ) {
	string id;
	string name;
	string password;
	string passwordConfirm;
	cout << "ע��(����׶�����0�˳���" << endl;
	cout << "����id��name��password��" << endl;
	cout << "������id��";
	cin >> id;
	if (id._Equal("0")) {
		system("cls");
		return;
	}
	while (studentList.search(id)!=NULL) {
		cout << "Ψһid�ظ�,����������id:" << endl;
		cin >> id;
		if (id._Equal("0")) {
			system("cls");
			return;
		}
	}
	cout << "������name��";
	cin >> name;
	if (name._Equal("0")) {
		system("cls");
		return;
	}
	cout << "������password��";
	cin >> password;
	if (password._Equal("0")) {
		system("cls");
		return;
	}
	cout << "��������һ�����룺";
	cin >> passwordConfirm;
	while (!passwordConfirm._Equal(password)) {
		if (passwordConfirm._Equal("0")) {
			system("cls");
			return;
		}
		cout << "�������벻ͬ��������ȷ�ϡ�" << endl;
		cout << "ȷ�����룺";
		cin >> passwordConfirm;

	}
	Student stu(id, name, password);
	studentList.add(stu);
	cout << "ע��ɹ���\t" + stu.toString()<<endl;
	Refresh();
}

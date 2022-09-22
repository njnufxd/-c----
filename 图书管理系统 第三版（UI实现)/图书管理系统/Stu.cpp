#include"test.cpp"
static void Stu(Student& stu, MyList<Book>& bookList, MyList<BorrowRecord>& recordList);
static void AllBooks(MyList<Book>& bookList);
static void Refresh();
static void AddBook(MyList<Book>& bookListvb);
static void AllRecords(MyList<BorrowRecord>& recordList);
static void MyRecords(MyList<BorrowRecord>& recordList,Student& student);
static void BorrowBook(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, Student& student);
static void SendBack(MyList<Book>& bookList,MyList<BorrowRecord> & recordList,Student& stu);
static void Stu(Student& stu, MyList<Book>& bookList, MyList<BorrowRecord>& recordList) {
	cout << "��ӭ " + stu.getName() + " ��" << endl;
	cout << "1.�鼮�б�" << endl;
	cout << "2.����鼮��Ĭ�Ͽɽ��ģ�" << endl;
	cout << "3.�鿴���н��ļ�¼" << endl;
	cout << "4.�鿴�ҵĽ��ļ�¼" << endl;
	cout << "5.�����鼮" << endl;
	cout << "6.�黹�鼮" << endl;
	cout << "0.�˳���¼" << endl;
	int choice;
	cout << "������ѡ��";
	cin >> choice;
	switch (choice) {
	case 1: {
		AllBooks(bookList);
		break;
	}
	case 2: {
		AddBook(bookList);
		break;
	}
	case 3: {
		AllRecords(recordList);
		break;
	}
	case 4: {
		MyRecords(recordList,stu);
		break;
	}
	case 5: {
		BorrowBook(bookList, recordList, stu); 
		break;
	}
	case 6: {
		SendBack(bookList, recordList, stu);
		break;
	}
	case 0: {
		system("cls");
		return;
	}
	}
	Stu(stu, bookList, recordList);
}
static void AllBooks(MyList<Book>& bookList) {
	cout << "id\tname\ttype\tstatus" << endl;
	bookList.display();
	Refresh();
}

static void Refresh() {
	cout << "�Ƿ�ˢ����Ļ��Y/N��" << endl;
	char cls;
	cin >> cls;
	if (cls == 'Y' || cls == 'y') {
		system("cls");
	}
}
static void AddBook(MyList<Book>& bookList) {
	string id;
	string name;
	string type;
	cout << "����鼮(����׶�����0�˳���" << endl;
	cout << "����id��name��type" << endl;
	cout << "������id��";
	cin >> id;
	if (id._Equal("0")) {
		system("cls");
		return;
	}
	while (bookList.search(id) != NULL) {
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
	cout << "������type��";
	cin >> type;
	if (type._Equal("0")) {
		system("cls");
		return;
	}
	Book book(id, name, type);
	bookList.add(book);
	cout << "��ӳɹ���\t" + book.toString() << endl;
	Refresh();
}
static void AllRecords(MyList<BorrowRecord>& recordList) {
	cout << "id\tBookId\tstudentId\tborrowTime\t\tstatus" << endl;
	recordList.display();
	Refresh();
}
static void MyRecords(MyList<BorrowRecord>& recordList, Student& student) {
	cout << "�ҵĽ��ļ�¼" << endl;
	cout << "id\tBookId\tstudentId\tborrowTime\t\tstatus" << endl;
	student.getRecordList()->display();
	Refresh();
}
static void BorrowBook(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, Student& student) {
	cout << "�����鼮������0�˳���" << endl;
	cout << "�������鼮��ţ�";
	string bookId;
	cin >> bookId;
	if (bookId._Equal("0")) {
		system("cls");
		return;
	}
	Book* book = bookList.search(bookId);
	while(true) {
		if(book == NULL){
			cout << "δ��ѯ����Ӧ�鼮!" << endl;
		}
		else if (book->getStatus() == 0) {
			cout << "���鼮��ǰ�޷�����" << endl;
		}
		else {
			break;
		}
		cout << "���������룺";
		cin >> bookId;
		if (bookId._Equal("0")) {
			system("cls");
			return;
		}
		book = bookList.search(bookId);
	}
	book->changeStatus();
	BorrowRecord record(student.getId(), bookId);
	recordList.add(record);
	cout << "���ĳɹ���" << "ѧ�ţ�" << record.getStudentId() << "��ţ�" << record.getBookId() << endl;
	Refresh();
}
static void SendBack(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, Student& stu) {
	MyList<BorrowRecord>* myRecords = stu.getRecordList();
	cout << "�黹�鼮������0�˳���" << endl;
	cout << "������Ҫ�黹���鼮��ţ�";
	string bookId;
	cin >> bookId;
	if (bookId._Equal("0")) {
		system("cls");
		return;
	}
	string recordId;
	Node<BorrowRecord>* pmove = myRecords->head;
	while (pmove) {
		if (pmove->getDate()->getBookId()._Equal(bookId) && pmove->getDate()->getState() == 0) {
			pmove->getDate()->changeStatus();
			recordId = pmove->getDate()->getId();
			break;
		}
		pmove = pmove->next;
	}
	while (recordId.empty()) {
		cout << "δ���ĸ��鼮" << endl;
		cout << "�����������鼮��ţ�";
		cin >> bookId;
		if (bookId._Equal("0")) {
			system("cls");
			return;
		}
		pmove = myRecords->head;
		while (pmove) {
			if (pmove->getDate()->getBookId()._Equal(bookId) && pmove->getDate()->getState() == 0) {
				pmove->getDate()->changeStatus();
				recordId = pmove->getDate()->getId();
				break;
			}
			pmove = pmove->next;
		}
	}
	Book* book = bookList.search(bookId);
	book->changeStatus();
	pmove=recordList.head;
	while (pmove) {
		if (pmove->getDate()->getBookId()._Equal(bookId)&& pmove->getDate()->getState() == 0) {
			pmove->getDate()->changeStatus();
			break;
		}
		pmove = pmove->next;
	}
	cout << "�黹�ɹ�" << endl;
	Refresh();
}
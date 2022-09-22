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
	cout << "欢迎 " + stu.getName() + " ！" << endl;
	cout << "1.书籍列表" << endl;
	cout << "2.添加书籍（默认可借阅）" << endl;
	cout << "3.查看所有借阅记录" << endl;
	cout << "4.查看我的借阅记录" << endl;
	cout << "5.借阅书籍" << endl;
	cout << "6.归还书籍" << endl;
	cout << "0.退出登录" << endl;
	int choice;
	cout << "请输入选择：";
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
	cout << "是否刷新屏幕（Y/N）" << endl;
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
	cout << "添加书籍(任意阶段输入0退出）" << endl;
	cout << "输入id，name，type" << endl;
	cout << "请输入id：";
	cin >> id;
	if (id._Equal("0")) {
		system("cls");
		return;
	}
	while (bookList.search(id) != NULL) {
		cout << "唯一id重复,请重新输入id:" << endl;
		cin >> id;
		if (id._Equal("0")) {
			system("cls");
			return;
		}
	}
	cout << "请输入name：";
	cin >> name;
	if (name._Equal("0")) {
		system("cls");
		return;
	}
	cout << "请输入type：";
	cin >> type;
	if (type._Equal("0")) {
		system("cls");
		return;
	}
	Book book(id, name, type);
	bookList.add(book);
	cout << "添加成功！\t" + book.toString() << endl;
	Refresh();
}
static void AllRecords(MyList<BorrowRecord>& recordList) {
	cout << "id\tBookId\tstudentId\tborrowTime\t\tstatus" << endl;
	recordList.display();
	Refresh();
}
static void MyRecords(MyList<BorrowRecord>& recordList, Student& student) {
	cout << "我的借阅记录" << endl;
	cout << "id\tBookId\tstudentId\tborrowTime\t\tstatus" << endl;
	student.getRecordList()->display();
	Refresh();
}
static void BorrowBook(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, Student& student) {
	cout << "借阅书籍（输入0退出）" << endl;
	cout << "请输入书籍编号：";
	string bookId;
	cin >> bookId;
	if (bookId._Equal("0")) {
		system("cls");
		return;
	}
	Book* book = bookList.search(bookId);
	while(true) {
		if(book == NULL){
			cout << "未查询到对应书籍!" << endl;
		}
		else if (book->getStatus() == 0) {
			cout << "该书籍当前无法借阅" << endl;
		}
		else {
			break;
		}
		cout << "请重新输入：";
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
	cout << "借阅成功！" << "学号：" << record.getStudentId() << "书号：" << record.getBookId() << endl;
	Refresh();
}
static void SendBack(MyList<Book>& bookList, MyList<BorrowRecord>& recordList, Student& stu) {
	MyList<BorrowRecord>* myRecords = stu.getRecordList();
	cout << "归还书籍（输入0退出）" << endl;
	cout << "请输入要归还的书籍编号：";
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
		cout << "未借阅该书籍" << endl;
		cout << "请重新输入书籍编号：";
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
	cout << "归还成功" << endl;
	Refresh();
}
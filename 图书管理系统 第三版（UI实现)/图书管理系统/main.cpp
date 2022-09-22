
#include"UI.cpp"
int BorrowRecord::count = 0;
int main() {
	MyList<Student> studentList;
	MyList<Book> bookList;
	MyList<BorrowRecord> borrowRecordList;
	cout << "系统正在初始化......" << endl;
	init(bookList, studentList, borrowRecordList);
	cout << "初始化完成" << endl;
	system("pause");
	system("cls");
	UI(bookList, studentList, borrowRecordList);
}
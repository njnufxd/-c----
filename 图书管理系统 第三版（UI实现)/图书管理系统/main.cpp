
#include"UI.cpp"
int BorrowRecord::count = 0;
int main() {
	MyList<Student> studentList;
	MyList<Book> bookList;
	MyList<BorrowRecord> borrowRecordList;
	cout << "ϵͳ���ڳ�ʼ��......" << endl;
	init(bookList, studentList, borrowRecordList);
	cout << "��ʼ�����" << endl;
	system("pause");
	system("cls");
	UI(bookList, studentList, borrowRecordList);
}
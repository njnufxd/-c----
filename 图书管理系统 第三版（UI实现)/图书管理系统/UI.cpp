#define _CRT_SECURE_NO_WARNINGS 1
#include"Stu.cpp"
using namespace std;
static void AllStudents(MyList<Student>& studentList);
static void Login( MyList<Book>& bookList,MyList<Student>& studentList, MyList<BorrowRecord>& recordList);
static void Register(MyList<Student>& studentList);

static void UI(MyList<Book>& bookList, MyList<Student>& studentList, MyList<BorrowRecord>& recordList) {
	cout << "图书管理系统" << endl;
	cout << "1.书籍列表" << endl;
	cout << "2.学生信息列表" << endl;
	cout << "3.登录学生账号" << endl;
	cout << "4.注册学生信息" << endl;
	cout << "5.添加书籍（默认可借阅）" << endl;
	cout << "6.查看所有借阅记录" << endl;
	cout << "0.退出" << endl;
	int choice;
	cout << "请输入选择：" << endl;
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
		cout << "系统正在保存数据......" << endl;
		save(bookList, studentList, recordList);
		cout << "保存完毕，谢谢使用。" << endl;
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
	cout << "登录(任意阶段输入0退出）" << endl;
	cout << "请输入id："<<endl;
	string id;
	cin >> id;
	if (id._Equal("0")){
		system("cls");
		return;
	}
	Student* stu;
	while ((stu =studentList.search(id))==NULL) {
		cout << "id不存在\n请重新输入id：" << endl;
		cin >> id;
		if (id._Equal("0")) {
			system("cls");
			return;
		}
		Refresh();
	}
	cout << "请输入密码：" << endl;
	string password;
	cin >> password;
	while (!stu->getPassword()._Equal(password)) {
		if (password._Equal("0")) {
			system("cls");
			return;
		}
		cout << "密码错误！" << endl;
		cout << "请重新输入password：" << endl;
		cin >> password;
	}
	system("cls");
	cout << "登录成功！";
	Stu(*stu, bookList, recordList);
}
static void Register(MyList<Student>& studentList ) {
	string id;
	string name;
	string password;
	string passwordConfirm;
	cout << "注册(任意阶段输入0退出）" << endl;
	cout << "输入id，name，password。" << endl;
	cout << "请输入id：";
	cin >> id;
	if (id._Equal("0")) {
		system("cls");
		return;
	}
	while (studentList.search(id)!=NULL) {
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
	cout << "请输入password：";
	cin >> password;
	if (password._Equal("0")) {
		system("cls");
		return;
	}
	cout << "请再输入一次密码：";
	cin >> passwordConfirm;
	while (!passwordConfirm._Equal(password)) {
		if (passwordConfirm._Equal("0")) {
			system("cls");
			return;
		}
		cout << "两次密码不同，请重新确认。" << endl;
		cout << "确认密码：";
		cin >> passwordConfirm;

	}
	Student stu(id, name, password);
	studentList.add(stu);
	cout << "注册成功！\t" + stu.toString()<<endl;
	Refresh();
}

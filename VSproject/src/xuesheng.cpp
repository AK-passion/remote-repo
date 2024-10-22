#include <iostream>
#include <string>
using namespace std;

// 定义学生结构体
struct Student {
    string name;   // 学生姓名
    int id;        // 学号
    string gender; // 性别
    int age;       // 年龄
};

// input 函数，用于输入学生信息
bool input(Student students[], int &length) {
    if (length >= 100) { // 假设最多只能存储100名学生
        cout << "无法添加更多的学生，已达到最大容量。" << endl;
        return false;
    }
    
    Student newStudent;
    cout << "请输入学生姓名: ";
    cin >> newStudent.name;
    cout << "请输入学生学号: ";
    cin >> newStudent.id;
    cout << "请输入学生性别: ";
    cin >> newStudent.gender;
    cout << "请输入学生年龄: ";
    cin >> newStudent.age;
    
    students[length] = newStudent; // 将新学生信息存入数组
    length++; // 数组长度加1
    return true;
}

// output 函数，用于输出所有学生的信息
void output(Student students[], int length) {
    if (length == 0) {
        cout << "当前没有学生信息。" << endl;
        return;
    }
    
    for (int i = 0; i < length; i++) {
        cout << "学生 " << i + 1 << ": " << endl;
        cout << "姓名: " << students[i].name << endl;
        cout << "学号: " << students[i].id << endl;
        cout << "性别: " << students[i].gender << endl;
        cout << "年龄: " << students[i].age << endl;
        cout << "-------------------------" << endl;
    }
}

// 主函数
int main() {
    Student students[100]; // 定义一个大小为100的学生数组
    int length = 0;        // 当前数组中的学生数量
    
    while (true) {
        cout << "\n学生管理系统菜单:\n";
        cout << "1. 添加学生信息\n";
        cout << "2. 显示学生信息\n";
        cout << "3. 退出程序\n";
        cout << "请选择操作: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: // 添加学生信息
                if (input(students, length)) {
                    cout << "学生信息添加成功！" << endl;
                } else {
                    cout << "学生信息添加失败。" << endl;
                }
                break;
            case 2: // 显示学生信息
                output(students, length);
                break;
            case 3: // 退出程序
                cout << "程序已退出。" << endl;
                return 0;
            default:
                cout << "无效的选择，请重试。" << endl;
        }
        
        char continueChoice;
        cout << "是否继续操作？(y/n): ";
        cin >> continueChoice;
        if (continueChoice == 'n' || continueChoice == 'N') {
            cout << "程序已退出。" << endl;
            break;
        }
    }
    
    return 0;
}

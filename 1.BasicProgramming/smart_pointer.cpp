#include<memory>
#include<iostream>
#include<vector>

using namespace std;

void memory_model(){
    /* ---------------------- C++的内存模型包含三部分：栈、静态内存、动态内存 ---------------------- */
    // 栈用于存放局部变量，当程序退出代码块时，局部变量就不能再被访问了
    // 全局变量有点不一样，不过应该也是放置在栈里面的
    {
        int a = 10;
        cout << "The value of a(located in local stack): " << a << endl;
    }

    // 静态内存用于存放由static修饰的变量，在程序运行前，static变量就已经存在，直到整个程序结束后static变量才会被释放
    static int a_static = 100;
    cout << "The value of a(located in static memory)" << a_static << endl;
    
    // 动态内存也称堆，存放由new或malloc产生的变量
    int *a = new int(1000); // 指针a指向的变量位于堆区
    cout << "The value of a(located in heap):" << *a << endl;
}

void init_a_var(){
    /* ---------------------- 变量的初始化方式 ---------------------- */
    // 区分初始化和赋值，【初始化】是在创建变量时赋予其一个初始值；
    // 【赋值】是擦除对象当前的值再赋予它一个新的值
    int var;  // 定义并初始化a（赋予默认值）
    var = 10; // 赋值

    // 列表初始化：C++11的新特点
    int a{100};
    string s{"hello, world!"};
    vector<int> v{1,2,3,4,5};
    int array[]{1,2,3,4,5}; 
}

void smart_pointer(){
    // 在C98中也存在智能指针auto_ptr，定义在auto_ptr.h文件中，但C11中提出了新的智能指针，定义在memory文件中
    // 智能指针是一种模板类（除了存放指针地址，还存放了计数器等属性），而指针则是复合类型（里面只存放地址），注意区分
    // shared_ptr：
    // shared_ptr<int> p = make_ptr<int>(42);
    int a = 10;
    // shared_ptr<int> q = &a;
}

class Simple_class{
    public:
        string name;
        Simple_class(string name){
            this->name = name;
        }
        ~Simple_class(){
            cout << "delete " << name << endl;
            delete this;
        }
};
void compare_pointer(){
    // 智能指针的释放
    shared_ptr<string> s(new string("nico"),
                            [](string* p){  // 为智能指针添加析构函数
                                cout << "delete " << *p << endl;
                                delete p;
                            });
    s = nullptr;    // 将nullptr赋给智能指针，从而释放指针
    cout << "complete release smart pointer" << endl;
    
    // 传统指针不会自动释放
    Simple_class* q = new Simple_class("alien");
    q = nullptr;    // 同样释放指针
    cout << "complete release class pointer" << endl;

    // 执行上述代码后会发现：将nullptr赋给智能指针后会执行析构函数，而传统指针并不会执行析构函数

}
int main(){
    // memory_model();
    // init_a_var();
    // smart_pointer();
    compare_pointer();
    return 0;
}
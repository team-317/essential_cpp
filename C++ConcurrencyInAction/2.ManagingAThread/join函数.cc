#include <thread>
#include <iostream>
#include <fstream>
using namespace std;

class background_task
{
public:
    int a;

public:
    void operator()() const
    {
        cout << "hello, concurrency world!" << endl;
        int a = 19;
    }
};
void simple_example()
{
    background_task f;
    // 直接调用，不采用线程
    f.operator()();
    // 采用线程，并等待其结束
    thread my_thread(f);
    my_thread.join();
}

struct func
{
    int &i;
    // i是一个引用，当所引用的对象i_被释放后，i将不能正常使用
    func(int &i_) : i(i_) {}
    void operator()()
    {
        std::ofstream myfile("./log.txt", std::ios_base::app);
        if (!myfile)
        {
            cerr << "Open file failed!" << endl;
            exit(0);
        }
        else
        {
            myfile << "Open file successfully!" << endl;
        }
        for (unsigned j = 0; j < 10; ++j)
        {
            try
            {
                myfile << j << i << endl;
            }
            catch (...)
            {
                myfile << "Exception happened!" << endl;
            }
        }
    }
};
void oops()
{
    int some_local_state = 0;
    // 将some_local_state 赋给引用func的成员对象i，
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    // 不等线程结束就退出函数，导致some_local_state被释放，线程中对some_local_state的引用变为未定义行为。
    my_thread.detach(); // 线程在后台运行
    // my_thread.join();
}

// 一个包装类，提供析构器使得函数退出前等待线程结束
class thread_guard
{
    thread &t;

public:
    explicit thread_guard(std::thread &t_) : t(t_) {}
    ~thread_guard()
    {
        if (t.joinable())
            t.join();
    }
    // C++中在一个函数的声明上指定 =delete 来删除该函数，使得该函数被禁用
    thread_guard(thread_guard const &) = delete; // 禁用拷贝函数（形似构造函数）
    // 这是 = 运算符的重载函数，指定 =delete 来删除该函数
    thread_guard &operator=(thread_guard const &) = delete; // 禁用赋值操作
};

void safe_join_a_thread()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    thread t(my_func); // 线程开始执行
    cout << "thread is working..." << endl;
    thread_guard g(t); // 将线程加入到包装类中，确保正常join
}
int main()
{
    // simple_example();
    oops();

    // safe_join_a_thread();
    return 0;
}
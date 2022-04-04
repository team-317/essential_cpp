#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>

// 顺序容器构造的适配器
#include<stack> // 不能由array和forward_list来构造
#include<queue> // 可以由vector额deque来构造

// 要使用泛型算法，需导入algorithm库，然后上面的这些库其实可以不用导入
#include<algorithm>

using namespace std;

/*-------------------------顺序容器-------------------------*/

int main(){

    int array[9] = {9,3,4,1,7,2,5,8,6}; // 拷贝初始化，使用了等号即为拷贝初始化！！！
    vector<int> ivec(begin(array), end(array));
    list<int> ilist(begin(array), end(array));
    int head = ilist.front();   // 获取容器的第一个元素
    int tail = ilist.back();    // 获取容器的最后一个元素

    // 字符串容器及相关操作
    string str = "Hello, world!";   // 拷贝初始化，使用了等号即为拷贝初始化！！！
    string str1("Hello, world!");    // 直接初始化
    string str2(10,'-');             // 直接初始化

    str.append(" Welcome to this world.");  // 向字符串对象后添加字符串，同'+'运算
    str.push_back('\n');            // 向字符串后面添加一个字符
    string sub = str.substr(0,13);  // 获取字串
    sub.erase(6);                   // 清除第六位之后的字符
    // sub.erase(6, 7);
    sub.insert(6, "Welcome to this world!"); // 向第六位之后添加字符
    auto index1 = str.find(',');     // 查找','出现的下标
    auto index2 = str.find_first_of(','); // 查找','第一次出现的位置

    // vector及相关操作
    vector<int> myvector(begin(array), end(array));
    myvector.push_back(-1); // 将元素添加到最后
    myvector.pop_back();    // 删除最后一个元素
    int first = myvector.front();   // 访问第一个元素
    int last = myvector.back();     // 访问最后一个元素
    int size = myvector.max_size();



    // 栈及相关操作
    stack<int> mystack; // 定义一个空栈，注意：没有"stack<int> emptyStack();"这样的构造方式
    stack<int, vector<int>> istack(ivec);   // 由已存在的容器来初始化栈

    mystack.push(9);          // 入栈
    int itop = mystack.top(); // 获取栈顶元素
    mystack.pop();            // 弹出栈顶元素

    mystack.empty();    // 检查栈是否为空
    mystack.size();     // 获取栈中元素的个数

    // 队列及相关操作
    queue<int> iqueue;
    queue<int, vector<int>> myqueue(ivec);

    int qfirst = myqueue.front(); // 返回队首元素
    int qlast=myqueue.back();     // 返回队尾元素
    myqueue.push(0);             // 向队尾添加元素

    myqueue.empty();    // 检查队列是否为空
    myqueue.size();     // 获取队列中元素的个数

    return 0;
}


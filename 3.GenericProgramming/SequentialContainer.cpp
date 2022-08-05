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


/* ------string相关的操作--------- */
void string_op(){
    string str = "Hello, world!";   // 拷贝初始化，使用了等号即为拷贝初始化！！！
    string str1("Hello, world!");    // 直接初始化，使用构造函数
    string str2(10,'-');             // 直接初始化，使用构造函数

    str.append(" Welcome to this world.");  // 向字符串对象后添加字符串，同'+'运算
    str.push_back('\n');            // 向字符串后面添加一个字符
    string sub = str.substr(0,13);  // 获取子串
    sub.erase(6);                   // 清除第六位之后的字符
    // sub.erase(6, 7);
    sub.insert(6, "Welcome to this world!"); // 向第六位之后添加字符
    auto index1 = str.find(',');     // 查找','出现的下标
    auto index2 = str.find_first_of(','); // 查找','第一次出现的位置
}

/* ------vector相关的操作--------- */
void vector_op(){
    int array[9] = {9,3,4,1,7,2,5,8,6}; // 拷贝初始化，使用了等号即为拷贝初始化！！！
    vector<int> ivec(begin(array), end(array));
    vector<int> myvector(begin(array), end(array));
    myvector.push_back(-1); // 将元素添加到最后
    myvector.pop_back();    // 删除最后一个元素
    myvector.empty();       // 检查是否为空
    int first = myvector.front();   // 访问第一个元素
    int last = myvector.back();     // 访问最后一个元素
    int size = myvector.max_size();
    

}

/* ------stack相关的操作--------- */
void stack_op(){
    stack<int> mystack; // 定义一个空栈，注意：没有"stack<int> emptyStack();"这样的构造方式
    stack<int, vector<int>> istack(ivec);   // 由已存在的容器来初始化栈

    mystack.push(9);          // 入栈
    int itop = mystack.top(); // 获取栈顶元素
    mystack.pop();            // 弹出栈顶元素

    mystack.empty();    // 检查栈是否为空
    mystack.size();     // 获取栈中元素的个数
}

/* ------queue相关的操作--------- */
void queue_op(){
    queue<int> iqueue;
    queue<int, vector<int>> myqueue(ivec);
    iqueue.push(3); // 入队操作
    iqueue.pop();   // 出队操作，不返回出队元素！！！
    int elem = iqueue.fornt();  iqueue.pop();   // 常用出队操作：先访问队头元素，再出队

    int qfirst = myqueue.front(); // 返回队首元素
    int qlast=myqueue.back();     // 返回队尾元素
    myqueue.push(0);             // 向队尾添加元素
    myqueue.empty();    // 检查队列是否为空
    myqueue.size();     // 获取队列中元素的个数
}

int main(){
    int array[9] = {9,3,4,1,7,2,5,8,6}; // 拷贝初始化，使用了等号即为拷贝初始化！！！
    list<int> ilist(begin(array), end(array));
    int head = ilist.front();   // 获取容器的第一个元素
    int tail = ilist.back();    // 获取容器的最后一个元素

    string_op();
    vector_op();
    // stack和queue并不含有begin和end两个迭代器，所以无法使用范围for循环进行遍历。
    stack_op();
    queue_op();

    return 0;
}


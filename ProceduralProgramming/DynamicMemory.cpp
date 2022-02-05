// 2.2调用函数：动态内存管理
#include<vector>
#include<iostream>
using std::vector;
// 深入理解C++ new/delete, new []/delete[]动态内存管理：https://www.cnblogs.com/tp-16b/p/8684298.html

vector<int> *memoryLeak(){
    // 申请128MB的内存，一个int元素占4B，相乘即为128MB
    vector<int> varray(32*1024*1024,1);                // 语句1
    // 申请128MB的内存
    vector<int> *parray = new vector<int>(32*1024*1024,1); // 语句2


    // 注意，parray位于堆区，退出memeoryLeak后不会释放
    // 而varray位于栈区，退出memoryLeak后会释放，所以return varray不能正常返回！！！
    return parray;
}
int main(){
    // memoryLeak();   // 此处设断点
    // 查看资源管理器，memoryLeak执行前后内存增加300多MB，来自语句2的执行
    // 语句1在执行后也会使内存增加300+MB，但退出memoryLeak后这些内存会自动释放
    // 语句1申请的空间位于栈中，不会出现内存泄漏，
    // 语句2使用new申请的空间位于堆中，没有释放，在本例中导致了内存泄漏！！！

    // 使用delete语句可以释放堆区定义的变量
    // vector<int> *p = memoryLeak();
    // delete p;

    // 对于数组，也可以使用new
    int *q = new int[1024*1024]();   // 最后加上的()使得数组元素进行初始化
    std::cout<<q[1024*1024]<<std::endl; // 数组不会检查越界错误，该语句可以正常执行
    delete [] q;    //数组的释放需要加[]

    // 下面的语句会报错"Segmentation fault"，编译时报错，而非运行时!!!
    // 因为栈的大小有限，这里栈大小约为1MB，而这个数组大小为128MB
    // int r[32*1024*1024];   // 当数组太大时，需要使用new在堆区进行申请!!!

    return 0;
}
#include<iostream>
#include<vector>
#include "scope.h"
using namespace std;

float global_var = 3.14;

int main(){
    /*-------------- 作用域 --------------*/
    // 局部作用域，定义在代码块中（在{}中），只能在代码块中访问，离开这个代码块就会释放掉
    int local_var = 10;
    cout << "local var: " << local_var << endl;
    // // 全局作用域global scope或者说file scope，定义在main之外，整个文件中都可以访问这个变量
    cout << "global var: " << global_var << endl;
    // 来自文件scope.h的全局变量（已定义），先声明，再访问
    extern int var;  // 使用extern声明变量
    cout << "global var come from other file: " << var << endl;

    /*
        注意：extern int var_name的作用是对变量进行声明，但不对它进行定义，
        对于局部变量，也可以使用extern声明一个变量，但对于局部变量没有必要，
        因为局部变量需要先定义后使用，并且在定义时完成声明；
    */
    // #define TEST
    #ifdef TEST  // 可以通过定义宏的方式对代码段进行测试，这里如果定义了宏 TEST，则执行之后的代码
        // 用extern对局部变量进行声明，再进行定义和赋值，在编译时将引发错误：重复声明
        extern int local;   // 声明一个变量（局部变量）
        int local = 111;    // 声明和定义变量并完成赋值（报错：重复声明）
    #endif
    // 对于全局变量不会有这样的错误，比如上面定义的 global_var 和 var


    /*-------------- 局部静态变量 --------------*/
    auto elems = fibon_seq(10);
    for(auto elem:*elems)    cout << elem << endl;
    /*
        注意区分const常量static和静态变量：
        const常量的值不可变，但static变量的值是可以改变的，
    */
    return 0;
}
vector<int>* fibon_seq(int size){
    // 将elems定义为局部静态变量，当程序结束时，局部静态变量elems并不会被释放！！！
    // 所以这里不需要使用new来申请空间！！！当程序结束后局部静态变量才会释放
    static vector<int> elems;
    // 生成斐波那契数列
    for(int i = elems.size(); i < size; ++i){
        if(i == 0 || i == 1){
            elems.push_back(1);
        } else {
            elems.push_back(elems[i-1] + elems[i-2]);
        }
    }
    // 由于程序结束后elems并不会被释放，所以可以返回给外部程序进行访问
    return &elems;
}
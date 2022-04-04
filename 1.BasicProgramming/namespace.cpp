// 1.1如何撰写C++程序
/*-------------------------变量类型和命名空间-------------------------*/
/*
C++中的命名空间，早期C++没有命名空间，在使用函数时和
C语言一样，只需要include相应的库即可，这类库以.h结尾。
后来C++设计了命名空间，需要使用using语句来导入名称，这
类库没有.h后缀。
C++命名空间（名字空间）详解 http://c.biancheng.net/view/2192.html
*/
// #include<stdio.h>   // 兼容C语言，导入库后便导入该库中的所有函数名
#include<cstdio>    // 等同于#include<stdio.h>，但cstdio中的名称属于命名空间std！！！
#include<iostream>  // 有include还不够，还需要使用using语句导入名称
#include<vector>
// 标准库中的名称都在命名空间std中，可以单独导入名称
// 导入std命名空间中的cout、endl
using std::cout;
using std::endl;     
using std::vector;
// 或者直接导入命名空间std
using namespace std;

// 还可以使用using来设置类型别名，等同于：typedef int elemType;
using elemType = int;

int main(){

    printf("使用printf，可以导入stdio.h直接使用\n");     // 此时无需导入命名空间便可使用

    cout<<"使用cout，"
        <<"在使用include后还需使用using入名称"
        <<endl;        // 需要先导入名称，或导入命名空间

    vector<int> varray(10,-1);
    // auto：根据初始值来匹配变量的类型
    auto iter = varray.begin();    // 拷贝初始化，使用auto根据初始值匹配array的类型
    // decltype 获取类型以便设置未初始化的对象
    decltype(varray.begin()) it;   // it是一个空的迭代器，未被初始化
    
    
    /*-------------------------关于switch和字符-------------------------*/
    //区分字符和字符串
    char ch[] = "B";    // 用双引号的就是字符串，如果写为 char ch = "B"; 将会报错
    char mych = 'B';      // 用单引号则是字符，要严格区分


    // swtich(mark)中的mark必须是整型（可以是字符）或枚举类型
    switch (mych) {
        case 'B':
            std::printf("hello");    break;  // 不要漏掉break
        case 'C':
            std::printf("hei");      break;
        default:
            std::printf("hi");

    }
    return 0;
}
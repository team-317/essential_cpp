// 1.1如何撰写C++程序
/*
C++中的命名空间，早期C++没有命名空间，在使用函数时和
C语言一样，只需要include相应的库即可，这类库以.h结尾。
后来C++设计了命名空间，需要使用using语句来导入名称，这
类库没有.h后缀。
C++命名空间（名字空间）详解 http://c.biancheng.net/view/2192.html
*/
#include<stdio.h>   // 兼容C语言，导入库后便导入改库中的所有函数名

#include<iostream>  // 有include还不够，还需要使用using语句导入名称
// 标准库中的名称都在命名空间std中，可以单独导入名称
// 导入std命名空间中的cout、endl
using std::cout;
using std::endl;     
// 或者直接导入命名空间std
using namespace std;


int main(){

    printf("使用printf，只需要include<stdio.h>\n");     // 无需导入命名空间便可使用

    cout<<"使用cout，"
        <<"在使用include后还需使用using入名称"
        <<endl;        // 需要先导入名称，或导入命名空间

    
    /*-------------------------关于switch和字符-------------------------*/
    //区分字符和字符串
    char ch[] = "B";    // 用双引号的就是字符串，如果写为 char ch = "B"; 将会报错
    char mych = 'B';      // 用单引号则是字符，要严格区分


    // swtich(mark)中的mark必须是整型（可以是字符）或枚举类型
    switch (mych) {
        case 'B':
            printf("hello");    break;  // 不要漏掉break
        case 'C':
            printf("hei");      break;
        default:
            printf("hi");

    }
    return 0;
}
// 1.5 Array和Vector
#include<vector>
#include<iostream>
// 导入std命名空间中的vector名称
using std::vector;

typedef int elemType;
void check(vector<int> varray){
    std::cout<<"在check中varray的地址:"
             <<&varray<<std::endl;
    varray[0] = 100;
}
int main(){
    /*-------------------------搞清楚数组（array）和vector的区别-------------------------*/
    // 数组就是C语言中的数组，并不陌生
    elemType array[9] = {     // 数组的初始化
        1,2,3,
        4,5,6,
        7,8,9
    };

    // vector和数组相似，但又有些不同
    // vector不能像数组那样初始化，但可以将数组转化为vector
    vector<elemType> varray(array, array+5);   // 将array中的前5个元素赋值为varray
    vector<elemType> varray1(varray.begin(), varray.end()); // 初始化方式同上

    vector<elemType> varray2();         // 可以定义一个空vector

    /*-------------------------值传递-------------------------*/

    // 传递前的地址：0x62fda0，varray[0]=1
    std::cout<<"varray的地址:"<<&varray<<std::endl;
    std::cout<<"varray[0]="<<varray[0]<<std::endl<<std::endl;

    // 传递后的地址：0x62fdf0，varray[0]=1
    check(varray);
    std::cout<<"varray[0]="<<varray[0]<<std::endl<<std::endl;

    // void check(vector<int> varray)实现的是值传递，在传递后的varray与传递前的varray无关！！！
    // 在C++中，vector对象在传递时传递的是所有值，而非像java那样传递vector对象的地址值，
    // 这也表明，C++的对象和Java的对象也是有区别的
    
    // 如果要实现引用传递，则使用&，将check定义为：void check(vector<int> &varray)
    // 区别与C中使用指针进行地址传递，指针使用->和*来操作对象，而引用则像是变量的别名，用起来更方便
    // 指针传递的方式同C语言，定义为：void check(vector<int> *varray)
    
    return 0;
}
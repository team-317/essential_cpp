// 1.5 Array和Vector
#include<vector>
#include<iostream>
// 导入std命名空间中的vector名称
using std::vector;

// 还可以使用using来设置类型别名，等同于：typedef int elemType;
using elemType = int;

void check(vector<int> varray){
    std::cout<<"在check中varray的地址:"
             <<&varray<<std::endl;
    varray[0] = 100;
}
int main(){
    /*-------------------------搞清楚数组（array）和vector的区别-------------------------*/
    // 数组就是C语言中的数组，并不陌生
    elemType array[9] = {     // 静态数组的初始化
        1,2,3,
        4,5,6,
        7,8,9
    };
    // 动态数组https://mp.weixin.qq.com/s/POjBmddtgJDi5EqxXUnNIw
    elemType *darray = new elemType[9]{1,2,3,4,5,6,7,8,9}; // 得到的是动态数组
    int size = 9;
    // elemType iarray[size];  // 不通过编译，因为在【编译阶段】size的值未知！！！
    elemType *iarray = new elemType[size];   // 可以通过编译，因为new分配空间是在【运行阶段】完成的

    // 注意：由new分配的动态数组实际上并不是一个数组类型，所以不能使用begin和end来获取其首尾地址
    // 也不能用【范围for循环（即for(auto elem:varray){//...}）】来遍历动态数组，但还是可以用动态数组来初始化一个容器
    // vector<elemType> evec(begin(darray), end(darray));  使用begin和end，错误
    // for(auto it:darray){;}   使用范围for循环遍历动态数组，错误
    vector<elemType> evec(darray, darray+9);    // 正确
    // 在一般情况下，如果需要动态数组，建议使用vector，它也是一个动态数组（内存动态增长）！！！

    

    // vector和数组相似，但又有些不同
    // vector不能像数组那样初始化，但可以将数组转化为vector
    vector<elemType> varray(array, array+5);      // 将array中的前5个元素赋值为varray
    vector<elemType> varray1(varray.begin(), varray.end()); // 初始化方式同上
    vector<elemType> varray2();                   // 可以定义一个空vector
    vector<elemType> varray3{1,5,3,9,4,7,6,2,8};  // 使用列表初始化，推荐！！！

    // 数组、vector、string都具有索引操作

    /*-------------------------值传递和引用-------------------------*/

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

    // 区分引用和取地址运算符
    elemType (&earray)[9] = array;  // 数组的引用
    vector<int> &rarray = varray;   // 引用
    vector<int> *parray = &varray;  // 取地址运算符
    
    return 0;
}
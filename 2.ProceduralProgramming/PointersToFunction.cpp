// 2.8函数指针
#include<vector>
#include<iostream>
using std::vector;
/*-------------------------用函数指针获得不同的数列-------------------------*/

// 三个数列函数，获取数列的前n个元素
vector<int>* fib_seq(int n){
    if (n<0 || n>8) return 0;
    int array[]={1,1,2,3,5,8,13,21};
    // 使用数组对vector进行初始化。需要注意的是，返回类型是指针，varray是局部变量，
    // 要使外部可以访问，则需要使用new在堆中申请空间
    vector<int> *varray = new vector<int>(array, array+n);
    return varray;
}
vector<int>* lucas_seq(int n){
    if (n<0 || n>=8) return 0;
    int array[]={1,2,4,7,11,18,29,47};
    vector<int> *varray = new vector<int>(array, array+n);
    return varray;
}
vector<int>* pell_seq(int n){
    if (n<0 || n>8) return 0;
    int array[]={1,2,5,12,29,70,169,408};
    vector<int> *varray = new vector<int>(array, array+5);
    return varray;
}

// #define TEST
#ifdef TEST
(int*) chage(int a){    // 这样的函数定义会报错，需改为int* chage(int a)
    int *b = new int(a);
    return b;
}
#endif

int main(){
    /*-------------- 函数指针和函数指针数组 --------------*/
    // 函数指针为vector<int> *(*seq_ptr)(int)
    // 函数指针也就是将函数名改为指针的形式，函数指针数组同理，如下
    vector<int>* (*seq_ptr[])(int)={
        fib_seq, lucas_seq, pell_seq
    };
    int iter = 0;
    bool run = false;
    while(run){
        vector<int>* seq = seq_ptr[iter](5);
        iter += 1;
        iter %= 3;
        for(int i=0; i<seq->size(); i++){
            std::cout<<(*seq)[i]<<"  ";
        }
        std::cout<<std::endl;
    }

    /*------------ 使用typedef和decltype简化函数指针的定义 ------------*/
    // 用decltype(fib_seq) Func来代替 std::vector<int> *Func(int n)
    // 用decltype(fib_seq) *Func表示  std::vector<int> *(*Func)(int n)
    typedef decltype(fib_seq) *Func; // 等价于typedef std::vector<int> *(*Func)(int n)
    Func fib = fib_seq;     // 等价于 std::vector<int> *(*fib)(int n) = fib_seq
    auto seq = *fib(5);
    for(auto elem:seq)  std::cout << elem << std::endl;

    /*  ------------- 函数指针和函数声明 -------------
        注意函数指针的声明和函数声明的区别，比如
        int *change(int a); 这是函数的声明，返回类型是整型指针
        int (*change)(int a); 这是函数指针的声明，返回的是整数类型
        所以函数声明int *change(int a); 更像是(int *) change(int a);但是实际上是不能这样写的，
        否则也会报错，可以通过这种方式进行理解。
    */
    // #define TEST
    #ifdef TEST
        auto a = chage(12);
        std::cout << "The value of a: " << a << std::endl;
    #endif

    return 0;
}
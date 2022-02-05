// 2.8函数指针
#include<vector>
#include<iostream>
using std::vector;
/*-------------------------用函数指针获得不同的数列-------------------------*/

// 三个数列函数，获取数列的前n个元素
vector<int> *fib_seq(int n){
    if (n<0 || n>8) return 0;
    int array[]={1,1,2,3,5,8,13,21};
    // 使用数组对vector进行初始化。需要注意的是，返回类型是指针，varray是局部变量，
    // 要使外部可以访问，则需要使用new在堆中申请空间
    vector<int> *varray = new vector<int>(array, array+n);
    return varray;
}
vector<int> *lucas_seq(int n){
    if (n<0 || n>=8) return 0;
    int array[]={1,2,4,7,11,18,29,47};
    vector<int> *varray = new vector<int>(array, array+n);
    return varray;
}
vector<int> *pell_seq(int n){
    if (n<0 || n>8) return 0;
    int array[]={1,2,5,12,29,70,169,408};
    vector<int> *varray = new vector<int>(array, array+5);
    return varray;}
int main(){
    // 函数指针为vector<int> *(*seq_ptr)(int)
    // 函数指针也就是将函数名改为指针的形式，函数指针数组同理，如下
    vector<int> *(*seq_ptr[])(int)={
        fib_seq, lucas_seq, pell_seq
    };
    int iter = 0;
    while(true){
        vector<int> *seq = seq_ptr[iter](5);
        iter += 1;
        iter %= 3;
        for(int i=0; i<seq->size(); i++){
            std::cout<<(*seq)[i]<<"  ";
        }
        std::cout<<std::endl;
    }
}
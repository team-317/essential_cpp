// 2.6、2.7 重载函数和模板函数
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
/*-------------------------重载和模板函数-------------------------*/
// 函数重载要求两个函数名的返回类型相同，
// 如果同一命名空间中的两个函数名相同，则这两个是重载函数，两者的返回类型必须相同
void display(vector<int> iarray){
    for(auto iter=iarray.begin(); iter<iarray.end(); iter++){
        cout<<*iter<<endl;
    }
}
void display(vector<float> iarray){
    for(auto iter=iarray.begin(); iter<iarray.end(); iter++){
        cout<<*iter<<endl;
    }
}

// 当重载的函数内部实现很相似时，可以考虑将重载改为模板实现
template <typename example, typename elemType>            // 必须放在函数上一行，形成模板函数
void display(vector<elemType> iarray){
    for(auto iter=iarray.begin(); iter<iarray.end(); iter++){
        cout<<*iter<<endl;
    }
}
int main(){
    return 0;
}
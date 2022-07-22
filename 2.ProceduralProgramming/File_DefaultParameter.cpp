// 2.3 提供默认参数值
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using std::vector;
using std::cout;
using std::endl;
using std::string;

/*-------------------------文件操作和默认参数-------------------------*/
// 默认参数统一位于右侧，不能同时出现在声明和定义中，一般位于声明中，而声明一般放在头文件中
void save_log(vector<int>, std::ofstream *stream=0);

void save_log(vector<int> array, std::ofstream *stream){
    for(int i=0; i<array.size(); i++){
        if(stream!=0)
            // 将数据送到io流中
            *(stream)<<array[i]<<endl;
    }
}
void show_log(std::ofstream *stream){
    int info;
    while(getline(stream, info)){
        cout << info << endl;
    }
}
int main(){
    // 默认是写，传递参数app后变为追加写，app即append mode，in则为读取模式，即input mode 
    std::ofstream myfile("./log.txt", std::ios_base::app);
    if (!myfile){
        cout<<"文件打开失败！"<<endl;
        return 0;
    }
    vector<int> array(5,5);
    // &在这里是取地址运算符，而非引用！！！
    // 如果是引用，则myfile的值一定不为0，即默认值为0将出错！！！
    save_log(array, &myfile);
    show_log(&myfile);
    return 0;
}
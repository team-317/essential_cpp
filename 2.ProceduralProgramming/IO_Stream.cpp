#include<iostream>
#include<fstream>

using std::string;
using std::cout, std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

void read_file(string fileName){
    // 打开文件的两种方式，方式一：在定义文件流时关联一个文件
    ifstream out1(fileName, std::ios_base::out);
    // 方式二：先定义空的文件流，再使用open函数进行关联
    ifstream out2;
    out2.open(fileName, std::ios_base::out);

    // 判断文件是否正常打开
    if(!out1.fail()){   // 也可以直接使用if(out1){...}
        // 使用cerr时信息会直接显示到终端，而不会先放在缓冲区
        // 如果使用cout，则信息会先放入缓冲区，当程序不正常退出时，没有从缓冲区中取出的信息将不被打印
        std::cerr << "Failed open file" << fileName << endl;
        exit(-1);
    }

    // 文件的读取操作，使用string类相关的getline函数对文件进行读取
    string info;
    cout << "方式一：使用string中的getline函数" << endl;
    while(out1){
        getline(out1, info);
        cout << info << endl;
    }
    cout << "方式二：使用 >> 运算符将信息输出到变量info中" << endl;
    while(out2 >> info){
        cout << info << endl;
    }

    // 使用与open函数相对应的close函数关闭文件
    out1.close();
    out2.close();

    // io流有四个状态位：goodbit、failbit、badbit、eofbit，可以调用相应的函数查看文件流的状态
    cout    << "good: " << out1.good() << endl
            << "fail: " << out1.fail() << endl
            << "bad: " << out1.bad() << endl
            << "eof: " << out1.eof() << endl;
}

void ifstream_and_ofstream(string fileName){
    /*
        ifstream: input file steam; ofstream: out file stream
        ifstream和ofstream类似于cin和cout，在cin和cout中程序是和终端交互的，
        而在ifsteam和ofsteam中程序中的信息是和文件进行交互的
    */

    // ifstream定义的是输入流，就像cin，用于将文件中的信息输入到变量
    ifstream out1(fileName, std::ios_base::app);
    if(!out1){
        cerr << "Can't open " << fileName << endl;
        exit(-1);
    }
    string info;
    out1 >> info;   // 将文件中的第一行信息赋给info
    cout << "The info from out1: " << info << endl;

    ofstream out2(fileName, std::ios_base::app);
    if(!out2){
        cerr << "Can't open " << fileName << endl;
        exit(-1);
    }
    // ofstream定义的文件流是输出流，将外部的信息输入到文件
    out2 << "234\n";
}

int main(){
    // read_file("log.txt");
    ifstream_and_ofstream("log.txt");
    return 0;
}
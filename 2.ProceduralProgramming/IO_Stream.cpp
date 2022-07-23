#include<iostream>
#include<fstream>

using std::string;
using std::cout, std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

/*
    fstream、ifstream、ofstream
    fstream：向文件读写数据
    ifstream：从文件读取数据
    ofstream：向文件写入数据
*/
void read_file_with_fstream(string fileName){
    // 打开文件的两种方式，方式一：在定义文件流时关联一个文件
    fstream out1(fileName, std::ios_base::in);
    // 方式二：先定义空的文件流，再使用open函数进行关联
    fstream out2;
    out2.open(fileName, std::ios_base::in);

    // 判断文件是否正常打开
    if(out1.fail()){   // 也可以直接使用if(out1){...}
        // 使用cerr时信息会直接显示到终端，而不会先放在缓冲区
        // 如果使用cout，则信息会先放入缓冲区，当程序不正常退出时，没有从缓冲区中取出的信息将不被打印
        std::cerr << "Failed open file" << fileName << endl;
        exit(-1);
    }

    // 文件的读取操作，使用string类相关的getline函数对文件进行读取
    string info;
    cout << "方式一：使用string中的getline函数" << endl;
    // getline会读取第一个换行符之前的字符串，并将这个字符串赋给info
    // 当读到文件末尾时，getline返回空字符串，while条件为False
    while(getline(out1, info)){     // 每一次读取，都会使得out1的游标向后移动
        cout << info << endl;
    }
    // 在使用getline读取到文件的末尾后，out1.eof=1, out1.fail=1, 而out1.good=0，
    // 文件将不能正常访问！！！可以通过clear函数将文件流的状态进行复位，使文件能够再次访问
    out1.clear();   // 先进行复位（一定要先复位再设置游标）
    out1.seekg(0, std::fstream::beg);   // 再将游标定位到文件开头

    cout << "或使用out1作为判断条件" << endl;
    while(out1){    // out1等价于out1.goodbit
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
    cout    << "close 后 out1 的四种状态: " << endl
            << "good: " << out1.good() << endl
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

    // ifstream定义的是输入流，从文件读取数据（cin是从终端读取数据）
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
    // ofstream定义的文件流是输出流，向文件写入数据（cout是向终端写入数据）
    out2 << "234\n";
}

int main(){
    read_file("log.txt");
    // ifstream_and_ofstream("log.txt");
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    auto a = new int[1024*1024*32]{};
    int sum = 0, index = 0;
    int *p = a;
    int *add = a;
    while(index<32*1024*1024){
        p += 256*1024;
        index += 256*1024;
        add = &(a[index]);
        *p = 100;
        sum += *(p);
    }
    return 0;
}
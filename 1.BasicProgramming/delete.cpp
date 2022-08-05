#include<iostream>
#include<string>
using namespace std;

class D{
public:
    string name = "hello";
    ~D(){
        cout << "释放空间" << endl;
    }
};

int main(){
    // auto d = new D();
    // delete d;
    auto d = D();
    return 0;
}
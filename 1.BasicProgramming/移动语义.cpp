#include<string>
#include<iostream>
#include<vector>
using namespace std;
// 移动语义可以优化内存的使用，减少变量的复制操作
void move_assign(string s){
	cout << "In move_assign func, info about s: " << s << endl;
}

void test1(){
	string s = "I'll be moved";
    // move操作会将s所在的位置从main转移到move_assign，而不是复制一份s再传递给move_assign
	move_assign(std::move(s));
    // 转移后原先的变量变为空，所以s的长度将变为0
	if(s.length() == 0)
		cout << "Move successfully! The length of s is zero" << s << endl;
}


class Move{
string s;
public:
	Move(string s_): s(std::move(s_)){
		cout << s_ << endl;
		cout << s << endl;
	}
};
void test2(){
	string s = "I'll be moved";
    // move操作会将s所在的位置从main转移到move_assign，而不是复制一份s再传递给move_assign
	Move m(s);
    // 转移后原先的变量变为空，所以s的长度将变为0
	if(s.length() == 0)
		cout << "Move successfully! The length of s is zero" << s << endl;
}
int main(){
	// test1();
	decltype(auto) a{"string"};
	cout << a << endl;
	test2();

}
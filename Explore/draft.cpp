#include<string>
#include<memory>
#include<iostream>
using std::cout, std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;
int main(){
	auto s = "adkfjad";
	auto i = 10;
	shared_ptr<int> j = make_shared<int>(i);
	shared_ptr< string> ps (new string ("I reigned lonely as a cloud."));
	// shared_ptr<int> p = make_shared<int>(42);
	cout << ps << endl;
}
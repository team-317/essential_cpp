// 3.2了解Iterator，即泛型指针，也叫迭代器，和python类似
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<unordered_set>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;
using std::set;
using std::unordered_set;
using std::begin;
using std::end;

int main(){
    /*-------------------------容器的通用遍历方式-------------------------*/
    // 容器分为顺序容器和关联容器
    // 顺序容器：vector（动态数组）、list（双链表）、deque（双端队列）、string（字符串）、数组
    // 关联容器：map（键值对）、set（集合）、unordered_map(哈希map)、unordered_set（哈希set）
    // map和set是按关键字有序保存的，unordered_map、unordered_set是按哈希函数组织的

    vector<int> myarray{4,5,2,1,2,5,1,5}; // 列表初始化

    // 使用iterator，适用于vector、list、deque、string、map、set，对于unordered_map和unordered_set不适用！！！
    // 每个标准容器都会提供一个名为begin()的操作函数，可以返回一个iterator指向第一个元素，
    // 另一个名为end()的函数则返回指向【最后一个元素的下一个位置】的iterator。
    for(auto iter=myarray.begin(); iter!=myarray.end(); iter++){
        cout<<*iter<<"  ";
    }
    cout<<endl;

    // 更简便的写法：【范围for循环】！！！
    for(auto elem:myarray){
        cout<<elem<<"  ";
    }
    cout<<endl;

    // 即使是双向链表，也可以使用泛型指针来遍历，这里使用逆向迭代器来实现逆序输出
    list<int> mylist(myarray.begin(), myarray.end());
    for(auto iter=mylist.rbegin(); iter!=mylist.rend(); iter++){    // iter++实际上是逆向的++
        cout<<*iter<<"  ";
    }

    // 对于set和unordered_set都是可以的！！！
    unordered_set<int> myunset(myarray.begin(), myarray.end());
    for(auto iter=myunset.begin(); iter!=myunset.end(); iter++){
        cout<<*iter<<"  ";
    }

    set<int> myset(myarray.begin(), myarray.end());
    for(auto iter=myset.begin(); iter!=myset.end(); iter++){
        cout<<*iter<<"  ";
    }


    // 对于vector、string可以使用数组的遍历方式
    for(int i=0; i<myarray.size(); i++){
        cout<<myarray[i]<<"  ";
    }
    cout<<endl;


    /*-------------------------容器的生成方式及初始化-------------------------*/
    // 1、产生空容器
    list<char> clist;
    vector<char> cvec;

    // 2、产生特定大小的容器
    list<bool> blist(8);
    vector<bool> bvec(8);

    // 3、产生特定大小的容器，并赋予初值
    vector<float> fvec(8,-1);
    list<float> flist(8, -1);

    // 4、通过首尾iterator产生容器，可以是数组地址，也可以是iterator对象
    int ia[8] = {1,2,3,4,5,6,7,8};
    vector<int> ivec(ia, ia+8);
    list<int> ilist(ivec.begin(), ivec.end());
    deque<int> dqueue(myarray.begin(),myarray.end());

    // 5、将旧容器复制给新容器
    list<int> intlist(ilist);


    return 0;
}
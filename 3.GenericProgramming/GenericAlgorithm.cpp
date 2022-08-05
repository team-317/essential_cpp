#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>

// 要使用泛型算法，需导入algorithm库，然后上面的这些库其实可以不用导入
#include<algorithm>

using namespace std;

/*-------------------------顺序容器的泛型算法-------------------------*/

// 泛型算法通用于不同类型的容器和不同类型的元素
int main(){
    // 既然是泛型算法，就不属于某一个类的成员函数，所以容器会被作为参数传入到泛型算法中
    int array[9] = {9,3,4,1,7,2,5,8,6};
    vector<int> ivec(begin(array), end(array));
    list<int> ilist(begin(array), end(array));
    int head = ilist.front();   // 获取容器的第一个元素
    int tail = ilist.back();    // 获取容器的最后一个元素



    // 排序
    sort(ivec.begin()+2, ivec.end()-2); // 默认升序排序，这里只对中间的5个元素排序
    // 传递lambda表达式实现降序排序，lambda表达式的返回类型为bool类型
    sort(ivec.begin(), ivec.end(),
            [](int a, int b){return a>b;}); 
    sort(ivec.begin(), ivec.end(), greater<int>());
    // 使用反向迭代器实现降序排序
    sort(ivec.rbegin(), ivec.rend());   


    return 0;
}


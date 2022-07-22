// 如果已定义宏 Flag，则不执行之后的语句，否则执行直到#endif
#ifndef Flag
// 进入预处理器后定义宏 Flag，这样当有多个文件包含scope.h时，对于主体部分（ifndef里的内容）只需要进行一次预处理
#define Flag
int var = 1;    // 定义全局变量
#endif      // 预处理器结束

vector<int>* fibon_seq(int size);
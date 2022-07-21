hello.out: hello.o	# 规则1：通过链接器将hello.o和标准库文件组合，形成最终的可执行文件hello.out
		gcc hello.o -o hello.out
hello.o: hello.s	# 规则2：通过汇编器将hello.s转化为机器指令，生成hello.o文件
		gcc -c hello.s -o hello.o
hello.s: hello.i	# 规则3：对hello.i文件进行编译，生成汇编语言文件hello.s
		gcc -S hello.i -o hello.s
hello.i: hello.c	# 规则4：对源文件hello.c进行预处理，生成hello.i文件
		gcc -E hello.c -o hello.i

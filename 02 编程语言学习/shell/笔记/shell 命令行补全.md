## 前言
最近想要完善一下我自己的UosInit脚本，觉得脚本参数这一块可以优化，其中命令行自动补全这一点很方便，所以去网上查找了一下资料后，写下此篇。
主要目的是记录 命令行工具及脚本怎么做到按tab键补全的功能。

主要参考以下两篇内容：
- https://www.cnblogs.com/gmpy/p/13202562.html#1971262189
- https://blog.csdn.net/Q1302182594/article/details/52344503

如果想要详细研究的话 man bash更加详细，但是太多了，我个人认为除非专门去做，否则不要在一个工具上下这么多功夫了。
而对于一般的研究 上面第一个链接有非常丰富的介绍，而第二个链接里有一个简单的例子。

## 命令
 自动补全是Bash Shell的功能，主要是利用了其内建的两个命令**compgen**和**complete**。
 
 ### compgen
```bash
	compgen -W "aa ab bb cc" -- "a"
```
	
表示从"aa ab bb cc"  匹配出以“a”开头的单词，上述命令的返回结果就是 “aa ab”：
```bash
liuwh@liuwh-PC:~/Desktop$ compgen -W "aa ab bb cc" -- "a"
aa
ab
liuwh@liuwh-PC:~/Desktop$
```

 ### complete
  语法：complete 补全行为选项 命令名
     解析：可用的行为选项如下所示：
- -F：执行指定函数名，候选结果保存在 COMPREPLY 数组变量里，补全功能更强大，可以实现命令参数补全，函数名在 /etc/bash_completion定义的。
- -f：补全文件名，后可跟 -X 参数。
-  -X：过滤表达式，符合表达式的文件名会被排除，即不会在补全候选显示出来，如果以感叹号开头，则表示反转，即符合表达式的文件名才显示。
-  -o：补全类型，filenames 表示补全的是一个文件，跟 -f 参数使用才有效；其它值如dirnames 表示补全目录。
 
 相关示例hello.sh可以去附件=》bash脚本补全中查看。
 使用方式是：
 ```
 source hello_complete # source 方式运行脚本 更新补全函数  root用户运行
 PATH=$(pwd):PATH	# 添加当前路径到环境变量中
 hello.sh  --[TAB]  # 执行脚本 tab补全
 ```
 ![[bash补全示例.png]]
 ## 内建变量
 
 ### COMP_CWORD
${COMP_WORDS} 的索引，指向当前光标位置所在的词。这个变量只有在被可编程补全功能 (参见下面的 Programmable Completion 章节) 调用的 shell 函数中才可用。

### COMP_LINE
当前命令行。这个变量只有在被命令补全功能调用的 shell 函数和外部命令中才可用。

### COMP_POINT
相对于当前命令起始处的当前光标位置。如果当前光标位置是当前命令的末端， 它的值就和 ${#COMP_LINE} 相等。 这个变量只有在被命令补全功能调用的 shell 函数和外部命令中才可用。

### COMP_WORDS
一个数组变量 (参见下面的 Arrays(数组)一节)，由当前命令行的各个单词构成。 这个变量只有在被命令补全功能调用的 shell 函数中才可用。

### COMPREPLY
一个数组变量，bash 从中读取可能的命令补全。 它是由命令补全功能调用的 shell 函数产生的。

### HOSTFILE
包含一个格式和`/etc/hosts`相同的文件名，当 shell 需要补全主机名时要读取它。shell 运行过程中可以改变可能的主机名补全列表；改变之后下一次需要主机名补全时 bash 会将新文件的内容添加到旧列表中。如果定义了 HOSTFILE 但是没有赋值，bash 将尝试读取 /etc/hosts 文件来获得可能的主机名补全列表。当取消 HOSTFILE 的定义时，主机名列表将清空。

### FIGNORE
一个冒号分隔的后缀名列表，在进行文件名补全时被忽略 (参见下面的 `READLINE` 章节)。一个后缀满足其中之一的文件名被排除在匹配的文件名之外。可以是这样： ".o:~".

### GLOBIGNORE
一个冒号分隔的模式列表，定义了路径名扩展时要忽略的文件名集合。 如果一个文件名与路径扩展模式匹配，同时匹配 `GLOBIGNORE` 中的一个模式时，它被从匹配列表中删除。

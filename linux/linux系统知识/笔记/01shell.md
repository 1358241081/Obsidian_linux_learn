本章节内容主要参考以下资料
[[Linux命令行与shell脚本编程大全  第3版  ,布鲁姆 ,P606.pdf]]
[[《鸟哥的Linux私房菜-基础篇》第四版.pdf]]
[[]]

课外小知识：

> CLI :命令行界面（英语：command-line
> interface，缩写：CLI）是在图形用户界面得到普及之前使用最为广泛的用户界面，它通常不支持鼠标，用户通过键盘输入指令，计算机接收到指令后，予以执行。也有人称之为字符用户界面（CUI）。通常认为，命令行界面（CLI）没有图形用户界面（GUI）那么方便用户操作。因为，命令行界面的软件通常需要用户记忆操作的命令，但是，由于其本身的特点，命令行界面要较图形用户界面节约计算机系统的资源。在熟记命令的前提下，使用命令行界面往往要较使用图形用户界面的操作速度要快。所以，图形用户界面的操作系统中，都保留着可选的命令行界面。

# shell基本语法
## shell简介
---
Shell是一种具备特殊功能的程序，它提供了用户与内核进行交互操作的一种接口。它接收用户输入的命令，并把它送入内核去执行。内核是Linux系统的心脏，从开机自检时就驻留在计算机的内存中，直到计算机关闭为止，而用户的应用程序存储在计算机的硬盘上，仅当需要时才被调入内存。Shell是一种应用程序，当用户登录Linux系统时，Shell就会被调入内存执行。Shell独立于内核，它是连接内核和应用程序的桥梁，并由输入设备读取命令，再将其转为计算机可以理解的机械码，Linux内核才能执行该命令。

### 首行格式规范

“#!”符号称为“Sha-bang”符号，是Shell脚本的起始符号，“#!”符号是指定一个文件类型的特殊标记，它告诉Linux系统这个文件的执行需要指定一个解释器。“#!”符号之后是一个路径名，这个路径名指明了解释器在系统中的位置，对于一般的Shell脚本而言，解释器是bash，也可以是sh，即用下面的两种方式作为脚本的第1行都是正确的：
```shell
#!/bin/bash
#!/bin/sh
```
含义: 设置当前shell脚本文件采用bash解析器运行脚本代码


###  注释
单行注释
```shell
# 注释内容
```
多行注释
```shell
:<<!
# 注释内容1
# 注释内容2
!
```

### shell父子关系
首先打开一个终端窗口，执行ps f命令
```bash
uos@uos-PC:~/Desktop$ ps f
  PID TTY      STAT   TIME COMMAND
23776 pts/3    Ss     0:00 /usr/bin/bash
26199 pts/3    R+     0:00  \_ ps f   #可以看到ps进程由bash命令启动
uos@uos-PC:~/Desktop$ 
```
然后执行bash ，再次执行ps f命令
```bash
uos@uos-PC:~/Desktop$ bash
uos@uos-PC:~/Desktop$ ps f
  PID TTY      STAT   TIME COMMAND
23776 pts/3    Ss     0:00 /usr/bin/bash
28092 pts/3    S      0:00  \_ bash
28123 pts/3    R+     0:00      \_ ps f
uos@uos-PC:~/Desktop$ exit  #此时退出子bash
exit
uos@uos-PC:~/Desktop$ 	#现在界面回到了父进程的bash上
```
*/etc/shells 记录当前系统支持的shell*
```bash
# /etc/shells: valid login shells
/bin/sh
/bin/bash
/usr/bin/bash
/bin/rbash
/usr/bin/rbash
/bin/dash
/usr/bin/dash
```

*改变默认shell*  
__chsh -s /usr/bin/dash__

---

## 命令
### 内建命令
### 外建命令



## 变量
运行shell时，会同时存在三种变量：

### 局部变量：
局部变量在脚本或命令中定义，仅在当前shell实例中有效，其它shell启动的程序不能访问局部变量。
### 环境变量：
所有的程序，包括shell启动的程序，都能访问环境变量，有些程序需要环境变量来保证其正常运行。必要的时候shell脚本也可以定义环境变量。
### shell变量：
shell变量是由shell程序设置的特殊变量。shell变量中有一部分是环境变量，有一部分是局部变量，这些变量保证了shell的正常运行

#### shell参数传递（这里多说一点题外话）
在shell脚本中　有许多内建的参数，这里仅仅列出跟参数传递相关的部分

参数传递
获取参数值：
$0 ： 固定，代表执行的文件名
$1 ： 代表传入的第1个参数
$n ： 代表传入的第n个参数(注意$10这个情况　会被认为是$1 和０连在一起)
```bash
  1 #!/bin/bash
  2 echo "参数0 " $0
  3 echo "参数1 " $1
  4 echo "参数2 " $2
  5 echo "参数9 " $3
  6 echo "参数10 " $10


uos@uos-PC:/tmp/test$ bash test.sh cc 2 3 4 5 6 7 8 9 aa 11
参数0  test.sh
参数1  cc
参数2  2
参数9  3
参数10  cc0　 这里可以看到参数10没有按照预料的取出来　而是参数１加上０字符串拼接了
uos@uos-PC:/tmp/test$ 
```
这里我们做一点修改
```bash
 1 #!/bin/bash
  2 echo "参数0 " $0
  3 echo "参数1 " $1
  4 echo "参数2 " $2
  5 echo "参数9 " $3
  6 #echo "参数10 " $10
  7 echo "参数10 " ${10}
  
uos@uos-PC:/tmp/test$ bash test.sh cc 2 3 4 5 6 7 8 9 aa 11
参数0  test.sh
参数1  cc
参数2  2
参数9  3
参数10  aa
```

$#：参数个数
```bash
   #!/bin/bash
   echo "参数个数:"$#
   
uos@uos-PC:/tmp/test$ bash test.sh cc 2 3 4 5 6 7 8 9 aa 11
参数个数:11
```
看到这里　假如我们想要获取最后一个参数该怎么做呢？可能本能的想到这样的写法
```bash
echo "最后参数:" $$#
#但是实际结果与我们预期不符合 可以看到这里并没有获得正确的参数　而是一个随机的数字
uos@uos-PC:/tmp/test$ bash test.sh 1 2
最后一个参数:10695　
  ```
有三个方式可以获得最后一个参数
其中一个很奇怪 我也不能理解　但是确实可以成功
```bash
  echo "最后一个参数:"${@: -1}　
  ＃echo "最后一个参数:"${*: -1}  这种方式与上面相同
  echo "最后一个参数:"${!#}
  : $@
  echo "最后一个参数:" $_
  
uos@uos-PC:/tmp/test$ bash test.sh cc 2 3 4 5 6 7 8 9 aa cc
最后一个参数:cc
最后一个参数:cc
最后一个参数: cc
```
第一种方式在后面字符串变量提取的时候会详细解释
第二种方式我是完全不理解这样做的原因，但是很诡异　确实能成功
第三种方式可能看起来比较诡异　做一个小试验可以解释一下
```bash
uos@uos-PC:/tmp/test$ echo 1 2 3
1 2 3
uos@uos-PC:/tmp/test$ echo $_
3
uos@uos-PC:/tmp/test$ echo 1 2 3 4
1 2 3 4
uos@uos-PC:/tmp/test$ echo $_
4
所以可以看出　$_ 获取的是上一次命令执行后的最后一个参数

但是在脚本传参时直接调用则会出现问题　因为关键　获取的是上一次命令执行后
所以这里使用了一个　：命令
这个命令本身不执行任何操作，只有参数展开或者执行重定向操作 用在这里是正合适啦
```

__$* 与 $@ 区别__
相同点：都是引用所有参数。
不同点：只有在双引号中体现出来。假设在脚本运行时写了三个参数 1、2、3，，则 " * " 等价于 “1 2 3”（传递了一个参数），而 “@” 等价于 “1” “2” “3”（传递了三个参数）。

__$ $__：脚本运行的当前进程号
__$！__：后台运行的最后一个进程的ID
__$?__： 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。(返回０正确是一种约定俗成，但是不遵守不会报错，只是别人在调用的时候会很迷茫)

### 变量操作

创建普通变量： name=“test” （=两边不可有空格）
创建只可函数体中使用的局部变量： local name=“test” （使用local修饰的变量在函数体外无法访问，并且local只能在函数体内使用）
引申一下后面的内容　shell脚本里，函数内的变量都是全局，也就是在一个函数中定义的变量可以不通过传参直接被别的地方使用，而且还有一点像是while for 等循环内创建的变量也是全局的。例如下面的例子
```shell
funcTestFor1() {
    for x in who am i ?; do
        echo $x
    done

    echo "x="$x # x可以使用　且整个脚本都可以使用
}

funcTestFor2() {
    echo "x="$x # x可以使用　
}

echo "x="$x # x可以使用　
```

使用变量： echo $name 或者 echo ${name} （推荐使用大括号版）
变量重新赋值： name=“new_test” （将原值覆盖）
只读变量： 使用readonly标识后的变量，不可被修改

```bash
uos@uos-PC:~/Desktop$ readonly name="123"
uos@uos-PC:~/Desktop$ echo $name
123
uos@uos-PC:~/Desktop$ name=456
bash: name：只读变量
```

删除变量： unset name; （删除之后不可访问，删除不掉只读变量）

#### 字符串变量

1. 单双引号的区别

```shell
uos@uos-PC:~/Desktop$ test=123
uos@uos-PC:~/Desktop$ echo '$test'  #打印为$test 而非我们预想的123
$test
uos@uos-PC:~/Desktop$ echo "$test"  #打印为123
123
uos@uos-PC:~/Desktop$ echo '\'      #打印为\  不会进行转义
\
uos@uos-PC:~/Desktop$ echo "\\"         #打印为\　进行转义
\
uos@uos-PC:~/Desktop$ echo "\"          #这里是等待输入了，因为判断是一个转义字符
> 

```
3）拼接字符串

```shell
uos@uos-PC:~/Desktop$ test="123"
uos@uos-PC:~/Desktop$ test2=$test456
uos@uos-PC:~/Desktop$ test2="$test"'456'
uos@uos-PC:~/Desktop$ echo $test
123
uos@uos-PC:~/Desktop$ echo $test2
123456
uos@uos-PC:~/Desktop$ 
```

4）获取字符串长度

```bash
#在${}中使用“#”获取长度

uos@uos-PC:~/Desktop$ name="test"
uos@uos-PC:~/Desktop$ echo ${#name}  		# 输出为4
4
```

5）提取子字符串

```bash
uos@uos-PC:~/Desktop$ name="0123456789"
uos@uos-PC:~/Desktop$ echo ${name:1:4}  #从第2个开始 往后截取4个字符
1234
uos@uos-PC:~/Desktop$ echo ${name::4}   #从第一个字符开始 往后截取4个字符
0123
uos@uos-PC:~/Desktop$ echo ${name:0:4}  #其实上面就是简化的写法，根据个人习惯选择吧
0123
uos@uos-PC:~/Desktop$ 
```

在这里可以引申一下

![[删除字符串前后空格#font face 楷体 center 删除字符串前后空格 center font]]







###  shell类型与环境变量
https://blog.csdn.net/weixin_28996657/article/details/112353765

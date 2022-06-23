```toc
```

这是我的obsidian笔记　我将用这个管理工具记录我的编程知识
以下是目录和相应的简介，关于obsidian可以通过网页搜索相关介绍
或者浏览obsidian官网<https://obsidian.md/>
或者b站视频<https://www.bilibili.com/read/cv15035273>
或者知乎<https://zhuanlan.zhihu.com/p/353449575>

**另外，当需要去想学什么知识的时候，就去学习点数学知识吧**

**编写原则**
_**1、尽量使用文字 而不是图片 ，使用一段时间后发现 如果是图片并不是很方便**_
_**2、可以引用网页但是存在链接失效的风险 所以遵循上一条原则 尽量使用文字 markdown格式**_
_**3、如果要引入pdf文档 则引入时要有对应的页数 形式如下**_

```
![[《鸟哥的Linux私房菜-基础篇》第四版.pdf#page=593]]
```

_**4、引入网页形式有两种**_
单纯的链接：

```
https://blog.csdn.net/weixin_28996657/article/details/112353765
```

内嵌：

```
<iframe 
 height=800
 width=1100  
src="https://wiki.archlinux.org/title/Fstab_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)"　
>
</iframe>
```

对于网页来说 如果是多个网页链接 最好以无序列表形式

- [www.baidu.com](http://www.baidu.com)
- [www.google.com`button-aaa`](http://www.google.com`button-aaa`)

_**5、图片排版尽量统一 **__
_**6、以二级标题作为页面初始标题**_
_**7、给链接取别名  示例：**_
`[[链接|别名]]`
_**7、使用图片  示例：**_
`  ![[图片名称]] `
_**8、换行  **_

```
<br></br> 或 <br/>
```

_**9、目录 结构 **_
为了统一管理除了最外层目录外，所有的次级目录如果内容多，则按照如下结构划分
```bash
├── 笔记
│   └── 基本操作.md   //存放笔记的位置 建议笔记最好有编号 方便排序
├── 附件
│   ├── Pasted image 20211210163650.png   //存放图片 音频视频 pdf等文件位置
│   └── Pasted image 20211210163741.png
└── readme.md	    //目录以及必要内容
```

## 表格

| 权限 | 对应数字 | 意义   |
| -- | ---- | ---- |
| r  | 4　   | 可读　　 |
| w  | 2　   | 可写　　 |
| x  | 1　   | 可执行　 |

### 如何设置中文

<https://www.v1tx.com/post/obsidian-set-chinese/>

### 网页播放修改倍速

> document.querySelector('video').playbackRate = 3

### 获取b站视频列表方式

- 打开学习教程的网页
  此处以b站初二数学为例
  <https://www.bilibili.com/video/BV1DJ411w7Th?p=25&vd_source=ccbe0c793ac5e34ebb735794692f049e>
- 点击F12 打开开发者模式，选择网页元素

![[视频列表获取示例.png]]

- 选择视频的url list  右键保存

![[视频列表获取示例2.png]]

- 将内容保存到本地任意文本文件内,我这里保存到了url.ini文件内

- 运行如下代码获取所有课程名称列表

```bash
liuwh@liuwh-PC ~/Desktop> sed 's/<\/li>/\\n/g' url.ini |awk -F "title=\"" '{print $2}'|awk -F "\"" '{print $1}'
11.1.1三角形的边
11.1.2三角形的高、中线与角平分线11.1.3三角形的稳定性Y
11.2.1三角形的内角Y
11.2.2三角形的外角
11.3-4 多边形及其内角和
12.1  全等三角形
12.2  三角形全等的判定(第1课时)
12.2  三角形全等的判定(第2课时)
12.2  三角形全等的判定(第3课时)
12.2  三角形全等的判定(第4课时)
12.3  角的平分线的性质
13.1  轴对称(第1课时)
13.1  轴对称(第2课时)
13.1  轴对称(第3课时)
13.2.1  作轴对称图形
13.2.2  用坐标表示轴对称
13.3.1  等腰三角形
13.3.2  等边三角形
14.1.1  同底数幂的乘法
14.1.2  幂的乘方
14.1.3  积的乘方
14.1.4  整式的乘法(第1课时)
14.1.4  整式的乘法(第2课时)
14.1.5  同底数幂的除法
14.1.6 整式的除法
14.2.1  平方差公式
14.2.2  完全平方公式(第1课时)
14.2.2  完全平方公式(第2课时)
14.4.1  提公因式法
14.4.2  公式法(第1课时)
14.4.2  公式法(第2课时)
15.1.1 从分数到分式
15.1.2 分式的基本性质（第1课时）
15.1.2 分式的基本性质（第2课时）
15.2.1 分式的乘除
15.2.2 分式的加减（第1课时）
15.2.2 分式的加减（第2课时）
15.2.3 整数指数幂
15.3 分式方程（第1课时）
15.3 分式方程（第2课时）
16.1 二次根式 第1课时
16.1 二次根式 第2课时
16.2 二次根式的乘除 第1课时
16.2 二次根式的乘除 第2课时
16.3 二次根式的加减
17.1 勾股定理 第1课时
17.1 勾股定理 第2课时
17.2 勾股定理的逆定理
18.1.1 平行四边形的性质（第1课时）
18.1.1 平行四边形的性质（第2课时）
18.1.2 平行四边形的判定（第1课时）
18.1.2 平行四边形的判定（第2课时）

```

- 运行以下代码获取视频链接

```bash
liuwh@liuwh-PC ~/Desktop> sed 's/<\/li>/\\n/g' url.ini |awk -F "href=\"" '{print $2}'| awk -F '"' '{print $1}'|sed 's/^/https:\/\/www.bilibili.com/g'
https://www.bilibili.com/video/BV1DJ411w7Th?p=1
https://www.bilibili.com/video/BV1DJ411w7Th?p=2
https://www.bilibili.com/video/BV1DJ411w7Th?p=3
https://www.bilibili.com/video/BV1DJ411w7Th?p=4
https://www.bilibili.com/video/BV1DJ411w7Th?p=5
https://www.bilibili.com/video/BV1DJ411w7Th?p=6
https://www.bilibili.com/video/BV1DJ411w7Th?p=7
https://www.bilibili.com/video/BV1DJ411w7Th?p=8
https://www.bilibili.com/video/BV1DJ411w7Th?p=9
https://www.bilibili.com/video/BV1DJ411w7Th?p=10
https://www.bilibili.com/video/BV1DJ411w7Th?p=11
https://www.bilibili.com/video/BV1DJ411w7Th?p=12
https://www.bilibili.com/video/BV1DJ411w7Th?p=13
https://www.bilibili.com/video/BV1DJ411w7Th?p=14
https://www.bilibili.com/video/BV1DJ411w7Th?p=15
https://www.bilibili.com/video/BV1DJ411w7Th?p=16
https://www.bilibili.com/video/BV1DJ411w7Th?p=17
https://www.bilibili.com/video/BV1DJ411w7Th?p=18
https://www.bilibili.com/video/BV1DJ411w7Th?p=19
https://www.bilibili.com/video/BV1DJ411w7Th?p=20
https://www.bilibili.com/video/BV1DJ411w7Th?p=21
https://www.bilibili.com/video/BV1DJ411w7Th?p=22
https://www.bilibili.com/video/BV1DJ411w7Th?p=23
https://www.bilibili.com/video/BV1DJ411w7Th?p=24
https://www.bilibili.com/video/BV1DJ411w7Th?p=25
https://www.bilibili.com/video/BV1DJ411w7Th?p=26
https://www.bilibili.com/video/BV1DJ411w7Th?p=27
https://www.bilibili.com/video/BV1DJ411w7Th?p=28
https://www.bilibili.com/video/BV1DJ411w7Th?p=29
https://www.bilibili.com/video/BV1DJ411w7Th?p=30
https://www.bilibili.com/video/BV1DJ411w7Th?p=31
https://www.bilibili.com/video/BV1DJ411w7Th?p=32
https://www.bilibili.com/video/BV1DJ411w7Th?p=33
https://www.bilibili.com/video/BV1DJ411w7Th?p=34
https://www.bilibili.com/video/BV1DJ411w7Th?p=35
https://www.bilibili.com/video/BV1DJ411w7Th?p=36
https://www.bilibili.com/video/BV1DJ411w7Th?p=37
https://www.bilibili.com/video/BV1DJ411w7Th?p=38
https://www.bilibili.com/video/BV1DJ411w7Th?p=39
https://www.bilibili.com/video/BV1DJ411w7Th?p=40
https://www.bilibili.com/video/BV1DJ411w7Th?p=41
https://www.bilibili.com/video/BV1DJ411w7Th?p=42
https://www.bilibili.com/video/BV1DJ411w7Th?p=43
https://www.bilibili.com/video/BV1DJ411w7Th?p=44
https://www.bilibili.com/video/BV1DJ411w7Th?p=45
https://www.bilibili.com/video/BV1DJ411w7Th?p=46
https://www.bilibili.com/video/BV1DJ411w7Th?p=47
https://www.bilibili.com/video/BV1DJ411w7Th?p=48
https://www.bilibili.com/video/BV1DJ411w7Th?p=49
https://www.bilibili.com/video/BV1DJ411w7Th?p=50
https://www.bilibili.com/video/BV1DJ411w7Th?p=51
https://www.bilibili.com/video/BV1DJ411w7Th?p=52
```

ps： 可以将获取的url 和课程列表复制到execl中，就能实现一一对应了。但是这个方法不好，太繁琐，以后改进，希望能够改进为脚本执行，通过curl之类的方式获取html信息

## obsidian 插件篇

### 自动生成目录

安装第三方插件  Dynamic Table of Contents

```toc
title: "## 我是一个标题" 
```

### 绘图插件

安装第三方插件 excalidraw
![[插图测试]]

### buttons

安装第三方插件buttons
资料可以看这个链接
<https://www.bilibili.com/video/BV1gQ4y1C7Rm/?spm_id_from=pageDriver>

```button
name testButtons
type command
action 关系图谱: 查看关系图谱
```

^button-jtco

### 自动补全表格

自动补全表格 Advanced Tables

| 测试 | 测试2 |
| -- | --- |
| a  | b   |

默认生效，启用即可

### 代码高亮

Editor Syntax Highlight
默认生效，启用即可

### 格式化markdown

虽说都叫 Markdown，但实际上标记和格式五花八门，很多编辑器也就一概不问，全都兼容。
这导致一些用户就习惯于混用各类标记。千奇百怪的格式既不美观，在某些编辑器上也不能正确渲染。
规范自己的书写习惯是长期的过程，使用软件辅助统一 Markdown 格式则来得更简单。

默认快捷键ctrl+alt+l

### 视频插件

**一边视频，一边笔记**需要安装两个插件到**Obsidian**，运行这两个插件——**Media Extended和Media Extended BiliBili**，把视频链接粘贴到笔记中，就可以用阅读视图打开笔记，打开视频链接就可以观看分屏视频或者悬浮视频。

<https://zhuanlan.zhihu.com/p/466468893>

<https://www.bilibili.com/video/BV1UY411b7E3>

<https://www.bilibili.com/video/BV1hf4y1P7iN>

<file:///home/liuwh/Downloads/电视剧等多个文件/新必修1/1集合/1.1.1集合的概念/概念课/1集合与元素.mp4>

目前因为未知原因 以上视频不能百分百打开 正在查明原因

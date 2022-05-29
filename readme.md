# 前言

这是我的obsidian笔记　我将用这个管理工具记录我的编程知识
以下是目录和相应的简介，关于obsidian可以通过网页搜索相关介绍
或者浏览<https://obsidian.md/> obsidian官网

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

***5、图片排版尽量统一 ***
_**6、以二级标题作为页面初始标题**_
_**7、给链接取别名  示例：**_
`[[链接|别名]]`
_**7、使用图片  示例：**_
`  ![[图片名称]] `
***8、换行  ***

```
<br></br> 或 <br/>
```

## 表格

| 权限 | 对应数字 | 意义   |
| -- | ---- | ---- |
| r  | 4　   | 可读　　 |
| w  | 2　   | 可写　　 |
| x  | 1　   | 可执行　 |

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

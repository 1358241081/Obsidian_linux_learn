```toc
title: "# c++对象模型" 
```

前言：
本学习记录使用侯捷c++对象模型视频

## c++面向对象I

### 1.C++编程简介.mp4
Object based(基于对象)
Object Oriented (面向对象)
![[Pasted image 20220608125802.png]]

### 2.头文件与类的声明.mp4


### 3.构造函数.mp4

### 4.参数传递与返回值.mp4

### 5.操作符重载与临时对象.mp4

### 6.复习Complex类的实现过程.mp4

### 7.三大函数：拷贝构造，拷贝复制，析构.mp4

### 8.堆，栈与内存管理.mp4

### 9.复习String类的实现过程.mp4

### 10.扩展补充：类模板，函数模板，及其他.mp4

### 11.组合与继承.mp4

### 12.虚函数与多态.mp4

### 13.委托相关设计.mp4

  
## c++面向对象II


### 导读1.mp4

### conversion function2.mp4
```c++
class Fraction
{
public:
	Fraction(int num,int den = 1)
	:m_numerator(num),m_denominator(den){}
	
	operator double()const{  //不要写返回值 
		return (double)(m_numerator/m_denominator);
	}
private:
	int m_numerator; //分子
	int m_denominator; //分母
};

Fraction f(3,5);
double d =4+f;
```
转换函数
### non-explicit one argument constructor 3.mp4
一个实参且没有加explicit关键字的函数
```c++
class Fraction
{
public:
	Fraction(int num,int den = 1)
	:m_numerator(num),m_denominator(den){}
	
	Fraction operator + (const Fraction&f){  
		Fraction a;
		//do something ...
		return a;
	}
private:
	int m_numerator; //分子
	int m_denominator; //分母
};

Fraction f(3,5);
Fraction d =4+f; //会出现什么呢？  会将4转换为Fraction
```

这个行为看起来很好，但是有可能出现下面的问题：

```c++
class Fraction
{
public:
	Fraction(int num,int den = 1)
	:m_numerator(num),m_denominator(den){}
	
	Fraction operator + (const Fraction&f){  
		Fraction a;
		//do something ...
		return a;
	}
	
	operator double()const{  //不要写返回值 
		return (double)(m_numerator/m_denominator);
	}
private:
	int m_numerator; //分子
	int m_denominator; //分母
};

Fraction f(3,5);
Fraction d =4+f; //会出现什么呢？  Error 二义性
```
显示的加上explict，明确的告诉编译器不要自动转换
![[Pasted image 20220614122841.png]]
仍然会报错，但是提示变为不能将double转换为Fraction
标准库内转换函数的用法
![[Pasted image 20220614123152.png]]
### pointer-like classes 4.mp4

### function-like classes 5.mp4

### namespace经验谈 6.mp4

### class template 7.mp4

### Funtion Template 8.mp4

### Member Template 9.mp4

### specialization 10.mp4

### 模板偏特化 11.mp4

### 模板模板参数 12.mp4

### 关于C++标准库 13.mp4

### 三个主题 14.mp4

### Reference 15.mp4

### 复合&继承关系下的构造和析构 16.mp4

### 关于vptr和vtbl 17.mp4

### 关于this 18.mp4

### 关于Dynamic Binding 19 (1).mp4

### 关于Dynamic Binding 19.mp4

### 关于New,Delete 20.mp4

### Operator new，operator delete.. 21.mp4

### 示例 22.mp4

### 重载new(),delete()$示例 23.mp4

### Basic_String使用new(extra)扩充申请量 24.mp4

  







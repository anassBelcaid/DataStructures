---
layout :  page
title  :  Assignment 2 Strings and Arrays
date   :  2022/10/17
permalink: /assign2/
---

<center>
<img 
    src="{{ site.url }}{{ site.baseurl }}/assets/vectors/banner.png"
    width="300"
    height="300">
</center>
* TOC
{:toc}

## Objectives:

1. Declare and manipulate structures.
2. Write some function to operate on strings.
3. Get familiar with some **string** methods
4. Operate and raw **C++** vectors.



## Structure Student

Your task is to write a **structure** `Student` which has the following attributes:
- First name
- last name
- Grade
- Age 

Write a simple program that **declare** this structure and read a **four** entires that corresponds to the student attributes and print those data.



For example, if the input is :

```
23
Adam
Hacker
20
```

The output will be:

```
23 Adam Hacker 10
```

## Strings:

### [Add Commas](https://www.codestepbystep.com/problem/view/cpp/strings/addCommas)

Write a simple function `addCommas` that accepts a string representing an **integer**. This function should add **commas** for each three digits starting from the **right**.

For example 
```
addCommas(12345678)  ====> 12,345,678
```


### [Cesar Chyper](https://www.codestepbystep.com/problem/view/cpp/strings/caesarCipher)

Write a program (with the mane function) which implement the **Cesar** code with a given **cypher**. Your program should ask the user for a **message** and a key ( the key represents translation) and then prints the **encoded** message.

**Examples**

```shell
Your message? Attack zerg at dawn
Encoding key? 3
DWWDFN CHUJ DW GDZQ
```


```shell
Your message? DWWDFN CHUJ DW GDZQ
Encoding key? -3
ATTACK ZERG AT DAWN
```


### [ ConvertToAlt](https://www.codestepbystep.com/problem/view/cpp/strings/convertToAltCaps)

Write a function named `convertToAltCaps` that accepts a string as a parameter and returns a version of the string where alternating letters are uppercase and lowercase, starting with the first letter in lowercase. For example, the call of convertToAltCaps("Pikachu") should return "pIkAcHu". 



The first letter must be a **lower case**.


**Example**:

```shell
convertToAltCaps("Pikachu") ===> "pIkAcHu"
```


### [ Count words](https://www.codestepbystep.com/problem/view/cpp/strings/countWords)


Write a function `countWords` that computes the number of **words`88 in a given string.

> A word is a succession of characters that are not **spaces**.



**Example**

```shell
auto v = countWords("What is your name?") =====> v=4
```
### [IsAllVowels](https://www.codestepbystep.com/problem/view/cpp/strings/isAllVowels)



Write a function that verifies if all the characters of a string a **vowels**.

> A vowels is character in the set `a,e,i,o,u`.

**Example**

```shell
isAllVowels("eiEIo") ====> true
isAllVowels("banana" ====> false
```



## Vectors 
### [Banish](#banish)

We will consider the following exercice
[Banish](https://www.codestepbystep.com/problem/view/cpp/arrays/banish) where we are asked to write a function `banish`  which receives a two raw vectors $$a_1$$ et $$a_2$$ and their size.

The function should remove each entry in $$a_1$$ that exists in $$a_2$$.


> An element is **deleted** by remove all the right element by one place and
adding a $$0$$ in the last place.


For example

```cpp
int a1[] = {42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1};

int a2[] = {42, 2222, 9};

banish(a1, 17, a2, 3);
```

After the call $$a_1$$ will be:

```shell
a_1 = {3, 0, 17, 8, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
```

### [Histogram](#histogram)

The goal of the [Histogram](https://www.codestepbystep.com/problem/view/cpp/collections/vector/histogram) exercise is to write a function `histogram` that accepts a **reference** to a array of integers.

> The range of each integers is $$[0,49]$$.


This function should print an **histogram** of those values grouped in $$\mathbf{10}$$ bins.
For example if we receive the array  $$\{48, 20, 31, 49, 35, 45, 33, 26, 48, 32,
19\}$$, the function must print:

```
0's : {}
10's : {19}
20's : {20, 26}
30's : {31, 35, 33, 32}
40's : {48, 49, 45, 48}
```

### [Flatten](#flatten)

In the  [Flatten](https://www.codestepbystep.com/problem/view/cpp/collections/grid/flatten), we ask to write a function that receives a **matrix** and convert it into a **flatten** vector. The elements of this matrix must be processed **Row by Row**. 

For example if we call the function with the following matrix:

$$
\begin{pmatrix}
3 & 8 & 12\\
2 & 9 & 17\\
43 & -8 & 46\\
203 & 14 & 97
\end{pmatrix}
$$

We will get the 

$$V=(3, 8, 12, 2, 9, 17, 43, -8, 46, 203, 14, 97)$$.



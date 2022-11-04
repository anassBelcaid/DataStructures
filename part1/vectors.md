---
layout : page
title  : STL vectors
date   :  2021/03/28  
permalink : /vectors/
---


<center>
<img 
    src="{{ site.url }}{{ site.baseurl }}/assets/vectors/banner.png"
    width="300"
    height="300">
</center>


* TOC
{:toc}

    
## [Collections in C++](#collections)
<a name='collections'></a>
Now we are ready to introdude the concept of `collections` in C++. they are
defined in the **Standard library** (STL).

A `collection` store a set of homogenous objects. They are implemented as
`templates` to give them the capacity to store any types without the need of
redefinition.

### [Collection Zoology](#stlcollections)
<a name='stlcollections'></a>

A `collection` store and define how to access to the elements. There are a set
of very useful collection and we present the most used ones in the following
figure:


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/collections.png"
  width="400">
</center>



### [Vectors](#vector)
<a name='vector'></a>

The `vector` collection in **C++** represents a dynamic vector which has the
flexibility of resizing itself according to the need. We mention that the
resizing is done automatically if we add or remove an element. 

> These collection will respect the concept of an array, which means thats the
values are stored in a **continguous** space. Giving a fast access to each one
of them.

We recommend the use of a vector in the following situation:

-  We prioritize the time to access to each element.
- The size of the array is knows and doesn't change regularity. 

In order to use this library, we must include its header `<vector>`

### [Initialisation](#initialisation)
<a  name="initialisation"></a>

This class has several **constructors**. The most used ones are:

1. Empty constructor $$\mathcal{O}(1)$$.

```cpp
//Create an empty vector with capacity 0
vector<int> v;  //capcity =  0

//Create a vector of string 
vector<string> strings;
```


2. Constructor with a given size: $$\mathcal{O}(n)$$

```cpp
//Create a vector of size n
vector<int> V(n);        
```

3. Constructor with an initial value.

```cpp
// Create a vector with size n and initial value 
vector<int> V(n, value);        
```


4. Constructor with Iterators. $$\mathcal{O}(n)$$.


This is the most advanced constructor which only need the memory addresses.

```cpp
int V[5]{4, -1, 3, 2, 11};  //Static array

//Create a vector from the memory of V !!!
vector<int> T(V, V+4);     

//Create a vector from T
vector<int> T2(T.begin(), T.begin()+2);
```






### [Iterating through the vector](#iteration)
<a href='iteration'></a>

On peut itérer un `vector` en utilisant les boucles d'indices ou la boucle
`foreach` déja établie dans les vecteurs simples.

We could iterate through the vector using either

- The **for** index loop.
- The **foreach** mechanism.

```cpp
vector<float> T(5);

//Indices loop
for(int i=0; i< T.size(); i++)
    cout<<T[i]<<" ";

//For each loop
for(auto v: T)
    cout<<v<<" ";
```

### [Methods ](#methods)
<a name='methods'></a>


Here is a set of useful methods:

1. `T[i]`: **Reference** on the ith element.
2. `T.at(i)`: Reference on the ith element with index verification.
3. `T.size()`: Length of the vector.
4. `T.capacity()`: Capacity of the vector.
5. `T.empty()`: Check if the vector is empty.
6. `T.front()`: Reference to the first element.
7. `T.back()`: Reference to the last element.
8. `T.begin()`: **Iterator** to the first element.
9. `T.end()`: **Iterator** to the last element.



In order to modify your vector, you have access to the following elements:

1. `push_back(value)`: Add an element to the end.
   $$\mathcal{O}(1)$$.)

2. `insert(iterator, value)`: Insert a value in the given **iterator**
   $$\mathcal{O}(n)$$.
3. `pop_back()`: remove the **last element** $$\mathcal{O}(1)$$.
4. `erase(iterator)`: erase the element pointed by the **iterator**.
   $$\mathcal{O}(n)$$.
5. `erase(begin, end)`: delete the element between **begin** and **end**.



### [Multi Dimensional vectors](#multivect)
<a name='multivect'></a>

A **multidimensional** array could be constructed using the **template**
mechanism. Since, we can specify the type of element. 

For example, let suppose we want to declare a **two**-dimensional array which is
a matrix.



```cpp
//Declate a static matrix 
float A[3][3];        

//Using uniform initialisation
int B[3][2]={ {1,2},{2,3}, {4,5} };

//Getting access to the elements.
for(int i=0; i<3; i++)
    for(int j=0; j<2; j++)
      //use B[i][j]
```

Now using the concept of vectors.

```cpp
//matrix using 4 rows and 3 columns
vector< vector<float> > matrix(4, vector<float>(3));

//Matrix with 5 rows and 2 columns with initial value 12
vector< vector<float> > matrix(5, vector<float>(2, 12));
```


We could use indices to loop through the elements.
```cpp
//loop over the rows
for(int i=0; i<4; i++)
    //Loop over the columns
    for(int j=0; j<3; j++)

        //Use indexing matrix[i][j]
```


We could also use the **for each ** mechanism


```cpp

//using a for each over the line
for(auto line: matrix)
    for(auto value: line)
        //use of value
```


### Exercise : Matrix vector product
 
On cherche à écrire un programme qui implémente la **multiplication** entre une
matrice

Write a program ( or function) to compute the product of a matrix
$$A\in\mathcal{M}_{n,m}$$  and a  $$x\in\mathbb{R}^m$$:


$$
B = \begin{pmatrix} a_{1,1} & a_{1,2}&\ldots& a_{1,m}\\
                a_{2,1} &  a_{2,2}&\ldots&a_{2,m}\\
                \vdots & \vdots & \vdots &\vdots \\
                a_{n,1} & a_{n,2}&\ldots & a_{n,m}\end{pmatrix}

\begin{pmatrix}x_1\\x_2\\\vdots\\x_m\end{pmatrix}
$$

A simple recall of the expression of the resutl


$$
B_i = \sum_{j=1}^m A_{i,j}x_j\quad 1\leq i \leq n
$$




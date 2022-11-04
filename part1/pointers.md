---
layout : page
title  : Memory and Pointers
date   :  2022/10/20
permalink: /pointers/
---


<center>
<img src="{{ site.url }}{{ site.baseurl
}}/assets/pointers/illustration_xkcd.png"
width="500">
</center>

-----
* TOC
{:toc}
-----





## [Definition](#whatisapointer)
<a name='whatisapointer'></a>

- An important notion in **C++** is the notion of `pointer`.
- The implementation of **Data structures** rely heavily on pointers.
- They are an advanced tools as they allow the programmer to **directly** manipulate data in the **memory**.




### [The memory concept](#memory)
<a name='memory'></a>

The memory in your machine could be represented as row of chank (or block) each
block has an **address**.

> This has a huge similarity with array. Where indices are the addresses and the
values has the bit encoding of values.




<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/illustration_memory.png">
</center>

- In **C++**, the position of each block is given by a fixed address that give
    us its placement in the RAM.

In order to understand this concept, let's imagines a variable:

<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/variable_representation.png">
</center>

Now in order to represent a variable, we store

- its names.
- its value.
- its Address.


For example the following diagram


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/erick_variable.png">
</center>

represents a variable with the type `string` named **name**. Its value is
**Erich** and its address is **200**.

> An important point to remember, is that the Operating system who gives us this
value.

### [Pointers and memory](#def)
<a name='def'></a>

Now lets imagine we want a variable that could **change its memory placement**.
Or, we could imagine a variable (where its values are **memory address**).


```cpp
//Simple variable
string var = "Erick"

// Variable to store the address of var
int *pointer = &var;
```


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/pointer_erick.png">
</center>


We could define a pointer as 

> A pointer is a variables whoses values are **addresses**.

Since the address of pointer in not important, we will use the following
diagram:


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/pointer_erick_2.png">
</center>


Here is a simple program that uses pointers to manipulate the data:


```cpp
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
   //Declare two variables
  int a = 13;
  int b = 15;

  //Print there addresses.
  cout<<"adresse of a: "<<&a<<endl;
  cout<<"adresse  of b: "<<&b<<endl;

  //Create a pointer on int
  int* p;
  
  //p  now point on a
  p = &a;
  cout<<"P pointe on : "<<p<<endl;

  //Now we will change p
  p = &b;
  cout<<"Now P point on  : "<<p<<endl;

  return 0;
}
```


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/change_point_left.png">
</center>


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/change_point_right.png">
</center>

**Take away**

- Each variable has an **address**. 
- Inversely, each address has **unique** memory value.
- The compiler knows the **address** of each variable.
mémoire.
- If we have the address of a variable, we could **extract** its value.

## [Syntax](#syntax)
<a name='syntax'> </a>

In order to declare a pointer, we precede the type with a star.


```cpp
//A pointer on integers
int* p;

//Pointer on strings
string* p2;

//Pointers on vectors
vector<int> * pV;
```


### [Extraction](#deference)
<a name='deference'></a>

Once we declare a pointer, we could `extract` the value stored in the memory
which it point to using also the **star** operator.


> this rise an ambiguity between the star of the declaration and the extracting
operator.

```cpp
//Declare a simple pointer
int a = 14;
int* p = &a;

//Print the adress and value 
cout<<"[value: "<<a<<", adress: "<<&a<<"]"<<endl;
cout<<"[value: "<<*p<<", adress: "<<p<<"]"<<endl;
```


A good convention is to finalise  a pointer that has no address to `nullptr`.

```cpp
int *p = nullptr;
```

> In this case, we must be careful as we canno't use the extraction operator in
an empty memory. Otherwise this will lead to the classical `segmentation fault`
error.




Also we could test if the pointer is null by simply using the name of the
pointer:
```cpp
if(ptr)   // pass the test if pointer is not null
if(!ptr)  // pass the test if the pointer is null
```
### [arithmetic](#arithmetique)
<a name='arithmetique'></a>


We could use some useful arithmetic operations to manipulate pointers:

For two pointers  $$p_1$$ et $$p_2$$:

- `p++`: Goes to the next memory case.
- `p + d`: Jumps by $$d$$ memory blocks.
- `p--`: return the previous block. 
- `p-d`: Jump back to the $$d$$ block.
- `p1 < p2`: boolean value that returns true if  $$p_1$$ **precedes**
$$p_2$$.



## [Pointers and arrays](#arrays)
<a name='arrays'></a>

### [array and pointers](#arraypointers)
<a name='arraypointers'></a>


A static array in **C++** is simply a **constant** pointer to the first
element. The constant aspect means that we cannot change is placement to avoid
losing the memory stored by the array.


Hence if we declare a static array


```cpp
//Declare a static array
int A[]{2,4,5,9,1};
```
- The first remark is that we cannot change the address of **A**. The expression
    `A++` will leads to an error.
- We could manipulate **A** either by indices or addresses.


<center>
pointer array
<img src="{{ site.url }}{{ site.baseurl }}/assets/pointers/pointer_array.png">
</center>


### [Looping an array](#looping)
<a name='looping'></a>

Pour parcourir le tableau, on pourra utiliser l'une de ces trois méthodes:

We could use the **pointers arithmetics** to loop an array:
```cpp
//Looping using indices
for(int i=0; i<5; i++)
    cout<<A[i]<<" ";

//Same loop using the extracting operator
for(int i=0; i<5; i++)
    cout<<*(A+i)<<" ";

//Advanced loop using pointers
for(int* p=A; p<A+5; p++)
    cout<<*p<<" ";
```



#### Exercice:

Lets suppose that we have an **STL** vector, and we want to print its values
using the **pointers** mechanism

> You cannot use the [] operator nor the at function.

> Hint: Search the data function.


```cpp

void printVector(vector<int> Arr)
{
    //You cannot use the [] nor at
}
```


## [Pointers and functions](#functions)
<a name='functions'></a>


For functions, we mentioned that we have the following type of passing
arguments:
- by copy
- by reference.
- by `address`.

Lets try to illustrate this concept for the classical exercise of swapping the
values of two variables.

Here is a program that achieves this, 

> Focus on the last version which uses pointers.


```cpp
#include <iostream>

using namespace std;

//First function no hope
void swap_copy(int a, int b)
{
    auto tmp = a;
    a        = b;
    b        = tmp;
}

//Second version (Prefered) references
void swap_ref(int &a, int &b)
{
    auto tmp = a;
    a        = b;
    b        = tmp;
}


//Third version (advanced) adresse
void swap_add(int *a, int *b)
{
    auto tmp = *a;
    *a       = *b;
    *b       = tmp;
}


int main()
{
  int a = 45;
  int b = 30;
 
  //Calling the first one
  swap_copy(a, b);
  cout<<"State after swap copy: \n";
  cout<<"[a: "<<a<<", b:"<<b<<"]\n";

  //Calling the second one
  swap_ref(a, b);
  cout<<"State after swap_ref: \n";
  cout<<"[a: "<<a<<", b:"<<b<<"]\n";


  a = 45;
  b = 30;

  //Call by adress (pay attention to the adresses)
  swap_add(&a, &b);
  cout<<"State after swap_add: \n";
  cout<<"[a: "<<a<<", b:"<<b<<"]\n";


  return 0;
}
```



## [Memory allocation](#memory)
<a name='memoryall'></a>

Now we will turn our attention to the advantages of using pointers to create
**dynamic** array which could change their capacity.

> Memory allocation refers to the concept for creating memory in the `heap` in
the fly (at run time).

In order to manage the memory space created in the heap, we must use **pointers**!!




### [Allocation](#new)
<a name='new'></a>


In order to create memory space, we use the `new` operator. For example:


```cpp
//pointer
int *ptr;

//Allocate a single case
ptr = new int;

//Give a value to this value
*ptr = 45;
```

In this example, we created a **single** value and we used the pointer **p** to
manipulate its data.

> A question arises, is how can we allocate several valuees like an array.


```cpp
//pointer as an array
int *Arr;

//allocate n cases
Arr = new int[3];

// allocate another spaces
//(memory leak as we forget to delete the previous space)
Arr = new int[6];
```

In a general way to allocate **N** blocks of type `T` is 

```cpp
T* ptr = new T[N]; 
```


### [Destruction ](#delete)
<a name='delete'></a>
As mentioned in the previous example, as **C++** programmer you must manage your
memory use, Hence you must delete any  space that is in use anymore.

> As as rule of thumb, if you allocate a memory space, it is your responsibility
to delete it.


Memory space could be deleted by the `delete` operator.

- `delete ptr`: delete a single value.
- `delete [] ptr`: delete a space by a vector.


```cpp
//Pointer
int *ptr;

//allocate a single value
ptr = new int;

//Delete this value
delete ptr;

//allocate 5 values
ptr = new int[5];

//Delete this space.
delete [] ptr;
```



---
layout : page
title  :  Functions
date   :  2022/10/10
permalink: /basics/
categories:  jekyll updates
---


# Table de matière

1. [Functions](#functions).
2. [Structures](#structures)
3. [Headers](#includes).



# Basics
<a name='linkLabel'></a>

The goal of this lecture it get you up to write basic **C++** programs with input and output.You will learn also to write your proper **structures** with some basic methods. You should also learn the mechanism of headers to structure your code.

## fonctions
<a name='functions'></a>

Either you are programming with a **procedural** approach or using **Object
Oriented paradigm**, you'll have to write some `functions`. Functions are the heart of programming. So what is a function

> A function is a set of instructions grouped to complete a given task.

> 1. For a better design, the task of a function should be simple and encourage **reusibility**.

> 2. With this in  mind, a good rule of advice is not to have functions with than **10 lines.**.
     


In order to illustrate the use and importance of functions, let's solve the
difficult problem of decomposing a number into a product of **primes** numbers.

$$
 n = \prod_{i} p_i ^{r_i}
$$

Where $$p_i$$ are **prime** numbers and **r_i** their multiplicity.


We if think carefully about this problem, we could extract the following
**parts**.


- `bool is_prime (int n)`: to verify if a number is **prime** or not. (a predicate)

```cpp

bool is_prime(int n)
{
    auto limit = floor( sqrt(n) ) ;
    for(auto div = 2; div<= limit; div++)
        if( n % div == 0)
            return false;

    return true;
}
```


- `int order( int n, int facteur)`: to compute the **multiplicity** of a given
    prime factor.

```cpp
int order(int n, int factor)
{
    auto count = 0;

    while( n % factor == 0)
    {
        count ++;

        n /= factor;
    }

    return count;
}
```

- `void print_decomposition(int n)`: Main function to compute the decomposition.

```cpp
void decomposition(int n)
{
    //Print the first value of n
    cout<<n<<"= ";
    
    //prime factors to test
    auto fact = 2;

    //while there are some factors we continue
    while( n >1)
    {
        if( (n % fact == 0) && (is_prime(fact)) ) 
            {
                auto r = order(n,  fact);

                cout<<"("<<fact<<"**"<<r<<") ";

                n /= pow(fact, r);
            }

        fact++;
    }

    cout<<endl;
}
```

Like in `Java`, we could **overload** functions by modifying:


1. The number of their arguments.
2. The type of the arguments.

For example, suppose we have the following declaration for the same **function**
name:

```cpp
//F1
float Log();

//F2
int Log(int l);

// F3
float Log(float l);

// F4
float Log(float l, float base);
```

Those functions are easily **differentiable** by their arguments.


```cpp
auto v1 = Log(5.5);      //F3

auto v2 = Log(5)         // F2

auto v3 = Log(3, 3);    //F4

auto v4 = Log()        //F1
```

> Functions cannot be differentiated just by their return value



```cpp
int Log(int a)

float Log(float b)  //Problème
```


<div class="fig figleft">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/overloading_by_type.png" >
</div>
<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/overloading_by_number.png" width="500">
</div>




> C++ offers a powerful mechanism to give defaults values to arguments


Let consider the following **declaration**.


```cpp
void temp(int i=10, float f = 8.8)
```

We could call this function either by specifying:

- the values of the two arguments.
- The value of one argument (will be attached to **i**)
- zero values and the function will use the two default arguments.




<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/default_arguments.png" >
  <div class="figcaption">Illustration of default arguments in C++</div>
</div>



-----



### Arguments


C++ offers three ways of receiving arguments:


1. By copy (default).
2. By reference.
3. By address. 


Let's illustrate those calls by the following example:


```cpp
#include <iostream>

using namespace std;

//Function to double its argument
int doubleValue(int x)
{
    x *= 2;

    return x;
}

int main(int argc, char *argv[])
{
    int myValue = 5;
    int result = doubleValue(myValue);

    cout << myValue << endl; // myValue will not change
    cout << result << endl;
    return 0;
}

```

Lets now compare the execution with the second type which is by **reference**


```cpp
//Function to double the value of its argument
int doubleValue(int & x)
{
    x *= 2;
}
```

- With this type of communication, **C++** will allows you to modify an
    argument.
- This type of communication is always preferred for high memory space object,
    which allow to use a variable without **copying** it.

> Also with those type of function, we need a variable name (**lvalue**).
Callinng it with a a simple value wouldn't work.


```cpp
doubleValue(15) // Expect an l-value???
```

> The third type (by address) uses pointers.

## Structures
<a name='structures'></a> 

 A **structure** in C++ is a group of data to form a new **type**.


For example, let's say we want to define the type **Studant**. It will be
represented by:


1. name (`string`)
2. state (`string`)
3. age   (`int`)

We could declare this structure in **C++** by the keyword `struct`.


```cpp
struct Student {
   string name;        //Attribute or field.
   string state; 
   int age;
};

//Use
Student S;
S.name = "Karim";   //. in order to get the fields
S.state = "Fes";
S.sage = 19;
```
This allow for a **compact** representation and ease of use in functions. For
example, let's say we want to print the information of the student, instead of
passing all its fields, we use an instance of this **struct**.


```cpp

void printStudentInfo(Student S)
{
   cout<<S.name<<" From "<< S.state<<" ( "<<S.age<<" )"<<endl; 
}
```

We could instantiate the fields of a structure using the `{}` operator.

```cpp
Student S = {"Imad", "Fes", 19};  //We should be careful about the order.
```

### The **pair** structure.


- A `pair` is a **predefined** structure with only two attributes.
    - first
    - second
- This structure is a `template` which means you should specify the **type** of
    each field.



```cpp

// Initiate a pair of integers.
pair<int, int> point;

//Get the fields
point.first = 3;
point.second = 4;
```

We also could use **uniform initialisation** to instantiate the pair:




```cpp
//initiate the pair with {4,5}
pair<int, int> point{4,5}

//Printing the values
cout<<point.first<<", "<<point.second<<endl;
```

We also could use the `auto` keywoard to exact the fields


```cpp
//Initiating the pair
pair<int, int> point{4,5}

//Extracting the values
auto [x, y] = point;

//Printing the values
cout<<x<<", "<<y<<endl;
```

A very useful method to create pairs is `make_pair`:


```cpp
//Fast creating of a pair using make_pair and auto
auto point = make_pair(22, 33);

//Getting the values
auto [x, y] = point;

//Printing the values
cout<<x<<", "<<y<<endl;
```

- For all the functionality of the struct pair check the <a href=" http://www.cplusplus.com/reference/utility/pair/">official documentation </a>
- If you want to store several values (more than two), you could use the
    structure  <a href="https://en.cppreference.com/w/cpp/utility/tuple">Tuple</a>
- Pairs are very useful to write function that return more than one single
    value. Let's consider the example of solving a second order polynomial in
    $$\mathbb{R}$$.


$$
ax^2 +bx + c = 0
$$

Our exercise will be to write a function with the following prototype:

```cpp
pair<bool, pair<double, double> > quadratic(int a, int b, int c)
```

1. The first value of the function return a **boolean** indicating either we
   have a solution or note.
2. The second field (which is a pair two) will store the solution values.


> Solution dans la démo.


## Includes
<a name='includes'></a>

<div class="fig figleft">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/header_icon.png"
  width="100" height="100" >
</div>

- **Header** are a mandatory process if you want to work with a large project. 
- They help you to structure your project into modular parts.

- **header** files have the **.h** or (**.hpp**) extension.

- A caveat to watch for is : those files could be included by several programs.
    Hence, we should assure that the function they defined are only introduced
    **once**. In order to achieved that we always add the following line to our
    header:

    ```cpp
    #pragma once
    ```



```cpp
// include_example.h
#pragma once
int square(int x);
bool even(int value);
```


```cpp

// include_example.cpp
#include <iostream>
#include "include_example.h"


// We could call the function normally now, as they have be defined
int main() {
    cout << square(15) << endl;
    if (even(42)) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }
}

int square(int x) {
    return x * x;
}

bool even(int v) {
    return v % 2 == 0;
}
```
-----------------------




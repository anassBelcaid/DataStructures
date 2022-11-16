---
layout : page
title  :  Complexity practice
date   :  2022/24/11  
permalink: /assign4/
---


* TOC
{:toc}


## Evaluating Complexity

### [Big Oh 1](https://www.codestepbystep.com/problem/view/cpp/bigoh/bigoh1)

Give the complexity of the following snippets:

```cpp
//a)
int sum = 0; 
for(int i=0; i<=N+2; i++)
    sum++;

for(int j=1; j<=N*2; j++)
    sum += 5;
cout << sum << endl;
```


```cpp
//b)
int sum = 0;
for (int i = 1; i <= N - 5; i++)
    for(int j = 1; j<= N-5; j+=2)
        sum++;
cout<< sum <<endl;
```

```cpp
//c)
int sum = N;
for(int i = 0; i < 100000; i++)
{
    for(int j = 0; j <= i; j++)
        sum += N;

    for(int j = 1; j <= i; j++)
        sum += N;

    for(int j = 1; j <= i; j++)
        sum += N;
}

cout<< sum << endl;
```

```cpp
//d)
Vector<int> list;
for( int i = 1; i <= N * N; i++)
{
    for(int j = 1; j <= N; j++)
        list.add( i + j);
}

for( int i = 1; i <= 2 * N; i++)
    list.remove( liste.size() - 1);

cout << "done!" << endl;
```


```cpp
//e
HashSet<int> set1;
for( int i = 1; i <= N; i++)
    set1.add(i);

Set<int> set2;
for(int i = 1; i <= N; i++)
{
    set1.remove(i);
    set2.add(i + N);
}
cout << "done!" << endl;
```

### [Big Oh 2](https://www.codestepbystep.com/problem/view/cpp/bigoh/bigoh2)

Same question:


```cpp
// a)
int sum = 0;
for (int i = 1; i <= N - 2; i++)
{
    for (int j = 1; j <= i + 4; j++)
        sum++;
    sum++;
}

for( int i = 1; i <= 100; i++)
    sum++;

cout << sum << endl;
```

```cpp
// b)
int sum = 0; 
for (int i = 1; i <= N; i++)
{
    for(int j = 1; j <= N * N; j++)
        sum++;
    
    for(int j = 1; j <= 100; j++)
        sum++;
    
    for(int j = 1; j <= N; j++)
        sum++;

    sum++;
}
cout << sum << endl;
```

```cpp
//c)
int sum = 0;

for( int i = 1; i <= N; i++)
{
    for( int j = 1; j <= 100; j++)
        sum++;

}

for( int k = 1; k <= 1000; k++)
    sum++;

cout << sum << endl;
```


```cpp
// d)
Set<int> set;
for (int i = 1; i <= N * 2; i++)
    set.add(i);

for(int k : set)
    cout << k << endl;
cout << "done!" << endl;
```

```cpp
// e)
Vector<int> vec;
for( int i = 1; i <= N + 100; i++)
    vec.add(i);

Stack<int> stack;
while( !vec.isEmpty() )
{
    stack.push(vec[vec.size() - 1]);
    vec.remove(vec.size() - 1);
}

while( !stack.isEmpty() ) 
    stack.pop();

cout << "done!" << endl;
```


### [Big Oh 3](https://www.codestepbystep.com/problem/view/cpp/bigoh/bigoh3)


Evaluate the complexity of the following snippets:

```cpp
// a)
HashSet<int> set1
for( int i= 0; i < N; i++)
    set1.add(i);


Set<int> set2;
for( int n : set1)
    set2.add(n);

cout << "done!" << endl;
```

```cpp
//b)

Vector<int> list;

for( int i = 0; i < N; i++)
    list.insert(k0, i*i);

Set<int< set;
for (int k : list)
    set.add(k);

cout << "done!" <<endl;
```

```cpp
// C
Vector<int> list1;
for(int  i = 0; i < N; i++)
    list1.add(i);

Vector<int> list2;
for(int i = 0; i < N; i++)
{
    list2.insert(0, list1[0]);
    list1.remove(0);
}

cout << "done!" << endl;
```


```cpp
// d)
int sum = 0;
for (int i = 0; i < N * 2; i++)
    for(int j = 0; j < 100; j++)
        for(int k = 0; k < j*j*j; j++)
            sum++;
cout<< sum << endl;
```

```cpp
// e)
int sum = 0;
for(int i = 0; i < N * 2; i++)
    for(int j = 0; j < i/2; j++)
        for(int k = 0; k < N*N; k++)
            sum++;
cout << sum << endl;
```


## [Search](#binary)

The goal of this section to **code** and **visualize** the running time of the search algorithms presented in the lecture.


> The starting code is in  <a href="{{ site.url }}{{site.baseurl}}/part2/search.zip">search_simulation.zip</a>


### [linear Search](#linear)


As the first step finish the code of the function **linear search** which is in `tests.h`

```cpp
int linear_search( vecI & nums)
{
  
}
```


### [Adding Tests](#tests)

Before measuring the running time, we want to make sure that our function produces the correct output. We will simple **unit test** using the `assert` function in the [assert.h](http://www.cplusplus.com/reference/cassert/assert/). Here is the syntax of this function:


```cpp
assert( boolean expression);
```


For example, the instruction `assert( 1 == 1)` will produce nothing since the logical expression is correct.  In the other hand, , the instruction `assert( 1 == 0 )` will generate an running error and stops the program.

In the header `tests.h`, you'll find the function `void tests`. Its main role is verify if the function produces the correct result. You could assume that `F` is a generic function for the search problem.

```cpp
void tests(int (*F)(vecI &, int) )
{

}
```

With this function we could add the following code to test our function:

```cpp
// Simple vector
vecI nums{1,2,7, 8, 9, 12};

//compute the index of 8
auto index = F(nums, 8)

//make sure that the index is 3
assert( index == 3);

//Write down the success message
cout << "Test 1 success" << endl;
```


Your role is to add some **testing** cases for your function.

- Add a test where the function **can't find** the value.
- Add a test where we test an empty vector.
- Write a test where the value is at the end.
- Write a test where the array has **10 values**.


### [Timing your function](#timing) 

Maintenant qu'on a assuré que notre fonction est correcte, on dois mesurer son
temps d'exécution. On sait déja qu'elle est **linéaire**, cependant on va
mesurer cet aspet.

Now that we check the correctness of our function, we could measure its time. We already that its **linear**. But the goal is to confirm that the rigorous simulation.

In order to measure the running time in `c++`, we will use the class 
`high_resolution_clock` in the 
[chrono](https://en.cppreference.com/w/cpp/chrono/high_resolution_clock) library. 

You goal now is to use the function to  finish the implementation of the `timing` in the `simulation.cpp` file.


```cpp
double timing(int(*F)(vecI &, int), vecI & nums, int target)
{
    // Measure teh time of the function F 
}

```


### [Binary Search](#binarySearch)

Now we will repeat the same procedure for the binary search method. Hence in the file `tests.h`, you should implement the function `binary_search`


> In order to test your new function, change the call of the tests functions to 

```cpp
tests(&binary_search)
```

### [Side By Side simulation](#sidebyside)


Finally, you could compare both running times by generating and plotting the result of each time:

Try to produce and table with the following form:

<center>
<style type="text/css">
.tg  {border-collapse:collapse;border-color:#ccc;border-spacing:0;}
.tg td{background-color:#fff;border-color:#ccc;border-style:solid;border-width:1px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:1px 2px;word-break:normal;}
.tg th{background-color:#f0f0f0;border-color:#ccc;border-style:solid;border-width:1px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:1px 2px;word-break:normal;}
.tg .tg-buh4{background-color:#f9f9f9;text-align:left;vertical-align:top}
.tg .tg-0lax{text-align:left;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-0lax">Size </th>
    <th class="tg-0lax">Time linear<br></th>
    <th class="tg-0lax">time binary</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-buh4">100</td>
    <td class="tg-buh4"></td>
    <td class="tg-buh4"></td>
  </tr>
  <tr>
    <td class="tg-0lax">200</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-buh4">400</td>
    <td class="tg-buh4"></td>
    <td class="tg-buh4"></td>
  </tr>
  <tr>
    <td class="tg-0lax">...</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-buh4">6400</td>
    <td class="tg-buh4"></td>
    <td class="tg-buh4"></td>
  </tr>
</tbody>
</table>
</center>


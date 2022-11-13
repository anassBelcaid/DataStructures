---
layout : page
title  : Algorithms Analysis
date   :  2022/11/13
permalink : /complexity/
---


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/bigoh_growth.png"
  width="400" height="400">
</center>


-----
* TOC
{:toc}
-----

    


## [Introduction](#intro)
<a name='intro'></a>

The main objective of this lecture is to teach you to evaluate **the complexity** of an algorithm. Simply put, given an algorithm, we are trying to evaluate the `the number of basic oeprations` and the space memory it needs in its execution. We will also study the growth of this number with the size of problem.

This will allow us to **compare** and estimate the **running time** of an algorithm without the need to execute it. 


### [Two sum](#twosume)
<a name='twosume'></a>

Let's illustrate this study with a classical problem `twosum`. The goal of this problem is to determine if an array $$L$$ has two elements $$a$$ and $$b$$ such that their sum is equal to a given target $$T$$. 


$$
(a, b) \in L^2,\;\;  a + b =T
$$

For example, if we consider the array   $$L = [1, 4, 6]$$ and the target $$T = 10$$. Then the function must return `True` since
$$
6  + 4 = 10
$$

However if the target is $$T = 11$$, the function must returns `False` since there no two elements that verifies the property.

Let's start with the **naive** approach, where we scan for each element if there is another one in the array such there sum is equal to the target.

```cpp
bool brute_force(vecI &nums, int target)
{
    for(int i=0; i<nums.size()-1; i++)
    {
        for(int j=i+1; j<nums.size(); j++)
            if( nums[i] + nums[j] == target)
                return true;
    }

    return false;
}
```

This is what we call **brute force** algorithm.

Now we will consider another approach where we will use a **mysterious** data structure (coming soon). The ultimate goal of this data structure is verify if an element exists or not in the collection.



```cpp
bool set_search(vecI & nums, int target)
{
    //Same program but using set search
    set<int> cache(nums.begin(), nums.end());

    for(auto v: nums)
        if( cache.find( target - v) != cache.end() )
            return true;

    return false;
}
```

> Now for the main question, if you have to **choose** between those two algorithms. Which one will you choose? 

In order to get the answer, we must analyse the following points:

- For those two algorithms, what is their running time?
- How much space (memory) they occupy in order to get the answer?


A first simple approach to answer the first question, is run both of them for  different (growing ) size of the array and measure each running time.

You can execute this simulation with the code [complexity simulation]():


<center>
<img src=" {{ site.url }}{{ site.baseurl }}/part2/images/simulation_numbers.png"
height="150">
</center>


- The running time of the second version is considerably **low** compared to the first one.

 - Each time we double the size of the problem, the running time of the first version **doubles** also.


This already gives a clear answer abou the superiority of the second version. But we must measure the **order of growth** of each algorithm:

We could graphically present their graph as a function of $$N \longrightarrow T(N)$$ where $$N$$ represents the size of the problem and $$T(N)$$ is the running time:


<center>
<img src=" {{ site.url }}{{ site.baseurl }}/part2/images/linear_two_sum.png"
height="300" width="400" >
</center>

The problem of this plot, is the running time seems almost constant compared to the growth of the first one. A useful solution, is to plot them in a **logarithmic** scale. Where we represent  $$ \log(N) \longrightarrow \log(T(N))$$.

> A second remark for the blue plot what is the order of growth, $$N$$, $$N^2$$,$$N^3$$ or $$e^N$$.




<center>
<img src=" {{ site.url }}{{ site.baseurl }}/part2/images/logarithmic_two_sum.png"
height="250" width="500" >
</center>

Now we can see that both graphs are direct lines. This order of growth is simply the **intercept** of the line.

1. The first **intecept** is $$2.06$$ leading to $$T(N ) \approx N^2$$.
2. The second line has $$1.03$$ which concludes that $$T(N) \approx N$$


### [Array pivot](#pivot)
<a name='pivot'></a>

We reinforce the ideas of the first exercise, we will repeat the same analysis for a second problem called `Pivot Index` of an array `T`. The problem goes as follow: 

> For a given array $$T$$, compute is `Pivot index` is it admits one. A pivot index index is where the sum of **srict** left is equal to the sum of **strict** right.

Here is a naive approach:


```cpp
bool brute_force(vecI &nums, int target)
{
    //Solving the pivot problem
    for(int i=0;i<nums.size(); i++)
    {
        auto left = 0;      //left sum
        auto right = 0;     // right sum

        //Calcul somme Gauche
        for(int j = 0; j<i; j++)
            left += nums[i];

        //Calcul somme droite
        for(int j=i+1; j<nums.size(); j++)
            right += nums[i];

        if( left == right)
            return i;
    }

    return false;
}
```

We will compare it the following proposition

```cpp
bool smart_search(vecI & nums, int target)
{
    //Same program but using set search
    auto right = 0;
    for(int i= 0; i<nums.size(); i++)
        right += nums[i];

    auto left = 0; 

    for(int i=0; i<nums.size(); i++)
    {
        right -= nums[i];

        if(left == right)
            return i;

        left += nums[i];
    }

    return false;
}
```


 Here is the result of the time analysis:

<center>
<img src=" {{ site.url }}{{ site.baseurl }}/part2/images/logarithmic_pivot.png"
height="250" width="500" >
</center>

----

## [Basic rules](#rules)
<a name='rules'></a>

Now we focus on evaluating the number of operations of algorithm. This depends heavily the **architecture** that will run the algorithm. We will focus on the simple case of **unique processor** which executes the instructions in a **sequential** manner.


### [Basic operations](#operations)
<a name='operations'></a>

Also we mut define what are the **basic operations** since a complex operation could be resumed in a single instruction in a high level language such a `python`. A clear example is the function `string.find`. We cannot accept that call as a simple instruction since there is black box executed behind and we must know it was implemented. Hence here is the basic operations for our analysis:




1. `arithmetic oeprations`: +, -, *, \, %.
2. `logic operations`: <, >, <=, >=, !=, ==.
3. `control statements`: if. 

Another remark is that operations are constants for **basic types** such as integer or floats. This cannot be the case of high level types such as **string** The sum or comparison between those objects is **not constant**.

Now that we have a basic tools for computing operations, let's apply those concepts on `pivot index`.


1. `for(int i=0; i<nums.size(); i++`: **1** Initialisation + **N** repetition.
2. `auto left = 0`: **2**  operations.
3. `auto right = 0`: 2 operations.
4. `for(int j=0; j<i; j++) left += nums[j]`: repetition of  **i** operations.
5. `for(int j=i+1; j<nums.size(); j++) left += nums[j]`: Repetition of  **N-i-1** Operations.
6. `if (left == right) return i`: **2** operations.


Hence if we note $$T(n)$$ the number of operations, we will get 

$$
T(n) = N\left( 2 + 2 + i + N-i-1 + 2\right)$$

$$
T(n) = N^2 + 5N$$

> This results confirms the experimental findings presented in the graph which gives $$T(N)$$ as a second order polynomial.


Let's repeat the same analysis on the second version:



- `auto right=0`: **2** operations.
- `for(int i=0; i<nums.size(); i++) right+=nums[i]`: $$2N$$ operations.
- `auto left = 0`: 2 operations.
- `for(int i=0; i<nums.size(); i++)`: Repetition of $$N$$ operations:
- `right -= nums[i]`: single  operation.
- `if (left == right) return i`: 2 operations.
- `left += nums[i]`: 1 single operation.

Which gives:


$$T(n) = 2 + 2N + N\left(1 + 2 + 1\right)$$

simplified as:

$$
T(n) = 6N + 2$$


### [Simplification](#simplify)
<a name='simplify'></a>

- In the analysis of the complexity, we don't need a i meticulous evaluation of the number of operations, but rather to estimate the order of growth of $$T(n)$$.
- A rigorous tool for this analysis is the **Big Oh** notation

  - For example for the first example we have $$T(n) = N^2 + 5N$$. But we know that when the size becomes important the dominant term is $$N^2$$.
  - also for the second algorithm could be simplified from  $$T(n)= 6n + 2$$ to $$T(n)=6n$$.

- Hence we write that $$T(n)$$ est proportional to $$N^2$$ in the first example and $$N$$ in the second.

### [Big Oh notation](#bigoh)
<a name='bigoh'></a>

 value or infinity. Big O is a member of a family of notations invented by Paul Bachmann,[1] Edmund Landau,[2] and others, collectively called Bachmann–Landau notation or asymptotic notation. The letter O was chosen by Bachmann to stand for Ordnung, meaning the order of approximation.


In mathematical term:

> If we consider two functions $$f$$ and $$g$$  from  $$\mathbb{N}$$ to 
$$\mathbb{R}$$ representing the running times of two algorithms. We say that $$f(n)$$ is a $$\mathcal{O}(g(n))$$ if exists a constant  $$c>0$$ and an integer $$n_0$$ such as: 

$$
\forall n \geq n_0 \quad f(n) \leq c g(n)
$$


<center>
<img src=" {{ site.url }}{{ site.baseurl }}/part2/images/big-o-graph.png"
width="500" height="200">
</center>

Hence with this tools will focus only on the dominant parts and could also ignore their multiplying **constants**.


For example:

- $$2n^3 -2n^2 -4  = \mathcal{O}(n^3)$$
- $$4n -2  = \mathcal{O}(n)$$
- $$ 4  = \mathcal{O}(1)$$

**Exercise**:

What is the order of growth of these functions:

- $$20n^3  + 10\log\; n + 5$$
- $$2000 \log\; n + 7n\log\;n + 5$$.


### [Notation Big Theta](#bigtheta)
<a name='bigtheta'></a>

There other notation where we analyse the best case scenairio $$\Omega$$.

\begin{equation}
  f(n) = \Omega(g(n)) \quad \Longleftrightarrow \exists M\;\; |\;\; f(n) \geq M
  g(n)
\end{equation}

The third one $$\mathbf{\Theta}$$ is **amortized analysis** where we get both bounds.


\begin{equation}
  f(n) = \Theta(g(n)) \quad \Longleftrightarrow \exists A,B\;\; |\;\;  A\;g(n)
  \leq f(n) \leq B g(n)
\end{equation}

----

## [Order of growth](#order)
<a name='order'></a>


### [Classical cases](#category)
<a name='category'></a>

Dans l'analyse de complexité, vous allez rencontrer un ensemble de classes
classiques qui sont résumés dans  tableau suivant:

In the analysis of complexity we have a class of predifined growths:


- $$\mathcal{O}(1)$$ : Constant.
- $$ \mathcal{O}(n)$$ : Linear.
- $$\mathcal{O}(n\log\; n)$$ : Quasilinear.
- $$\mathcal{O}(n^2)$$:  Quadratic.
- $$\mathcal{O}(n^3)$$:  Cubic.
- $$\mathcal{O}(n^k)$$:  Polynomial.
- $$\mathcal{O}(k^n)\; k>1$$:  Exponential.


### [Examples](#examples)
<a name='examples'></a>

-  **Constant**


The type of algorithms that doen't depend on the size of the problem. Hence **super handy**:

1. Deleting from the end of an **array**.
2. Adding in the end of an array (if not capacity full)
3. Deleting an item from a **stack**.
4. Getting the value in a **hashmap**.

- **Linear**:

Most of simple **loops** are **linear**


```cpp
for(int i=0; i<nums.size(); i++)
    nums[i] = 0;
```

This operations is proportional to the size of the array, hence  $$\mathcal{O}(N)$$.

> This class is very appreciable, as the running time run proportionally with the size of the problem.



- **Quadratic**

The class of algorithms with a growing $$N^2$$. The basic case is with a two inner loops:


```cpp
for(int i=0; i<nums.size(); i++)
{
    for(int j=0; j<nums.size(); j++)
    retulst ++;
}
```

> This order of growth is very limiting as they become impraticable with higher values.


### [Hidden instructions](#hidden)
<a name='hidden'>

In analysing your code, you need to pay attention to **hidden boxes**. For example in the firt example, we have the search in a set.


```cpp
bool set_search(vecI & nums, int target)
{
    //Same program but using set search
    set<int> cache(nums.begin(), nums.end());

    for(auto v: nums)
        if( cache.find( target - v) != cache.end() )
            return true;

    return false;
}
```
If we want to analyse this algorithm, we have to get the folowing answers:

- `set<int> cache(numbs.begin(), nums.end())`: What is the number of operations?
- `for(auto v: nums)`: Repetition $$N$$ times.
- `if cache.find(target - v) != cache.end())`: What is the number of operations of this instruction?

If we look the documentation of the `set` class [documentation Set](http://www.cplusplus.com/reference/set/set/set/),  we get the following results:

For the second operation which apply the  [find](http://www.cplusplus.com/reference/set/set/find/) method, we have a **logarithmic** complexity $$\mathcal{O}(\log\;n)$$.

Hence if we combine all the results, we get:
$$
T(n) = n  + n(\log\; n) = \mathcal{O}(n\log\;n)
$$


**Exercise**:

Evalute the complexity of the following code:

```cpp
vector<int> arr;

for(int i=0; i<n; i++)
    arr.insert(0, i+1);
```



## [Search](#Search)
<a name='Search'></a>



Now we have the tool to analyse two algorithms to solve the **search** problem in a **sorted** array.

- **Linear search**
- **Binary Search**


### [Linear Search](#linearSearch)
<a name='linearSearch'></a>


This is the classical search seen in the chapter of array. This simply **ignore** that the array is **sorted**.

```cpp
for(int i=0; i<nums.size(); i++)
    if( nums[i] == s)
        return s;
```

If we analyse the code, we get that this search has a **linear complexity** $$\mathcal{O}(n)$$. Hence the name.

### [Binary search](#dichotomy)
<a name='dichotomy'></a>

In **binary search**, we take advantage of the fact that array is sorted. Hence we will seek the value in the **middle** and compare it to the target. We will have thre cases:

1. The value is equal to the target. (done)
2. The value is larger, we will continue the search in **left** part.
3. the value is smaller, we will continue the search in the **right** part.

The steps of those algorithms are illustrated in the following figure:

<center>
<img src=" {{ site.url }}{{ site.baseurl }}/part2/images/binary-and-linear-search-animations.gif" height="300"  width="500">
</center>

In order to analyse the complexity of this procedure, we will remark that each operation, we execute two basic insructions.

1. compute the value of the mean.
2. compare it the target.

Afer thta we will continue the search in an array with **half** of the size of the original one. Hence we can write the number of operations as:


$$
\begin{equation}
  f(n) = \underbrace{2}_{\scriptsize\text{taille n}} +
  \underbrace{2}_{\scriptsize \text{ taille} \frac{n}{2^1}} + 
\underbrace{2}_{\scriptsize \text{ taille} \frac{n}{2^2}}+\ldots +
\underbrace{2}_{\scriptsize \text{ taille} \frac{n}{2^k}}
= 2 (k+1) = \mathcal{O}(k)
\end{equation}
$$

Now we need to compute the value of $$k$$. We know that 


$$
\begin{eqnarray}
  \frac{n}{2^k} &\leq & 1 \\
  \log_2(n) - k & \leq & 0\\
  k             & \geq & log_2(n) + 1
\end{eqnarray}
$$

Hence we proved that the complexity of **binary  search** is logarithmic $$\mathcal{O}(log{n})$$.

> This offer a more efficient way to search a value if the array is sorted.

> As a challenge try to implement both those algorithms and repeat the analysis experimental methods presented in the first example to confirm the findings.


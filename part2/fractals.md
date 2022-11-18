---
layout : page
title  :  Homework on Fractals
date   :  2022/11/30
permalink : /fractals/
---

<center>
  <img src="{{ site.rul }}{{ site.baseurl }}/part2/sierpensky.png">
</center>





* TOC
{:toc}


 


## [1. Step By Step ](#step)


### [IsPalindrome(*)](#palindrome)
<a name='palindrome'></a>

As a first exercise, we will ask you write a **recursive** function that verifies if a `string` is a **palindrome**.

> A string is palindrome is it is equal to its reversed version.


for example the string `madam` is palindrome.


Here is the link <img src="{{ site.rul }}{{ site.baseurl }}/assets/logo_step.png" width="30"
heigth="30">
[isPalindrome](https://www.codestepbystep.com/problem/view/cpp/recursion/isPalindrome) for the exercise.

**Constraintes**:

1. You cannot use any **global** variables.
2. You cannot use any **loops**.
3. You cannot use any **auxiliary** structures such as an array.
4. You must ignore the case of the variable. Hence the letter 'A' will be the same as 'a'


### [CountBy(**)](#count)

In the next exercise, you are asked to write a recursive function `countToBy` that gets two  integers $$n$$ and $$m$$. The function should   print a sequence ending by  $$n$$ each time we jump by $$m$$.

Here is a list of example for a better understanding of this function:

```cpp
// Will values from [1, 10] each time we jump by 1
countToBy(10, 1);  // will print 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

// print until 30 but each time we jump by 4
countToBy(30, 4); // will print 2, 6, 10, 14, 18, 22, 26, 30
```

> Take an important note that the sequence doesn't starts from $$1$$ each time. But rater it should always **end** at $$n$$.



Here is the link   <img src="{{ site.rul }}{{ site.baseurl }}/assets/logo_step.png" width="30"
heigth="30">
[countToBy](https://www.codestepbystep.com/problem/view/cpp/recursion/countToBy) to the exercise.

> Also in case $$m$$ or $$n$$ are strictly inferior to $$1$$. Your code must throw an integer exception.

Here is how you throw that exception:

```cpp
// Throw an exception with the value of n
if ( n < 1)
    throw n;
```



### [Combin (***)](#combin)

Now for a serious  problem, You'll be asked to implement the `combin` function that accepts two integers $$n$$ and $$k$$ and return the value  of $$ C_n^k$$.


We recall that the value of this expression is given by:

$$
C_n^k = \dfrac{n!}{k!(n - k)!}
$$

Unfortunately this expression will gives you an **exponential** complexity. Try to find a more useful relation:


Here is a link for the exercise
<img src="{{ site.rul }}{{ site.baseurl }}/assets/logo_step.png" width="30"
heigth="30">
[Combin](https://www.codestepbystep.com/problem/view/cpp/recursion/combin).


> A little advice, without **Memoization** you will be stuck in the final test which will give a time limit exceeded announcing that your solution has a higher complexity.




## [2. Number of Partitions (**)](#partitions)

We will define the `number of partitions` of an integer $$n$$ using as a **max** value $$m$$. The number of ways we wcould decompose $$n$$ as a sum of integers that are inferior to $$m$$. 


> The sequence must be in an **increasing order**.

Let's illustrate this for the integer $$n=6$$ and the max value $$m = 4$$. With this we have $$\mathbf{9}$$ ways to decompose:


```shell
1. 6 = 2 + 4
2. 6 = 1 + 1 + 4
3. 6 = 3 + 3
4. 6 = 1 + 2 + 3
5. 6 = 1 + 1 + 1 + 3
6. 6 = 2 + 2 + 2
7. 6 = 1 + 1 + 2 + 2
8. 6 = 1 + 1 + 1 + 1 + 2
9. 6 = 1 + 1 + 1 + 1 + 1 + 1
```

You task ( should you accept it) is to write a function `count_partitions(n, m)` that compute this number.



In the project <a href="{{ site.url }}{{ site.baseurl }}/part2/partitions.zip">
partitions.zip </a>, You'll find code with unit tests.


> **Hint 1** Try to come up with a recurrence on $$m$$. 

> **Hint 2** In the above example, try to find the difference between the first two lines and the rest.


## [3. Fractals](#fractals)

### [Sierpensky](#sierp)
<a name='sierp'></a>
In this exercice we will draw the classical [Sierpensky triangle](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_triangle) using the **Stanford library** for graphics.

As shown in the figure, a Sierpensky triangle of order $$8$$ is simply a filled triangle. An order two Sierpinski triangle is composed of **three** sierpenski triangle of order $$0$$.


<center>
  <img src="{{ site.url }}{{ site.baseurl }}/part2/images/768px-Sierpinski_triangle_evolution.png">
  </center>


Here is a project which contains all the code <a href="{{ site.url }}{{ site.baseurl
}}/part2/Sierpensky.zip">Sierpensky.zip </a>. The code will ask the order of triangle, and will draw that triangle
vous trouverez

Your task is to fill the following function:

```cpp
void Sierpensky( GWindow &app, float x, float y , float width, int order)
```

Where:

- `app`: is the main window to draw the triangle.
- `x, y`: are the  **coordinates** for the first triangle
- `width`: is the  **width** of the triangle
- `order`: is the order.


> In order to help you achieve you goal, we give you a simplified function to draw  a **filled
triangle**:

```cpp
void draw_triangle(GWindow &app, float x, float y, float width)
```

Where:

- `app`: is a reference on the window.
- `x, y`: are the **coordinates** for the first point
- `width`: is the shared **width**.




### [Sierpensky Carpet](#carpet)
<a name='carpet'></a>

The [Sierpensky carpet](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_carpet)s a plane fractal first described by Wacław Sierpiński in 1916. The carpet is a generalization of the Cantor set to two dimensions; another is Cantor dust.

The technique of subdividing a shape into smaller copies of itself, removing one or more copies, and continuing recursively can be extended to other shapes. For instance, subdividing an equilateral triangle into four equilateral triangles, removing the middle triangle, and recursing leads to the Sierpiński triangle. In three dimensions, a similar construction based on cubes is known as the Menger sponge.


<center>
  <img src="{{ site.url }}{{ site.baseurl}}/part2/animated_carpet.gif">
</center>

In the project <a href="{{ site.url }}{{site.baseurl}}/assignments/06_recurrence/carpet.zip"> carpet.zip </a> you could fill the following function:

```cpp
void carpet(GWindow &win, int x, int y, int width , int order)
```



Afin de tracer un rectangle dans une fenêtre vous utiliser le code suivant:
Same as the triangle, we offer you a basic procedure to draw a rectangle

```cpp
   // Draw a rectangle with coordinate (x, y) and width [width]
   GRect * rect = new GRect(x, y, width, width);

   //Fill the rectangle
   rect->setFilled(true);

   //Add the rectangle to the window
   win.add(rect);
```



Your task it produce the following carpet with order $$5$$ as shown in the figure:


<center>
  <img src="{{ site.url }}{{ site.baseurl}}/part2/carpet_5.png">
</center>


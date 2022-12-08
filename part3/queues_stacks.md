---
layout : page
title  : Queues and Stacks
date   :  2022/12/08
permalink : /queues/
---

<center>
  <img src="{{ site.url }}{{ site.baseurl }}/static_files/presentations/lec9.png"
  width="600" height="300">
</center>



* TOC
{:toc}


## Abstract representation

In this chapter we will discuss a new **container** to store our data. The **stacks** and **queues** containers. Those also knows as `Abstract data types`, meaning we are defining the **interface** for the container not how it is actually implemented.

> An **abstract data Type (ADT)** is defined by its behavior frm the point of view the user of the data, and by the operations it can accomplish with the data.

As a concrete example, the stack and queue have similar interfaces, but they are used for very different problems, as we shall see.


## Queues

A queue or (**First-in First Out**) ADT is a collection where the first added element will be precessed first.

<center>
  <img src="{{ site.url }}{{ site.baseurl }}/part3/queues.png"
  width="400" height="200">
</center>

This ADT will have the following interface:

1. `enqueue(value)` place an entity onto the back of the queue.
2. `dequeue()` : remove an entity from the front of the queue and return it.
3. `front()` : look at the entity at the front of the queue, but don't remove it.
4. `isEmpty()` a boolean indicating the collection is empty or not.




Here is a example of the execution of this **API**.

```cpp
Queue Q;            // {} empty queue
Q.enqueue(42);      // {42}
Q.enqueue(-3);      // {42, -3} 
Q.enqueue(17);      // {42, -3, 17}
cout << Q.dequeue() << endl;   // 42 ( Q is {-3, 17})
cout << Q.front() << endl;   // -3 ( Q is {-3, 17})
cout << Q.dequeue() << endl;   // -3 ( Q is {17})

```



### Linked Lists implementation

For our first exercise, we will use **linked list** to represent the elements of the queue. You can 

- Either use your proper imlementation of linked lists.
- Use the [List class](https://cplusplus.com/reference/list/list/)  


> Code in the demo



### Circular array implementation

A more efficient way to implement a queue. Specially if we are limited by the use of a **fixed size array** is to use **two pointers** indicating the starting and the ending position. 

> The goad is to reuse the wasted storage freed by the dequeue operations.

<center>
  <img src="{{ site.url }}{{ site.baseurl }}/part3/cir_queue4.png"
  width="500" height="300">
</center>

Here is a link of the exercise on [code step by step](https://www.codestepbystep.com/problem/view/cpp/collectionimpl/stackqueue/ArrayStack) 

## Stack

The stack **API** is different since it is **Last in Last out** ADT.

We will name the interface as 

1. `push(value)` : place an entity onto the top of the stack.
2. `pop()` : remove an entity from the top of the stack.
3. `top()` look at the entity at the top of the stack.
4. `isEmpty()` : a boolean returning **true** if the stack is empty.


<center>
  <img src="{{ site.url }}{{ site.baseurl }}/part3/stack.png"
  width="400" height="200">
</center>

## Postfix expressions

- When you were first learning albebraic expressions, your teacher probably gave you a problem like this and said what is the result?

```
5 * 4 - 8 / 2 + 9
```

- The class got all sorts of differents answers, because no one knew the order of operations yet (the correct answer is **25** by the way). Parenthesis become necessary as well (e.g. **10 / (8 -3)**).

- This is a somewhat annoying problem - it would be nice if there were a better way to do arithmetic so we didn't have to worry about order of operations and parenthesis.

- As it turns out, there is a **better way!** We can use a system of arithmetic called  `postfix notation`. The expression above would become the following:

```
5 4 * 8 2 / - 9 +
```

> Given a postfix notation like the one presented above, write a program using **stack** and **queue** to evaluate the value of this expression.

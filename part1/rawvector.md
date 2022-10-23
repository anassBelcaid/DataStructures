---
layout : page
title  : Vectors and Grids
date   :  2021/03/20  
permalink : /rawvectors/
---

<center>
<img 
    src="{{ site.url }}{{ site.baseurl }}/assets/vectors/banner.png"
    width="300"
    height="300">
</center>

One of the simplest **Data structure** that are linear are **vectors** or
**arrays**. They form a *continuous* collection of data that share the same
**Type**. All the programming languages offers a direct mechanism to declare and
manipulate them. They are the first but most important **Data structure** that a
serious programmer should master in his long journey.
    


* TOC
{:toc}





## Static vectors
<a name='staticvect'></a>

In the first part, we will introduce the notion of a **static** vector in C++.

### DVD Collection
<a name='dvdbox'></a>
Let's suppose that we have a set  of **DVD's** and we want to store them ( in a
compact way).

> What will be our choice for storing them?

- We can find a big **shell** to store all the possible DVD?
- The problem arise when we want to **add** or **remove** one of them.
- Another consideration is the **size** of the shell. Do we go for the just the
    number of DVD that we have and sacrifice the possibility of adding other.
- Or we can buy a bigger shell, but we will sacrifice money as we don't always
    need all the empty spaces.
- Also we remark in a DVD, we have the following **invariants**:

    1.  Each DVD has its own **cover**.
    2.  The cover always shows the title and the cast.
    3.  All the covers has the same **size**.



<center>
<img  src="{{ site.url }}{{ site.baseurl}}/assets/vectors/dvd_illustration.png"
   width="400">
</center>

Now suppose that we want to write our **application** to store and manipulate
our **inventory** of DVDs. We have to choose the **attributes** to represent our
DVD. We must also choose the **maximal number** of DVD that we could store.


> This number is so **important** because in static vectors, it must be known in
the Declaration phase and never change in the program.

The ideal structure to store those **DVD** is a **raw vector** or `array`.



### Array Definition.

> An array is a collection of objects. Those objects must share the same type.
Also in the memory view, those items are stored in a **contiguous** way. This
will allow a **random access**  to each element in a constant time.


Here is a simple example that show how to declare a static array with a known
size.


```cpp
//Declaring an array of size 15
int vec[15];     

//We could also read N , but once we declare the array, 
// the size never changes.

int N;
cout<<"Donner la taille: "
cin>>N

float vec2[N];
```

And now we, could apply these declaration to our problem of DVDs.


```cpp
#include <iostream>
#include <string>

using namespace std;

// Structure of a DVD
struct  DVD
{
    string name;
    string director;
    int year;
};

int main(int argc, char *argv[])
{
    //Store a line for a dvd
    string line; 

    //Getting the number of dvds
    int N;
    getline(cin, line);
    N = stoi(line);

    //Array of dvd
    DVD inventory[N];

    for(int i=0; i<N; i++)
    {
        getline(cin, line);
        inventory[i] = from_line(line);
    }

    for(auto dvd: inventory)
        cout<<dvd<<endl;

    return 0;
}
```

### Indexing operator


> Les deux opérations primitives pour un tableau sont l'écriture et la lecture dans ces composantes. Le reste des opérations est fondé sur ces opérations.

> The basic operation given by an array is the ability to **write** and **read**
any value in the array. 

Those operations use the **indexing** syntax `[i]` which gives a **reference**
to the **ith** elements. 

> The indices are orered from `0` to `N-1` where `N` is the size of the vector.


```cpp
#Getting access to the first DVD
auto dvd1 = inventory[0];

//Modify its content
inventory[0].year = 2000;
```

Also to loop all the elements of the array, we could use one of the following
**for** loops

```cpp
for(int i=0 ; i<N; i++)
    //Use inventory[i]

for(auto dvd: inventory)
    //Use dvd

for(auto &dvd: inventory)
    //Use dvd
```

### length and Capacity

An interesting question arises:

> If someone asks you what is the size of your array. What will the answer?

There are two correct responses for that question:

1. The maximal number of elements that the array could store (`capacity`).

2. The actual number of elements stored in the array (`length`).



```cpp
//An array of capacity 100
int tab[100];

//Adding some elements
tab[0] = 3;  //[lenght=1, capacity=100]
tab[1] = 4;  //[lenght=2, capacity=100]
tab[2] = 5;  //[lenght=3, capacity=100]
```

### Argument to a function

A static (or raw) vectors in C++ don't know its **length** nor its
**capacity**. So when passing this array to a **function**, we must also pass
those values too.

> An array is simply an **address**  (or pointer) for the first element.


```cpp
#include <iostream>

using namespace std;

void augment(int grades[], int capacity)
{
    // try this with the simple for each loop
    for(int i=0; i<capacity; i++)
        grades[i]++;
}

int main(int argc, char *argv[])
{
    //Array with capacity 5
    int grades[5]{14, 16, 18, 10, 20};

    //Call with a function
    augment(grades, 5);
    
    //Printing
    for(auto v: grades)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}
```


### Exercises.


Write a `function` that gets an array and return the number of elements that has an even number of digits.



**Example 1**:

```
Input: nums = [12,345,2,6,7896]
Output: 2

Explications: 
12 has 2 digits. 
345 has 3 digits. 
2 has 1 digits. 
6 has 1 digits. 
7896 has 4 digits. 
```


**Example 2**:
```
Input: nums = [555,901,482,1771]
Output: 1 

Explication: 
Only 1771 has an even number of digits.
```



## Classic operations on arrays.

Let's execute some basic operations on an array. If we get back the DVD example,
we will need the following operations:
1. **Add** a new DVD to the collection.
2. **Delete** a given DVD.
3. **Look up** for a DVD.


----

### Insertion 

> Inserting in an array could be done in different positions: 

- Insert at the **end** of the array



<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/insertion_end.png"
  width="400">
  </center>

```cpp
bool insert_end(int arr[], int &lenght, int capacity, int value)
{
    //Verify if we could insert an element
    if( lenght >= capacity)
        return false;

    else
    {
        arr[lenght++] = value;
    }
}
```

 - Inserting in the **front** 


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/Array_Insertion_2.png"
  width="500">
</center>

```cpp
bool insert_begin(int arr[], int &lenght, int capacity, int value)
{
    //Verify if we could insert
    if( lenght >= capacity)
        return false;

    else
    {
        //Shifting
        for(int i = lenght; i>0; i--)
            arr[i]= arr[i-1];
        //Insert element
        arr[0] = value;

        //Don't forget to increase the length
        lenght++;
    }
}
```


- Insertion in a given position `index`.


<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/Array_Insertion_3.png"
  width="500">
</center>

```cpp
bool insert_at(int arr[], int &lenght, int capacity, int value, int index)
{
    //Verify if we could insert
    if( lenght >= capacity)
        return false;

    else
    {
        //Shifting
        for(int i = lenght; i>index; i--)
            arr[i]= arr[i-1];
        //Insert element
        arr[index] = value;

        //Don't forget to increase the length
        lenght++;
    }
}
```


----

### Deletion 



Deleting an element given by its index consists of shifting all the remaining (
placed at the right) and decrease the actual `length`.

<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/Array_Deletion_3.png"
  width="600">
</center>


```cpp
bool delete_at(int arr[], int &lenght , int index)
{
    if( index < 0 || index>= lenght)
        return false;

    //shift back
    for(int i=index; i<lenght-1; i++)
        arr[i] = arr[i+1];

    //length decreases
    lenght--;

    //Deletion is successful
    return true;
}

```
----

### Search

> Now for the most important operations as its arises in many applications.

> Searching for a `target` consists of returning the index of the **first
occurrence**  of this target in the array.


There are several methods to search for an element in a given array. For the
time being, we will start with the most basic search which is **linear search**.



`Linear search`: start by checking the first element, and then goes to the
second, until its either finds the **target** or arrives the end of the array.



<center>
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/Array_Search_1.png"
  width="600">
</center>

```cpp
int linear_search(int arr[], int lenght, int target)
{
    //Simple loop
    for(int i=0; i<lenght; i++)
        if( arr[i] == target)
            return i;
    
    //Failure
    return -1;
}
```

> Once we will introduce the notion of **recurrence**, we will go back to this
problem for a more efficient solution if the array is sorted ( Stay tuned).



---
layout :  page
title  : Strings
date   :  2022/10/17
permalink: /strings/
---



## Table of contents

1. TOC
{:toc}




## [The string class](#cppstrings)
<a name='cppstrings'></a>

### [Definition](#definition)
<a name='definition'></a>

In C++ a `string` is a colleciton of characters. In order to use this class, we must introduce its header `<string>`.



```cpp
#include<string>
...
string s = "hello"
```

- A literal  **string** is group of characters enclosed between **""**.

- We cannot use the single character delimiter ` ` as it's reserved for a single character.
    - `"This is a string"`
    - `'This will lead to an error'`
- In the `API` level, strings in **C++** have the same functionality as in **Python** or **Java**.

- One major difference with those languages, is that in C++, string a `mutables`. Which means that we could change their values.
- Another difference, is that C++ has two types of strings. 
  1. Those compatible with the **C** language.
  2. Those **OOP** oriented type which uses classes.



### [Conversion](#convertion)
<a name='convertion'></a>

The class method `to_string` is very useful to convert number to their **string** equivalent.


```cpp

#include <iostream>
#include <string>
 
int main() 
{
    double f = 23.43;
    double f2 = 1e-9;
    double f3 = 1e40;
    double f4 = 1e-40;
    double f5 = 123456789;
    std::string f_str = std::to_string(f);
    std::string f_str2 = std::to_string(f2); // Note: returns "0.000000"
    std::string f_str3 = std::to_string(f3); // Note: Does not return "1e+40".
    std::string f_str4 = std::to_string(f4); // Note: returns "0.000000"
    std::string f_str5 = std::to_string(f5);
    std::cout << "std::cout: " << f << '\n'
              << "to_string: " << f_str  << "\n\n"
              << "std::cout: " << f2 << '\n'
              << "to_string: " << f_str2 << "\n\n"
              << "std::cout: " << f3 << '\n'
              << "to_string: " << f_str3 << "\n\n"
              << "std::cout: " << f4 << '\n'
              << "to_string: " << f_str4 << "\n\n"
              << "std::cout: " << f5 << '\n'
              << "to_string: " << f_str5 << '\n';
}

```

If we want more control on the number of floating digits, we use a more advanced
method [`sprintf`](http://www.cplusplus.com/reference/cstdio/sprintf/) (which stand string print formatted).

It syntax is given as follows:

```cpp
std::sprintf(buffer, "fmt", value);
```

- `fmt`: where is desired **format** (like you learn in C).
- `value`: the value that we want to convert. 
- `buffer`: The string called also **buffer** to store the result. 

Also for the inverse conversion (**string to number**), we use the following
functions:


- [stoi](http://www.cplusplus.com/reference/string/stoi/): to get an
    **integer**.
en **entier**.
- [stol](http://www.cplusplus.com/reference/string/stol/): to get a **long**
- [stof](http://www.cplusplus.com/reference/string/stof/): to get a **float**
- [stod](http://www.cplusplus.com/reference/string/stod/): to get a **double**.



## [The array representation](#chars)
<a name='chars'></a>

A **String** is represented in the **memory** as an array of characters `char`.
Each one of those characters could be obtained using the `[]` operator.


```cpp
string S = "Fear the Tree"
```


<table align="center">
<thead>
  <tr>
    <th class="tg-0pky">Index</th>
    <th class="tg-0pky">0</th>
    <th class="tg-0pky">1</th>
    <th class="tg-0pky">2</th>
    <th class="tg-0pky">3</th>
    <th class="tg-0pky">4</th>
    <th class="tg-0pky">5</th>
    <th class="tg-0pky">6</th>
    <th class="tg-0pky">7</th>
    <th class="tg-0pky">8</th>
    <th class="tg-0pky">9</th>
    <th class="tg-0pky">10</th>
    <th class="tg-0pky">11</th>
    <th class="tg-0pky">12</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0pky">Character<br></td>
    <td class="tg-btxf">F</td>
    <td class="tg-0pky">e</td>
    <td class="tg-btxf">a</td>
    <td class="tg-0pky">r</td>
    <td class="tg-btxf">' '</td>
    <td class="tg-0pky">t</td>
    <td class="tg-btxf">h</td>
    <td class="tg-0pky">e</td>
    <td class="tg-btxf">' '</td>
    <td class="tg-0pky">t</td>
    <td class="tg-btxf">r</td>
    <td class="tg-0pky">e</td>
    <td class="tg-btxf">e</td>
  </tr>
</tbody>
</table>

In order to get the **ih** character we use 
- `S[i]` : not safe
- `S.at(i)` : check memory (safer but slower).



```cpp
char ch1 = S[3];  //'r'
char ch2 = S.at(2); //'a'
```
> To illustrate the difference between those two methods, let's consider the
following calls.

```cpp
char ch1 = S[13];  // Runtime error, nothing is signaled in complied time (with default flags)
char ch2 = S.at(13);  //Will throw an exception
```


- In order to loop between the elements of a string, you have the following loops:

```cpp
//Index based
for(size_t i = 0; i<chaine.size(); i++)
    cout<<chaine[i];
cout<<endl;

//foreach
for(auto ch: chaine)
    cout<<ch;
cout<<endl;
```
- The **characters** are encoded using the `ASCII` codes as showed int the following figure:


<div class="fig figcener ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/ceaser_cypher.png" >


<div class="figcaption">

The <b>Cesar</b> encoding is a method in cryptography which encodes a character by
translating it by integer k. Hence for example if we consider the example of the
letter `A` and the integer k=3. The code of 'A' will be 'D',  the code of 'B'
will be 'E' and so forth.
</div>
</div>




- This representation will allow us to use **mathematical operations** such as the **Cesar encoding** to manipulate the characters.

> Exercise: Write a program to encode the string "ATTACKATDOWN" with a **Cesar** encoding with size k=5.



```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string message = "ATTACK AT DAWN";
    int key = 5;
    string encoded = "";  //Encoded message

    for(auto ch: message)
    {
        //Only encode letters 
       if( ch >= 'A' && ch<='Z')        
       {
        //Formula change
        char  dis= ( ch - 'A' + key) % 26;
        encoded += 'A' + dis;
       }
       else
        encoded += ch;
    }
    cout<<encoded<<endl;
    return 0;
}
```


```shell
Input: ATTACK AT DAWN
Output: FYYFHP FY IFBS
```




## [String methods](#methods)
<a name='methods'></a>
In this section, we will present the available methods for the string object.

### [Concatenation && Comparison](#string_cmp)
<a name='string_cmp'></a>


- Like `Java` and  `Python`, we could **concatenate** two strings using the **+=** operator.

```cpp
string s1 = "Programming in "
string s2 = s1 + " CPP";  //s2 = Programming in CPP
s1 += "?";      //Add the string "?" 
```

- Unlike `Java`, we could directly compare strings using the **==** operator.

```cpp
string s3 = "Zebra";
if ( s3 == "Tiger" )
    cout<<"Different"<<endl;

if (s3 < "Tiger")
    cout<<"Inferior"<<endl;
```

- Also those strings are **mutables**.

```cpp
s3.append("Giraffe"); // s2 now is  "ZebraGiraffe"
s3.erase(4,3); // erase three characters from  4,
s3[5] = 'i'; // change a single character
s3[9] = 'e'; //Danger
```

- Here is a list of useful methods:

    - `s.append(str)`: Add a string at the end. 
    - `s.compare(str)`: Like Java, this is a comparator which return  $$[-1,0,1]$$ according the comparison result.

    - `s.erase(index, lenght)`: delete [length] character starting from [index].
    - `s.find(str)`:  Search the string [str] if it exists ottherwise `npos`.
    - `s.insert(index, str)`: insert the string [str] at the position [**index**].
    - `s.size()`: return the **size** of the string.
    - `s.substr(start, length)`: return the string with lenght with **[length]**
        starting from **start**.

## [Ctype Library](#ctype)
<a name='ctype'></a>

The library `ctype` offers a set of useful function to verify the nature of
character.


- `#include<ctype>`

    - **isalnum**: return **true** if the character is alphabetic or numeric.
    - **isalpha**: return **true** is the character is alphabetic.
    - **islower**: lower case letter.
    - **isupper**: upper case letter.
    - **isdigit**: verify if it is a digit..
    - **isxdigit**: is an hexadecimal digit.
    - **iscntrl**: is control character.
    - **isspace**: for the space character.
    - **tolower**: to convert a **letter** (not a string) into a lower case.
    - **toupper**: Same but to **upper case**.

- Example:

```cpp
string mixed = "ab80c3d27"
cout<<"digits  "<<mixed<<": "<<endl;

for(auto ch: mixed)
    if( isdigit(ch) )
        cout<<ch<<endl;

//Convert all in upper case
string s = "my string";
for(auto & ch: s)
    ch = toupper(ch)
cout<<"Now "<<s<<endl;
```









## [String Stream](#streams)
<a name='streams'></a>

The **String stream** is a useful tool to manipulate streams using **the power of streams**. For example if we want to concatenate string, the **+=** operator will use a quadratic time (more to know in coming chapters) to **reallocate** the memory. A better solution is to use **[stringstream](https://www.cplusplus.com/reference/sstream/stringstream/)** with the stream syntax using the **<<** and **>>** operator to manipulate data.

- **operator<<**: to get (read) values into the stream.
- **operator>>**: to extract values from the stream.
- **str**: to get the current string.
- **clear**: to clear (delete) the content of the string.

To illustrate the use of those streams, let's suppose we want to process the
data of a student `("Adil", "Fes", 23)` and we want to create a string in the
form   `name [state:
Fes] [age: 23]` to represent this student. We could achieve this using stream:

```cpp
Stduent S{"Adil", "Fes", 23};

//Construct the stream
stringstream SS;

//Creating the string using what you learn for << and >>
ss<<S.name<<" [state: "<<S.state<<"] [age: "<<S.age<<"]";

//Printing the stream
cout<<ss.str()<<endl;
```

We could also use them as input stream (like cin)

```cpp
string str("Hello from the dark side");
```

Let suppose we want to get all the words of this string ( difficult exercise just just the basic methods).

```cpp
// Create a stream with str as string
stringstream SS(str);

//string to get the words
string word;

//Loop to read all the words
while( SS>>word)
{
    cout<<word<<endl;
}
```

#### Exercice




> Write a function that receives a string that contains of numbers separated by comma, and print those number (each number in its line.


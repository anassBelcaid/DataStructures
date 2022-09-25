---
layout : page
title  : Introducion
date   :  2022-09-26
permalink: /overview/
---


1. [Course Information](#courseinfo)
 -  [Abstract techniques ](#abstracttechniques)
 - [Master Recurrence](#recuPower)
 - [Complexity analysis](#algoanalys)
2. [Logistics](#logistics)
    - [Course portal](#portail)
    - [Discuss plateform](#piazza)
    - [Grading](#grade)
    - [Training](#stepstep)

3. [C++](#cpp)
    - [Definition](#defcpp)
    - [Why C++](#whycpp)
    - [Compagnies C++](#compagniecpp)
    - [First program](#linkLabel)
    - [Second program](#secondprogram)
    - [Why Data structures](#impdata)



## [**Objectives**](#objectifs)
<a name='objectifs'></a>



Welcome to the course **Algorithms and Data structures**.
The objectifs of this course:


> Gain deep knowlede on advanced algorithms and the zoology of data structure to
solve different problems.

But What de we mean by a **hard Problem**. This is a list of problems in
Computer Science sorted by their difficulty:

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{site.baseurl}}/assets/intro/instantanious_directions.png" width="60%">
  <div class="figcaption"> Computing the Shortes path.</div>
</div>


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{site.baseurl}}/assets/intro/speech_recognition.png" width="50%">
  <div class="figcaption"> Natural Language processing.</div>
</div>

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{site.baseurl}}/assets/intro/autonomous_driving.png" width="50%" >
  <div class="figcaption"> Imitation Driving in Self Driving cars. J.Zhou and al 2021</div>
</div>

## Course Objective
<a name='courseinfo'></a>

> The goal if of course is not solve those advanced problems. Nevertheless, it
is a mandatory step toward it.


We could resume the essential point of the course as follows:



1. Explore the abstract techniques to solve problems.
2. Master the notion of **recurrence**.
3. Get a intermediate grasp on **data structures** the their use for different
   situation.
4. Master the tool of **algorithms analysis** to compare the complexity of
   algorithms.




### [Abstract  techniques](#abstracttechniques)
<a name='abstracttechniques'></a>



1. How to compute the **expeceted distance** between two random **facebook**
   usesrs.
<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{site.baseurl}}/assets/intro/facebook_distance.png" width="50%">
  <div class="figcaption"> This is a classical question in the <b>Graph theory</b>.</div>
</div>



2. How to send an email between two cities:
<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/rooting_problem.png" width="50%">
  <div class="figcaption"> 
  We want to send an email between two countries or cities. We have a map of the
  connectec servers between those cities. But which server to choose. Thise is
  also a graph theory problem which uses <b> rooting </b></div>
</div>


### [Appreciate the power of recurrence](#recuPower)
<a name='recuPower'></a>



**Recurence** is a powerful technique that will allow you to tackle a large set
of problems.



<div class="fig figleft ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/fractal_tree.jpg" width="40%">
</div>

<div class="fig figright ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/fractal_tree.jpg" width="40%">
  <div class="figcaption"> Image d'un arbre <b>fractal</b>, Si vous zoumer sur une
  partie de cette arbre, vous allez trouver la <b> même image</b>
  A fractal Image. The beauty of this image is if you <b>zoom</b> in any leaf of
  this tree. You'll see another tree.

  </div>
</div>



### [Learn to analyse the complexity of your algorithms](#algoanalys)
<a name='algoanalys'></a>


One of the maine objectifs of this course it allow you to compare the
**complexity** of a set of proposed algorithms. For example, let's visit [Sorting algorithms playground](https://www.toptal.com/developers/sorting-algorithms) to appreciate the difference between a set of sorting algorithms.

<div class="fig figcenter ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/complexity.png" width="60%">
  <div class="figcaption"> Playground pour explorer la différence entre les
  algorithmes de tri.</b></div>
</div>


## [**Logistics**](#logistics)
<a name='logistics'></a>

### [Course portal](#portail)
<a name='portail'></a>


The main portal of the course is in the website:

<div class="notyet">
<div class="title-wrap">
<font size = "5">https://anassbelcaid.github.io/datastructure</font>
</div>
</div>

It has : 

1. Planning of the lectures.
2. Contents and useful links to visit ** before the lecture**.
3. Description of the **Homeworks**.
4. Collection o **ressources** pour le cours.




### [Discussion forum](#piazza)
<a name='piazza'></a>

We will use [**Piazza**](https://piazza.com/) for all the discussions post
lectures. You'll be more than encouraged to actively participate in the form.
Either to ask the questions to to respond to others.





> We need our **academic** mail to register to the course.

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/piazza.png"
  width="1000" heigh="800">
  <div class="figcaption"> Main plateform for discussion.</div>
</div>




### [Grading](#grade)
<a name='grade'></a>

Your grade will be decided accordign the following the piechart:
<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/img/piechart.png">
  <div class="figcaption">  Distribution of your grade.</div>
</div>





##  The C++ language
<a name='cpp'></a>


### [Définition](#defcpp)
<a name='defcpp'></a>


The [C++](https://en.wikipedia.org/wiki/C%2B%2B) language est an **Object
Oriented Progamming** langauge. Its **perferomances and **speed** make is one
the standard facto in programming languages. As a example, in the area of **deep
learning** which needs a huge computation power, all the plateform library are
written in **C++**.



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/lang_popularity.png" width="400px">
  <div class="figcaption"> Worldwide language popolarity comparison: Mar 2021 compared to a year ago</div>
</div>

Here are some know courses that use **C++** as its core languge:


1. Physics Based simulation Biological Structure.
2. **[Introduction to Cuda](https://ericdarve.github.io/)** (**Deep learning**). 
3. [**Introduction to Computer Networks**](http://web.stanford.edu/class/cs244a/)
4. [**Convolutional Neural Networks**](https://medium.com/syntechx/convolutional-neural-network-cnn-in-c-52c9ed47a6ea)
5. Parallel computing in **Healthcare**. 
6. Medical **Robotics**.
7. **Music computing** design.
8. **Signal processing** models.


#### [Why C++](#whycpp)
<a name='whycpp'></a>

Etant donné l'explosion et l'efficacité des réseaux de neurones. Tous les
**framework** en base sont implémentés en `C++` pour leur efficacité. Puis
offrent des interfaces en des langages simples comme `Python` pour leur
exploitation.



```cpp
/*
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <vector>

#include "tensorflow/cc/framework/grad_op_registry.h"
#include "tensorflow/cc/framework/gradients.h"
#include "tensorflow/cc/ops/array_ops_internal.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/lib/strings/strcat.h"

namespace tensorflow {

REGISTER_NO_GRADIENT_OP("ShapeN");
REGISTER_NO_GRADIENT_OP("Rank");
REGISTER_NO_GRADIENT_OP("Size");

Status UnpackGrad(const Scope& scope, const Operation& op,
                  const std::vector<Output>& grad_inputs,
                  std::vector<Output>* grad_outputs) {
  int axis;
  TF_RETURN_IF_ERROR(GetNodeAttr(op.node()->attrs(), "axis", &axis));
  grad_outputs->push_back(Stack(scope, grad_inputs, Stack::Axis(axis)));
  return scope.status();
}
```

<div class="figcaption"> Code C++ de Array grad sur tensorflow.</div>


### [Compagnies that usesC++](#compagniecpp)
<a name='compagniecpp'></a>

**Compagnies that uses C++**


<div class="fig figcenter fighighlight">
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/amazon.png" width="24%" height="80">      
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/intel.png" width="80" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/facebook.png" width="80" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/google.png" width="100" height="80">      
  <br>
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/apple.png" width="100" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/microsoft.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/adobe.png" width="24%" height="80">      
<div class="figcaption"> Companies that uses C++ at their core language.</div>
</div>



**Some projects written in C++**


<div class="fig figcenter fighighlight">
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/java.png" width="150" height="60">      
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/office.jpg" width="150" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/photoshop.png" width="150" height="60">      
  <br>
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/vlc.png" width="150" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/windows.jpg" width="150" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/youtube.png" width="150" height="60">      
<div class="figcaption"> some harcore software that are written in C++</div>
</div>


**Projets in C++**

<div class="fig figleft">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/project_1.png"
width="40%" height="200">
</div>
<div class="fig figright">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/project_2.png"
width="40%" height="200">
</div>

<div class="figcaption"> Projets using  C++, The  <b>F35</b> Lightning
|| was written with  C++ for a high efficient reaction time. Right, the
<em>Spirit rover</em> which was operational for 6 years, where it was designed
for a discovey mission for three months..</div>


> Why this course uses C++

<div class="fig figleft">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/c++_timing.png"
width="40%" height="230">
</div>

<div class="fig figright">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/c++_lowlevel.png"
width="40%" height="200">

</div>
<div class="figcaption"> A Chart showing the position of C++ among other langauges given its speed and level of developeement.</div>



### [First program ](#linkLabel)
<a name='linkLabel'></a>

To get our feet wet, let's write a program to verfify if a numer is **perfect**.

> A number is **perfect** if its equal to the sum of its divisor exluding
itself.

for example the number $$6$$ is perfect.

$$

6 = 1 + 2 + 3
$$


```cpp
#include <iostream>  

//utiliser l'espace des nom std
using namespace std;

//Fonction pour vérifier si n est pafait
bool is_perfect( int n)
{
    auto S = 0;

    for(auto div=1; div <= n/2; div++)
        if ( n % div == 0)
            S += div;

    return S == n;
}

//fonction principale
int main(int argc, char *argv[])
{

    int count = 0;  //count des nombres parfaits

    int candidate = 1; //nombre à vérifier

    while( count < 3)
         {
             if(is_perfect( candidate ))
                {
                   cout<<candidate<<" ";                
                     count++;
                }
             candidate++;
         }
    //Retour à la ligne
    cout<<endl; 
    
    return 0;
}
```


### [Deuxième programme](#secondprogram)
<a name='secondprogram'></a>

```cpp
/*tracer une distribution normale
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
 
int main()
{
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
 
    // Generate a normal distribution around that mean
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()}; 
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
 
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(normal_dist(e2))];
    }
    std::cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

```


### [Importance of Data structure](#impdata)
<a name='impdata'></a>


Mastering the tool of **data structures** is a must of each serious programmer.
This mastery  could help you choose the perfect mecanism to store data:

<div class="fig figleft ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/arrays.png" width="60%" >
</div>
<div class="fig figleft ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/linked_list.png" width="60%" >
</div>
<div class="fig figleft ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/trees.png" width="60%" >
</div>

<div class="figcaption"> Set of basic data structure.</div>

> Let suppose that we want to write a program which group:

1. Add 100000 elements in the collection.
2. Try to find 10000 elements in the collection.
3. Delete 10000 in this collection


Here are the results for a different set of data structure. All the test are
conducted in  basic computer with `2.8GHz Inter core`.


<center>
<style type="text/css">
.tg  {border-collapse:collapse;border-color:#ccc;border-spacing:0;}
.tg td{background-color:#fff;border-color:#ccc;border-style:solid;border-width:0px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{background-color:#f0f0f0;border-color:#ccc;border-style:solid;border-width:0px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-c3ow{border-color:inherit;text-align:center;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-c3ow">Structure</th>
    <th class="tg-c3ow">Temps total<br></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-c3ow">Vecteur</td>
    <td class="tg-c3ow">15.057</td>
  </tr>
  <tr>
    <td class="tg-c3ow">Vecteur Trie</td>
    <td class="tg-c3ow">1.563</td>
  </tr>
  <tr>
    <td class="tg-c3ow">Liste chainée</td>
    <td class="tg-c3ow">92.202</td>
  </tr>
  <tr>
    <td class="tg-c3ow">HashTable</td>
    <td class="tg-c3ow">0.145</td>
  </tr>
  <tr>
    <td class="tg-c3ow">Arbre binaire</td>
    <td class="tg-c3ow">0.164</td>
  </tr>
</tbody>
</table>
Temps d'exécution pour chaque structure.
</center>





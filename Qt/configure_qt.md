---
layout : page
title  :   Qt Creator and the Stanford Library
date   :  2022/09/28
permalink: /qtcreator/
---


In this tutorial we will install the **IDE** `QtCreator` which will help you
write your first code in **C++**. Occasionally, we also use the **Stanford
library** for some *interactive* homework.

## Qt Installation

###  **1) Download Qt Inline installer**

The official **QT creator** page is in the [https://www.qt.io/download-qt-installer](https://www.qt.io/download-qt-installer). Visit the website, it will detect automatically your platform ( windows or mac ). According to this, it will present the correct binary to download.


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/link_qt_creator.png">
</div>


###  **2) Run the installer**

Selon votre système d'exploitation, vous devez lancer l'exécutable qui est la
forme suivante:

Run the installer for your system:

- `qt-unified-linux-online-run` for Linux.
- `qt-unified-windows-version.exe`: for Windows.
- `qt-unified-macOs-online.dmg`: for Mac Os.

Launch you installation and be careful about the following points:


- Don't install the version **6** of Qt.
- Take the highest version with the fifth major number **Qt.5.xx.0**.
- The only needed component is **MinGW8.xx..32 bit**  

> This is illustrated in the following figure:


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/install-windows-mingw.png"
  width="500" height="400">
</div>




### **3) Stanford Library**


This step is **optional** but could be careful for some projects with some
graphics. We will install the C++ **Stanford** library.

- Download the declarations of the library  <a href="{{ site.url }}{{site.baseurl}}/Qt/CS106.zip"> CS106.zip</a>

- Unzip the content in a folder named **CS106**.
- You'll find a folder with two projects:
  1. Welcome : simple project to test your installation.
  2. Library : The main components of the library.
 

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/folder_state.PNG">
</div>


### **3.1) Library**

Open the project configuration file `Library.pro`  with **Qt Creator**.

Accept the options for the configurations as showed in the figure:

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/configure_project.PNG">
</div>

Once the project is opened, you can launch the configuration process:



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/configure_and_run.PNG">
</div>


### **4.1) Sample project**

Once the compilation of the library is finished, you can open the second project in `Welcome.pro`

1. Compile the project.

> If you encounter an error. This means that the first step was not completed.

2. Execute the project.

> You'll a terminal window asking you to enter your name:



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/Welcome_console.PNG"
  widht="400" height="300">
</div>

3. Once you entered your name, you'll see it with the Stanford logo:



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/stanford_message.PNG"
  widht="200" height="200">
</div>


>> Congratulation you just finished configuration of you IDE.

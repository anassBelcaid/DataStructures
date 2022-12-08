#pragma once
#include <iostream>
using std::cout;
using std::endl;

struct SinglyLinkedNode
{
  //attribut
  int value;
  SinglyLinkedNode * next;

  //Constructor
  SinglyLinkedNode(int value):value(value),next(nullptr){};
  SinglyLinkedNode(int value, SinglyLinkedNode* next):value(value),next(next){};
};

struct SinglyLinkedList
{
  SinglyLinkedNode * head;  //Tete de la liste chainnee

  SinglyLinkedList():head(nullptr){};

  //{{{ Delete at index
  void deleteAtIndex(int index)
  {
    //fonction pour supprimer le neoud a l'indice index
    auto n = size();

    if( index < 0 || index >= n)
      return;

    if(index == 0)
    {
      //detruire le neod
      auto tmp = head->next;
      delete head;
      head  = tmp;
      return;
    }

    //Realiser index - 1 saut
    auto current = head;
    for(int i=0; i < index - 1; i++)
      current = current->next;

    //obtenir 
    auto node = current->next;
    auto nodeN = node->next;

    delete node;
    current->next = nodeN;


  }
  //}}}

  //{{{ Add at index
  void insertAtIndex(int value , int index)
  {
    //fonction pour inserer un noeud value at index [index]
    auto n = size();
    if(index < 0 || index > n)
      return ;

    if( index == 0)
      insertAtHead(value);
    else if (index == n)
      insertAtEnd(value);
    else
    {
      auto tmp = head;
      //realiser (i-1) sauts
      for(int i=0; i < index - 1; i++)
        tmp = tmp->next;
      tmp->next = new SinglyLinkedNode(value,tmp->next);
    }


  }
  //}}}
  //{{{ size
  int size()const
  {
    int count = 0;
    auto tmp = head;
    while( tmp)
    {
      count ++;
      tmp = tmp->next;
    }
    return count;
  }
  //}}}

  //{{{ insert at end
  void insertAtEnd(int value)
  {
    // fonction pour inserver une valeur a la fin de la liste
    if(!head)
    {
      head = new SinglyLinkedNode(value);
    }
    else
    {
      //chercer le dernier element
      auto tmp = head;
      //attendre la fin
      while( tmp->next)
        tmp = tmp->next;
      tmp->next = new SinglyLinkedNode(value);
    }
    //}}}
  }
  //{{{ fonction insert at head
  void insertAtHead(int value)
  {
    //fonction pour inserer au debut
    //Creer un noeud avec la valeur value qui pointe sur head
    auto node = new SinglyLinkedNode(value, head);


    //Corriger la tete qui doit etre maintenent node
    head = node;
  }
  //}}}
  // {{{ Fonction print
  void print()
  {
    //afficher la liste
    auto tmp = head;

    while( tmp)
    {
      cout << tmp->value;
      if( tmp->next)
        cout << "->";
      else
        cout << endl;
      tmp = tmp->next;
    }
    //}}}

  }
};

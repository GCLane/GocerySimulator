/* 8/31/98 Mary Elaine Califf
 * a C++ array implementation of queues
 */
// Modifications:
//    8/20/2003 Mary Elaine Califf
//        Changed to ANSI C++
// Revised 08/21/2021
// Grant Lane and Mary Elaine Califf 
//Implementation of a queue of ints

#include <iostream>
#include "Queue.h"

using namespace std;


Queue::Queue() // constructor
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}
//Copy method for Queue
Queue::Queue(const Queue& copyQueue)
{
  copy(copyQueue);
}
//Destructor
Queue::~Queue()
{
  clear();
}
//Overrides the assignment operator
Queue Queue::operator=(const Queue& theQueue)
{
  if(this != &theQueue)
  {
    clear();
    copy(theQueue);
  }

  return *this;
}
//Private copy method that does a deep copy of the Queue
void Queue::copy(const Queue& copyQueue)
{
  size = 0;
  if(copyQueue.head == nullptr)
  {
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    head = new Node(copyQueue.head->data);
    Node* ptr1 = copyQueue.head->next;
    Node* ptr2 = head;
    tail = ptr2;
    size++;
    while(ptr1)
    {
      Node* temp = new Node(ptr1->data);
      ptr2->next = temp;

      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
      tail = ptr2;
      size++;
    }
  }
}
//Private clear method to help with deletion of a Queue
void Queue::clear()
{
  Node* curPtr = head;
  while(curPtr)
  {
    Node* deleteNode = curPtr;
    curPtr = curPtr->next;
    size--;
    delete deleteNode;
  }
}
void Queue::enqueue(int newValue) // add newValue to queue
{
  Node* temp = new Node(newValue);

  if (head == nullptr) // empty queue
  {
    head = temp;
    tail = head;
    size++;
  }
  else
  {
    tail->next = temp;
    tail = tail->next;
    tail->next = nullptr;
    size++;
  }
}

int Queue::dequeue()
{
  //Assuming queue is not empty
  Node* temp = head;
  int num = temp->data;
  head = head->next;
  if(head == nullptr)
    tail == nullptr;
  delete temp;
  size--;
  return num;
}

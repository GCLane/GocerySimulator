/* 8/31/98 Mary Elaine Califf
 * a C++ array implementation of a queue of integers which may have length of up to 100
 * 
 * Revised 08/21/2021
 */
// _____ and Mary Elaine Califf 
//Header file for a queue of ints

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
  
  // constructor
  Queue();

  //copy constructor
  Queue(const Queue& copyQueue);

  //destructor
  ~Queue();

  //override the assignment operator
  Queue operator=(const Queue& theQueue);

  // getter for size
  int getSize() { return size; }

  // is the queue empty
  bool isEmpty() { return (head == nullptr); }

  // adds a new value to the queue
  // fails and returns false if the queue is full
  void enqueue(int newValue);

  // removes a value from the queue and returns it
  // Precondition: queue must not be empty
  int dequeue();

  // return item at the front of the queue without removing it
  // Precondtion: queue must not be empty
  int front() { return head->data; }

private:
  // private methods would go here
  struct Node
  {
    int data;
    Node* next;
  
    Node(int dataVal, Node* nextPtr = nullptr) : data(dataVal), next(nextPtr){}
  };

  Node* head;
  Node* tail;
  int size;
  
  void clear();
  void copy(const Queue& copyQueue);
};

#endif

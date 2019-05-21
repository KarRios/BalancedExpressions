// Adapted from version by Frank Carrano and Timothy Henry
#include "LinkedStack.h"

template<class Type>
LinkedStack<Type>::LinkedStack() : head(nullptr) {
    
} // end default constructor

template<class Type>
LinkedStack<Type>::LinkedStack(const LinkedStack<Type> & aStack) {
    // TODO: Implement pseudocode
  Node<Type> * originalPointer = aStack.head;
  Node<Type> * temp;
    // Point to nodes in original chain

    if(originalPointer == nullptr) {
      head = nullptr;
    }
    else {
        // Copy first node
      head = new Node<Type>;
      head->data = aStack.head->data;
      originalPointer = aStack.head->next;
      temp = head;
      while(originalPointer != nullptr) {
	temp->next = new Node<Type>;
	temp = temp->next;
	temp->data = originalPointer->data;
	originalPointer = originalPointer->next;	
        } // end while 
      temp->next = nullptr;
    } // end if 
} // end copy constructor

template<class Type>
LinkedStack<Type>::~LinkedStack() {
  bool result = false;
  do{
    result = pop();
  }while(result != false);
} // end destructor

template<class Type>
bool LinkedStack<Type>::isEmpty() {
  if(head == nullptr){
    return true;
  }
  return false;
} // end isEmpty

template<class Type>
bool LinkedStack<Type>::push(Type & newElement) {
  Node<Type> * temp = new Node<Type>;
  temp->data = newElement;
  temp->next = head;
  head = temp;
  return true;
} // end push

template<class Type>
bool LinkedStack<Type>::pop() {
    // TODO: implement function
  Node<Type> * temp = new Node<Type>;
  if(head == nullptr)
    return false;

  temp = head;
  head = head->next;
  temp->next = nullptr;
  free(temp);
  return true;
} // end pop

template<class Type>
Type LinkedStack<Type>::peek() {
  if(isEmpty()){
    exit(EXIT_FAILURE);
  }
  return head->data;
} // end peek

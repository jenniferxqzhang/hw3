#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// note: smaller is less than or equal to the pivot number
// larger is greater to (strictly) to the pivot number


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  // base case is if the list is empty
  if(head == nullptr ){

    // set smaller and larger to nullptr
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  // if we make it here, the linked list is populated:
  Node* temp = head; // create a temporary variable to alter head later on
  head = head->next; 
  temp->next = nullptr;

  // recursively process list
  llpivot(head, smaller, larger, pivot);

  // compare the values to the pivot number
  // insert value into the larger linked linked list
  if(temp->val > pivot){
    // check if larger has been initialized
    if(larger == nullptr){
      larger = temp;
    }
    else{
      temp->next = larger; 
      larger = temp;
    }
  }
  // repeat the process with the smaller
  else{
    // check if smaller has been initialized 
    if(smaller == nullptr){
      smaller = temp;
    }
    else{
      temp->next = smaller;
      smaller = temp;
    }
  }
}

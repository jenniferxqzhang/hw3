#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vals; // vector to store heap values
  int m; // m-ary tree
  PComparator compare; // compare functor

};

// Add implementation of member functions here

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vals[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item

  // personal note (from lecture): pop takes last (greatest) node
  // puts it in the top location and then recursively swaps
  // it for the smallest child until it is in its right place

  size_t curr = 0;
  size_t best; // represents the top priority item
  size_t left = m *curr + 1;

  // takes the last node and puts it in the top location (esentially popping the first node)
  vals[0] = vals.back(); 
  vals.pop_back();

  // move down the heap and figure out if any parents need to be swapped with their children
  while (left < vals.size()){
    best = curr;
    size_t right = m * curr + m;

    for (size_t i = left; i < vals.size() && i <=right; i++){
      if(compare(vals[i], vals[best])){
        best = i; // swap if condition is triggered (min or max)
      }
    }

    // if no swap is needed, break
    if(best == curr){
      break;
    }

    //swap variables
    T temp = vals[curr];
    vals[curr] = vals[best];
    vals[best] = temp;
    curr = best;
  
    // update left 
    left = m *curr + 1;

  }
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{

  // first add item to the last open position in the heap
  vals.push_back(item);
  size_t curr = vals.size()-1;
  size_t parent;

  // while there are still nodes to traverse:
  while(curr > 0){

    // find the parents location
    parent = (curr -1)/m;

    // compare the current value with the parent's
    if(compare(vals[curr],vals[parent])){
      // if needed, swap
      std::swap(vals[curr], vals[parent]);
      curr = parent;
    }
    else{
      // if no swap is needed, heap is in the correct order
      break;
    }
  }
}

// since heap uses the vector container, we can use .empty()
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return vals.empty();
}

// since heap uses the vector container, we can use .size()
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return vals.size();
}


// destructor - not needed in this case
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}


// constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator compare) : m(m), compare(compare) // initalize data members in an initialization list
{

}


#endif


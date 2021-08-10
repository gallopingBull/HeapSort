/**
 * @file MinPriority.cpp  Implementation of minpriority queue 
 * 
 * @brief Implemenation of min-priority queue and min-heap. 
 * 
 * @author Joshua Salcido
 * @date 5/17/16
 */

#include <iostream> 
#include <string>
#include <vector> 
#include <utility> 
#include "MinPriority.h" 
using std::swap;

using namespace std; 

/*
 * Minpriority constructor
*/
MinPriority::MinPriority(){
    //heapsize = -1; 
}

/*
 * Minpriority destructor 
*/
MinPriority::~MinPriority(){
}


/*
 * Checks if vertex from input is already in array
 *
 *@param string 
 *@return bool
*/
bool MinPriority::isMember(string id){
    for(unsigned int i = 0; i < minHeap.size(); i++){
        if(id == minHeap[i]->id){
            return true;
        }
    }
    return false; 
}

/*
 * Insert new element into array 
 *
 * @param string
 * @param key
 *
*/
void MinPriority::insert(string id, int key){
   
    Element *tmp = new Element(); 
    tmp->id = id;
    tmp->key = key;
    minHeap.push_back(tmp); 

    decreaseKey(id, key); 
}

/*
 * 
 * Decreases key element in the array 
 *
 * @param string
 * @param key
*/
void MinPriority::decreaseKey(string id, int newKey){
    
    int heapsize = minHeap.size(); 
    int index; 

    if(heapsize == 0){
        //cout << "empty"; 
    }
    else{

        for(int i = 0; i < heapsize; i++){
            if(minHeap[i]->id == id){
                index = i; 
                if(newKey > minHeap[index]->key){
                    return; 
                }
                minHeap[index]->key = newKey;
                while(index > 0 && minHeap[parent(index)]->key > minHeap[index]->key){
                    swap(minHeap[index], minHeap[parent(index)]);
                    index = parent(index); 
                }
            break;     
            }
        }
    }
}


/*
 * returns smallest element
 *
 * @param string
 * @return string
*/
string MinPriority::extractMin(){
    string min;
    int heapsize = minHeap.size(); 

    if(heapsize < 1){
        //cout << "Empty"; 
    }

    else{
        min = minHeap[0]->id; 
        minHeap.erase(minHeap.begin());
        minHeapify(0); 

    }

    return min; 
}

/*
 * builds the heap 
 *
*/
void MinPriority::buildMinHeap(){
    int heapsize = minHeap.size(); 
    for(int i =  (heapsize / 2); i > 0; i--){
        minHeapify(i); 
    }
}

/*
 * Checks if heap is empty 
 *
 * @return bool 
*/
bool MinPriority::isEmpty(){
    return minHeap.size() == 0; 
}

/*
 * Assists buildMinHeap in building heap
 *
 * @param int
*/
void MinPriority::minHeapify(int i){
    int smallest = 0;
    int l = left(i);
    int r = right(i);
    int heapsize = minHeap.size(); 

    if(l < heapsize && minHeap[l]->key < minHeap[i]->key){
        smallest = l; 
    }
    else{
        smallest = i; 
    }
    if(r < heapsize && minHeap[r]->key < minHeap[smallest]->key){
        smallest = r;
    }
    if(smallest != i){
        swap(minHeap[i], minHeap[smallest]); 
        minHeapify(smallest); 
    }
}

/*
 * returns parent 
 *
 * @param int 
 * @return int 
*/
int MinPriority::parent(int i){
    return (i-1) / 2;
}

/*
 * returns left child  
 *
 * @param int 
 * @return int 
*/
int MinPriority::left(int i){
    return (2 * i) + 1;
}

/*
 * returns right child  
 *
 * @param int 
 * @return int 
*/
int MinPriority::right(int i){
    return (2 * i) + 2; 
}

/*void MinPriority::print(){
    vector<Element>::iterator it;

    for(it = minHeap.begin(); it != minHeap.end(); it++){
        cout << it->id << " "; 
    }
    cout << endl; 
}*/ 

/*
 * returns heapsize
 *
 * @return int 
*/
int MinPriority::heapSize(){
    int heapsize = (int)minHeap.size()-1; 

    return heapsize; 
}

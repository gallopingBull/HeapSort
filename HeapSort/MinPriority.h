/**
 * @file MinPriority.h  Declaration of min-priority queue using a min-heap
 * 
 * @author Joshua Salcido
 * @date 5/17/16
 */

//#pragma once
#ifndef MINPRIORITY_H
#define MINPRIORITY_H

#include <string> 
#include <vector>
//#include "graph.h" 

using namespace std;

class MinPriority{
    public: 
          MinPriority();
          ~MinPriority();
          void insert(string id, int key);
          void decreaseKey(string id, int newKey);
          string extractMin();
          bool isMember(string id);
          
          // My methods
          void print(); 
          int heapSize();
          bool isEmpty(); 

    private: 
          class Element{
              public:
                  string id;
                  int key;
                  //Element(string, int);
                  //~Element(); 
          };
          
          //int heapsize; 
          vector<Element*> minHeap; 
          void buildMinHeap(); 
          void minHeapify(int i);
          int parent(int i);
          int left(int i);
          int right(int i);

};
#endif 

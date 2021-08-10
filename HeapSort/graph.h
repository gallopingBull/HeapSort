/**
 * @file graph.h  Declaration of graph and assoicated methods 
 * 
 * @author Joshua Salcido
 * @date 5/17/16
 */


//#pragma once 
#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <map>

#include <iostream>
#include <vector> 
#include <algorithm> 

#include "MinPriority.h"
#define INFINITE 100 

using std::string; 
using std::map;
using namespace std; 

class Graph{
  
  public:
      Graph();
      ~Graph(); 
      void addVertex(string name);
      void addEdge(string from, string to, int weight); 
      string getShortestPath(string from, string to);
      

  private:
    class Neighbor{
      public: 
        string name; 
        int weight; 
        //Neighbor* parent; 
    }; 
 
    class Vertex{
        public: 
          string pi; 
          int key; 
          Vertex* parent;

    };

    void buildSSPTree(string source); 
    void relax(string u, string v, int weight); 

    MinPriority minQ; 
    map<string, Vertex*> vertices; 
    map<string, vector<Neighbor*>> adjList;

    string currentSource;

};
#endif 



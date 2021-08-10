/**
 * @file SSPapp.cpp  Implementation of SSPapp methods
 * 
 * @author Joshua Salcido
 * @date 5/17/16
 */

#include <iostream>
#include <string> 
#include "SSPapp.h"

using namespace std; 

/*
 * program driver. calls method to read graphs  
 *
 * @param int 
 * @return int 
*/
int main(){
  SSPapp mySSPapp; 
  mySSPapp.readGraph();
  mySSPapp.processQueries(); 
  return 0; 
}

/*
 * reads input into graph 
 *
*/
void SSPapp::readGraph(){
    
    string vertex, pVertex;
    string from, to;
    int vCount, eCount, weight;
    
    cin >> vCount; 
    myGraph.addVertex(vertex); 
    
    for(int i = 0; i < vCount; i++){
        cin >> vertex; 
        myGraph.addVertex(vertex); 

    }

    cin >> eCount; 
    for(int j = 0; j < eCount; j++){
        cin >> from;
        cin >> to; 
        cin >> weight; 
        myGraph.addEdge(from, to, weight);
    }
}

/*
 * prints out queries 
*/
void SSPapp::processQueries(){
    string from, to, getPath;

    while(!cin.eof()){
        cin >> from >> to; 
        getPath = myGraph.getShortestPath(from, to); 
        from.clear();
        from = " ";
        to.clear();
        to = " ";
        cout << getPath << endl; 
    }
}

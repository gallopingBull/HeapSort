/**
 * @file graph.cpp  Implemenations of graph and assoicated methods 
 * 
 * @author Joshua Salcido
 * @date 5/17/16
 */

#include <iostream> 
#include <string>
#include <cstdlib>
//#include <sstream> 

#include "graph.h" 
using namespace std; 


/*
 * Graph Constructor 
*/
Graph::Graph(){
    Vertex *vertex = new Vertex(); 
    vertex->key = INFINITE;
    vertex->pi = "NIL"; 
}

/*
 * Graph Destructor 
*/

Graph::~Graph(){
}

/*
 * Adds vertices to array 
 *
 * @param strings
*/
void Graph::addVertex(string name){
   
    Vertex *tmp = new Vertex;
    tmp->pi = "NIL"; 
    tmp->key = INFINITE; 
    vertices[name] = tmp; 

}

/*
 * Adds edges to array
 *
 *@param string
 *@param string
 *@param int 
*/
void Graph::addEdge(string from, string to, int weight){

    Neighbor *tmp = new Neighbor(); 
    tmp->name = to; 
    tmp->weight = weight; 
    adjList[from].push_back(tmp); 
    
    map<string, Vertex*>::iterator it; 
}

/*
 * Looks for shortest path between vertices and returns
 * the value. 
 *
 *@param string
 *@param string
 *@return string
*/
string Graph::getShortestPath(string from, string to){
    string space =  " ";
    if(from != " " && to != " "){
        buildSSPTree(from); 
        vector<Vertex> tmp; 
        space = to; 
        string c = to; 
        string convert;
        while(vertices[c]->pi != "NIL"){
            string d, a;

            a = vertices[c]->pi; 
            d= a; 

            d.append("->");
            d.append(space);
            space = d; 
            c = a; 
        }
        space.append(" with length "); 
        int ssp = vertices[to]->key;
        convert = std::to_string(ssp);
        space.append(convert); 
    }
    return space; 
}

/*
 * Build single source path tree 
 *
 *@param string
 * 
*/
void Graph::buildSSPTree(string source){
    string u;

    for(map<string, Vertex*>::const_iterator it = vertices.begin(); it!=vertices.end(); ++it){
        it->second->key = INFINITE;
        it->second->pi = "NIL"; 
    }
    
    vertices[source]->key = 0; 

    for(map<string, Vertex*>::const_iterator it = vertices.begin();it != vertices.end(); ++it){
        minQ.insert(it->first, it->second->key); 
    }
    
    while(minQ.heapSize() > 0){
        u = minQ.extractMin();
        for(map<string, vector<Neighbor*>>::const_iterator tmp1 = adjList.begin(); tmp1 != adjList.end(); ++tmp1){
            if(((*tmp1).first) == u){
                for(vector<Neighbor*>::const_iterator inc = ((*tmp1).second.begin()); inc != ((*tmp1).second.end()); inc++){
                    int tmp;
                    tmp = vertices[u]->key + ((*inc)->weight);
                    if(tmp < vertices[((*inc)->name)]->key){
                        vertices[((*inc)->name)]->key = tmp;
                        vertices[((*inc)->name)]->pi = u; 
                         minQ.decreaseKey(((*inc)->name), tmp);
                    }
                }
            }
        }
    }
}

/*void Graph::relax(string u, string v, int weight){
    if (v.d > u.d + weight){
        v.d = u.d + weight; 
        v.pi = u;  
    } 
}*/ 

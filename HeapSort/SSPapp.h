/**
 * @file SSPapp.h  Declaration of SSPapp methods  
 * 
 * @author Joshua Salcido
 * @date 5/17/16
 */

//#pragma once
#ifndef SSPAPP_H
#define SSPAPP_H

#include <string>
#include "graph.h" 

class SSPapp{
  public:
    void main(); 
    void readGraph();
    void processQueries(); 
  private:
    Graph myGraph; 
};

#endif

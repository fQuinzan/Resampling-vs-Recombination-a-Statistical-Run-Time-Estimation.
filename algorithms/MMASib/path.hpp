//
//  path.hpp
//  Reeval
//
//  Created by Francesco Quinzan on 30.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef path_hpp
#define path_hpp

#include "libraries.h"
#include "table.hpp"
#include "pheromone.hpp"
#include "random.hpp"

class path{
    
    class table<int> data;
    int lambda;
    
public:
    
    /* set path according to pheromone traits */
    void set (class pheromone*);
    
    /* get single row */
    std::vector<int> get(int i){
        std::vector<int> path = path::data.GET_ROW(i);
        return(path);
    };
    
    /* get single value */
    inline int value (int k){
        return(path::data.GET_VALUE(0, k));
    };
    
    /* get the optimum */
    vector<int> best(class fitness*);
    
    /* check convergence */
    int check();
    
    /* get lambda parameter */
    inline int size(){
        return(path::data.GET_N_ROW());
    };
    
    /* constructor - fix lambda */
    path(int lambda){
        path::lambda = lambda;
    }
    
};

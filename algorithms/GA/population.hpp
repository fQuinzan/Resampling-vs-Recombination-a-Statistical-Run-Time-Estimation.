//
//  population.hpp
//  Reeval
//
//  Created by Francesco Quinzan on 28.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef population_hpp
#define population_hpp

#include "libraries.h"
#include "table.hpp"
#include "random.hpp"

class population {
    
    class table<int> data;
    int ord;
    
public:
    
    /* generate random population */
    
    void set(int, int, int);
    
    /* get dimension, size order */
    inline int dimension(){
        return(population::data.GET_N_COL());
    };
    inline int size(){
        return(population::data.GET_N_ROW());
    };
    inline int order(){
        return(population::ord);
    };
    
    /* erase given individual */
    void kill(int individual){
        population::data.ERASE_ROW(individual);
        return;
    };
    
    /* get individual as vector<int> */
    vector<int> individual(int individual){
        return(population::data.GET_ROW(individual));
    };
    
    /* get pointer to a specific value*/
    vector<int>* row(int);
    
    /* introduce mutation factor */
    void mutation(int);
    
    /* create offspring */
    void offspring(int);
    
    /* check if true optimum has been reached */
    int check();
    
};

#endif /* population_hpp */

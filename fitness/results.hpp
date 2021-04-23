//
//  results.hpp
//  Reeval
//
//  Created by Francesco Quinzan on 26.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef results_hpp
#define results_hpp

#include "libraries.h"
#include "table.hpp"

class results{
    
    class table<double> data;
    
public:
    
    /* adds element to the table */
    void add (double);
    
    /* clear the entire table */
    void clear(){
        results::data.CLEAR();
        return;
    };
    
    /* delete a specific row */
    void del(int i){
        results::data.ERASE_ROW(i);
        return;
    };
    
    /* find index with min/max value */
    int max ();
    int min ();
    
    /* find minimum/maximum value */
    double minimum(){
        return (results::data.GET_VALUE(results::min(), 0));
    };
    double maximum(){
        return (results::data.GET_VALUE(results::max(), 0));
    };
    
    /* get an element of the vector */
    double get (int i){
        return(data.GET_VALUE(i, 0));
    };
    
    /* get an element of the vector */
    int size(){
        return(data.GET_N_ROW());
    };
    
};

#endif /* results_hpp */

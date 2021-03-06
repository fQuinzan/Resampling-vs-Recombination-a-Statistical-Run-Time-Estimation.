//
//  path.cpp
//  Reeval
//
//  Created by Francesco Quinzan on 30.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#include "path.hpp"
#include "table.hpp"
#include "pheromone.hpp"
#include "random.hpp"


void path::set(class pheromone * pheromone){
    path::data.CLEAR();
    path::data.RESIZE(path::lambda, pheromone->dimension());
    for (int i = 0; i < path::lambda; i++){
        for (int j = 0; j < pheromone->dimension(); j++){
            if(randomEngine::uar() < pheromone->get(0,j))
                path::data.SET_VALUE(1, i, j);
        }
    }
    return;
};


int path::check(){
    
    int err = 0;
    
    for (int i = 0; i < data.GET_N_ROW(); i++){
        for (int j = 0; j < data.GET_N_COL(); j++){
            err = err + data.GET_VALUE(i, j);
        }
        if (err == data.GET_N_COL())
            break;
        else
            err = 0;
        
    }
    return err;
    
};

/* get the optimum */
vector<int> path::best(class fitness* fitness){
    return(path::data.GET_ROW(fitness->results::max()));
};

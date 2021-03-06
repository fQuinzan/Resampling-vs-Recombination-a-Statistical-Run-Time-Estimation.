//
//  ACO.hpp
//  OneMax
//
//  Created by Francesco Quinzan on 29.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef ACO_hpp
#define ACO_hpp

#include "libraries.h"
#include "pheromone.hpp"
#include "path.hpp"

class ACO {
    
    // flow control parameters
    int MAX_STEPS = std::numeric_limits<int>::max();
    int N_STEPS;
    
    // search space and algorithm parameters
    int dimension;
    int size;
    double rho;
    
    // fitness parameters
    int n = 1;
    double sigma = 0;
    
public:
    
    // constructor - set dimension/evaporation factor
    ACO(int dimension, int size, double rho){
        ACO::dimension = dimension;
        ACO::size = size;
        ACO::rho = rho;
    }
    
    // set random error
    void posteriorNoise(double sigma, int n){
        ACO::sigma=sigma;
        ACO::n = n;
        return;
    };
    
    // run algorithm
    int run();
    
};

#endif /* ACO_hpp */

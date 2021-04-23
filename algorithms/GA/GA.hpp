//
//  GA.hpp
//  OneMax
//
//  Created by Francesco Quinzan on 26.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef GA_hpp
#define GA_hpp

#include "libraries.h"
#include "OneMax.hpp"
#include "population.hpp"
#include "random.hpp"
#include "fitness.hpp"

class GA {
    
    // flow control parameters
    int MAX_STEPS = std::numeric_limits<int>::max();
    int N_STEPS;
    
    // search space parameters
    int dimension;
    int size;
    int order;
    
    // fitness parameters
    int n = 1;
    double sigma = 0;
    
public:
    
    int N_PARENTS = 2;
    
    // constructor - set dimension/size/order
    GA(int dimension, int size, int order){
        GA::dimension = dimension;
        GA::size = size;
        GA::order = order;
    };
    
    // constructor - set random error
    void posteriorNoise(double sigma, int n){
        GA::n = n;
        GA::sigma=  sigma;
        return;
    };
    
    // run algorithm
    int run();
    
};

#endif /* GA_hpp */

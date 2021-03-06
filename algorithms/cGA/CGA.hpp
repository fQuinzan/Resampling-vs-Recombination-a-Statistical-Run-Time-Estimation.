//
//  CGA.hpp
//  OneMax
//
//  Created by Francesco Quinzan on 06.11.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef CGA_hpp
#define CGA_hpp

#include "libraries.h"
#include "fitness.hpp"

class CGA{
    
    /* flow control parameters */
    int maxSteps = std::numeric_limits<int>::max();
    int nSteps;
    
    /* search space and algorithm parameters */
    int dimension;
    double K;
    
    /* fitness parameters */
    int n = 1;
    double sigma = 0;
    
public:
    
    /* constructor - set dimension and K parameter */
    CGA(int dimension, double K){
        CGA::dimension = dimension;
        CGA::K = K;
    }
    
    /* set posterior noise */
    void posteriorNoise(double sigma, int n){
        CGA::sigma = sigma;
        CGA::n = n;
        return;
    };
    
    /* run algorithm */
    int run();
    double f(vector<int> *);
    double g(vector<int> *);
    void swap(vector<int> *, vector<int> *);
    
};

#endif /* CGA_hpp */

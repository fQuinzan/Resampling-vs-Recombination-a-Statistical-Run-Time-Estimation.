//
//  randomEngine.hpp
//  OneMax
//
//  Created by Francesco Quinzan on 27.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef random_hpp
#define random_hpp

#include "libraries.h"

namespace randomEngine{
    
    namespace randomEngine{
        
        /* get a string in imput and convertit to integer - for setting seed */
        extern int getASCII();
        
        /* return real number u.a.r. */
        extern double uar();
        
        /* return integer between >= 0 and < n u.a.r. */
        extern int int_uar(int n);
        
        /* return real with normal distribution with given mean and sd */
        extern double nrm(double mean, double sd);
        
        /* return a random k-sequence of distinct integers < n */
        extern vector<int> intChain_uar(int n, int k);
        
        /* set seed based on manually inserted randomness and current date & time */
        extern void set_seed(int);
        
    };

};

#endif /* random_hpp */

//
//  randomEngine.cpp
//  OneMax
//
//  Created by Francesco Quinzan on 27.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#include "random.hpp"

/* random number generator */
mt19937_64 generator;

/* return real number u.a.r. */
double randomEngine::uar(){
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return(distribution(generator));
};

/* return integer between >= 0 and < n u.a.r. */
int randomEngine::int_uar(int n){
    std::uniform_int_distribution<int> distribution(0, n - 1);
    return(distribution(generator));
};

/* return real with normal distribution with given mean and sd */
double randomEngine::nrm(double mean, double sd){
    std::normal_distribution<double> distribution(mean, sd);
    return (distribution(generator));
};

/* return a random k-sequence of distinct integers < n */
vector<int> randomEngine::intChain_uar(int n, int k){
    vector<int> results;
    if (k <= n){
        for (int i = 0; i < n; i++)
            results.push_back(i);
        for (int j = 0; j < n-k; j++)
            results.erase(results.begin() + randomEngine::int_uar((int)results.size()));
    }
    return(results);
};

/* set seed based on manually inserted randomness and current date & time */
void randomEngine::set_seed(int seed){
    std::srand(seed);
    seed = (unsigned)std::rand();
    generator.seed(seed);
    return;
};

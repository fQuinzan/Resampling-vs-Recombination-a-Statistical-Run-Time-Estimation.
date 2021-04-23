//
//  ACO.cpp
//  OneMax
//
//  Created by Francesco Quinzan on 29.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#include "ACO.hpp"
#include "pheromone.hpp"
#include "path.hpp"

int ACO::run(){
    
    ofstream ACO_pheromone_analysis;
    ACO_pheromone_analysis.open ("/Users/fq00/Desktop/ACO_pheromone_analysis.txt");
    
    /* Step 1: set up values */
    class fitness fitness;
    class path path(ACO::size);
    class pheromone pheromone(ACO::dimension, ACO::rho);
    
    for (ACO::N_STEPS = 0; ACO::N_STEPS < ACO::MAX_STEPS; ACO::N_STEPS++){
        
        /* Step 2: choose random path accordingly to pheromone */
        path.set(&pheromone);
        
        /* Step 3: compute fitness */
        fitness.fit(&path, ACO::sigma, ACO::n);
        
        /* Step 4: check convergence condition */
        if (path.check() == ACO::dimension) break;
        
        /* Step 5: adjust pheromone to fitness (food gain) */
        pheromone.adjust(&path, &fitness);
        
    }
    
    ACO_pheromone_analysis.close();
    return (ACO::N_STEPS);
    
}

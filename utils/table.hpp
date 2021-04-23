//
//  database.hpp
//  OneMax
//
//  Created by Francesco Quinzan on 28.10.15.
//  Copyright © 2015 Francesco Quinzan. All rights reserved.
//

#ifndef table_hpp
#define table_hpp

#include "libraries.h"

template <class T> class table{
    
    std::vector<std::vector<T>> TABLE;
    
public:
    
    T GET_VALUE(int i, int j);
    
    void RESIZE(int, int);
    
    int GET_N_COL();
    
    void ERASE_ROW(int n);
    
    std::vector<T> GET_ROW(int n);
    
    void SET_VALUE(T val, int i, int j);
    
    int GET_N_ROW();
    
    void CLEAR();
    
};

template <class T> T table<T>::GET_VALUE(int i, int j){
    try{
        return (table::TABLE.at(i)).at(j);
    }
    catch(const std::out_of_range& oor){
        exit (EXIT_FAILURE);
    }
};

template <class T> int table<T>::GET_N_COL(){
    return((int)(table::TABLE.front()).size());
};

template <class T> void table<T>::ERASE_ROW(int n){
    try{
        table::TABLE.erase(table::TABLE.begin() + n);
    }
    catch(const std::out_of_range& oor){
        exit (EXIT_FAILURE);
    }
    return;
};

template <class T> vector<T> table<T>::GET_ROW(int i){
    try{
        return table::TABLE.at(i);
    }
    catch(const std::out_of_range& oor){
        exit (EXIT_FAILURE);
    }
};

template <class T> void table<T>::SET_VALUE(T val, int i, int j){
    try{
        (table::TABLE.at(i)).at(j) = val;
    }
    catch(const std::out_of_range& oor){
        exit (EXIT_FAILURE);
    }
    return;
};

template <class T> int table<T>::GET_N_ROW(){
    return((int)table::TABLE.size());
};

template <class T> void table<T>::CLEAR(){
    table::TABLE.clear();
    return;
};

template <class T> void table<T>::RESIZE (int N_ROW, int N_COL){
    table::TABLE.resize(N_ROW);
    for (int i = 0; i < table::TABLE.size(); i++)
        (table::TABLE.at(i)).resize(N_COL);
    return;
};

#endif /* database_hpp */

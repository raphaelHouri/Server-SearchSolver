//
// Created by meshi on 16/01/2020.
//
#pragma once

#ifndef FINALPROJECTPART2_SEARCHERABSTRACT_H
#define FINALPROJECTPART2_SEARCHERABSTRACT_H


#include "Searcher.h"

using namespace  std;
template <class T>
class SearcherAbstract: public Searcher<T, vector<State<T> *>>{
protected:
    int evaluateNodes;


public:
    SearcherAbstract() {
        evaluateNodes = 0;
    }

    //for the algo
    int getNumOfNodesEvaluated() {
        return this->evaluateNodes;
    }


    //return the reverse path
    vector<State<T> *> reversePath(State<T> *lastState, State<T> *init) {

        vector<State<T> *> shortPath;

        while (!(lastState->equals(init))) {
            shortPath.push_back(lastState);
            lastState = lastState->getCamefrom();
        }
        shortPath.push_back(lastState);
        return shortPath;
    }
    bool containInClose(vector<State<T>*> closeVec,State<T> *s) {
        for (const auto &state : closeVec) {
            if(state == s)
                return true;
        }
        return false;
    }

};

#endif //FINALPROJECTPART2_SEARCHERABSTRACT_H

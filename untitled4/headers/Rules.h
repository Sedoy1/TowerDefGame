#ifndef UNTITLED4_RULES_H
#define UNTITLED4_RULES_H
#include "Spawner.h"

template <typename T>
class Rules{
private:
    std::vector<T> rulesLoose;
    std::vector<T> rulesWin;
public:
    void addRuleLoose(T rule);
    void addRuleWin(T rule);
    bool checkWinRules();
    bool checkLooseRules();
};

template<typename T>
void Rules<T>::addRuleLoose(T rule) {
    rulesLoose.push_back(rule);
}

template<typename T>
void Rules<T>::addRuleWin(T rule) {
    rulesWin.push_back(rule);
}

template<typename T>
bool Rules<T>::checkWinRules() {
    for(auto rule: rulesWin){
        if (!rule()){
            return false;
        }
    }
    return true;
}

template<typename T>
bool Rules<T>::checkLooseRules() {
    for(auto rule: rulesLoose){
        if (!rule()){
            return false;
        }
    }
    return true;
}

#endif //UNTITLED4_RULES_H

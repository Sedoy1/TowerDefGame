//#pragma once
//#include "../headers/Rules.h"
//
//template class Rules <std::function<bool()>>;
//
//template<class T>
//void Rules<T>::addRuleLoose(T rule) {
//    rulesLoose.push_back(rule);
//}
//
//template<class T>
//void Rules<T>::addRuleWin(T rule) {
//    rulesWin.push_back(rule);
//}
//
//template<class T>
//bool Rules<T>::checkWinRules() {
//    for(auto rule: rulesWin){
//        if (!rule()){
//            return false;
//        }
//    }
//    return true;
//}
//
//template<class T>
//bool Rules<T>::checkLooseRules() {
//    for(auto rule: rulesLoose){
//        if (!rule()){
//            return false;
//        }
//    }
//    return true;
//}

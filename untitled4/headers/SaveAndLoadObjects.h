#ifndef UNTITLED4_SAVEANDLOADOBJECTS_H
#define UNTITLED4_SAVEANDLOADOBJECTS_H
#include "fstream"
#include "vector"
#include "memory"

template<class T>
void SaveObjects(T & object, const std::string & path){
    std::ofstream out(path);
    object.GetInfo(out);
    out.close();
}

template<class T>
void SaveObjects(std::vector<std::shared_ptr<T>> & vector, const std::string & path){
    std::ofstream out(path);
    for(auto i : vector)
        i->GetInfo(out);
    out.close();
}

template<class T>
void LoadObjects(T & where){

}

#endif //UNTITLED4_SAVEANDLOADOBJECTS_H

#pragma once

#include <list>
#include <cmath>
#include <iterator>
#include <list>

template <typename T>
class PrimeGen{
public:
  PrimeGen(){vect.push_back(2);vect.push_back(3);vect.push_back(5);};
  T generate_next(void);
  T last(void);
  void remove(typename std::list<T>::iterator start, typename std::list<T>::iterator end);
  typename std::list<T>::iterator begin(void);
  typename std::list<T>::iterator end(void);
private:
  std::list<T> vect;
};

template <typename T>
T PrimeGen<T>::generate_next(void){
  T cand=this->last();
  while(true){
    bool found=true;
    cand+=2;
    if(!(cand%5)){
      continue;
    }
    T sqrt_cand=std::sqrt(cand)+1;
    for(auto it=this->begin(); *it<sqrt_cand && it!=this->end(); it++){
      if(cand/(*it)*(*it)==cand){
        found=false;
        break;
      }
    }
    if(found){
      vect.emplace_back(cand);
      return cand;
    }
  }
}

template <typename T>
T PrimeGen<T>::last(void){
  return vect.back();
}

template <typename T>
typename std::list<T>::iterator PrimeGen<T>::begin(){
  return vect.begin();
}

template <typename T>
typename std::list<T>::iterator PrimeGen<T>::end(){
  return vect.end();
}

template <typename T>
void PrimeGen<T>::remove(typename std::list<T>::iterator start, typename std::list<T>::iterator end){
  vect.erase(start, end);
  return;
}


#ifndef HASHBUCKET_H
#define HASHBUCKET_H
#include <vector> 
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std; 

class Hashbucket{
 public:
  Hashbucket(){};
  void addElement(string word){
    if(count == 0){
      arr = new string[size]();
    }
    arr[count] = word;
    count++;
  };
  void increment() {size++;}
  void decrement() {size--;}
  int getSize() {return size;}
  int getCount() {return count;}
  string *getWords() {return arr;}
  
  string *arr;

private:
  int size = 0;
  int count = 0;
  
};
#endif

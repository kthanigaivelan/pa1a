#ifndef HASHBUCKET_H
#define HASHBUCKET_H
#include <string>
#include <iostream>

using namespace std;

class Hashbucket{
public:
  Hashbucket(){
    size = 0;
    idx = 0;
  }
  void addElement(string word){
    if(idx == 0){
      words = new string[size];
      words[idx] = word;
      idx++;
    }
    else{
      words[idx] = word;
      idx++;
    }
  }
  long getSize(){return size;}
  string * getWords(){return words;}
  void increment(){size++;}
  void decrement(){size--;}
  long getLastInserted(){return idx;}
  bool alreadyExists(string word){
    bool status = false;
    if(idx != 0){
      for(int i=0; i <idx; i++){
	if(words[i].compare(word) == 0){
	  status = true;
	}
      }
    }
    return status;
  }
  
  string * words;
  
private:
  long size = 0;
  long idx = 0;
};
#endif

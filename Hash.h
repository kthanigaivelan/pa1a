// hash.h

#ifndef HASH_H
#define HASH_H
#include <vector> 
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "Hashbucket.h"

using namespace std; 



class Hash{

 public:
  Hash(int argc, char *argv[]);
  void insert1(char * argv[], int size);
  void insert2(char* argv[]);
  int hornerVal(string x);
  int input(); 
  int num_inserted(); 
  int tablesize(); 
  int collisions(); 
  void elements(); 
  int max(); 
  void maxwords(); 

  ~Hash();
private:
  int p;
  int C;
  int size;
  int insertedwords = 0; 
  Hashbucket * table;
 
  
  
};
#endif
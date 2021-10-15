#ifndef HASH_H
#define HASH_H

#include "Hashbucket.h"

class Hash{
public:
  Hash(long p,long C,int argc,char *argv[]);
  ~Hash();
  long long hornerVal(string word);
  long inputSize();
  long numInserted();
  long primaryArraySize();
  long numCollisions();
  long maxIndex(); //helper for numCollisions
  void maxWords();
  void elements();
  void query(string word);
  bool empty;
  
private:
  long long p;
  long long C;
  long size;
  Hashbucket * h;
  //bool empty = false;
};

#endif

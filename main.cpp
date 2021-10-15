#include "Hash.h"
#include "Hashbucket.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
  ifstream file;
  string word;

  file.open(argv[1]);
  getline(file, word);
  long p = stoll(word);
  getline(file, word);
  long C = stoll(word);
  file.close();

  //h = new Hashbucket[p];
  //for(long i=0; i<p; i++){
  //h[i] = new Hashbucket();
  //}
  /*
  file.open(argv[2]);
  while(getline(file,word)){
    size++;
    long long key = hornerVal(word);
    h[key]->increment();
  }
  file.close();
  */
  Hash h1 = new Hash(p,C,argc,argv);
  return 0;
}

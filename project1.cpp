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
  Hash h1(p,C,argc,argv);
  cout << "Size of input: " << h1.inputSize() << endl;
  cout << "Number of words in table: " << h1.numInserted() << endl;
  cout << "Primary array size: " << h1.primaryArraySize() << endl;
  cout << "Maximum number of collisions in a hashbucket: " << h1.numCollisions() << endl;;
  cout << "The number of hashbuckets b with x elements:" << endl;
  h1.elements();
  //cout << endl;
  cout << "Keys in most populated bucket: ";
  h1.maxWords();
  cout << endl;

  //  cout << "Queries" << endl;
  if(argc == 4){
    cout << "Queries" << endl;
    file.open(argv[3]);
      while(getline(file,word)){
	h1.query(word);
      }
  }
  return 0;


}

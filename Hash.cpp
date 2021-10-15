#include "Hash.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Hashbucket.h"

using namespace std;

Hash::Hash(long p,long C,int argc,char *argv[]){
  ifstream file;
  string word;
  this->p = p;
  this->C = C;
  /*  file.open(argv[1]);
  getline(file, word);
  p = stoll(word);
  getline(file, word);
  C = stoll(word);
  file.close();
  */
  h = new Hashbucket[p]();
  //h = (Hashbucket*)malloc(p+1);
  //for(long i=0; i<p; i++){
  //h[i] = new Hashbucket();
  //}
  
  file.open(argv[2]);
  while(getline(file,word)){
    size++;
    long long key = hornerVal(word);
    h[key].increment();
  }
  file.close();

  file.open(argv[2]);
  while(getline(file,word)){
    long long key = hornerVal(word);
    bool exists = h[key].alreadyExists(word);
    if(!exists){
      h[key].addElement(word);
    }
    else{
      h[key].decrement();
    }
  }
};

Hash::~Hash(){
  //for(long i=0; i<size; i++){
  //delete h[i];
  //}
  delete [] h;
}

long long Hash::hornerVal(string word){
  long long val = 0;
  for(long i=word.length() - 1; i>= 0; i--){
    val = val * C ;
    val = val + int(word.at(i));
    //val = val * C;
    val = val % p;
  }
  return val;
}

long Hash::inputSize(){
  return size;
}

long Hash::numInserted(){
  long inserted = 0;
  for(long i=0; i < p; i++){
    inserted = inserted + h[i].getSize();
  }
  return inserted;
}

long Hash::primaryArraySize(){
  return p;
}

long Hash::numCollisions(){
  long maxIdx = maxIndex();
  return (h[maxIdx].getSize()) - 1;
}

long Hash::maxIndex(){
  long maxNumWords = 0;
  long maxIdx = -1;
  for(long i=0; i <p; i++){
    if(h[i].getSize() > maxNumWords){
      maxNumWords = h[i].getSize();
      maxIdx = i;
    }
  }
  return maxIdx;
}

void Hash::maxWords(){
  long maxIdx = maxIndex();
  string * tmp = h[maxIdx].getWords();
  for(long i=0; i<(h[maxIdx].getSize()); i++){
    cout << tmp[i] << " ";
  }
  cout << endl;
}

void Hash::elements(){
  for(long i =0; i<21; i++){
    long count =0;
    cout << "x=" << i << " : " << "b=";
    for(long j=0; j<p; j++){
      if(h[j].getSize() == i){
	count++;
      }
    }
    cout << count << endl;
    }
}

void Hash::query(string word){
  long key = hornerVal(word);
  bool yes = h[key].alreadyExists(word);
  if(yes){
    long idx = h[key].existsAt(word);
    cout << "Key \"" << word << "\" exists at (" << key << ", " << idx << ")." << endl;
  }
  else{
    cout << "Key \"" <<	word <<	"\" does not exist." << endl;
  }
}


/*int main(int argc, char *argv[]){
  Hash h1(argc,argv);
  return 0;
  }*/


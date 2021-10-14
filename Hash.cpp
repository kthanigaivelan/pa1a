#include <string>
#include <iostream> 
#include <fstream>
#include <vector> 
#include  "Hash.h"
#include <math.h> 

#include "Hashbucket.h"

using namespace std; 

  Hash::Hash(int argc, char *argv[]){
    string line;
    ifstream fileRead;
    fileRead.open(argv[1]);
    getline(fileRead, line);
    string pString = line;
    getline(fileRead, line);
    string CString = line;
    fileRead.close();
    this->p = stoll(pString);
    //this->p = 11;
    this->C = stoll(CString);
    
    //count for size 
    size = 0; 
    fileRead.open(argv[2]);
    while ( getline(fileRead,line) ){
      size++; 
    }
    fileRead.close(); 

    table = new Hashbucket[p]();
    
    //first pass
    
    fileRead.open(argv[2]);
    while ( getline(fileRead,line) ){
      int val = hornerVal(line);
      int key = val % p;

    
      table[key].increment();
    }
    fileRead.close();

    
    //second pass
    
    fileRead.open(argv[2]);
    while(getline(fileRead,line)){
      int val = hornerVal(line);
      int key = val % p;
      bool alreadyExists = false;
      if(table[key].getSize() > 0){
	int arrSize = table[key].getSize();
	string * arr = table[key].getWords();
	for(int i = 0; i < arrSize; i++){
	  if(arr[i].compare(line) == 0){
	    alreadyExists = true;
	  }
	}
	
      }
      if(alreadyExists){
	table[key].decrement();
      }
      else{
	table[key].addElement(line);
      }
    }
    
  }

int Hash::hornerVal(string x){
   long long key = 0;
   long long temp = 0;
    for(int i = x.length()-1; i >= 0; i--){
      temp += x[i];
      temp *= C;
      temp %= p; 
    }
    return (int)temp;
}

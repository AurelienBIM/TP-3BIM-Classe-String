#include "string.h"

//getters

inline size_t string::size() const {
	return size_;
}

inline size_t string::length() const{
  return size_;  
}

inline size_t string::capacity() const {
	return capacity_;
}

inline size_t string::max_size() const{
  return MAX_SIZE;
}

//setters

inline void string::reserve(size_t cap){
  if(cap>MAX_SIZE){ 
    capacity_ = MAX_SIZE;
  }
  else if(cap>capacity_){ 
    capacity_ = cap;
  }
}

// Constructeurs

string::string (){
	size_ = 0;
	capacity_ = 0;
	chaine = nullptr;
}

string::string (const string& s){
	size_ = s.size();
	capacity_ = s.capacity();
	chaine = new char[capacity_+1];
	char* tmp = s.c_str();
	for (unsigned int i = 0 ; i<(size_+1) ; i++){
		chaine[i] = tmp[i];
	}
}

string::string (const char* ch){
  char c = ch[0];
  unsigned int longueur = 0;
  while(c != '\0'){
    longueur ++;
    c = ch[longueur];
  }
  if (longueur > MAX_SIZE){
    longueur = MAX_SIZE;
    std::cout << "Erreur : Chaine trop longue"  << std::endl;
  }
  size_ = longueur;
  capacity_ = longueur;
  chaine = new char[longueur + 1];
  for(unsigned int i = 0 ; i < longueur ; i++){
    chaine[i] = ch[i];
  }
  chaine[longueur] = '\0';
}

//destructeur

string::~string(){
	delete [] chaine;
}

//methodes

void string::clear (void){
	chaine[0] = '\0';
	size_ = 0;
}

void string::resize (size_t n, char c){
  if(n > MAX_SIZE){
    n = MAX_SIZE;
    std::cout << "Erreur : Chaine trop longue"  << std::endl;
  }
  if(n > size_){
    char* tmp = new char[n+1];
    for(unsigned int i = 0 ; i < size_ ; i++){
      tmp[i] = chaine[i];
    }
    delete[] chaine;
    for(unsigned int i = size_ ; i < n ; i++){
      tmp[i] = c;
    }
    tmp[n] = '\0';
    size_ = n;
    capacity_ = n;
    chaine = tmp;    
  }
  else{
    chaine[n] = '\0';
    size_ = n;
  }
}

void string::resize (size_t n){
  resize(n,'\0');
}

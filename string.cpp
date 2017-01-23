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

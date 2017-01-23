#include "string.h"

// Constructeurs

string::string (){
	size_ = 0;
	capacity_ = 0;
	chaine = nullptr;
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
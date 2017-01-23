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

bool string::empty(void) const{
	bool tmp;
	if (size()==0){
	  tmp=true;
	}
	else { 
		tmp=false; 
	}
	return tmp;
}

//Operations
 
string& string::operator= (char c){
  if(capacity_ < 1){
    delete[] chaine;
    chaine = new char[2];
    capacity_ = 1;
    size_ = 1;
  }
  chaine[0] = c;
  chaine[1] = '\0';
  return *this;
} 
 
string& string::operator= (const string& s){
	size_ = s.size();
	capacity_ = s.capacity();
	delete [] chaine;
	chaine = new char[capacity_+1];
	char* tmp = s.c_str();
	for (unsigned int i= 0 ; i<size_+1 ; i++){
		chaine[i] = tmp[i];
	}
	return *this;
}

string& string::operator= (const char* s){
	
  if(chaine != nullptr){
    delete [] chaine;
  }
  size_ = string(s).length();
  if(size_ > 0){
    chaine = new char [size_ + 1];
    for (size_t i = 0 ; i<=size_+1 ; i++){
      chaine[i] = s[i];
    }
  }
  else{
    chaine = nullptr;
  }
  return *this;
}

string operator+ (const string& s1, const string& s2){
	unsigned int l1 = s1.size();
	unsigned int l2 = s2.size();
	unsigned int l = l1 + l2;
	if (l > s1.MAX_SIZE){
		l = s1.MAX_SIZE;
    	std::cout << "Erreur : Chaine trop longue"  << std::endl;
	}
	char* somme = new char[l+1];
	char* chaine1 = s1.c_str();
	char* chaine2 = s2.c_str();
	for (unsigned int i = 0 ; i<l1 ; i++){
		somme[i] = chaine1[i];
	}
	for (unsigned int i = l1 ; i<l ; i++){
		somme[i] = chaine2[i-l1];
	}
	somme[l] = '\0';
	return string(somme);
}


string operator+ (const string& s1, char c){
  char* chaine1 = s1.c_str();
  unsigned int l1 = s1.size();
  unsigned int l = l1 + 1;
  if (l > s1.MAX_SIZE){
    l = s1.MAX_SIZE;
    std::cout << "Erreur : Chaine trop longue"  << std::endl;
  }
  char* somme = new char[l+1];
  for (unsigned int i =0; i<l1; i++){
    somme[i]=chaine1[i];
  }
  somme[l1]=c;
  somme[l] = '\0';
  return string(somme);
}
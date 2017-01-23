#ifndef STRING_H__
#define STRING_H__

#include <cstddef>
#include <iostream>

class string{

 	protected :
 //attributs
  size_t capacity_;
  size_t size_;
  char* chaine;
  static const size_t MAX_SIZE = 100;

	public :
//constructeurs
  string (void);
  string(const string& s);
  string (const char* ch);

//destructeur
  ~string(void);
  
//getters
  inline size_t length(void) const;
  inline size_t size(void) const; 
  inline char* c_str(void) const;
  inline size_t capacity(void) const;
  inline size_t max_size(void) const;

//setters
  inline void reserve (size_t cap);

//methodes
  void clear (void);
  void resize(size_t n,char c);
  void resize(size_t n);
  bool empty(void) const;

//Operations
	string& operator= (const string& s);  
};

inline char* string::c_str() const {
	return chaine;
}
  
#endif //STRING_H__

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
  static const size_t MAX_SIZE = 500;

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
	string& operator= (char c);
	string& operator= (const string& s);
	string& operator= (const char* s);
	friend string operator+ (const string& s1, const string& s2);
  	friend string operator+ (const string&& s1, const char* c);
  	friend string operator+ (const string& s1, char c); 
};

inline char* string::c_str() const {
	return chaine;
}
  
#endif //STRING_H__

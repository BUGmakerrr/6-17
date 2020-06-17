#include<iostream>
#include<assert.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
//支持增删查改的string类
class string{
public:
	string(const char* str = ""){
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	~string(){
		delete[] _str;
		_size = _capacity = 0;
	}
	size_t size()const{
		return _size;
	}
	size_t capacity() const{
		return _capacity;
	}
	const char& operator[](size_t i) const{
		assert(i < _size);
		return _str[i];
	}
	const char* c_str(){
		return _str;
	}


private:
	char* _str;
	size_t _capacity;
	size_t _size;
};
ostream& operator<< (ostream& out, const string& s){
	for (size_t i = 0; i < s.size(); ++i){
		cout << s[i];
	}
	return out;
}

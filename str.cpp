// Ofir Shtrosberg, 207828641
#include "str.h"
//constructor
Str::Str() {
    m_str = new char[5];
    strcpy(m_str, "none");
}
//constructor
Str::Str(const Str &other) {
    m_str = new char[strlen(other.getStr()) + 1];
    strcpy(m_str, other.getStr());
}
//constructor
Str::Str(const char *str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}
//destructor
Str::~Str() {
    delete[] m_str;
}

//checks if the current object is equal to the given Str object
bool Str::operator==(const Str &other) const {
    int compareResult = strcmp(m_str, other.getStr());
    if(compareResult == 0){
        return true;
    }
    return false;
}
//checks if the current object is not equal to the given Str object
// return the opposite of the equal operator
bool Str::operator!=(const Str &other) const {
    return !(*this == other);
}
//checks if the current Str object is lexicographically bigger than the given Str object
bool Str::operator>(const Str &other) const {
    int compareResult = strcmp(m_str, other.getStr());
    if(compareResult > 0){
        return true;
    }
    return false;
}
//checks if the given Str object is lexicographically bigger than the current Str object
bool Str::operator<(const Str &other) const {
    int compareResult = strcmp(m_str, other.getStr());
    if(compareResult < 0){
        return true;
    }
    return false;
}
//delete the old m_str and update it to be other's m_str
const Str &Str::operator=(const Str &other) {
    //if they are not pointing to the same string
    if(m_str!= other.getStr()){
        delete[] m_str;
        m_str = new char[strlen(other.getStr()) + 1];
        strcpy(m_str, other.getStr());
    }
    return *this;
}
//using the last = operator by creating Str object from the given string
const Str &Str::operator=(const char *str) {
    Str str1(str);
    *this = str1;
    return *this;
}
//return the m_str[index]
char &Str::operator[](int index) const {
    try {
        return m_str[index];
    }
    catch (...){};
}
//prefix ++
//add 1 to all the chars in the current's m_str
const Str &Str::operator++() {
    for (size_t i = 0; i < strlen(m_str); ++i) {
        m_str[i] += 1;
    }
    return *this;
}
//postfix ++
//add 1 to all the chars in the current's m_str
Str Str::operator++(int) {
    Str tempStr = *this;
    for (size_t i = 0; i < strlen(m_str); ++i) {
        m_str[i] += 1;
    }
    return tempStr;
}
//return the first index of the given char if fount, if not returns -1
int Str::operator()(char ch) const {
    for (size_t i = 0; i < strlen(m_str); ++i) {
        if(m_str[i]==ch){
            return i;
        }
    }
    return -1;
}
//concatenates between current's m_str and other's m_str
Str Str::operator+(const Str &other) const {
    Str concatStings = new char[strlen(m_str)+ strlen(other.getStr())+1];
    for (size_t i = 0; i < strlen(m_str); ++i) {
        concatStings[i] = m_str[i];
    }
    for (size_t i = 0; i < strlen(other.getStr()); ++i) {
        concatStings[strlen(m_str)+i] = other[i];
    }
    concatStings[strlen(m_str)+ strlen(other.getStr())] = '\0';
    return concatStings;
}
//concatenates between current's m_str and other's m_str.
//update current's m_str to be the concatenation
const Str &Str::operator+=(const Str &other) {
    Str stringConcat = *this+other;
    *this = stringConcat;
    return *this;
}

//returns the len of current's m_str
Str::operator int() const {
    return strlen(m_str);
}

//concatenates between str and other's m_str
Str operator+(const char *str, const Str &other) {
    Str concatStings = new char[strlen(str)+ strlen(other.getStr())+1];
    for (size_t i = 0; i < strlen(str); ++i) {
        concatStings[i] = str[i];
    }
    for (size_t i = 0; i < strlen(other.getStr()); ++i) {
        concatStings[strlen(str)+i] = other[i];
    }
    concatStings[strlen(str)+ strlen(other.getStr())] = '\0';
    return concatStings;
}
//concatenates the given Str num times
Str operator*(int num, const Str &other) {
    Str concatStings = new char[num*strlen(other.getStr())+1];
    for (size_t j = 0; j < (size_t)num; ++j) {
        for (size_t i = 0; i < strlen(other.getStr()); ++i) {
            concatStings[j*strlen(other.getStr())+i] = other[i];
        }
    }
    concatStings[num*strlen(other.getStr())] = '\0';
    return concatStings;
}


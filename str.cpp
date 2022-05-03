// Ofir Shtrosberg, 207828641
#include "str.h"

//constructor
Str::Str() {
    m_str = nullptr;
    *this = "none";
}

//constructor
Str::Str(const Str &other) {
    m_str = nullptr;
    *this = other;
}

//constructor
Str::Str(const char *str) {
    m_str = nullptr;
    *this = str;
}

//destructor
Str::~Str() {
    delete[] m_str;
}

//checks if the current object is equal to the given Str object
bool Str::operator==(const Str &other) const {
    int compareResult = strcmp(m_str, other.getStr());
    if (compareResult == 0) {
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
    if (compareResult > 0) {
        return true;
    }
    return false;
}

//checks if the given Str object is lexicographically bigger than the current Str object
bool Str::operator<(const Str &other) const {
    int compareResult = strcmp(m_str, other.getStr());
    if (compareResult < 0) {
        return true;
    }
    return false;
}

//delete the old m_str and update it to be other's m_str
const Str &Str::operator=(const Str &other) {
    //if they are not pointing to the same string
    if (this != &other) {
        *this = other.getStr(); //will use the next operator
    }
    return *this;
}

//using the last = operator by creating Str object from the given string
const Str &Str::operator=(const char *str) {
    if (str != m_str) {
        delete[] m_str;
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }
    return *this;
}

//return the m_str[index]
char &Str::operator[](int index) const {
    try {
        return m_str[index];
    }
    catch (...) {}
}

//prefix ++
//add 1 to all the chars in the current's m_str
const Str &Str::operator++() {
    int size = (int)strlen(m_str);
    for (int i = 0; i < size; ++i) {
        m_str[i] += 1;
    }
    return *this;
}

//postfix ++
//add 1 to all the chars in the current's m_str
Str Str::operator++(int) {
    int size = (int)strlen(m_str);
    Str tempStr = *this;
    for (int i = 0; i < size; ++i) {
        m_str[i] += 1;
    }
    return tempStr;
}

//return the first index of the given char if fount, if not returns -1
int Str::operator()(char ch) const {
    int size = (int)strlen(m_str);
    for (int i = 0; i < size; ++i) {
        if (m_str[i] == ch) {
            return (int)i;
        }
    }
    return -1;
}

//concatenates between current's m_str and other's m_str
Str Str::operator+(const Str &other) const {
    int size = (int)strlen(m_str);
    int otherSize = (int)strlen(other.getStr());
    Str concatStings = new char[size + otherSize + 1];
    for (int i = 0; i < size; ++i) {
        concatStings[i] = m_str[i];
    }
    for (int i = 0; i < otherSize; ++i) {
        concatStings[size + i] = other[i];
    }
    concatStings[size + otherSize] = '\0';
    return concatStings;
}

//concatenates between current's m_str and other's m_str.
//update current's m_str to be the concatenation
const Str &Str::operator+=(const Str &other) {
    Str stringConcat = *this + other;
    *this = stringConcat;
    return *this;
}

//returns the len of current's m_str
Str::operator int() const {
    return strlen(m_str);
}

//concatenates between str and other's m_str
Str operator+(const char *str, const Str &other) {
    int size = (int)strlen(str);
    int otherSize = (int)strlen(other.getStr());
    Str concatStings = new char[size + otherSize + 1];
    for (int i = 0; i < size; ++i) {
        concatStings[i] = str[i];
    }
    for (int i = 0; i < otherSize; ++i) {
        concatStings[size + i] = other[i];
    }
    concatStings[size+otherSize] = '\0';
    return concatStings;
}

//concatenates the given Str num times
Str operator*(int num, const Str &other) {
    int otherSize = (int)strlen(other.getStr());
    Str concatStings = new char[num * otherSize + 1];
    for (int j = 0; j < num; ++j) {
        for (int i = 0; i <otherSize; ++i) {
            concatStings[j * otherSize + i] = other[i];
        }
    }
    concatStings[num * otherSize] = '\0';
    return concatStings;
}
// Ofir Shtrosberg, 207828641
#include "str.h"
#include "iostream"

//constructor
Str::Str() {
    m_str = strdup("none");
}

//constructor
Str::Str(const Str &other) {
    m_str = nullptr;
    *this = other;
}

//constructor
Str::Str(const char *str) {
    m_str = strdup(str);
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
        if (m_str != nullptr) {
            delete[] m_str;
        }
        m_str = strdup(other.getStr());
    }
    return *this;
}

//delete the old m_str and update it to be the given str
const Str &Str::operator=(const char *str) {
    if (&m_str != &str) {
        if (m_str != nullptr) {
            delete[] m_str;
        }
        m_str = strdup(str);
    }
    return *this;
}

//return the m_str[index]
char &Str::operator[](int index) const {
    if (index >= (int) strlen(m_str) || index < 0) {
        cout << "error" << endl;
        exit(0);
    }
    return m_str[index];
}

//prefix ++
//add 1 to all the chars in the current's m_str
const Str &Str::operator++() {
    int size = (int) strlen(m_str);
    for (int i = 0; i < size; ++i) {
        m_str[i] += 1;
    }
    return *this;
}

//postfix ++
//add 1 to all the chars in the current's m_str
Str Str::operator++(int) {
    int size = (int) strlen(m_str);
    Str tempStr = *this;
    for (int i = 0; i < size; ++i) {
        m_str[i] += 1;
    }
    return tempStr;
}

//return the first index of the given char if fount, if not returns -1
int Str::operator()(char ch) const {
    int size = (int) strlen(m_str);
    for (int i = 0; i < size; ++i) {
        if (m_str[i] == ch) {
            return (int) i;
        }
    }
    return -1;
}

//concatenates between current's m_str and other's m_str
Str Str::operator+(const Str &other) const {
    int size = (int) strlen(m_str);
    int otherSize = (int) strlen(other.getStr());
    char *concatStings = new char[size + otherSize];
    strcpy(concatStings, m_str);
    strcat(concatStings, other.getStr());
    Str strConcat(concatStings);
    return strConcat;
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
    Str str1(str);
    return (str1 + other);
}

//concatenates the given Str num times
Str operator*(int num, const Str &other) {
    int otherSize = (int) strlen(other.getStr());
    char *concatStings = new char[num * otherSize];
    strcpy(concatStings, other.getStr());
    for (int j = 1; j < num; ++j) {
        strcat(concatStings, other.getStr());
    }
    Str str1(concatStings);
    return str1;
}
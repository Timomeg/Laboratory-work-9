#include "String.hpp"
// ok
String::String(){
    size = 0;
    capacity = 0;
    Data = new char [size];
}
//ok
String::String(const String& copy){
    size = copy.size;
    capacity = copy.capacity;
    Data = new char [size];
    std::strncpy(Data, copy.Data, size);
}
// ok
String::String(const char* data){
    size = strlen(data);
    capacity = 2 * size;
    Data = new char [size];
    strncpy(Data, data, size);
}
// ok
String::~String(){
    delete[] Data;
}
// ok
String& String::operator=(const String& rhs){
    size = rhs.size;
    capacity = rhs.capacity;
    std::strncpy(Data, rhs.Data, size);
    return *this;
}
// ok
size_t String::Capacity() const{
    return capacity;
}
// ok
size_t String::Size() const{
    return size;
}
// ok
String& String::operator+=(const String& rhs){
    capacity *= 2;
    std::strncpy(Data+size, rhs.Data, size);
    size += rhs.size;
    return *this;
}
// ok
String& String::operator*=(unsigned int m){
    capacity *= 2*m;
    char* copy = new char [size];
    std::strncpy(copy, Data, size);

    delete[] Data;
    Data = new char [capacity];
    for (size_t i{}; i < m; i++){
        std::strncpy(Data+i*size, copy, size);
    }
    size *= m;
    return *this;
}
// ok
bool String::operator==(const String& rhs) const{
    for (size_t i{}; i < size; i++){
        if (Data[i] != rhs.Data[i]){
            return false;
        }
    }
    return true;
}
// ok
bool String::operator<(const String& rhs) const{
    if (size < rhs.size){
        return true;
    }
    else if (size > rhs.size){
        return false;
    }
    else{
        for (size_t i{}; i < size; i++){
            if (Data[i] < rhs.Data[i]){
                return true;
            }
            if (Data[i] > rhs.Data[i]){
                return false;
            }
        }
    }
    return false;
}
// ok
int32_t String::Find(const String& substr) const{
    int32_t index{-1};
    size_t flag{};
    for (size_t i{}; i < size; i++){
        if(substr[0] == Data[i]){
            flag += 1;
            index = i;
        } 
        else if(substr[flag] == Data[i]){
            flag += 1;
        }
        else{
            flag = 0;
            index = -1;
        }
        if (substr.size == flag){
            return index;
        }
    }
    return index;
}
// ok
void String::Replace(char oldSymbol, char newSymbol){
    for (size_t i{}; i < size; i++){
        if (Data[i] == oldSymbol){
            Data[i] = newSymbol;
        }
    }
}
// ok
bool String::Empty() const{
    if (size != 0){
        return false;
    }
    return true;
}
// ok
char String::operator[](size_t index) const{
    return Data[index];
}
char& String::operator[](size_t index){
    return Data[index];
}
// ok
void String::RTrim(char symbol){
    size_t i = size - 1 ;
    while (Data[i] == symbol){
        memmove(&Data[i], &Data[i+1], size - i);
        i--;
    }
}
// ok
void String::LTrim(char symbol){
    size_t i = 0;
    while (Data[0] == symbol){
        memmove(&Data[0], &Data[1], size - i);
        i++;
    }
}

void String::swap(String& oth){

}
// ok
std::ostream& operator<<(std::ostream& stream, const String& str){
    stream << str.Data;
    return stream;
}
// ok
String operator+(const String& a, const String& b){
    String c = a;
    c += b;
    return c;
}
// ok
String operator*(const String& a, unsigned int b){
    String c = a;
    c *= b;
    return c;
}
// ok
bool operator!=(const String& a, const String& b){
    if (a.Size() != b.Size()){
        return true;
    }
    else{
        for (size_t i{}; i < a.Size(); i++){
            if (a[i] != b[i]){
                return true;
            }
        }
    }
    return false;
}

// ok
bool operator>(const String& a, const String& b){
    if (a.Size() > b.Size()){
        return true;
    }
    else if (a.Size() < b.Size()){
        return false;
    }
    else{
        for (size_t i{}; i < a.Size(); i++){
            if (a[i] < b[i]){
                return true;
            }
            if (a[i] > b[i]){
                return false;
            }
        }
    }
    return false;
}

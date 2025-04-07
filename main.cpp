#include "String.hpp"
#include "String.cpp"
int main(){
    String str1{"4123"};
    String str12{"432"};
    str1.swap(str12);
    std::cout << str1<< '\t'<< str12 << std::endl;
    return 0;
}
 
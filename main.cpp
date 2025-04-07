#include "String.hpp"
#include "String.cpp"
int main(){
    String str1{"3121427479124712"};
    String str12{"317"};
    String a = str1;
    std::cout << a.Find("79") << std::endl;
    return 0;
}
 
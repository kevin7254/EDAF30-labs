#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


template <typename T>
std::string toString(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename T>
T string_cast(const std::string& s)
{
    std::stringstream ss(s);
    T t;
    ss >> t;
    return t;
}
int main ()
{
    std::cout << toString(1) << std::endl;
    std::cout << toString(1.0) << std::endl;
    std::cout << toString("test") << std::endl;
    std::cout << toString(true) << std::endl;
    std::cout << toString('a') << std::endl;

    int i = string_cast<int>("1");
    return 0;
}
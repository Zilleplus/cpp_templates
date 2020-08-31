#include"accum1.hpp"
#include<iostream>

int main()
{
    // print average value
    int num[]{1,2,3,4,5};
    std::cout << "the average value of the integer value is "
        << accum(num,num+5) /5
        << std::endl;

    // create array of character values
    char name[] = "template";
    int length = sizeof(name) - 1;

    // (try to) print the average value
    std::cout << "the average value of the character is \""
        << name << "\" is "
        << accum(name, name+length)/ length
        << std::endl;
}

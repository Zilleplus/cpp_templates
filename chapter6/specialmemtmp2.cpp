#include<iostream>
#include<string>

class Person{
    private: 
        std::string name;
    public:
        template<typename STR>
        explicit Person(STR&& n) : name(std::forward<STR>(n)){
            std::cout << "TMPL-CONSTR"<< name << "'\n";
        }

        // copy and move constructor:
        Person(Person const& p) : name(p.name){
            std::cout << "COPY-CONSTR Person'" << name << "'\n";
        }

        Person(Person&& p) : name(std::move(p.name)){
            std::cout << "MOVE-CONSTR Person'" << name << "'\n";
        }
};

int main(){
    std::string s = "sname";
    Person p1(s); // copying str-constr
    Person p2("tmp"); // call's move string-constr
    //Person p3(p1); // doesn't call the copy ctor.
    // -> The template has higher priority over the copy ctor.
    Person p4(std::move(p1)); // call's move
}

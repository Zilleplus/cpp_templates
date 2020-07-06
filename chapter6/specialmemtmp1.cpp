#include<iostream>
#include<string>

class Person{
    private: 
        std::string name;
    public:
        // constructor for passed intial name:
        explicit Person(std::string const& n) : name(n){
            std::cout << "copying string-CONSTR for '"<< name << "'\n";
        }

        explicit Person(std::string&& n) : name(std::move(n)){
                std::cout << "moving string-CONSTR for '" << name << "\n";
        }

        // copy and move constructor:
        Person(Person const& p) : name(p.name){
            std::cout << "COPY-CONSTR Person'" << name << "'\n";
        }

        Person(Person const&& p) : name(std::move(p.name)){
            std::cout << "MOVE-CONSTR Person'" << name << "'\n";
        }
};

int main(){
    std::string s = "sname";
    Person p1(s); // copying str-constr
    Person p2("tmp"); // call's move string-constr
    Person p3(p1); // calls copy-constr
    Person p4(std::move(p1)); // call's move
}

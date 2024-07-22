/*
both class and struct are used to create user-defined data types.

key differences:
class:  members are private by default.
        used for active objects with private data and member functions to maniuplate 
        the data, encapsulating objects and behavior.

struct: members are public by default.
        used for passive objects with public data and no or minimal member functions
        (similar to plain old data (POD) types)
*/

// struct example:
#include <iostream>
#include <string>

// define a struct
struct Person_struct {
    std::string name_s;
    int age_s;

    // constructor
    Person_struct(std::string n, int a) : name_s(n), age_s(a) {}

    // member fucntion
    void introduce() const {
        std::cout << "Hi, I'm "<< name_s << " and I'm "<<age_s<< " years old."<<std::endl;
    }
};

int main() {
    // create a person struct
    Person_struct person_struct("Alice", 30);

    // access public members directly
    std::cout<<person_struct.name_s<<" is "<<person_struct.age_s<<" years old."<<std::endl;

    // call the member function
    person_struct.introduce();
    return 0;
}
 
/*
the members name_s and age_s are public by default, so they can be accessed directly
outside the struct. 

**struct is good for simple data structures whith public access.**
*/ 

/*
//_____________________________________________________________________________
// class example:

//define a class
class Person{
private:
    std::string name;
    int age;

public:
    // constructor
    Person(std::string n, int a) : name(n) , age(a) {}

    // public member function to access private data
    void introduce() const {
        std::cout<<"Hi, I'm "<<name<<" and I'm "<<age<<" years old."<<std::endl;
    }

    // public getter for name
    std::string getName() const {
        return name;
    }

    // public getter for age
    int getAge() const {
        return age;
    }
};

int main() {
    // create a Person object
    Person person("Bod", 25);

    // access private members via public methods
    std::cout<<person.getName()<<" is "<<person.getAge()<<" years old."<<std::endl;

    // call the member function
    person.introduce();
    return 0;
}
*/
/*
the members name and age are private by default, so they cannot be accessed directly
outside of the class. public member functions intoduce, getName, getAge are provided 
to access and manipulate the data.
this enforces encapsulation.

**class is good for more complex objects that require encapsulation and member functions 
to operate on the data.**
*/



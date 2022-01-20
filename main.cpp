#include <iostream>

using namespace std;

/*
 * class Person - stores and prints a person's name
 * class Spy inherited from class Person has
 * a function to add an alias
 */

// class Person
class Person {
public:
    Person(const char *name = "nobody");
    virtual ~Person() = default;
    virtual void identity() const;
    virtual void interrogate();
private:
    std::string name;
};

Person::Person(const char *name) {
    this->name = name;
}

// identity() prints the name of the person
void Person::identity() const {
    cout << "My name is " << this->name << endl;
}

// interrogate() does nothing (empty body) in class Person
void Person::interrogate() { }

/*
 * constructor Spy has 3 parameters
 * name of the spy, alias of the spy, and resistance (spy’s resistance to interrogation)
 * every time interrogate() is called resistance is decremented by 1
 * when resistance > 0 --> identity() prints alias
 * when resistance < 1 --> identity() prints both real name & alias
 */
class Spy: public Person {
public:
    Spy(const char *name, const char *alias, int res): Person(name) {
        this->alias = alias;
        this->res = res;
    }
    void identity() const override;
    void interrogate() override;
    void set_identity(const char *alias);

private:
    string alias;
    int res;
};

void Spy::identity() const {
    if (this->res <= 0) {
        Person::identity();
    }
    cout << "My alias is: " << this->alias << endl;
}

void Spy::interrogate() {
    this->res -= 1;
}

void Spy::set_identity(const char *alias) {
    this->alias = alias;
}

int main(int argc, char** argv) {
    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);

    cout << endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << endl;
        spy.interrogate();
        spy.identity();
    }
    spy.set_identity("Bill Munny");
    spy.identity();

    cout << endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        cout << "Who are you?" << endl;
        spy2.interrogate();
        spy2.identity();
    }

    return 0;
}








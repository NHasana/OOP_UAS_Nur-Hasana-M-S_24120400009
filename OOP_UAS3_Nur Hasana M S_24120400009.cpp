// OOP_UAS3_Nama_NIM.cpp
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Person {
protected:
    string firstName, lastName;
public:
    Person(string fn, string ln) : firstName(fn), lastName(ln) {}
    virtual void info() = 0;
    string getFullName() { return firstName + " " + lastName; }
};

class Player : public Person {
public:
    Player(string fn, string ln) : Person(fn, ln) {}
    void info() override { cout << "Player: " << getFullName() << endl; }
};

class Coach : public Person {
public:
    Coach(string fn, string ln) : Person(fn, ln) {}
    void info() override { cout << "Coach: " << getFullName() << endl; }
};

class Staff : public Person {
public:
    Staff(string fn, string ln) : Person(fn, ln) {}
    void info() override { cout << "Staff: " << getFullName() << endl; }
};

class PersonFactory {
public:
    virtual unique_ptr<Person> createPerson(string fn, string ln) = 0;
};

class PlayerFactory : public PersonFactory {
public:
    unique_ptr<Person> createPerson(string fn, string ln) override {
        return unique_ptr<Person>(new Player(fn, ln));
    }
};

class CoachFactory : public PersonFactory {
public:
    unique_ptr<Person> createPerson(string fn, string ln) override {
        return unique_ptr<Person>(new Coach(fn, ln));
    }
};

class StaffFactory : public PersonFactory {
public:
    unique_ptr<Person> createPerson(string fn, string ln) override {
        return unique_ptr<Person>(new Staff(fn, ln));
    }
};

int main() {
    PlayerFactory pf;
    CoachFactory cf;
    StaffFactory sf;

    auto player = pf.createPerson("Budi", "Santoso");
    auto coach = cf.createPerson("Andi", "Setiawan");
    auto staff = sf.createPerson("Sari", "Putri");

    vector<unique_ptr<Person>> team;
    team.push_back(move(player));
    team.push_back(move(coach));
    team.push_back(move(staff));

    for (auto& person : team) {
        person->info();
    }

    return 0;
}

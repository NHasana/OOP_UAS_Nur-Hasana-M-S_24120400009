#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class dasar: Person
class Person {
protected:
    string personId;
    string firstName;
    string lastName;
    string dateOfBirth;
    string nationality;
public:
    Person(string pid, string fn, string ln, string dob, string nat)
        : personId(pid), firstName(fn), lastName(ln), dateOfBirth(dob), nationality(nat) {}
    string getFullName() { return firstName + " " + lastName; }
};

// Player turunan dari Person
class Player : public Person {
private:
    int jerseyNumber;
    double marketValue;
    string position;
    string status; // e.g., Active, Injured
public:
    Player(string pid, string fn, string ln, string dob, string nat,
           int jersey, double mv, string pos, string st)
        : Person(pid, fn, ln, dob, nat), jerseyNumber(jersey),
          marketValue(mv), position(pos), status(st) {}
    void playMatch() {
        cout << getFullName() << " is playing a match!" << endl;
    }
};

// Coach turunan dari Person
class Coach : public Person {
private:
    string licenseLevel;
    string role; // Head Coach, Assistant Coach
public:
    Coach(string pid, string fn, string ln, string dob, string nat,
          string license, string r)
        : Person(pid, fn, ln, dob, nat), licenseLevel(license), role(r) {}
    void conductTraining() {
        cout << getFullName() << " is conducting training as " << role << "." << endl;
    }
};

// Club
class Club {
private:
    string clubId;
    string name;
    string foundingDate;
    double budget;
    string league;
public:
    Club(string cid, string n, string fd, double b, string lg)
        : clubId(cid), name(n), foundingDate(fd), budget(b), league(lg) {}
    string getName() { return name; }
};

// Team
class Team {
private:
    string teamId;
    string name;
    string division; // U-23
    string league;
    string clubId;
    vector<Player> players;
    vector<Coach> coaches;
public:
    Team(string tid, string n, string div, string lg, string cid)
        : teamId(tid), name(n), division(div), league(lg), clubId(cid) {}

    void addPlayer(const Player& p) { players.push_back(p); }
    void addCoach(const Coach& c) { coaches.push_back(c); }

    void showTeam() {
        cout << "Team: " << name << " (" << division << ")" << endl;
        cout << "Players: " << players.size() << endl;
        for (auto& p : players) cout << "- " << p.getFullName() << endl;
        cout << "Coaches: " << coaches.size() << endl;
        for (auto& c : coaches) cout << "- " << c.getFullName() << endl;
    }
};

int main() {
    // Buat Club
    Club club("C001", "FC Cakrawala", "2020-01-01", 5000000, "Liga 3");

    // Buat Team U-23
    Team team("T001", "FC Cakrawala Muda", "U-23", "Liga 3", "C001");

    // Buat Head Coach & Assistant Coach
    Coach headCoach("CO001", "Andi", "Setiawan", "1980-03-15", "Indonesia", "A", "Head Coach");
    Coach assistantCoach("CO002", "Budi", "Pratama", "1985-08-20", "Indonesia", "B", "Assistant Coach");

    team.addCoach(headCoach);
    team.addCoach(assistantCoach);

    // Buat 15 Player
    for (int i = 1; i <= 15; ++i) {
        Player p("P00" + to_string(i), "Player" + to_string(i), "Last", "2002-01-01", "Indonesia",
                 i, 10000, "Midfielder", "Active");
        team.addPlayer(p);
    }

    // Tampilkan data team
    cout << "Club: " << club.getName() << endl;
    team.showTeam();

    return 0;
}

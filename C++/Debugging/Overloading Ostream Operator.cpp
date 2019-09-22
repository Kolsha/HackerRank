#include <iostream>

using namespace std;

class Person {
public:
    Person(const string &first_name, const string &last_name) : first_name_(first_name), last_name_(last_name) {}

    const string &get_first_name() const {
        return first_name_;
    }

    const string &get_last_name() const {
        return last_name_;
    }

private:
    string first_name_;
    string last_name_;
};
/*
 * Difficulty Medium
 * Max Score 20
 * https://www.hackerrank.com/challenges/overloading-ostream-operator/
 */
// Enter your code here.

ostream &operator<<(ostream &os, const Person &p) {
    os << "first_name=" << p.get_first_name();
    os << ",last_name=" << p.get_last_name();
    return os;
}

int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Person {
public:
    Person(): Person("None", 0, 0) {}; //delegating constructor to avoid code duplication
    Person(string name, int age, int luck) : name(name), age(age), luck(luck) {} //list initialization
    const string &getName() const {
        return name;
    }

    const int &getAge() const {
        return age;
    }

    const int &getLuck() const {
        return luck;
    }

    void setName(const string &name) {
        Person::name = name;
    }

    void setAge(int age) {
        Person::age = age;
    }

    void setLuck(int luck) {
        Person::luck = luck;
    }

    virtual ~Person() {
    }


private:
    string name;
    int age;
    int luck;
};
int randomizer(int number){
    return rand() % number;
}
Person theLuckiest (vector<Person> &persons){
    Person temp;
    for (const Person& p: persons) {
        if (p.getLuck() > temp.getLuck()){
            temp = p;
        }
    }
    return temp;
}
Person leastLucky (vector<Person> &persons){
    Person temp = persons[0];
    for (const Person& p: persons) {
        if (p.getLuck() < temp.getLuck()){
            temp = p;
        }
    }
    return temp;
}
void changeLuck(Person &p1, Person &p2){
    int temp;
    temp = p1.getLuck();
    p1.setLuck(p2.getLuck());
    p2.setLuck(temp);

    cout << p1.getName() << "'s luck has changed to " << p1.getLuck() << endl;
    cout << p2.getName() << "'s luck has changed to " << p2.getLuck() << endl;
}
void output(const Person &p1, const Person &p2){
    if (p1.getLuck() > p2.getLuck()){
        cout << "The luckiest – " << p1.getName() << ", luck: " << p1.getLuck() << endl;
        cout << "The least lucky – " << p2.getName() << ", luck: " << p2.getLuck() << endl;
    }
    else {
        cout << "The luckiest – " << p2.getName() << ", luck: " << p2.getLuck() << endl;
        cout << "The least lucky – " << p1.getName() << ", luck: " << p1.getLuck() << endl;
    }
}
int main() {
    srand(time(NULL));

    vector<Person> persons;

    persons.push_back(Person("Dora", 18, randomizer(11)));
    persons.push_back(Person("Dana", 19, randomizer(11)));
    persons.push_back(Person("Nura", 22, randomizer(11)));
    persons.push_back(Person("JnD", 30, randomizer(11)));
    persons.push_back(Person("Assel", 46, randomizer(11)));

    for (const Person& p: persons){
        cout << p.getName() << "'s luck is: " << p.getLuck() << endl;
    }

    output(theLuckiest(persons), leastLucky(persons));

    changeLuck(persons[randomizer(5)], persons[randomizer(5)]);

    Person *dyno = new Person("Rano", 9, randomizer(11)); //allocating memory in heap

    changeLuck(*dyno, persons[randomizer(5)]);

    delete dyno; //it is needed to deallocate memory, if it's not deleted, memory address will be taken and another object won't be created to this address


    //PART 2
    int arr[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            arr[i][j] = randomizer(10);
        }
    }

    vector<int> numbers;
    numbers.push_back(randomizer(10));
    numbers.push_back(randomizer(10));

    cout << &numbers[0] << "    " << &numbers[1];



    return 0;
}

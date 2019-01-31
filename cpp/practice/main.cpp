#include <iostream>

using namespace std;

class Animal{
private:
    int food;
    int weight;

public:
    void setAnimal(int _food, int _weight){
        food = _food;
        weight = _weight;
    }

    void increaseFood(int inc){
        food += inc;
        weight += (inc / 3);
    }

    void viewStat(){
        cout << "이 동물의 food : " << food << endl;
        cout << "이 동물의 weight : " << weight << endl;
    }
};

int main() {
    Animal animal;
    animal.setAnimal(100, 50);
    animal.increaseFood(30);

    animal.viewStat();
    return 0;
}
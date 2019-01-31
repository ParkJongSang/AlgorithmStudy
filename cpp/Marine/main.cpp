#include <iostream>
#include <string.h>

using namespace std;

class Marine{
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, char* marine_name);
    ~Marine();
    int attack();
    void beAttacked(int damage_earn);
    void move(int x, int y);

    void showStatus();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, char *marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::~Marine(){
    cout << name << " 의 소멸자 호출 ! " << endl;
    if(name != NULL){
        delete[] name;
    }
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() {
    return damage;
}

void Marine::beAttacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;
}

void Marine::showStatus() {
    cout << " *** Marine : "<<name<< " *** " << endl;
    cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;
}
int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    //malloc과 동일하게 new도 동적으로 메모리를 할당한다.
    //new는 메모리를 할당함과 동시에 생성자를 호출한다.
    marines[1] = new Marine(3, 5, "Marine 1");

    marines[0] -> showStatus();
    marines[1] -> showStatus();

    cout << endl << "마린1 이 마린2 를 공격!" << endl;

    marines[0] -> beAttacked(marines[1]->attack());

    marines[0] -> showStatus();
    marines[1] -> showStatus();

    delete marines[0];
    delete marines[1];
    //동적으로 할당한 메모리는 반드시 해제해줘야 한다.
    return 0;
}
#include<iostream>
using namespace std;

class Hero{
    
    public:
        int health;
        string name;
        char level;

    // Paramerterized Constructor
    Hero(int health){
        cout<< "this-> "<< this << endl;
        this->health = health;
    }
    Hero(){
        cout<< "Constructor" << endl;
    }

    int getHealth(){
        return health;
    }

    void setHealth(int h){
        health = h;
    }
};

int main(){

    // Dynamical allocation (in Heap)
    Hero *ha = new Hero(10);
     
    // (*ha).setHealth(10);
    // cout<< (*ha).getHealth() << endl;
    // // or
    // ha->setHealth(11);
    // cout<< ha->getHealth() << endl;

    // Static allocation
    // Hero simran;
    // simran.setHealth(10);
    // simran.name = "Mahek";
    // simran.level = 'A';
    // cout<< simran.name << endl;
    // cout<< simran.level<<endl;
    // cout<< simran.getHealth() << endl;


    // cout<< sizeof(simran) << endl;

    return 0;
}
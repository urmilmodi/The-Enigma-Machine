#include <iostream>
#include <cctype>

#include "../include/RotorController.hpp"
#include "../include/Rotor.hpp"
#include "../include/Reflector.hpp"

using namespace std;

int main() {
    
    
    
    RotorController a(Reflectors(1), Rotors(0), Rotors(1), Rotors(2));

    Letter st = a.run(A);

    RotorController b(Reflectors(1), Rotors(0), Rotors(1), Rotors(2));

    cout << (b.run(st)) << endl; // does not decode info as it should

    //cout << st << endl;
/*
    cout << a.run(R) << endl;
    cout << a.run(R) << endl;
*/
    
    return 0;
}
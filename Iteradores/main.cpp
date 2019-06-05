#include <iostream>
#include "ArithProgression.h"
#include "GeomProgression.h"

using namespace std;

int main() {

    ArithProgression a{1,17,3};
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;

    GeomProgression g{1,20,4};
    for (auto it = g.begin(); it != g.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;

    return 0;
}
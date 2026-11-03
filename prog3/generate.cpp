// Cris Padilla Castillo
// CECS 325-02
// Prog 3

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Please enter 3 parameters:" << endl;
        cout << "   Parameter 1: total count of numbers you want." << endl;
        cout << "   Parameter 2: min value." << endl;
        cout << "   Parameter 3: max value." << endl;
        cout << "Example: % generate 1000000 -100000 100000" << endl;
        return 1;
    }

    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]:" << argv[i] << endl;
    }

    int count = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    ofstream fout("numbers.dat");

    srand(time(0));
    for (int i = 0; i < count; i++) {
        int num = rand() % (max - min + 1) + min;
        fout << num << endl;
    }

    fout.close();
    return 0;
}

// Cris Padilla Castillo
// CECS 325-02
// Prog 3

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source including inappropriate AI use.
// I did not share this program with anyone. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bubble(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: mysort <input file> <output file>" << endl;
        cout << "Example: % mysort numbers.dat mysort.out" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    vector<int> numbers;
    int num;
    while (numbers.size() < 1000000 && fin >> num) {
        numbers.push_back(num);
    }
    fin.close();

    cout << "Starting Vector bubble sort with " << numbers.size() << " items" << endl;
    bubble(numbers);
    cout << "Ending bubble sort" << endl;

    ofstream fout(argv[2]);
    for (int i = 0; i < numbers.size(); i++) {
        fout << numbers[i] << endl;
    }
    fout.close();

    return 0;
}

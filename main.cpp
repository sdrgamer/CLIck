#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

double total=120;

int main(int argc,char *argv[]) {
    if (argc==1) {
        cerr << "Error: no arg" << endl;
        return 1;
    }

    if (!strcmp(argv[1],"-b")||!strcmp(argv[1],"--bpm")) {
        if (argc==2) {
            cerr << "Error: no BPM" << endl;
            return 1;
        }
        try {
            total = 60.0/stod(argv[2]);
        }
        catch (...){
            cerr << "Error: wrong BPM" << endl;
            return 1;
        }
    }

    if (!strcmp(argv[1],"-h")||!strcmp(argv[1],"--help")) {
        cout << "CLIck\n\n-h|--help for this text to show up\n-b|--bpm for set the bpm number" << endl;
        return 1;
    }

    if (!strcmp(argv[1],"-v")||!strcmp(argv[1],"--version")) {
        cout << "CLIck Version 0.0.1" << endl;
        return 1;
    }

    while (1) {

        cout << "tick" << endl;

        this_thread::sleep_for(chrono::duration<double>(total));
    }
}
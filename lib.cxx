
#include <iostream>
#include "lib.h"

using namespace std;


string InputProgram() {
    string Program;
    string str;
    for (;;) {
        getline(std::cin, str);
        if (ContainsByte(str, '#')) {
            str = str.substr(0, IndexOfByte(str, '#') + 1);
            Program.append(str);
            break;
        }
        Program.append(str);
    }
    return Program;
}

bool ContainsByte(const string &str, char c) {
    return str.find(c) != string::npos;
}

unsigned long long IndexOfByte(const string &str, char c) {
    if (ContainsByte(str, c)) {
        return str.find(c);
    }
    return -1;
}
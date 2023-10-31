#define MAIN_CXX
#ifdef MAIN_CXX
#include <iostream>
#include <string>
#include "lib.h"

using namespace std;

string prog, token;
char ch;
int syn, p, m;

void scanner() {
    token = "";
    ch = prog[p];
    p++;
    m = 0;

    while (ch == ' ') {
        ch = prog[p];
        p++;
    }
    if (islower(ch) || isupper(ch) || ch == '_') {
        while (islower(ch) || isupper(ch) || ch == '_' || isdigit(ch)) {
            token += ch;
            ch = prog[p];
            p++;
        }
        p--;
        syn = 3;
    } else if (ch == '{') {
        syn = 1;
        token = ch;
    } else if (ch == '}') {
        syn = 2;
        token = ch;
    } else if (isdigit(ch)) {
        syn = 3;
        token = ch;
    } else if (ch == '#') {
        syn = 0;
        token = ch;
    } else {
        syn = -1;
    }
    if (syn != 0) {
        if (syn == -1) {
            cout << "Error" << endl;
        } else {
            printf("(%d, %s)\n", syn, token.c_str());
        }
    }
}

int main() {
    cout << "请输入源程序，以#结束:" << endl;
    //    {id}
    prog = InputProgram();
    cout << "词法分析的结果是:" << endl;
    p = 0;
    for (scanner(); syn != 0;) {
        scanner();
    }
    return 0;
}
#endif
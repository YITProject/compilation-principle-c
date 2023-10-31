//#define MAIN_CXX
#ifdef MAIN_CXX

#include <iostream>
#include <string>
#include "lib.h"

using namespace std;

string prog, token, str;
char ch;
int syn, p, m, sum, kk = 1;

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
    } else if (ch == '#') {
        syn = 0;
        token = ch;
    } else {
        cout << ch << endl;
        syn = -1;
    }
    if (syn != 0) {
        if (syn == -1) {
            cout << "Error" << endl;
        } else {
            str += to_string(syn);
            printf("(%d, %s)\n", syn, token.c_str());
        }
    }
}


void S() {
    if (syn == 1) {
        scanner();
        S();
        if (syn == 2) {
            scanner();
        } else {
            cout << "此处该出现'}'" << endl;
            kk = 0;
        }
    } else if (syn == 3) {
        scanner();
    } else {
        cout << "此处该出现一个标识符或者'{'" << endl;
        kk = 0;
    }
}

int main() {
    cout << "请输入源程序，以#结束:" << endl;
    //    {id} | id
    prog = InputProgram();
    cout << prog << "词法分析的结果是:" << endl;
    p = 0;
    scanner();
    S();
    if (!syn && kk) {
        cout << "语法分析成功" << endl << "分析的结果是" << endl;
        cout << str;
    } else {
        cout << "语法分析不成功" << endl;
    }
    return 0;
}

#endif
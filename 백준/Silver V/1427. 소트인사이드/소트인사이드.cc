#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int CtoI(const char c){
    return c - 48;
}

int compt(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}

int main(){
    int inside[10];
    int i;
    string str;
    cin >> str;
    for(i = 0; str[i] > 0; i++) {
        inside[i] = CtoI(str[i]);
    }
    qsort(inside, i, sizeof(int), compt);
    for (int j = 0 ; j < i; j++)
        cout << inside[j];
    cout << endl;
    return 0;
}

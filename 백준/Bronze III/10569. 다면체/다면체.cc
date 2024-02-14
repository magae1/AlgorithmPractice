//
//  Polyhedron.cpp
//  BaekJun_practice
//
//  Created by caurental on 2022/01/14.
//

#include <iostream>
using namespace std;

int main(void)
{
    int TableCase;
    int V, E;
    cin >> TableCase;
    int * M = new int[TableCase];
    for (int i = 0; i < TableCase; i++)
    {
        cin >> V >> E;
        M[i] = 2 - V + E;
    }
    for (int i = 0; i < TableCase; i++)
        cout << M[i] << endl;
    return 0;
}

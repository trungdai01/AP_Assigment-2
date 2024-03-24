#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
    int aVar = 10;
    int& refAvar = aVar;

    cout << "refAvar " << refAvar << endl;
    aVar++; 
    cout << "refAvar " << refAvar << endl;

    return 0;
}
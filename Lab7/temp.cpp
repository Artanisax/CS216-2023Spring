#include <iostream>
#include <random>
using namespace std;

const int N = 5e5;

int main(){
    srand(time(NULL));
    FILE *p = fopen("x.in","w");
    fprintf(p, "1");
    for (int i = 1; i < N-1; i++)
        fprintf(p, "?");
    fprintf(p, "0");
    return 0;
}
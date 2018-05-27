#include <iostream>
using namespace std;
long gcd(long, long);
int main(){
    long a = 110;
    long b = 11;
    cout << gcd(a, b) << endl;
    return 0;
}
long gcd(long a, long b){
    while(b != 0){
        long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


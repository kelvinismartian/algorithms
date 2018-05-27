#include <iostream>
using namespace std;
void printDigit(int n){
    cout << n;
}
void printOut(int n){
    if(n >= 10)
        printOut(n / 10);
    printDigit(n % 10);
}
int main(){
    int yj = 12345;
    printOut(yj);
    cout << endl;
    return 0;
}

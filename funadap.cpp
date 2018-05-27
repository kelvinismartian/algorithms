#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
using namespace std;
void Show(double);
const int LIM = 5;
int main(){
    double arr1[LIM] = {36, 39, 42, 45, 48};
    double arr2[LIM] = {25, 27, 29, 31, 33};
    vector<double> qr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "qr8:\t";
    for_each(qr8.begin(), qr8.end(), Show);
    cout << endl;
    cout << "m8:\t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;
    
    vector<double> sum(LIM);
    transform(qr8.begin(), qr8.end(), m8.begin(), sum.begin(),
            plus<double> ());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);
    transform(qr8.begin(), qr8.end(), prod.begin(), 
            bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;

    return 0;
}
void Show(double s){
    cout.width(6);
    cout << s << ' ';
}

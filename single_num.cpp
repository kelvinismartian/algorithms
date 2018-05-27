#include <iostream>
using namespace std;
void single_num(int arr[], int n){
    int outcome = 0;
    for(int i = 0; i < n; ++i){
        outcome ^= arr[i];
    }
    cout << outcome << endl;
}

int get_first_one(int n){
    return n & ~(n - 1);
}
void double_num(int* arr, int len){
    int aXORb = 0;
    int a = 0;
    int b = 0;
    for(int i = 0; i < len; ++i){
        aXORb ^= arr[i];
    }
    int firstOne = get_first_one(aXORb);
    for(int i = 0; i < len; ++i){
        if(arr[i] & firstOne)
            a ^= arr[i];
    }
    b = aXORb ^ a;
    cout << a << "\t" << b << endl;
}

void triple_num(int* arr, int len){
    int a = 0;
    int b = 0;
    int c = 0;
    int aXORbXORc = 0;
    for(int i = 0; i < len; ++i){
        aXORbXORc ^= arr[i];
    }
    int firstOne = 0;
    for(int i = 0; i < len; ++i){
        firstOne ^= get_first_one(aXORbXORc ^ arr[i]);
    }
    for(int i= 0; i < len; ++i){
        if(get_first_one(aXORbXORc ^ arr[i]) == firstOne)
            c ^= arr[i];
    }
    int aXORb = aXORbXORc ^ c;
    int secondOne = get_first_one(aXORb);
    for (int i = 0; i < len; ++i){
        if(secondOne & arr[i] && arr[i] != c)
            a ^= arr[i];
    }
    b = aXORb ^ a;
    cout << c << "\t" << b << "\t" << a << endl;
}

int main(){
    int arr[] = {1, 2, 3, 1, 2, 3, 4, 4, 5, 5, 7};
    single_num(arr, sizeof(arr) / sizeof(arr[0]));
    int arr_[] = {1, 2, 3, 1, 2, 3, 4, 4, 5, 5, 7, 8};
    double_num(arr_, sizeof(arr_) / sizeof(arr_[0]));
    int arr__[] = {1, 2, 3, 1, 2, 3, 4, 4, 5, 5, 7, 8, 9};
    triple_num(arr__, sizeof(arr__) / sizeof(arr__[0]));
    return 0;
}


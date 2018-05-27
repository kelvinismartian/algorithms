#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void str_qpl(char* str, int n = 0){
    if(str[n] == '\0')
        cout << str << endl;
    else{
        for(int i = n; str[i] != '\0'; i++){
            swap(str[n], str[i]);
            str_qpl(str, n + 1);
            swap(str[n], str[i]);
        }
    }
}
void str_qpl_STL(string& str){
    sort(str.begin(), str.end());
    cout << str << endl;
    while(next_permutation(str.begin(), str.end()))
        cout << str << endl;
}
int main(){
    char lt[4] = "let";
    string yj(lt);
    str_qpl(lt);
    cout << endl;
    str_qpl_STL(yj);
    return 0;
}


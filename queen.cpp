#include <iostream>
using namespace std;

int total = 0;
int n = 8;
int* temp = new int(n);

bool is_ok(int row){
    for(int j = 0; j != row; j++){
        if(temp[row] == temp[j] || row - temp[row] == j - temp[j] || 
                row + temp[row] == j + temp[j])
            return false;
    }
    return true;
}

void queue(int row){
    if(row == n){
        total++;
    }
    else{
        for(int col = 0; col != n; col++){
            temp[row] = col;
            if(is_ok(row))
                queue(row + 1);
        }
    }
}
int main(){
    queue(0);
    cout << total << endl;
    return 0;
}


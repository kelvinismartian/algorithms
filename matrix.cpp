#include <iostream>
#include <vector>
using namespace std;
template <typename Object>
class Matrix{
    private:
        vector<vector<Object>> array;
    public:
        Matrix(int rows, int cols): array(rows){
            for(int i = 0; i < rows; i++)
                array[i].resize(cols);
        }
        const vector<Object>& operator[](int row)const{
            return array[row];
        }
        vector<Object>& operator[](int row){
            return array[row];
        }
        int numrows()const{
            return array.size();
        }
        int numcols()const{
            return numrows()? array[0].size(): 0;
        }
};
int main(){
    vector<int> lt = {1, 2, 3};
    Matrix<int> yj(3, 3);
    for(int i = 0; i < yj.numrows(); i++)
        yj[i] = lt;
    for(int i = 0;i < yj.numrows(); i++){
        for(int j = 0; j < yj.numcols(); j++)
            cout << yj[i][j] << " ";
        cout << endl;
    }
    return 0;
}

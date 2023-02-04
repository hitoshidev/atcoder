#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> mat(H, vector<int>(W, 0));
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            cin >> mat[i][j];
        }
    }
    vector<int> sum_cols(W);
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            sum_cols[j] += mat[i][j];
        }
    }
    vector<int> res_rows(W, 0);
    for(int i=0; i<H; ++i) {
        int sum_row = accumulate(mat[i].begin(), mat[i].end(), 0);
        for(int j=0; j<W; ++j) {
            res_rows[j] = sum_row + sum_cols[j] - mat[i][j];
        }
        vector<int>::iterator itr;
        for(itr = res_rows.begin(); itr != res_rows.end() -1; ++itr) {
            cout << *itr << " "; 
        }
        cout << *itr << endl;
    }
}

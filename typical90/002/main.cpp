#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int main()
{
    size_t N;
    cin >> N;
    if(N % 2 != 0) {
        cout << endl;
        return 0;
    }
    int score = 0;
    int max = (1U<<N);
    for(int bit=0; bit < max; ++bit) {
        string S="";
        score = 0;
        for(int i = (1U<<(N-1)); i > 0; i >>= 1) {
            if(bit & i) {
                --score;
                S += ")";
            }
            else {
                ++score;
                S += "(";
            }
            if(score<0) {
                break;
            }
        }
        if(score == 0) {
            cout << S << endl;
        }
    }
    return 0;
}

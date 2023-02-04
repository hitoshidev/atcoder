#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    size_t n, l, k;
    cin >> n >> l >> k;
    vector<size_t> a(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto check = [&](int64_t sub) {
        size_t prev_len = 0;
        size_t cur = 0;
        size_t num_parts = 0;
        for(; cur != n; ++cur) {
            if(a[cur] - prev_len >= sub) {
                ++num_parts;
                prev_len = a[cur]; 
            }
        }
        if(l - prev_len >= sub) {
            ++num_parts;
        }
        return num_parts >= (k + 1);
    };
    int64_t left = -1, right = l + 1;
    while(right - left > 1) {
        int64_t mid = (left + right) / 2;
        if(check(mid)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left << endl;
}

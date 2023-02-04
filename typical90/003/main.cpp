#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

using Graph = vector<vector<int>>;

vector<int> dfs(const Graph& g, int v) {
    int N = g.size();
    vector<int> dists(N, -1);
    dists[v] = 0;
    stack<int> st;
    st.push(v);
    while(!st.empty()) {
        int cur = st.top();
        st.pop();
        for(int next : g[cur]) {
            if(dists[next] == -1) {
                dists[next] = dists[cur] + 1;
                st.push(next);
            }
        }
    }
    return dists;
}

int main()
{
    int N;
    cin >> N;
    Graph g(N);
    for(int i=0; i<N-1; ++i) {
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    //てきとーな頂点から一番遠い頂点を見つける 
    auto dists = dfs(g, 0);
    auto max_itr = max_element(dists.begin(), dists.end());
    int max_v = max_itr - dists.begin();
    // 一番遠い頂点から一番遠い頂点をみつける
    auto mdists = dfs(g, max_v);
    max_itr = max_element(mdists.begin(), mdists.end());
    cout << (*max_itr)+1 << endl;

}

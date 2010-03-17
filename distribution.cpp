#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
    int n,m;
    scanf("%d%d", &n, &m);
    int ss[10000];
    int as[10000];
    for(int i = 0; i < n; i++) {
        scanf("%d%d", ss+i, as+i);
        ss[i]--;
    }
    vector<priority_queue<pair<int,int> > > qs(n);
    for(int i = n-1; i>= 1; i--) {
        qs[ss[i]].push(make_pair(
                    qs[i].empty()?as[i]:as[i]+qs[i].top().first,i));
    }
    int sum = 0;
    for(int j = 0; j < m; j++) {
        int i = 0;
        vector<int> stk;
        while(true) {
            stk.push_back(i);
            if(qs[i].empty())break;
            int ii = qs[i].top().second; qs[i].pop();
            i = ii;
        }
        while(!stk.empty()) {
            i = stk.back(); stk.pop_back();
            sum += as[i]; as[i] = 0;
            if(i != 0) {
        qs[ss[i]].push(make_pair(
                    qs[i].empty()?as[i]:as[i]+qs[i].top().first,i));
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}


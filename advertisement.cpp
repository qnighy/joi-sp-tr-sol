#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int tim;
vector<int> num,low;
vector<int> stk;
vector<bool> inS;

vector<vector<int> > graph;

vector<vector<int> > scc;
vector<int> sccmap;

void search(int i) {
    num[i] = low[i] = tim++;
    stk.push_back(i);inS[i]=true;
    for(int j = 0; j < (int)graph[i].size(); j++) {
        int jj=graph[i][j];
        if(num[jj]==0) {
            search(jj);
            low[i] = min(low[i], low[jj]);
        } else if(inS[jj]) {
            low[i] = min(low[i], num[jj]);
        }
    }
    if(num[i] == low[i]) {
        scc.push_back(vector<int>());
        while(true) {
            int x = stk.back();stk.pop_back();inS[x]=false;
            scc.back().push_back(x);
            sccmap[x] = scc.size()-1;
            if(x==i)break;
        }
    }
}
void makescc() {
    num.assign(n,0);
    low.assign(n,0);
    inS.assign(n,false);
    sccmap.assign(n,-1);
    tim = 1;
    for(int i = 0; i < n; i++) {
        if(num[i]==0) search(i);
    }
}

int main(int argc, char **argv)
{
    scanf("%d%d", &n, &m);
    graph.resize(n);
    for(int i = 0; i < m; i++) {
        int a,b;
        scanf("%d%d", &a, &b);a--;b--;
        graph[a].push_back(b);
    }
    makescc();
    vector<bool> flag(scc.size(),true);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            if(sccmap[graph[i][j]]==sccmap[i])continue;
            flag[sccmap[graph[i][j]]]=false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < (int)scc.size(); i++) {
        if(flag[i])cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}


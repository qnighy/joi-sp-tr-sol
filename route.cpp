#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int src;
    int dest;
    int wei;
    bool flag;
    Edge() : src(-1),dest(-1),wei(-1),flag(false){}
    Edge(int w, int x, int y): src(w),dest(x), wei(y),flag(false){}
};

int xs[100], ys[100];
int main(int argc, char **argv)
{
    int n,m;
    freopen("route.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", xs+i, ys+i);
    }
    vector<vector<Edge> > edges(n);
    for(int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);a--;b--;
        edges[a].push_back(Edge(a,b,c));
        edges[b].push_back(Edge(b,a,c));
    }
    priority_queue<pair<int,Edge*> > q;
    for(int i = 0; i < edges[0].size(); i++) {
        q.push(make_pair(-edges[0][i].wei,&edges[0][i]));
    }
    while(!q.empty()) {
        int dist = q.top().first;
        Edge& e = *q.top().second;
        q.pop();
        if(e.flag)continue;
        e.flag=true;
        if(e.dest==1) {
            printf("%d\n",-dist);
            return 0;
        }
        for(int i = 0; i < edges[e.dest].size(); i++) {
            Edge& e2 = edges[e.dest][i];
            if((xs[e.src]-xs[e.dest])*(xs[e2.dest]-xs[e2.src])
                +(ys[e.src]-ys[e.dest])*(ys[e2.dest]-ys[e2.src])<=0) {
                q.push(make_pair(dist-e2.wei,&e2));
                //printf("%d-%d-%d\n",e.dest
            }
        }
    }
    printf("-1\n");
    return 0;
}



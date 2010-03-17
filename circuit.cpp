#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int n,k;
    int as[10000];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", as+i);
        as[i]--;
    }
    bool flag[10000] = {0};
    vector<vector<int> > loops[10010];
    for(int i = 0; i < n; i++) {
        if(flag[i])continue;
        int j = i;
        vector<int> loop;
        do {
            loop.push_back(j);
            flag[j] = true;
            j = as[j];
        } while( j != i );
        loops[loop.size()].push_back(loop);
    }
    int nas[10000];
    for(int i = 1; i <= n; i++) {
        int num = i;
        int knum = k;
        int req = 1;
        for(int j = 2; num>1; j++) {
            if(num%j==0) {
                while(num%j==0)num/=j;
                while(knum%j==0){knum/=j;req*=j;}
            }
        }
        for(int useloop = 0; useloop < loops[i].size(); useloop+=req) {
            if(loops[i].size()-useloop<req) {
                printf("0\n");return 0;
            }
            vector<int> nloop(i*req);
            for(int j = 0; j < i*req; j++) {
                int k = j*knum%(req*i);
                nloop[j%(req*i)]=
                    loops[i][useloop+k%req][k/req];
            }
            for(int i = 0; i < nloop.size(); i++) {
                nas[nloop[i]] = nloop[(i+1)%nloop.size()];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d\n", nas[i]+1);
    }
    return 0;
}


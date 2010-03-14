#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;

int xs[1000];
int ys[1000];
double evtx[4000];
double evty[4000];
int evts[4000];
int evtssize;
// 0: in inside
// 1: leave inside
// 2: in outside
// 3: leave outside
int evtcmp(const int *e0, const int *e1) {
    double e0x = evtx[*e0];
    double e0y = evty[*e0];
    double e1x = evtx[*e1];
    double e1y = evty[*e1];
    int e0z = e0y>0 ? e0x>0 ? 0 : 1 : e0x>0 ? 3 : 2;
    int e1z = e1y>0 ? e1x>0 ? 0 : 1 : e1x>0 ? 3 : 2;
    if(e0z!=e1z)return e0z<e1z ? -1 : 1;
    if(e0x*e1y!=e1x*e0y)return e0x*e1y>e1x*e0y ? -1 : 1;
    return 0;
}
int main(int argc, char **argv)
{
    int n;
    double d;
    scanf("%d %lf\n", &n, &d);
    for(int i = 0; i < n; i++) {
        scanf("%d %d\n", xs+i, ys+i);
    }
    double d2 = d*2;
    double d2sq = d2*d2;
    int maxcnt = 1;
    for(int i = 0; i < n; i++) {
        evtssize=0;
        for(int j = 0; j < n; j++) {
            if(i==j)continue;
            double cosa = xs[j]-xs[i];
            double sina = ys[j]-ys[i];
            evtx[j*4+0] = cosa;
            evty[j*4+0] = sina;
            evts[evtssize++] = j*4+0;
            evtx[j*4+1] = -cosa;
            evty[j*4+1] = -sina;
            evts[evtssize++] = j*4+1;
            double cosbsq = cosa*cosa+sina*sina-d2sq;
            if(cosbsq<0)continue;
            double cosb = sqrt(cosbsq);
            //double sinb = d2;
            #define sinb d2
            evtx[j*4+2] = -cosa*cosb-sina*sinb;
            evty[j*4+2] = cosa*sinb-sina*cosb;
            evts[evtssize++] = j*4+2;
            evtx[j*4+3] = cosa*cosb-sina*sinb;
            evty[j*4+3] = cosa*sinb+sina*cosb;
            evts[evtssize++] = j*4+3;
        }
        qsort(evts,evtssize,sizeof(*evts), (int(*)(const void*,const void*))evtcmp);
        //for(int j = 0; j < evtssize; j++) {
        //    printf("%d: %d,%d\n", i, evts[j]/4, evts[j]%4);
        //}
        int sel[1000] = {0};
        int cnt = 0;
        for(int j = 0; j < evtssize; j++) {
            if(evts[j]&1) {
                if(sel[evts[j]/4]>0) {
                    sel[evts[j]/4]--;
                    cnt--;
                }
            } else {
                sel[evts[j]/4]++;
                cnt++;
            }
        }
        //int maxcnt = 0;
        for(int j = 0; j < evtssize; j++) {
            maxcnt = max(maxcnt, cnt+1);
            if(evts[j]&1) {
                cnt--;
            } else {
                cnt++;
            }
        }
        //printf("%d: %d\n", i, maxcnt);
    }
    printf("%d\n", maxcnt);
    return 0;
}


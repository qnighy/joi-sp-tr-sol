#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

struct Matrix {
    int m00, m01, m02;
    int m10, m11, m12;
    pair<int,int> trans(const pair<int,int>& pt) {
        return make_pair(m00*pt.first+m01*pt.second+m02,
                m10*pt.first+m11*pt.second+m12);
    }
    Matrix() {}
    Matrix(int m00,int m01,int m02,int m10,int m11,int m12)
        :m00(m00),m01(m01),m02(m02),m10(m10),m11(m11),m12(m12) {}
};
int w,h,kk;
char tbl[40][40];
char cpytbl[40][40];
char& exttbl(const pair<int,int>& pt) {
    static char dummy;
    dummy = 0;
    if(pt.first>=0 && pt.second>=0 && pt.first<w && pt.second<h)
        return cpytbl[pt.first][pt.second];
    return dummy;
}

int main(int argc, char **args) {
    scanf("%d%d%d", &w, &h, &kk);
    vector<pair<int,int> > pts;
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            scanf("%hhd", &tbl[x][y]);
            if(tbl[x][y])pts.push_back(make_pair(x,y));
        }
    }

    vector<Matrix> mats;
    for(int xx=0;xx<2*w;xx++)mats.push_back(Matrix(-1,0,xx,0,1,0));
    for(int yy=0;yy<2*h;yy++)mats.push_back(Matrix(1,0,0,0,-1,yy));
    for(int ss=0;ss<w+h;ss++)mats.push_back(Matrix(0,-1,ss,-1,0,ss));
    for(int dd=-h;dd<w;dd++)mats.push_back(Matrix(0,1,dd,1,0,-dd));
    deque<pair<int,int> > lst;
    for(int i = 0; i < (int)mats.size(); i++) {
        for(int j = 0; j < (int)mats.size(); j++) {
            for(int x = 0; x < w; x++) {
                for(int y = 0; y < h; y++) {
                    cpytbl[x][y] = tbl[x][y]*4;
                }
            }
            bool flag = true;
            int redcnt = 0;
            vector<deque<pair<int,int> > > lsts[9];
            for(int k = 0; k < (int)pts.size(); k++) {
                const pair<int,int>& pt = pts[k];
                if(exttbl(pt)!=4)continue;

                lst.clear();
                lst.push_back(pt); exttbl(pt) = 3;

                pair<int,int> p;
                p = mats[i].trans(pt);
                for(int k = 0; exttbl(p)==4; k++) {
                    lst.push_back(p);
                    exttbl(p) = 3;
                    p = mats[k&1 ? i : j].trans(p);
                }
                p = mats[j].trans(pt);
                for(int k = 0; exttbl(p)==4; k++) {
                    lst.push_front(p);
                    exttbl(p) = 3;
                    p = mats[k&1 ? j : i].trans(p);
                }
                int tblflg = 3;
                if(lst.size()>=2 &&
                        mats[i].trans(lst[0])==lst[1] &&
                        mats[j].trans(lst.front())==lst.back()) {
                    //loop
                } else {
                    if(
                        exttbl(mats[j].trans(lst.front()))==0 ||
                        exttbl(mats[j].trans(lst.back()))==0
                            )tblflg&=~1;
                    if(
                        exttbl(mats[i].trans(lst.front()))==0 ||
                        exttbl(mats[i].trans(lst.back()))==0
                            )tblflg&=~2;
                }
                if(tblflg==0){flag=false;break;}
                for(int l = 0; l < lst.size(); l++) {
                    exttbl(lst[l])=tblflg;
                }
                if(tblflg==2)redcnt+=lst.size();
                if(tblflg!=3)continue;
                lsts[lst.size()].push_back(lst);
            }
            if(!flag)continue;
            for(int s = 8; s >= 1; s>>=1) {
                for(int k = 0; k < (int)lsts[s].size(); k++) {
                    int colr = 1;
                    if(kk-redcnt>=lsts[s][k].size()) {
                        colr = 2;
                        redcnt += lsts[s][k].size();
                    }
                    for(int l = 0; l < (int)lsts[s][k].size(); l++) {
                        exttbl(lsts[s][k][l]) = colr;
                    }
                }
            }
            if(redcnt!=kk)continue;
            for(int y = 0; y < h; y++) {
                for(int x = 0; x < w; x++) {
                    printf("%d%c",cpytbl[x][y], " \n"[x+1==w]);
                }
            }
            return 0;
        }
    }
    printf("No Answer...\n");
    return 0;
}


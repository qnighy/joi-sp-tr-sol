#include <stdio.h>
#include <math.h>

int ccw(int x0, int y0, int x1, int y1, int x2, int y2) {
    int cross,dot;
    x1 -= x0; y1 -= y0;
    x2 -= x0; y2 -= y0;
    cross = x1*y2-x2*y1;
    dot = x1*x2+y1*y2;
    if(cross>0) return +1;
    if(cross<0) return -1;
    if(dot<0) return +2;
    if(x1*x1+y1*y1<x2*x2+y2*y2)return -2;
    return 0;
}
int cross(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    return ccw(x0,y0,x1,y1,x2,y2)*ccw(x0,y0,x1,y1,x3,y3)<0 &&
        ccw(x2,y2,x3,y3,x0,y0)*ccw(x2,y2,x3,y3,x1,y1)<0;
}
int crossR(int rx0, int ry0, int rx1, int ry1, int x0, int y0, int x1, int y1) {
    return
        cross(rx0,ry0,rx0,ry1,x0,y0,x1,y1) |
        cross(rx1,ry0,rx1,ry1,x0,y0,x1,y1) |
        cross(rx0,ry0,rx1,ry0,x0,y0,x1,y1) |
        cross(rx0,ry1,rx1,ry1,x0,y0,x1,y1) |
        cross(rx0,ry0,rx1,ry1,x0,y0,x1,y1) |
        cross(rx0,ry1,rx1,ry0,x0,y0,x1,y1);
}

int xs[220];
int ys[220];
double wf[220][220];
int ss[50];
int ts[50];
int us[50];
int vs[50];

int main(int argc, char **argv)
{
    int a,b,c,w,h,i,j,k;
    double len;
    scanf("%d%d%d%d%d", &a, &b, &c, &w, &h);
    for(i = 0; i < a; i++) {
        scanf("%d%d", &xs[i], &ys[i]);
    }
    for(i = 0; i < b; i++) {
        scanf("%d%d%d%d", &ss[i], &ts[i], &us[i], &vs[i]);
        xs[a+c+i*4+0] = xs[a+c+i*4+1] = ss[i];
        xs[a+c+i*4+2] = xs[a+c+i*4+3] = us[i];
        ys[a+c+i*4+0] = ys[a+c+i*4+2] = ts[i];
        ys[a+c+i*4+1] = ys[a+c+i*4+3] = vs[i];
    }
    for(i = 0; i < c; i++) {
        scanf("%d%d", &xs[a+i], &ys[a+i]);
    }
    for(i = 0; i < a+c+b*4; i++) {
        for(j = 0; j < a+c+b*4; j++) {
            wf[i][j]=w*h;
        }
    }
    for(i = 0; i < a+c+b*4; i++) {
        for(j = 0; j < a+c+b*4; j++) {
            int flag = 1;
            wf[i][j]=w*h;
            for(k = 0; k < b; k++) {
                if(crossR(ss[k],ts[k],us[k],vs[k],xs[i],ys[i],xs[j],ys[j])) {
                    flag = 0;
                }
            }
            if(flag) {
                wf[i][j] = hypot(xs[i]-xs[j],ys[i]-ys[j]);
            }
            if(i<a && j<a)wf[i][j]=0;
        }
    }
    for(k = 0; k < a+c+b*4; k++) {
        for(i = 0; i < a+c+b*4; i++) {
            for(j = 0; j < a+c+b*4; j++) {
                if(wf[i][j]>wf[i][k]+wf[k][j]) {
                    wf[i][j]=wf[i][k]+wf[k][j];
                }
            }
        }
    }
    len = 0;
    for(i = 0; i < c; i++) {
        len += wf[0][a+i];
    }
    printf("%0.3f\n",len*2);
    return 0;
}


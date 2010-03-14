#include <stdio.h>


int n,w,h,x,y;
int ranges[1000][4];
int table[100][100];
int graph[1000][1000] = {{0}};
int flag[1000] = {0};
int count = 0;
void search(int i) {
    int j;
    if(flag[i])return;
    flag[i]=1;
    for(j = 0; j < n; j++) {
        if(graph[i][j]) {
            search(j);
        }
    }
    count++;
    printf("%d%c", i+1, " \n"[count==n]);
}
int main(int argc, char **argv)
{
    int i;
    scanf("%d%d%d", &n, &w, &h);
    for(i = 0; i < n; i++) {
        ranges[i][0]=-1;
    }
    for(y = 0; y < h; y++) {
        for(x = 0; x < w; x++) {
            scanf("%d", &i);i--;
            table[y][x]=i;
            if(i==-1)continue;
            if(ranges[i][0]==-1) {
                ranges[i][0]=y;
                ranges[i][1]=x;
                ranges[i][2]=y+1;
                ranges[i][3]=x+1;
            } else {
                if(ranges[i][0]>y)ranges[i][0]=y;
                if(ranges[i][1]>x)ranges[i][1]=x;
                if(ranges[i][2]<y+1)ranges[i][2]=y+1;
                if(ranges[i][3]<x+1)ranges[i][3]=x+1;
            }
        }
    }
    for(i = 0; i < n; i++) {
        for(y = ranges[i][0]; y < ranges[i][2]; y++) {
            for(x = ranges[i][1]; x < ranges[i][3]; x++) {
                if(table[y][x]!=-1) {
                    graph[table[y][x]][i]=1;
                }
            }
        }
    }
    for(i = 0; i < n; i++) {
        search(i);
    }
    return 0;
}


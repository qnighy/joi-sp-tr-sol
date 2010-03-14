#include <stdio.h>
#include <stdlib.h>

struct edge {
    int dir;
    int x,y;
};

int cmpedge(const struct edge *e0, const struct edge *e1) {
    if(e0->x!=e1->x)return e0->x-e1->x;
    if(e0->y!=e1->y)return e0->y-e1->y;
    return e0->dir-e1->dir;
}

struct edge edges[100000];
int edges_size = 0;

const int px[] = {1,0,-1,0};
const int py[] = {0,-1,0,1};

int main(int argc, char **argv)
{
    int dir;
    int x=0, y=0;
    int sum;
    while(1) {
        char ch;
        scanf("%c\n", &ch);
        if(ch=='E') {
            edges[edges_size].x = x++;
            edges[edges_size].y = y;
            edges[edges_size++].dir = 0;
        } else if(ch=='S') {
            edges[edges_size].x = x;
            edges[edges_size].y = y++;
            edges[edges_size++].dir = 1;
        } else if(ch=='W') {
            edges[edges_size].x = --x;
            edges[edges_size].y = y;
            edges[edges_size++].dir = 0;
        } else if(ch=='N') {
            edges[edges_size].x = x;
            edges[edges_size].y = --y;
            edges[edges_size++].dir = 1;
        } else if(ch=='Q') {
            break;
        }
    }
    qsort(edges,edges_size,sizeof(*edges),(int(*)(const void*,const void*))cmpedge);
    x = edges[0].x;
    y = edges[0].y;
    dir = 2;
    sum = 0;
    do {
        struct edge se;
        se.x = x - (dir==2?1:0);
        se.y = y - (dir==1?1:0);
        se.dir = dir%2;
        if(bsearch(&se, edges, edges_size, sizeof(*edges), (int(*)(const void*,const void*))cmpedge)) {
            int nx=x+px[dir];
            int ny=y+py[dir];
            sum += (x+nx)*(y-ny);
            x+=px[dir];
            y+=py[dir];
            dir=(dir+3)%4;
        } else {
            dir=(dir+1)%4;
        }
    }while(x!=edges[0].x || y!=edges[0].y || dir!=2);
    printf("%d\n",sum/2);
    return 0;
}


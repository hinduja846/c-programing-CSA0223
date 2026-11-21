#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { long long comparisons, swaps, shifts; } Stats;
void bubble(int a[], int n, Stats *s) {
    s->comparisons=s->swaps=s->shifts=0;
    for (int end=n-1; end>0; --end) {
        int changed=0;
        for (int j=0; j<end; ++j) {
            s->comparisons++;
            if (a[j]>a[j+1]) {
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                s->swaps++; changed=1;
            }
        }
        if (!changed) break;
    }
}
void selection(int a[], int n, Stats *s) {
    s->comparisons=s->swaps=s->shifts=0;
    for (int i=0; i<n-1; ++i) {
        int min=i;
        for (int j=i+1; j<n; ++j) {
            s->comparisons++;
            if (a[j]<a[min]) min=j;
        }
        if (min!=i) {
            int t=a[i]; a[i]=a[min]; a[min]=t; s->swaps++;
        }
    }
}
void insertion(int a[], int n, Stats *s) {
    s->comparisons=s->swaps=s->shifts=0;
    for (int i=1; i<n; ++i) {
        int key=a[i], j=i-1;
        while (j>=0) {
            s->comparisons++;
            if (a[j]<=key) break;
            a[j+1]=a[j]; s->shifts++; --j;
        }
        a[j+1]=key;
    }
}
void fill(int *a, int n, int mode) {
    for(int i=0;i<n;i++) a[i]=i;
    if(mode==1) { for(int i=n-1;i>0;i-=7) { int t=a[i]; a[i]=a[i-1]; a[i-1]=t; } }
    if(mode==2) { for(int i=0;i<n/2;i++) { int t=a[i]; a[i]=a[n-1-i]; a[n-1-i]=t; } }
    if(mode==3) { srand(123); for(int i=n-1;i>0;i--) { int j=rand()%(i+1),t=a[i];a[i]=a[j];a[j]=t;} }
}
int main(void) {
    const int ns[]={100,1000,10000};
    const char *orders[]={"sorted","nearly_sorted","reverse","random"};
    puts("n,order,algorithm,comparisons,swaps,shifts");
    for(int z=0;z<3;z++) for(int mode=0;mode<4;mode++) {
        int n=ns[z]; int *src=malloc((size_t)n*sizeof(int)), *a=malloc((size_t)n*sizeof(int));
        if(!src||!a) return 1;
        fill(src,n,mode);
        for(int alg=0;alg<3;alg++) {
            memcpy(a,src,(size_t)n*sizeof(int)); Stats st={0};
            if(alg==0) bubble(a,n,&st);
            if(alg==1) selection(a,n,&st);
            if(alg==2) insertion(a,n,&st);
            printf("%d,%s,%s,%lld,%lld,%lld\n",n,orders[mode],
                   alg==0?"bubble":alg==1?"selection":"insertion",
                   st.comparisons,st.swaps,st.shifts);
        }
        free(src);free(a);
    }
    return 0;
}

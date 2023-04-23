#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100005;
struct cpl{
    double r,i;
};
cpl operator + (const cpl &a, const cpl &b){
    return (cpl){a.r+b.r,a.i+b.i};
}
cpl operator - (const cpl &a, const cpl &b){
    return (cpl){a.r-b.r,a.i-b.i};
}
cpl operator * (const cpl &a, const cpl &b){
    return (cpl){a.r*b.r-a.i*b.i,a.i*b.r+a.r*b.i};
}
ostream& operator << (ostream& oss, const cpl &a){
    oss<<'('<<a.r<<' '<<a.i<<')';
    return oss;
}
cpl tmp[MAXN<<2];
void fft(int n, cpl *a, int flg){
    if(n==1) return;
    int i;
    for(i=0;i<n;i++){
        if(i&1)
            tmp[(n>>1)+(i>>1)] = a[i];
        else
            tmp[(i>>1)] = a[i];
    }
    memcpy(a, tmp, n*sizeof(cpl));
    fft(n>>1, a, flg);
    fft(n>>1, &a[n>>1], flg);
    cpl *e = a;
    cpl *d = &a[n>>1];
    cpl wm = flg ? (cpl){cos(2*M_PI/n), sin(2*M_PI/n)}:(cpl){cos(2*M_PI/n), -sin(2*M_PI/n)};
    cpl wk = (cpl){1,0};
    for(int k=0;k<(n>>1);k++){
        tmp[k] = e[k] + wk * d[k];
        tmp[k+(n>>1)] = e[k] - wk * d[k];
        wk = wk * wm;
    }
    memcpy(a, tmp, n*sizeof(cpl));
}

void do_fft(int n, double *a, double *b, double *res){
    int fn = 1;
    while(fn<=(n<<1)) fn <<= 1;
    cpl *p1 = new cpl[fn];
    cpl *p2 = new cpl[fn];
    for(int i=0;i<n;i++){
        p1[i]=(cpl){a[i],0};
        p2[i]=(cpl){b[i],0};
    }
    for(int i=n;i<fn;i++){
        p1[i]=(cpl){0,0};
        p2[i]=(cpl){0,0};
    }
    fft(fn, p1, 1);
    fft(fn, p2, 1);
    for(int i=0;i<fn;i++){
        p1[i] = p1[i]*p2[i];
    }
    delete[] p2;
    fft(fn, p1, 0);
    for(int i=0;i<fn;i++){
        res[i] = p1[i].r / fn;
    }
    delete[] p1;
}
double q[MAXN];
double q2[MAXN];
double h[MAXN];
double ans1[MAXN<<2], ans2[MAXN<<2];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lf",&q[i]);
        q2[n-i-1]=q[i];
        h[i] = i ? 1.0/i/i : 0;
    }
    do_fft(n, q, h, ans1);
    do_fft(n, q2, h, ans2);
    for(int i=0;i<n;i++){
        printf("%0.3lf\n", ans1[i]-ans2[n-i-1]);
    }
    return 0;
}
/*
5
4006373.885184
15375036.435759
1717456.469144
8514941.004912
1410681.345880
*/

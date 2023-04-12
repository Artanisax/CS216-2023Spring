#include<bits/stdc++.h>
using namespace std;

void IO_accel()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 4e5+5;

typedef pair<double,double> pdd;

pdd p[N],tmp[N];

bool cmp_y(pdd a,pdd b){
	return a.second<b.second;
}

double dis(pdd a,pdd b){
	return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

double divide(int l,int r){
	if(l==r) return DBL_MAX;
	if(r-l==1) return dis(p[l],p[r]);
	int mid=l+r>>1,tot=0;
	double d=min(divide(l,mid),divide(mid+1,r));
	for(int i=l;i<=r;i++)
		if(fabs(p[i].first-p[mid].first)<d) tmp[++tot]=p[i];
	sort(tmp+1,tmp+tot+1,cmp_y);
	for(int i=1;i<tot;i++)
		for(int j=i+1;j<=tot&&tmp[j].second-tmp[i].second<d;j++)
			d=min(d,dis(tmp[i],tmp[j]));
	return d;
}

int main(){
	IO_accel();
	int n;
	cin >> n;
	// scanf("%d", &n);
	for(int i = 1;i <= n; i++)
		// scanf("%lf%lf",&p[i].first,&p[i].second);
		cin >> p[i].first >> p[i].second;
	sort(p+1, p+n+1);
	cout << fixed << setprecision(0) << pow(divide(1, n), 2);
	// printf("%.4lf", divide(1,n));
	return 0;
}
//https://algo.codemarshal.org/contests/uits_iupc_19/problems/J
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int _I(){int x; scanf("%d",&x); return x;}
long long _L(){long long x; scanf("%lld",&x); return x;}
long long a,b,c,mod;
const int MatSZ = 5;
const int bit_sz = 10;
long long temMat[MatSZ][MatSZ];
long long V[5][5] = {
        {1,1,0,0,0},
        {0,1,1,0,1},
        {0,0,1,1,0},
        {0,0,0,1,1},
        {0,0,0,0,1},
};
long long I[5][5] = {
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1},
};
long long A[5][5];
long long B[5][5];
long long C[5][5];
long long dr[22];
long long fr[22];
long long n,m;
LL pre_cal[1<<bit_sz][3][5][5];
bool vis[1<<bit_sz];

void mat_cpy(LL P[MatSZ][MatSZ], LL Q[MatSZ][MatSZ]){
        for(int i = 0; i < MatSZ; i++)
                for(int  j = 0; j < MatSZ; j++)
                        P[i][j] = Q[i][j];
}

void mat_mul(LL P[MatSZ][MatSZ], LL Q[MatSZ][MatSZ]){
        for(int i=0; i<MatSZ; i++) {
                for(int j=0; j<MatSZ; j++) {
                        temMat[i][j]=0;
                        for(int k=0; k<MatSZ; k++) temMat[i][j]+=(P[i][k]*Q[k][j])%mod;
                        temMat[i][j]%=mod;
                }
        }
        mat_cpy(P,temMat);
}

void up(int x){
        int v = x*bit_sz;
        for(int i = 0; i < v; i++) mat_mul(A,A);
}

void pow_(LL n){
        if(n == 1) return;
        if(n < (1<<bit_sz) && vis[n]) return;
        pow_(n>>1);
        LL qq = n>>1;
        if(qq < (1<<bit_sz) && vis[qq]) mat_cpy(A,pre_cal[qq][0]);
        mat_mul(A,A);
        if(n&1) mat_mul(A,B);
        mat_cpy(pre_cal[n][0], A);
        vis[n] = 1;
        return;
}

void pre_(){
        int i,v,j;
        v = 1<<bit_sz;
        for(i = v-1; i > 0; i--){
                mat_cpy(A,V);
                pow_(i);
                for(j = 1; j < 3 ; j++){
                        mat_cpy(A,pre_cal[i][0]);
                        up(j);
                        mat_cpy(pre_cal[i][j],A);
                }
        }
}

void _new(){
        mat_cpy(pre_cal[1][0],V);
        mat_cpy(A,V);
        mat_cpy(B,A);
}

int cases;

void lipu_mira(){
        printf("Case %d: ",++cases);
        int i,j;
        n = _L();
        if(n < 5) {
                printf("%lld\n",dr[n]);return;
        }
        long long mm,p,q,r = n-4;
        mat_cpy(C,I);
        for(j = 0; j < 3; j++){
                p = ( (1<<bit_sz) - 1) << (j*bit_sz);
                p = r&p;
                p >>= (j*bit_sz);
                mm = (r >> (bit_sz*j));
                if(p){
                        mat_cpy(A,pre_cal[p][j]);
                        mat_mul(C,A);
                }
        }
        long long ans = n-2+n;
        ans += m;
        ans %= m;
        for(i = 0; i < 5; i++){
                ans += ((fr[i]*C[0][i])%m);
                ans %= m;
        }
        printf("%lld\n",ans);
}

int main(){
        //freopen("in1.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        m = 1000000007LL;
        mod = m;
        fr[0] = 2LL;      dr[1] = 1;
        fr[1] = 6LL;      dr[2] = 2;
        fr[2] = 6LL;
        fr[3] = 4LL;      dr[3] = 4;
        fr[4] = 1LL;      dr[4] = 8;
        _new();
        pre_();
        int t = _I();
        while(t--) lipu_mira();
        return 0;
}

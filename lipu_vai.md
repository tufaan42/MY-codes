/***********prime_fact*********/
int Ans[ RNG ];

for( i = 2 ; i < RNG ; i ++ ) {
        if( Ans[i] ) continue;
        for( j = i ; j < RNG ; j += i ) {
                int x = j;
                while( x%i == 0 ) {
                        x/=i;
                        Ans[j] ++;
                }
        }
}
/***************segmented_sieve***********/
#include <bits/stdc++.h>
using namespace std;

int Prime[100001] , Prime_sz;
bool vis[ 100001 ] ;
void sieve_precal() {
        int i , j , k;
        for( i = 2 ; i < 100001 ; i ++ ) {
                for( j = i+i ; j < 100001 ; j += i ) vis[j] = 1;
        }
        for( i = 2; i < 100001; i ++ ) {
                if( !vis[i] ) Prime[ Prime_sz++ ] = i;
        }
}

int _list[1000007] , list_sz;
bool segsieve_vis[1000007];
void segSieve( int a, int b ) {
        if( a < 2 ) a = 2;
        memset( segsieve_vis , 0 , sizeof( segsieve_vis ) );
        for(int i = 0 ; i < Prime_sz ; i ++ ) {
                long long int x = ( a / Prime[i] ) + ( ( a % Prime[i] ) != 0 );
                x = ( x * Prime[i] );
                if(x == Prime[i]) x += Prime[i];
                for( long long int j = x; j <= b; j += Prime[i] ) segsieve_vis[j-a] = 1;
        }
        for(int i = 0; i < ( b - a + 1 ); i ++ ) {
                if( !segsieve_vis[i] ) _list[list_sz++] = i+a;
        }
}

int main()
{
        sieve_precal();
        int a,b;
        while( scanf("%d %d",&a,&b)==2 ) {

                list_sz = 0;
                segSieve( a , b );
                if( list_sz < 2 ) {
                        printf("There are no adjacent primes.\n");
                        continue;
                }

                int x , y , p , q , mn=b-a+1 , mx=0 , dist ;
                for( int i = 1 ; i < list_sz ; i ++ ) {
                        dist = _list[i] - _list[i-1];
                        if( dist > mx ) {
                                mx = dist;
                                x = _list[i-1] , y = _list[i];
                        }
                        if( dist < mn ) {
                                mn = dist;
                                p = _list[i-1] , q = _list[i];
                        }
                }
                printf("%d,%d are closest, %d,%d are most distant.\n",p,q,x,y);
        }
        return 0;
}

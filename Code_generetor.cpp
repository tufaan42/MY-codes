#include<bits/stdc++.h>
using namespace std;

int main()
{
        //freopen("in.txt","r",stdin);
        freopen("data1.txt","w", stdout);
        srand(time(0));
        puts("1000");
        for(int i = 0; i < 1000; i++){
                int n,x;
                n = (rand()%1001);
                printf("%d",n);
                for(int j = 0; j < 6; j++){
                        printf(" %d",rand()%7);
                }
                putchar(10);
        }
        //double Start = clock();
        //double End = clock();
        //printf("%lf",End-Start);
        return 0;
}

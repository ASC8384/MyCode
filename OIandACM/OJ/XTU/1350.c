#include <stdio.h>
#include <string.h>
#include <math.h>
 
int main()
{
    int t;
    scanf("%d", &t);
     
    while(t--){
        double x;
        scanf("%lf", &x);
        printf("%.3lf\n", sqrt(1.0 - x * x));
    }
    return 0;
}
/**************************************************************
    Problem: 1060
    User: ASC_8384
    Language: C
    Result: 正确
    Time:3 ms
    Memory:1132 kb
****************************************************************/

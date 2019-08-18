#include <stdio.h>

int main(){
	
	int T,n,m,i,j,k,t,c,ans;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n%11) puts("0");
		else {
			n /= 11;
			m = n / 101;
			ans = 1e5;
			for(i=0;i<=m;i++){
				t = n - i*101;
				j = t / 91;
				k = t % 91;
				c = i+j+k;
				if(c < ans) ans = c;				
			}
			printf("%d\n",ans);	
		}
	}
	return 0;
}
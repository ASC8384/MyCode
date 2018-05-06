void insertsort(int a[]){
	for(int i = 2; i <= n; i++){
		int t = a[i];
		int j = i - 1;
		while(t < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

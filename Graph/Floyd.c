for(k = 1; k <= n; k++)
	for(j = 1; j <= n; j++)
		if(k != j)
			for(i = 1; i <= n; i++)
				if(k != i)
					if(i != j)
						if(*(*(dis + i) + j) > *(*(dis + i) + k) + *(*(dis + k) + j))
							*(*(dis + i) + j) = *(*(dis + i) + k) + *(*(dis + k) + j);
//存图于dis[][]

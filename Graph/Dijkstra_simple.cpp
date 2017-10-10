void dijkstra(int s, int t){
//预先 memset(map, 0x7f, sizeof map);
    memset(djk, 0x7ffffff, sizeof djk);
    for(int i = 1; i <= n; i++)
        djk[i] = map[s][i];
    djk[s] = 0;
    use[s] = 1;
    int pos = 0;
    int tmp = 0x7ffffff;
    int cnt = 1;
    while(cnt < n){
        for(int i = 1; i <= n; i++)
            if(!use[i] && djk[i] < tmp){
                pos = i;
                tmp = djk[i];
            }
        if(!pos)
            NULL;
        use[pos] = 1;
        for(int i = 1; i <= n; i++)
            if(djk[i] > djk[pos] + map[pos][i])
                djk[i] = djk[pos] + map[pos][i];
        tmp = 0x7ffffff;
        pos = 0;
        cnt++;
    }
}//djk[t] 答案
//s 进，t 出
//map 邻接矩阵

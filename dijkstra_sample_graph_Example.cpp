#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[vertices+1];
    vector<int> distarr(vertices,INT_MAX);
    int i =0;
    for(i =0;i<edges;i++)
    {
        int a = vec[i][0];
        int b = vec[i][1];
        int wt = vec[i][2];
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    distarr[source]=0;
    
    pq.push(make_pair(0,source));
    
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int curnode = it.first;
            int wt = it.second;
            if(distarr[curnode]>wt+dist)
            {
                distarr[curnode] = wt+dist;
                pq.push(make_pair(wt+dist,curnode));
            }
        }
      //  int j =0;
      /*  for(j=0;j<vertices;j++)
        {
            cout << distarr[j] << "," << endl; 
        }*/
        
    }
    
    return distarr;
}

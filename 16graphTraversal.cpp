#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>>& adj, int x, int y){
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void traversalBFS(vector<vector<int>> adj, int start, vector<int> &ans){
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);

    visited[start] = true;
    int vis;
    while(!q.empty()){
        vis = q.front();
        ans.push_back(vis);
        q.pop();
        for(int i=0; i<adj.size(); i++){
            if(adj[vis][i] == 1 && (!visited[i])){
                q.push(i);
                visited[i]=true;
            }
        }

    }

}

void dfs(int start, vector<vector<int>> adj, vector<int> &ans, vector<bool> &visited){
    visited[start] = true;
    ans.push_back(start);
    for(int i=0; i<adj[start].size(); i++){
        if(adj[start][i] && (!visited[i])){
            dfs(i, adj, ans, visited);
        }
    }
}
void traversalDFS(vector<vector<int>> adj, int start, vector<int> &ans){
    vector<bool> visited(adj.size(), false);
    dfs(start, adj, ans, visited);
}   

int main(){
    int V, E;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the number of Edges : ";
    cin>>E;

    vector<vector<int>> adj(V+1, vector<int>(V+1, 0));

    cout<<"Enter the edges(pairs of vertices from 1 to "<<V<<") : "<<endl;
    for(int i=0; i<E; i++){
        int x, y;
        cout<<"Edge "<<i+1<<" : ";
        cin>>x>>y;
        addEdge(adj, x, y);
    }
    vector<int> ans;
    traversalBFS(adj, 1, ans);
    vector<int> ans1;
    traversalDFS(adj, 1, ans1);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<ans1.size(); i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;


    return  0;
}


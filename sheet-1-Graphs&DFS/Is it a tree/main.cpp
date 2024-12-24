    #include<bits/stdc++.h>
    using namespace std;
    #define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #define ll long long
    const int N = 2e5 + 5;
  //  const ll MOD = 1e9 + 7;
  vector<vector<int>> adj(N);
  vector<int>vis(N, 0);

    bool dfs(int u,int par)
    {
        vis[u]= true;
        bool cyclic = false;
        for(int neig: adj[u]){
            if (!vis[neig])
                cyclic |= dfs(neig, u);
            else if(neig != par)
                return true;
        }
        return cyclic;

    }

    int main() {
        IO

        int t=1;
        //cin>>t;
        while (t--){
            int edges,nodes;
            cin>>nodes>>edges;
            adj.resize(nodes);
            vis.assign(nodes, 0);
            for (int i = 0; i < edges; ++i) {
                int from,to;
                cin>>from>>to;
                adj[from].push_back(to);
                adj[to].push_back(from);
            }
            bool iscyclic = false;
            int components=0;
            for (int i = 1; i <= nodes; ++i) {
                if(!vis[i]){
                    iscyclic |= dfs(i, i);
                    components++;
                }
            }
            if(!iscyclic && components == 1) cout<<"YES";
            else cout<<"NO";

        }
        

    }

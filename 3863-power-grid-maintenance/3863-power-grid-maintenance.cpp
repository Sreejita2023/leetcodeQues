class Solution {
public:
    vector<vector<int>> adj;
    vector<int> color;
    int clr;

    void dfs(int x) {
        color[x] = clr;
        for(auto &y : adj[x]) {
            if(color[y] == -1) dfs(y);
        }
    }
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        adj.clear(); adj.resize(c);
        for(auto e : connections) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }

        color.assign(c, -1); clr = 0;
        for(int i = 0; i < c; i++) {
            if(color[i] == -1) {
                dfs(i);
                clr++;
            }
        }

        vector<set<int>> v(clr);
        for(int i = 0; i < c; i++) {
            v[color[i]].insert(i);
        }

        vector<int> ans;
        for(auto q : queries) {
            int x = q[1]-1;
            if(q[0] == 1) {
                if(v[color[x]].count(x)) ans.push_back(x+1);
                else if(v[color[x]].size() == 0) ans.push_back(-1);
                else ans.push_back((*v[color[x]].begin()) + 1);
            }
            else {
                if(v[color[x]].count(x)) {
                    v[color[x]].erase(x);
                }
            }
        }

        return ans;
    }
};
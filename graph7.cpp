#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<limits.h>


using namespace std;

// class graph{
//     public:
//         unordered_map<int, list< pair<int,int> > >adjlist;
//         void addedge(int u, int v, int w, int d){
//             // d==1->directed
//             if(d==1)
//                 adjlist[u].push_back(make_pair(v,w));
//             // d==0-> un directed
//             else if (d==0){
//                 adjlist[u].push_back(make_pair(v,w));
//                 adjlist[v].push_back(make_pair(u,w));
//             }
//         }

//         void printlist(){
//             for( auto i: adjlist){
//                 cout<<i.first<<" -> {";
            
//                 for(auto j:i.second){
//                     cout<<"{ "<<j.first;
//                     cout<<" , "<<j.second<<"}";

//                 }
//                 cout<<" }"<<endl;
//             }
//         }
//         void belmonford(int n,int src){
//             vector<int>dist(n+1,INT_MAX);
//             dist[src]=0;
//             for(int i=1;i<n;i++){
//                 // bool flag=false;
//                 for(auto a:adjlist){
//                     for(auto b:a.second){
//                         int u=a.first;
//                         int v=b.first;
//                         int w=b.second;

//                         if(dist[u]!=INT_MAX && dist[u]+w <dist[v])
//                             dist[v]=dist[u]+w;
//                     }
//                 }

//             }
//             // shortest path aagaya hai 
//             // cycle check kiya jaye abb 
//             bool upd=false;
//             for(auto a:adjlist){
//                 for(auto b:a.second){
//                     int u=a.first;
//                     int v=b.first;
//                     int w=b.second;

//                     if(dist[u]!=INT_MAX && dist[u]+w <dist[v])
                        
//                         upd=true;
//                 }
//             }
//             if(upd){
//                 cout<<"negative cycle is present ";
//             }
//             else    cout<<"no negative cycle ";

//             for (int  i=1;i<n;i++){
//                 cout<<dist[i]<<" ";
//             }


//         }
//         void floydWarshal(int n) {
//             //intial state
//             vector<vector<int> > dist(n, vector<int>(n, 1e9));
//             //diagnol pr 0
//             for(int i=0; i<n; i++) {
//                 dist[i][i] = 0;
//             }
//             //kuch weights graph k andar bhi given h
//             //update dist array accordingly
//             for(auto a: adjlist) {
//                 for(auto b: a.second) {
//                     int u = a.first;
//                     int v = b.first;
//                     int wt = b.second;
//                     dist[u][v] = wt;
//                 }
//             }
//             //main logic - helper logic 
//             for(int helper = 0; helper < n; helper++) {
//                 for(int src =0; src < n; src++) {
//                     for(int dest = 0; dest < n; dest++) {
//                         dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
//                     }
//                 }
//             }

//             //printing distance array
//             for(int i=0; i<n; i++) {
//                 for(int j=0; j<n; j++ ) {
//                     cout << dist[i][j] << " ";
//                 }
//                 cout << endl;
//             }
//         }

// };

class graph{
    
    public:
        unordered_map<int, list<int> >adjlist;
        void addEdge(int u, int v, bool direct){
            // direct =0=> undirect
            if(direct==0){
                adjlist[u].push_back(v);
                adjlist[v].push_back(u);
            }
            // direct 1=direct
            else{
                adjlist[u].push_back(v);
            }
            cout<<"printing the adj list"<<endl;
            printAdjList();
            cout<<endl;

        }

        void printAdjList() {
            for(auto i: adjlist) {
                cout << i.first << "-> {";
                for(auto neighbour : i.second) {
                cout << neighbour <<", ";
                }
                cout << "}" << endl;
            }
        }

        void dfs1(int src, stack<int>&order,unordered_map<int, bool>&vis){
            vis[src]=true;
            for(auto i : adjlist[src]){
                if(!vis[i]){
                    dfs1(i,order,vis);
                }

            }
            order.push(src);
        }

        void dfs2(int src, unordered_map<int, bool>&vis2, unordered_map<int, list<int> >&adjnew){
            vis2[src]=true;

            // type 2 question ke liye ye cout hai 
            cout<<src<<" ";

            for (auto i:adjnew[src]){
                if(!vis2[i])
                    dfs2(i,vis2,adjnew);
            }


        }

        void ssc(int n){
            stack<int>order;
            unordered_map<int, bool>vis;
            //step 1 :  order nikalo
            for(int i=0;i<n;i++){
                if(!vis[i])
                    dfs1(i,order,vis);
            }

            // step 2 
            // abb har connection ko reverse karo in new adjlist

            unordered_map<int, list<int> >adjnew;
            for (auto i:adjlist){
                for(auto j:i.second){
                    int u=i.first;
                    int v=j;
                    adjnew[v].push_back(u);
                }
            }

            // step 3 traversal 
            unordered_map<int, bool>vis2;
            int count=0;
            while(!order.empty()){
                int src=order.top();
                order.pop();
                
                if(!vis2[src]){
                    // type 2 question h]jahan ssc ko print karne bola jaye tab ye couts likho dfs2 me bhi cout likho
                    cout<<" ssc #"<<count+1<<" ";
                    dfs2(src,vis2,adjnew);
                    count++;
                    cout<<endl;
                }
            }

            cout<<"total ssc : " <<count<<endl;
        }
};

/* 
// leet 1192: bridge testing 

class Solution {
public:
    void solve(int src, int parent, unordered_map<int,list<int> >& adj, int &timer, 
    vector<vector<int>>& ans,vector<int>& tin,vector<int>& low,unordered_map<int,bool>& vis ) {
        
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        //nbrs
        for(auto nbr: adj[src]) {
            if(nbr == parent) {
                //ignore this
                continue;
            }
            if(!vis[nbr]) {
                //step1
                solve(nbr, src, adj, timer, ans, tin, low, vis);
                //low update
                low[src] = min(low[src], low[nbr]);
                //bridge testing
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }

            }
            else {
                //ek or raasta milgya 
                //low update
                low[src] = min(low[src], low[nbr]);
                //no need of bridge testing
            }
        }


    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int> > adj;
        for(auto vec: connections) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //main logic 
        int timer = 1;
        vector<vector<int>> ans;
        vector<int> low(n,0);
        vector<int> tin(n,0);
        int src = 0;
        int parent = -1;
        unordered_map<int,bool> vis;
        solve(src, parent, adj,timer,ans, tin, low,vis);
        return ans;
    }
};
*/



int main(){

    graph g;
    // g.addedge(1,2,-1,1);
    // g.addedge(2,3,3,1);
    // g.addedge(1,3,4,1);
    // g.addedge(2,5,2,1);
    // g.addedge(2,4,2,1);
    // g.addedge(4,3,5,1);
    // g.addedge(4,2,1,1);
    // g.addedge(5,4,-3,1);

    // g.printlist();

    // int src=1;
    // int n=5;

    // g.belmonford(n,src);


    // floyd-warshal 
    // g.addedge(0, 1, 3, 1);
	// g.addedge(1, 0, 2, 1);
	// g.addedge(0, 3, 5, 1);
	// g.addedge(1, 3, 4, 1);
	// g.addedge(3, 2, 2, 1);
	// g.addedge(2, 1, 1, 1);
	// g.floydWarshal(4);

    // strongly connected component
    g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 0, 1);

	g.addEdge(2, 4, 1);

	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 4, 1);

	g.addEdge(6, 7, 1);
	int n = 8;

    g.ssc(8);
}
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

// undirected bfs

// class graph{
//     public:
//         unordered_map<int , list<int> >adjlist;
//         void addedge(int u, int v, bool direct){
//             // direct=0->undirectional 
//             if(direct==0){

//                 adjlist[u].push_back(v);
//                 adjlist[v].push_back(u);
//             }
//             // direct=1->directional
//             else{
//                 adjlist[u].push_back(v);
//             }

//         }
//         bool checkcycleundirectedbfs(int src){
//             unordered_map<int, bool>visited;
//             queue <int> q;
//             unordered_map<int,int>parent;

//             // initial case 
//             q.push(src);
//             visited[src]=true;
//             parent[src]=-1;

//             while(!q.empty()){
//                 // check karenge visited aur parent
//                 // agar kisi node pe uske parent ke alawa kisis dusre node se bhi ja sakte hain to cycle hai 
//                 int front=q.front();
//                 q.pop();
//                 for(auto i : adjlist[front]){
//                     if(!visited[i]){
//                         visited[i]=true;
//                         q.push(i);
//                         parent[i]=front;
//                     }
//                     else if(visited[i]&& i!=parent[front]){
//                         return true;
//                     }
//                 }
//             }
//             return false;

//         }
        
// };

// int main(){
//     graph g;
//     g.addedge(0,1,0);
//     g.addedge(1,2,0);
//     g.addedge(1,3,0);
//     g.addedge(2,4,0);
//     g.addedge(2,5,0);
//     g.addedge(3,4,0);

//     bool ans=g.checkcycleundirectedbfs(0);
//     if(ans){
//         cout<<"cycle present ";
//     }
//     else{
//         cout<<"no cycle";
//     }

// }



// undirected dfs 

// class Solution {
//     public:
//       bool checkCycle(int src,unordered_map<int,bool>& vis, int parent,vector<int> adj[]) {
//           vis[src] = true;
          
//           for(auto nbr: adj[src]) {
//               if(nbr == parent) {
//                   continue;
//               }
//               if(!vis[nbr]) {
//                   bool ans = checkCycle(nbr, vis, src, adj);
//                   if(ans == true) {
//                       return true;
//                   }
//               }
//               else if(vis[nbr]==1 ) {
//                   return true;
//               }
//           }
//           return false;
//       }
//       // Function to detect cycle in an undirected graph.
//       bool isCycle(int V, vector<int> adj[]) {
//           unordered_map<int,bool> vis;
//           for(int i=0;i<V;i++) {
//               if(!vis[i]) {
//                   int parent = -1;
//                   bool isCyclic = checkCycle(i, vis, parent,adj);
//                   if(isCyclic == true) {
//                       return true;
//                   }
//               }
//           }
//           return false;
//       }
//   };




// directed dfs
// class Solution {
//     public:
//       bool checkCyclic(int src, unordered_map<int,bool>& vis,
//           unordered_map<int,bool> &dfsTrack,vector<int> adj[] ) {
              
//           vis[src] = true;
//           dfsTrack[src] = true;
          
//           for(auto nbr: adj[src]) {
//               if(!vis[nbr]) {
//                   bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
//                   if(ans == true) {
//                       return true;
//                   }
//               }
//               if(vis[nbr]==1 && dfsTrack[nbr]==1) {
//                   //cycle present
//                   return true;
//               }
//           }
          
          
//           //backtrack - [yahi galti karta hu]
//            dfsTrack[src] = false;
//           return false;
//       }
//       // Function to detect cycle in a directed graph.
//       bool isCyclic(int V, vector<int> adj[]) {
//          unordered_map<int,bool> vis;
//          unordered_map<int,bool> dfsTrack;
         
//          for(int node=0; node<V; node++) {
//              if(!vis[node]) {
//                  bool isCyclic = checkCyclic(node, vis, dfsTrack, adj);
//                  if(isCyclic) {
//                      return true;
//                  }
//              }
//          }
//          return false;
//       }
//   };
  
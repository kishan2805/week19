#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;

// class graph{
//     public:
//         unordered_map<int, list<int> >adjlist;
//         void addedge(int u, int v, bool direct){
//             // direct =0=> undirect
//             if(direct==0){
//                 adjlist[u].push_back(v);
//                 adjlist[v].push_back(u);
//             }
//             // direct 1=direct
//             else{
//                 adjlist[u].push_back(v);
//             }
//             cout<<"printing the adj list"<<endl;
//             printAdjList();
//             cout<<endl;

//         }

//         void printAdjList() {
//             for(auto i: adjlist) {
//                 cout << i.first << "-> {";
//                 for(auto neighbour : i.second) {
//                 cout << neighbour <<", ";
//                 }
//                 cout << "}" << endl;
//             }
//         }
// };

template<typename t>
class graphwt{
    public:
        unordered_map<t, list<pair<t,t> > >adjlist;
        void addedge(t u, t v,t wt, bool direct){
            // direct 0= undirect
            if(direct==0){
                adjlist[u].push_back(make_pair(v,wt));
                adjlist[v].push_back(make_pair(u,wt));
            }
            // direct 1=direct
            else{
                adjlist[u].push_back(make_pair(v,wt));
            }
            cout<<"printing the adj list"<<endl;
            printAdjList();
            cout<<endl;

        }

        void printAdjList() {
            for(auto i: adjlist) {
                cout << i.first << "-> {";
                for( pair<t ,t> j : i.second) {
                cout << "{"<<j.first <<", "<<j.second<<"}";
                }
                cout << "}" << endl;
            }
        }
        void bfs(t src,unordered_map<t,bool>&visited){
            // adj list: already there 
            // visited
            
            // queue
            queue <t>q;

            // initial 
            q.push(src);
            visited[src]=true;

            // travel in graph
            while(!q.empty()){
                t front=q.front();
                cout<<front<<" ";
                q.pop();

                for(auto i:adjlist[front]){
                    t nbr=i.first;
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }

            }

        }
        void dfs(t src,unordered_map<t,bool>&visited){
            // adjlis already 
            // visited

            visited[src]=true;
            cout<<src<<" ";

            for(auto i:adjlist[src]){
                t childdata=i.first;
                if(!visited[childdata]){
                    visited[childdata]=true;
                    dfs(childdata,visited);
                }
            }



        }
};



int main(){
    graphwt<int> g;
    g.addedge(0,1,5,1);
    g.addedge(1,2,4,0);
    g.addedge(2,3,3,0);
    g.addedge(2,1,9,1);

    g.addedge(4,5,11,0);


    unordered_map<int,bool>visited;

    // for(int i=0;i<=5;i++){
    //     if(!visited[i]){
    //         g.bfs(i,visited);
    //     }
    // }

    for(int i=0;i<=5;i++){
        if(!visited[i]){
            g.dfs(i,visited);
        }
    }


   

}
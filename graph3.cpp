#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>

using namespace std;


class graph{
    public:
        unordered_map<int, list<int> >adjlist;
        void addedge(int u, int v, bool direct){
            // if direct ==1 -> directed
            if(direct==1)
                adjlist[u].push_back(v);
            // if direct ==0 ->undirected 
            else{

            
                adjlist[u].push_back(v);
                adjlist[v].push_back(u);
            }

            

            // printadj();


        }
        void printadj(){
            // we already have acess of adj list 
            cout<<endl<<"printing the list" <<endl;
            for(auto i:adjlist){
                cout<<i.first<<" : { ";
                for(auto j : i.second){
                    cout<<j<<", ";
                }
                cout<<" }"<<endl;
            }
        }
        void toposortdfs( int src,unordered_map<int,bool>&visited,stack<int>&st){

            visited[src]=true;
            for(auto child:adjlist[src]){
                if(!visited[child]){
                    
                    toposortdfs(child,visited,st);
                }
            }
            st.push(src);

        }

        void toposortbfs(int n){
            queue<int>q;
            unordered_map<int,int>indegree;
            // initialize the indegree
            for(auto i:adjlist){
                for(auto j:i.second){
                    indegree[j]++;
                }
            }
            // queue mee sara zero wala daal do
            for(int i=0;i<n;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            // BFS
            while(!q.empty()){
                int front=q.front();
                q.pop();
                cout<<front<<" -> ";
                for(auto nbr:adjlist[front]){
                    // substract karo jo bhi child hai front node ke 
                    indegree[nbr]--;
                    // check karo ki kahin baccho ka bhi to indegree update ke baad 0 to nahi hua 
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }


        }
        void shortestpathbfs(int src, int dest){
            unordered_map<int,bool>visited;
            unordered_map<int , int>parent;
            queue<int>q;

            visited[src]=true;
            parent[src]=-1;
            q.push(src);
            


            // sabka parent upload karo 
            while(!q.empty()){
                int front=q.front();
                q.pop();

                

                for(auto nbr:adjlist[front]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        parent[nbr]=front;
                        visited[nbr]=true;
                    }
                    
                }
            }
            vector<int> ans;
            while(dest!=-1){
                ans.push_back(dest);
                dest=parent[dest];
            }
            reverse(ans.begin(),ans.end());
            for(auto i:ans){
                cout<<i<<" ";
            }
            
        }

};

int main(){

    graph g;
    // g.addedge(0,1,1);
    // g.addedge(1,2,1);
    // g.addedge(2,3,1);
    // g.addedge(2,4,1);
    // g.addedge(3,5,1);
    // g.addedge(4,5,1);
    // g.addedge(5,6,1);
    // g.addedge(5,7,1);

    // g.printadj();
    // int n=8;

// toposort dfs

    // unordered_map<int , bool>visited;
    // stack<int>st;

    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g.toposortdfs(i,visited,st);
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;

// toposort bfs

    // g.toposortbfs(n);

// shortest path bfs 
    g.addedge(0,1,0);
    g.addedge(0,2,0);
    g.addedge(0,3,0);
    g.addedge(1,4,0);
    g.addedge(2,5,0);
    g.addedge(4,5,0);
    g.addedge(3,6,0);
    g.addedge(6,5,0);
    int src=0;
    int dest=5;
    g.shortestpathbfs(src,dest);



    return 0;
}
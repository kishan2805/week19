#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<limits.h>


using namespace std;

class graph{
    public:
        unordered_map<int,list<pair< int,int> > >adjlist;
        void addedge(int u, int v, int w, bool direct){
            if(direct==1){
                adjlist[u].push_back(make_pair(v,w));
            }
            else{
                adjlist[u].push_back(make_pair(v,w));
                adjlist[v].push_back(make_pair(u,w));
            }
        }
        void printadj(){
            cout<<"printing the adj list "<<endl;
            for(auto i :adjlist){
                // int nbr=adjlist[i];
                cout<<i.first<<" -> ";
                for(auto j:i.second){
                    cout<<" ("<<j.first<<" , "<<j.second<<" )";

                }
                cout<<endl;

            }
        }
        void toposortdfs(int src, stack<int>&st, unordered_map<int , bool>&visited){
            visited[src]=true;

            for(auto nbrpair: adjlist[src]){
                int nbrdest=nbrpair.first;
                int nbrweig=nbrpair.second;

                if(!visited[nbrdest])
                    toposortdfs(nbrdest,st,visited);



            }
            st.push(src);
        }

        void shortestdistance(int n , stack<int>&st){
            vector<int>dist(n,INT_MAX);
            int src=st.top();
            st.pop();
            
            dist[src]=0;

            // now update the distance vector for all node accessible from src
            for(auto i: adjlist[src]){
                int nbri=i.first;
                int nbrdis=i.second;
                if(dist[src]+nbrdis <dist[nbri]){
                    dist[nbri]=dist[src]+nbrdis;
                }
            }

            // apply same for all 
            while(!st.empty()){
                int src=st.top();
                st.pop();
                
                

                // now update the distance vector for all node accessible from src
                for(auto i: adjlist[src]){
                    int nbri=i.first;
                    int nbrdis=i.second;
                    if(dist[src]+nbrdis <dist[nbri]){
                        dist[nbri]=dist[src]+nbrdis;
                    }
                }

            }
            for(auto i:dist){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        void dijkstraShortestDistance(int n, int src, int dest) {
            vector<int> dist(n+1, INT_MAX);
            set<pair<int,int> > st;
    
            //INTIAL STATE -> (0,src)
            st.insert(make_pair(0,src));
            dist[src] = 0;
    
            //distance updation logic 
            while(!st.empty()) {
                auto topElement = st.begin();
                pair<int, int> topPair = *topElement;
                int topDist = topPair.first;
                int topNode = topPair.second;
                //remove the topNode
                st.erase(st.begin());
    
                //update distance of nbr
                for(pair<int,int> nbrPair: adjlist[topNode]) {
                    int nbrNode = nbrPair.first;
                    int nbrDist = nbrPair.second;
                    if(topDist + nbrDist < dist[nbrNode]) {
                        //found a new shorter distnace
                        //now update: 
                        
                        // -> set ki entry
                        //find previousEntry and delete it
                        auto previousEntry = st.find(make_pair(dist[nbrNode], nbrNode));
                        if(previousEntry != st.end()) {
                            // entry present in set
                            st.erase(previousEntry);
                        }
                        // -> dist ka array
                        dist[nbrNode] = topDist + nbrDist;
                        //create a new entry in the set for new distance
                        st.insert(make_pair(dist[nbrNode], nbrNode));
                    }
                }
            }
            cout << "Shortest Distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
    
    
        }

};


int main(){

    graph g;
    // g.addedge(0,1,5,1);
    // g.addedge(0,2,3,1);
    // g.addedge(2,1,2,1);
    // g.addedge(2,3,5,1);
    // g.addedge(2,4,6,1);
    // g.addedge(1,3,3,1);
    // g.addedge(4,3,1,1);

    // g.printadj();

    // stack<int>st;
    // unordered_map<int, bool>visited;
    // int src=0;
    // int n=5;



    // g.toposortdfs(src,st,visited);
    

    // for( int i=0; i<5;i++){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;

    // g.shortestdistance(n,st);


    g.addedge(1,6,14,0);
	g.addedge(1,3,9,0);
	g.addedge(1,2,7,0);
	g.addedge(2,3,10,0);
	g.addedge(2,4,15,0);
	g.addedge(3,4,11,0);
	g.addedge(6,3,2,0);
	g.addedge(6,5,9,0);
	g.addedge(5,4,6,0);
    int n = 6;
	int src = 6;
	int dest = 4;
	g.dijkstraShortestDistance(n, src, dest);


    return 0 ;

}

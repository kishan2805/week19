// leet 207

// class Solution {
//     public:
//         void topSortBfs(int n, vector<int>& topoOrder,unordered_map<int , list<int> >& adjList) {
//             queue<int> q;
//             map<int,int> indegree;
            
//             //initialise kardi indegree ssanki
//             for( auto i : adjList) {
//                 for(auto nbr: i.second) {
//                     indegree[nbr]++;
//                 }
//             }
//             //push all zero indegree wali node into queue
//             for(int node=0; node<n; node++) {
//                 if(indegree[node] == 0) {
//                     q.push(node);
//                 }
//             }
    
//             //BFS chalate hai
//             while(!q.empty()) {
//                 int frontNode = q.front();
//                 q.pop();
//                 topoOrder.push_back(frontNode);
    
//                 for(auto nbr: adjList[frontNode]) {
//                     indegree[nbr]--;
    
//                     //check for zero
//                     if(indegree[nbr] == 0) {
//                         q.push(nbr);
//                     }
//                 }
//             }
//         }
//         bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//             unordered_map<int , list<int> > adjList;
//             for(vector<int> i: prerequisites) {
//                 int u = i[0];
//                 int v = i[1];
//                 adjList[v].push_back(u);
//             }
    
//             vector<int> topoSort;
//             topSortBfs(numCourses, topoSort, adjList);
//             if(topoSort.size() == numCourses) 
//                 return true;
//             else
//                 return false;
//         }
//     };

// leet 210

// class Solution {
//     public:
//         void topSortBfs(int n, vector<int>& topoOrder,unordered_map<int , list<int> >& adjList) {
//             queue<int> q;
//             map<int,int> indegree;
            
//             //initialise kardi indegree ssanki
//             for( auto i : adjList) {
//                 for(auto nbr: i.second) {
//                     indegree[nbr]++;
//                 }
//             }
//             //push all zero indegree wali node into queue
//             for(int node=0; node<n; node++) {
//                 if(indegree[node] == 0) {
//                     q.push(node);
//                 }
//             }
    
//             //BFS chalate hai
//             while(!q.empty()) {
//                 int frontNode = q.front();
//                 q.pop();
//                 topoOrder.push_back(frontNode);
    
//                 for(auto nbr: adjList[frontNode]) {
//                     indegree[nbr]--;
    
//                     //check for zero
//                     if(indegree[nbr] == 0) {
//                         q.push(nbr);
//                     }
//                 }
//             }
//         }
//         vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//             unordered_map<int , list<int> > adjList;
//             for(vector<int> i: prerequisites) {
//                 int u = i[0];
//                 int v = i[1];
//                 adjList[v].push_back(u);
//             }
    
//             vector<int> topoSort;
//             topSortBfs(numCourses, topoSort, adjList);
//             //valid 
//             if(topoSort.size() == numCourses)
//                 return topoSort;
//             else{
//                 //invalid
//                 return {};
//             } 
//         }
//     };



// leet 1631


// class Solution {
//     public:
    
//         bool isSafe(int newX, int newY, int row, int col,vector<vector<int> >& diff, int currX, int currY ) {
//             if(newX >=0 && newY >=0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]) {
//                 return true;
//             }
//             else {
//                 return false;
//             }
//         }
    
//         int minimumEffortPath(vector<vector<int>>& heights) {
//             priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > mini;
//             int row = heights.size();
//             int col = heights[0].size();
//             vector<vector<int> > diff(row, vector<int>(col, INT_MAX));
//             int destX = row-1;
//             int destY = col-1;
//             //initial state
//             //set srcn ka distance 0
//             diff[0][0] = 0;
//             //min heap meentry for src push krdo
//             mini.push({0,{0,0}});
    
//             while(!mini.empty()) {
//                 auto topPair = mini.top();
//                 mini.pop();
//                 int currDiff = topPair.first;
//                 pair<int,int>  currNodeIndexPair = topPair.second;
//                 int currX = currNodeIndexPair.first;
//                 int currY = currNodeIndexPair.second;
//                
                
//                 //now we can travel to all nbr i.e. top, down, left, right
//                 int dx[] = {-1,0,1,0};
//                 int dy[] = {0,1,0,-1};
//                 for(int i=0; i<4; i++) {
//                    
//                     int newX = currX + dx[i];
//                     int newY = currY + dy[i];
//                     if(isSafe(newX, newY,row,col,diff,currX, currY)) {
//                        
//                         int maxDiff = max(currDiff, abs(heights[currX][currY]-heights[newX][newY]));
//                         //check can we update diff array
//                         diff[newX][newY] = min(diff[newX][newY], maxDiff);
//                        
//                         //entry create karo min Heap me
//                         if(newX != destX || newY != destY) {
//                             mini.push({diff[newX][newY], {newX, newY}});
//                            
//                         }
//                     }
//                 }
    
//             }
//             return diff[destX][destY];
//         }
//     };
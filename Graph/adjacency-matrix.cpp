#include <iostream>
#include <vector>

using namespace std;

class Graph{
protected:
  int numOfVertices;
  vector<vector<bool>> matrix;
public:
  Graph(int n){
    numOfVertices = n;
    vector<bool> tempRowVector(numOfVertices,false);
    for(int i=0; i<numOfVertices; i++){
      matrix.push_back(tempRowVector);
    }
  }
  ~Graph(){
    
  }
  void addEdge(int i, int j){
    matrix[i][j] = true;
  }
  void removeEdge(int i, int j){
    matrix[i][j] = false;
  }
  bool hasEdge(int i, int j){
    return matrix[i][j];
  }
  void outEdges(int i, vector<int> &edges){
    for(int j=0; j<numOfVertices; j++){
      if(matrix[i][j]){
	edges.push_back(j);
      }
    }
  }
  void inEdges(int i, vector<int> &edges){
    for(int j=0; j<numOfVertices; j++){
      if(matrix[j][i]){
	edges.push_back(j);
      }
    }
  }
  int vertices(){
    return numOfVertices;
  }
};

int main(){
  Graph g(4);
  g.addEdge(0,0);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(2,2);
  g.addEdge(2,3);

  g.removeEdge(2,2);
  cout<<"2 has a loop: "<<g.hasEdge(2,2)<<endl;
  
  vector<int> outs1;
  g.outEdges(1, outs1);
  cout<<"outEdges of 1: ";
  for(int element:outs1){
    cout<<element<<" ";
  }
  cout<<endl;
  
  vector<int> ins3;
  g.inEdges(3, ins3);
  cout<<"inEdges of 3: ";
  for(int element:ins3){
    cout<<element<<" ";
  }
  cout<<endl;

  cout<<"Number of vertices: "<<g.vertices()<<endl;
  return 0;
}

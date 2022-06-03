#include <iostream> 

using namespace std;


bool solv(int **arr,int i,int j,int row,int col,bool **visited){
    bool b1=false,b2=false,b3=false,b4=false;
    if(visited[i][j]){return false;}
    else{visited[i][j]=true;}
    if(arr[i][j]==0){
    return false;
    }
    else if(arr[i][j]==2){
    return true;
    }
    
    else if(arr[i][j]==1&&!visited[i][j]){
        if(j+1<col){
        if(arr[i][j+1]==1&&!visited[i][j+1])
           solv(arr,i, j+1,row,col,visited);}
        if(i+1<row){
        if(arr[i+1][j]==1&&!visited[i+1][j])
            solv(arr,i+1, j,row,col,visited);}
        
        if(i!=0&&j!=0){
            if(j!=0&&!visited[i][j-1])
            if(arr[i][j-1]==1)
             solv(arr,i, j-1,row,col,visited);
            if(i!=0&&!visited[i-1][j])
            if(arr[i-1][j]==1)
             solv(arr,i-1, j,row,col,visited);
        }

    }
    if(!b1&&!b2&&!b3&&!b4){return false;}
    return false;
}

int main() 
{ 

    int row,col;
    cin>>row>>col;
    int i,j;

    int **maze=new int*[row];
    for(i=0;i<row;i++){
            maze[i]=new int[col];
    }

    for( i=0;i<row;i++){
        for( j=0;i<col;j++)
            cin>>maze[i][j];
    }
    bool **visited=new bool*[row];
    for(i=0;i<row;i++){
            visited[i]=new bool[col];
    }

    for( i=0;i<row;i++){
        for( j=0;i<col;j++)
            visited[i][j]=false;
    }

    bool ans=solv(maze,0,0,row,col,visited);
    if(ans){
        cout<<"Path Found";
    }
    else{
        cout<<"Path Not Found";
    }
    
    return 0; 
} 

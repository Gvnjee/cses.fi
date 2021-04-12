#include<bits/stdc++.h>
using namespace std;
 
bool vis[1001][1001];
int n , m;

bool check(int x, int y ){
    if( x >=0 && x<n && y>=0 && y<m ) return 1;
    return 0;
}

void dfs(int x,int y){
    vis[x][y] = 1;
    if( check(x-1,y) && !vis[x-1][y] ) dfs( x-1,y) ;
    if( check(x+1,y) && !vis[x+1][y] ) dfs( x+1,y) ;
    if( check(x,y-1) && !vis[x][y-1] ) dfs( x,y-1) ;
    if( check(x,y+1) && !vis[x][y+1] ) dfs( x,y+1) ;
    return ;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i  < n  ; i ++ )
    {
        string s;
        cin >> s;
        for(int j=0 ; j < m ; j++ )
        {
            if( s[j] == '.' ) vis[i][j] = 0;
            else vis[i][j] = 1;
        }
    }
    int ans= 0 ;
    for(int i = 0 ; i  < n  ; i ++ )
       for(int j=0 ; j < m ; j++ )
            if( !vis[i][j] ) dfs(i,j) , ans++;
    cout << ans;
}

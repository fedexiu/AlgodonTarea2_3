#include <bits/stdc++.h>
#include "costs.h"
#include "editdistance.h"

using namespace std;




int main(){
    set_tables();



    int n, m;
    cin>>n>>m;


    vector<char> s(n);
    vector<char> t(m);

    for(int i = 0; i<n; ++i){
        cin>>s[i] ;
    }
    for(int i = 0; i<m; ++i){
        cin>>t[i];
    }

    cout<<editdistancebf(s, n, t, m)<<"\n";

    return 0;    
}
#include <iostream>
#include <numeric>
#include <string>
#include <cstring>

using namespace std;

int main(){
    int shops, judges, i, j, k;
    cin>>shops>>judges;
    bool quit[judges], out[shops];
    int vote[shops];
    string judge[shops];
    memset(out,1,sizeof(out));
    for(i=0;i<judges;i++){
        cin>>judge[i];
    }
    for(i=0;i<shops;i++){
        for(j=0,fill_n(vote,shops,0);j<judges;j++){
            if(quit[j]==true){
                continue;
            }
            for(k=0;k<shops;k++){
                if(judge[j][k]=='0'){
                    quit[j]=true;
                }
                if(!out[judge[j][k]-'0']){
                    vote[k]++;
                    break;
                }
            }
        }
        for(j=1,k=0;j<shops;j++){
            k=vote[0];
            if(vote[j]<vote[j-1]){
                k=vote[j];
            }
        }
        for(j=0;j<shops;j++){
            if(vote[j]==k){
                out[j]=true;
            }
        }
        if(accumulate(out,out+shops,0)==1){
            for(j=0;j<shops;j++){
                if(out[j]){
                    cout<<j<<endl;
                    return 0;
                }
            }
        } else if(accumulate(out,out+shops,0)<1){
            k=0;
            for (i = 1; i < shops; i++){
                for (j = 0; j < i; j++){
                    if (vote[i] == vote[j]){
                        break;
                    }
                }
                if (i == j){
                k++;
                }
            }
            cout<<(-k)<<endl;
            return 0;
        }
    }
}
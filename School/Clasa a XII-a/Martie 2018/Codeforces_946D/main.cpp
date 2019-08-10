#include <iostream>

using namespace std;
int n, m, k;
int ds[501][501], dr[501][501];
int sol;
int main()
{
    int i, j;
    bool ok;
    char elem;

    cin>>n>>m>>k;
    for(i=1; i<=n; i++){
        ok = true;
        for(j=1; j<=m; j++){
            cin>>elem;
            if(elem == '1'){
                if(ok== true){
                    ds[i][0] = j;
                    ok = false;
                }
                dr[i][0] = j;
            }
            ds[i][j] = dr[i][j] = elem - '0';
        }
    }

    int s;
    for(i=1; i<=n; i++){
        s=0;
        for(j=1; j<=m; j++){
            s += ds[i][j];
            if(ds[i][j] != 0)
             ds[i][j] = s;
        }

        s=0;
        for(j=m; j>=1; j--){
            s += dr[i][j];
            if(dr[i][j] != 0)
             dr[i][j] = s;
        }
    }

    /*cout<<endl;
    for(i=1; i<=n; i++){
        for(j=0; j<=m; j++)
            cout<<ds[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1; i<=n; i++){
        for(j=0; j<=m; j++)
            cout<<dr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/

    int pozI, pozJ, temp;
    bool type; // 0 - ds, 1 - dr
    double valMax = 1;
    while(k > 0 && valMax > 0){
        valMax = 0;

        for(i=1; i<=n; i++){
            if(ds[i][0] != 0 && dr[i][0] != 0){
                if(ds[i][0] == dr[i][0] && 1 > valMax && ds[i][0] != 0)
                    valMax = 1, pozI = i, pozJ = ds[i][0], type = 0;

                for(j=ds[i][0] + 1; j<=m; j++){
                    if(ds[i][j] != 0){
                        if(float(j - ds[i][0]) / (ds[i][j]) > valMax){
                            valMax = double(j - ds[i][0]) / (ds[i][j]);
                            pozI = i, pozJ = j;
                            type = 0;
                        }
                    }
                }

                /*
                for(j=1; j<=m; j++){
                    if(j - ds[i][0] > 0 && ds[i][j] != 0){
                        if(float(j - ds[i][0]) / (ds[i][j]) > valMax){
                            valMax = double(j - ds[i][0]) / (ds[i][j]);
                            pozI = i, pozJ = j;
                            type = 0;
                        }
                    }
                    else if(1 > valMax && ds[i][j] != 0){
                            valMax = 1;
                            pozI = i, pozJ = j;
                            type = 0;
                        }
                }
                */

                for(j=dr[i][0]-1; j>=1; j--){
                    if(dr[i][j] != 0){
                        if(float(dr[i][0] - j) / (dr[i][j]) > valMax){
                            valMax = double(dr[i][0] - j) / (dr[i][j]);
                            pozI = i, pozJ = j;
                            type = 1;
                        }
                    }
                }
            }
        }

        if(valMax > 0){
            if(type == 0){
                if(ds[pozI][0] == pozJ)
                    temp = 1, dr[pozI][0] = 0;
                else
                    temp = ds[pozI][pozJ] - ds[pozI][ds[pozI][0]];

                ok = true;
                ds[pozI][0] = 0;
                for(j=1; j <= pozJ; j++)
                    ds[pozI][j] = 0;
                for(j=pozJ + 1; j<=m; j++)
                    if(ds[pozI][j] > 0){
                        if(ok == true){
                            ds[pozI][0] = j;
                            ok = false;
                        }
                        ds[pozI][j] -= temp;
                    }
                //
                for(j=pozJ; j>=1; j--)
                    dr[pozI][j] = 0;
            }
            else if(type == 1) {
                if(dr[pozI][0] == pozJ)
                    temp = 1, ds[pozI][j] = 0;
                else
                    temp = dr[pozI][pozJ] - dr[pozI][dr[pozI][0]];

                ok = true;
                dr[pozI][0] = 0;
                for(j=m; j>= pozJ; j--)
                    dr[pozI][j] = 0;
                for(j=pozJ-1; j>=1; j--)
                    if(dr[pozI][j] > 0){
                        if(ok == true){
                            dr[pozI][0] = j;
                            ok = false;
                        }
                        dr[pozI][j] -=temp;
                    }
                //
                for(j=pozJ; j<=m; j++)
                    ds[pozI][j] = 0;
            }
            k -= temp;
        }
    }

    cout<<endl;
    for(i=1; i<=n; i++){
        for(j=0; j<=m; j++)
            cout<<ds[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1; i<=n; i++){
        for(j=0; j<=m; j++)
            cout<<dr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    for(i=1; i<=n; i++){
        sol += dr[i][0] - ds[i][0];
    }
    cout<<sol;
    return 0;
}

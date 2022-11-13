
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
typedef long long ll;

bool vis[60];

bool detectCycle(int pos,int parent,vector<int>graph[],vector<int> &cycle)
{
    vis[pos]=true;
    for (int i=0;i<graph[pos].size();i++)
    {
        int x=graph[pos][i];
        if (vis[x] && x!=parent)
        {
            //cout << "1st if "<<endl;
            //cout << "x is " << x << " parent is  " << parent << endl;
            cycle.pb(pos);
            return true;
        }
        if (!vis[x] && detectCycle(x,pos,graph,cycle) )
        {
            //cout << "2nd if "<<endl;
            cycle.pb(pos);
            return true ;
        }
    }
    return false;
}
bool exists (vector<int> &V,int a)
{
    for (int i=0;i<V.size();i++)
    {
        if (V[i]==a)
        {
            return true;
        }
    }
    return false;
}



int main() {


    freopen("Tests.txt", "r", stdin);

    int t;
    cin >> t;
    int T =t;
    while(t--)
    {
        int res=0;
        memset(vis,false,sizeof(vis));
        vector<int>graph[60];
        int n;
        cin >>n;
        ll c[60];
        for (int i=0;i<n;i++)
        {
            cin >> c[i];
        }
        for (int i=0;i<n-1;i++)
        {
            int Ai,Bi;
            cin >> Ai >> Bi;
            graph[Ai-1].pb(Bi-1);
            graph[Bi-1].pb(Ai-1);
        }
        if (n==2)
        {
            cout << "Case #" << T-t << ":
                " << c[0]+c[1]<<endl;

        }
        else
        {

            for (int i=0;i<n;i++)
            {
                //memset(vis,false,sizeof(vis));
                for (int j=0;j<n;j++)
                {
                    if (i!=j)
                    {

                            int cpt =0;
                            vector<int>aux[60] ;
                            for (int i=0;i<60;i++)
                            {
                                for (int j:graph[i])
                                {
                                    aux[i].pb(j);
                                }
                            }
                            if (!exists(graph[i],j))
                            {
                                aux[i].pb(j);
                                aux[j].pb(i);
                            }

                            vector<int> cycle;
                            if (detectCycle(i,-1,aux,cycle))
                            {
                                //cout << "the i is " << i << " and j is "<< j<< endl;
                                bool zero=false;
                                for (int i=0;i<cycle.size();i++)
                                {
                                    //cout << cycle[i]<< " " ;
                                    cpt += c[cycle[i]];
                                    if (cycle[i]==0)
                                        zero = true ;
                                }
                                //cout <<"cpt is "<< cpt <<endl ;
                                if (zero)
                                res = max(res,cpt);
                            }
                            memset(vis,false,sizeof(vis));


                    }
                }
            }
            cout << "Case #" << T-t << ": " << res<<endl;

        }












    }






}





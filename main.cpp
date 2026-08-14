#include <bits/stdc++.h>
using namespace std;
vector<string>names;
vector<int>scores;

void merge(int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;

    vector<int>Lscore(n1);
    vector<int>Rscore(n2);
    vector<string>Lname(n1);
    vector<string>Rname(n2);

    for(int i=0;i<n1;i++)
    {
        Lscore[i]=scores[l+i]; 
        Lname[i]=names[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        Rscore[i]=scores[m+1+i];
        Rname[i]=names[m+1+i];
    }

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(Lscore[i]>=Rscore[j])
        {
            scores[k]=Lscore[i];
            names[k]=Lname[i];
            i++;
        }
        else
        {
            scores[k]=Rscore[j];
            names[k]=Rname[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        scores[k]=Lscore[i];
        names[k]=Lname[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        scores[k]=Rscore[j];
        names[k]=Rname[j];
        j++;
        k++;
    }
} 

void mergeSort(int l,int r)
{
    if((r-l+1)>=2)
    {
        int m=(l+r)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }
}

int main()
{
    int k,n;
    cin>>k>>n;

    for(int i=0;i<n;i++)
    {
        string name;
        cin>>name;
        int score=1;

        int children;
        cin>>children;
        score*=3*children;

        int disease; 
        cin>>disease;
        if(disease>0) 
        {
            score*=5*disease;
        }

        int old;
        cin>>old;
        if(old>0) 
        {
            score*=3*old;
        }

        int income; 
        cin>>income;
        if(income==0) 
        {
            score*=4;
        }

        names.push_back(name);
        scores.push_back(score);
    }
    if(k<n)
    mergeSort(0,n-1);

    cout<<"Total Families: "<<min(n,k)<<"\n\n";
    cout<<"Families:\n";

    for(int i=0;i<min(n,k);i++)
    {
        cout<<names[i]<<" "<<scores[i]<<"\n";
    }    
}

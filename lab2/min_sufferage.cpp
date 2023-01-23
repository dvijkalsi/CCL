#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;    
    cout<<"Enter the number of tasks: ";
    cin>>n;

    vector<vector<int>> v(2);
    v[0].resize(n);
    v[1].resize(n);
    cout<<"Enter the time taken by each task on vm1: ";
    for(int j=0;j<n;j++)
    {
        cin>>v[0][j];
    }
    cout<<"Enter the time taken by each task on vm2: ";
    for(int j=0;j<n;j++)
    {
        cin>>v[1][j];
    }

    //using minimum sufferage algorithm to find the sceduling of tasks and displaying gantt chart

    int m=n;
    vector<int> vm_tc(2);

    while (m--)
    {
        vector<int> diff(n,0);
        int max_diff=INT_MIN;
        int max_index;
        for(int i=0;i<n;i++)
        {
            diff[i]=abs(v[0][i]-v[1][i]);
            if(diff[i]>max_diff)
            {
                max_diff=diff[i];
                max_index=i;
            }
        }

        if(v[0][max_index]+vm_tc[0]<v[1][max_index]+vm_tc[1])
        {
            vm_tc[0]+=v[0][max_index];
            cout<<"Task "<<max_index+1<<" is scheduled on vm1"<<" and finishes at "<<vm_tc[0]<<endl;
            v[0][max_index]=INT_MAX;
            v[1][max_index]=INT_MAX;

        }
        else
        {
            vm_tc[1]+=v[1][max_index];
            v[1][max_index]=INT_MAX;
            v[0][max_index]=INT_MAX;
            cout<<"Task "<<max_index+1<<" is scheduled on vm2"<<" and finishes at "<<vm_tc[1]<<endl;

        }


    }
    
    cout<<"Total processing time: "<<max(vm_tc[0],vm_tc[1])<<endl;




    return 0;

}
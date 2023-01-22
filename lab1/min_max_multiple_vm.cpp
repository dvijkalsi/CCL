#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;    
    cout<<"Enter the number of tasks: ";
    cin>>n;
    int vm;
    cout<<"Enter the number of VMs: ";
    cin>>vm;
    vector<vector<int>> v(vm);

    for(int i=0;i<vm;i++)
    {
        v[i].resize(n);
        cout<<"Enter the time taken by each task on vm"<<i+1<<": ";
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }


    //using min max algorithm to find the sceduling of tasks and displaying gantt chart
    int m=n;        
    vector<int> vm_tc(vm);
    while(m--)
    {
        vector<pair<int,int>> min_array(n);

        //finding the min time taken by each task
        for(int i=0;i<n;i++)
        {
            min_array[i].first=INT_MAX;
            for(int j=0;j<vm;j++)
            {
                if(v[j][i]<min_array[i].first)
                {
                    min_array[i].first=v[j][i];
                    min_array[i].second=j;
                }
            }
        }

        int max_time=INT_MIN;
        int max_index_row;
        int max_index_col;

        for(int i=0;i<n;i++)
        {
            if(min_array[i].first+vm_tc[i] >max_time)
            {
                max_time=min_array[i].first;
                max_index_row=min_array[i].second;
                max_index_col=i;
            }
        }


        vm_tc[max_index_row]+=max_time;
        cout<<"Task "<<max_index_col+1<<" is scheduled on vm"<<max_index_row+1<<" and finishes at time: "<<vm_tc[max_index_row]<<endl;





        for(int i=0;i<vm;i++)
        {
            v[i][max_index_col]=INT_MIN;
        }


    }
    
    //finding the total time taken by vms
    int max_vm_tc=INT_MIN;
    for(int i=0;i<vm;i++)
    {
        max_vm_tc=max(max_vm_tc,vm_tc[i]);
    }
    cout<<"Total time taken by all VMs: "<<max_vm_tc<<endl;
    


    return 0;
}
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


    //using max min algorithm to find the sceduling of tasks and displaying gantt chart
    int m=n;        
    vector<int> vm_tc(vm,0);
    while(m--)
    {
        vector<pair<int,int>> max_array(n);

        //finding the min time taken by each task
        for(int i=0;i<n;i++)
        {
            max_array[i].first=INT_MIN;
            for(int j=0;j<vm;j++)
            {
                if(v[j][i]>max_array[i].first)
                {
                    max_array[i].first=v[j][i];
                    max_array[i].second=j;
                }
            }
        }

        int min_time=INT_MAX;
        int min_index_row;
        int min_index_col;

        for(int i=0;i<n;i++)
        {
            if(max_array[i].first+vm_tc[i] <min_time)
            {
                min_time=max_array[i].first;
                min_index_row=max_array[i].second;
                min_index_col=i;
            }
        }


        vm_tc[min_index_row]+=min_time;
        cout<<"Task "<<min_index_col+1<<" is scheduled on vm"<<min_index_row+1<<" and finishes at time: "<<vm_tc[min_index_row]<<endl;





        for(int i=0;i<vm;i++)
        {
            v[i][min_index_col]=INT_MAX;
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
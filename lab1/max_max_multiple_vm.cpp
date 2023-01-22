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


    //using max max algorithm to find the sceduling of tasks and displaying gantt chart
    int m=n;        
    vector<int> vm_tc(vm);
    while(m--)
    {
        vector<int> max_array(n);

        //finding the max time taken by each task
        for(int i=0;i<n;i++)
        {
            max_array[i]=INT_MIN;
            for(int j=0;j<vm;j++)
            {
                max_array[i]=max(max_array[i],v[j][i]);
            }
        }
        int max_time=INT_MIN;
        int max_index;

        for(int i=0;i<n;i++)
        {
            if(max_array[i]>max_time)
            {
                max_time=max_array[i];
                max_index=i;
            }
        }

        for(int i=0;i<vm;i++)
        {
            if(v[i][max_index]==max_time)
            {
                vm_tc[i]+=max_time;
                cout<<"Task "<<max_index+1<<" is scheduled on vm"<<i+1<<" and finishes at time: "<<vm_tc[i]<<endl;
            }
        }

        for(int i=0;i<vm;i++)
        {
            v[i][max_index]=INT_MIN;
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
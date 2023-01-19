#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;    
    cout<<"Enter the number of tasks: ";
    cin>>n;

    vector<int> vm1(n);
    vector<int> vm2(n);

    cout<<"Enter the time taken by each task on vm1: ";
    for(int i=0;i<n;i++)
    {
        cin>>vm1[i];
    }
    cout<<"Enter the time taken by each task on vm2: ";
    for(int i=0;i<n;i++)
    {
        cin>>vm2[i];
    }

    //using min min algorithm to find the sceduling of tasks and displaying gantt chart
    int m=n;        
    int vm1_tc=0;
    int vm2_tc=0;
    while(m--)
    {
        vector<int> min_array(n);

        //finding the min time taken by each task
        for(int i=0;i<n;i++)
        {
            min_array[i]=min(vm1[i],vm2[i]);
        }
        int min_time=INT_MAX;
        int min_index;

        for(int i=0;i<n;i++)
        {
            if(min_array[i]<min_time)
            {
                min_time=min_array[i];
                min_index=i;
            }
        }
        if(vm1[min_index]<vm2[min_index])
        {
            vm1_tc+=min_time;
            cout<<"Task "<<min_index+1<<" is scheduled on vm1 and finishes at time: "<<vm1_tc<<endl;

        }
        else
        {
            vm2_tc+=min_time;
            cout<<"Task "<<min_index+1<<" is scheduled on vm2 and finishes at time: "<<vm2_tc<<endl;
        }
        vm1[min_index]=INT_MAX;
        vm2[min_index]=INT_MAX;
    }
    cout<<"Total time taken: "<<max(vm1_tc,vm2_tc)<<endl;

    return 0;
}
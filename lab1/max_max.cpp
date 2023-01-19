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

    //using max max algorithm to find the sceduling of tasks and displaying gantt chart
    int m=n;        
    int vm1_tc=0;
    int vm2_tc=0;
    while(m--)
    {
        vector<int> max_array(n);

        //finding the max time taken by each task
        for(int i=0;i<n;i++)
        {
            max_array[i]=max(vm1[i],vm2[i]);
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
        if(vm1[max_index]>vm2[max_index])
        {
            vm1_tc+=max_time;
            cout<<"Task "<<max_index+1<<" is scheduled on vm1 and finishes at time: "<<vm1_tc<<endl;

        }
        else
        {
            vm2_tc+=max_time;
            cout<<"Task "<<max_index+1<<" is scheduled on vm2 and finishes at time: "<<vm2_tc<<endl;
        }
        vm1[max_index]=INT_MIN;
        vm2[max_index]=INT_MIN;
    }
    cout<<"Total time taken: "<<max(vm1_tc,vm2_tc)<<endl;

    return 0;
}
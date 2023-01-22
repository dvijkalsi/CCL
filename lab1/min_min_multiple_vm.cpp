#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nt, nm;
    cout<<"Enter number of tasks:\t\t";
    cin>> nt;
    cout<<"Enter number of machines:\t";
    cin>>nm;
    int data[nm][nt], temp[nm][nt], total = 0;
    cout<<endl;
    for(int i = 0; i < nm; i++)
        for(int j = 0; j < nt; j++)
        {
            cout<<"Enter processing time for VM "<<i + 1<<" & T "<<j + 1<<":\t";
            cin>>data[i][j];
            temp[i][j] = data[i][j];
        }
    cout<<"\nAccepted data:"<<"\n\n";
    for(int i = 0; i < nt; i++)
        cout<<"\tT "<<i + 1;
    for(int i = 0; i < nm; i++)
    {
        cout<<"\nVM "<<i + 1<<"\t";
        for(int j = 0; j < nt; j++)
        {
            cout<<data[i][j]<<"\t";
        }
    }
    int task[nt], time[nt], mach[nt], ptr = -1;
    while(ptr < nt - 1)
    {
        int min_t[nt], min_m[nt];
        for(int i = 0; i < nt; i++)
        {
            int min = INT_MAX, pos = -1;
            for(int j = 0; j < nm; j++)
                if(data[j][i] < min)
                {
                    min = data[j][i];
                    pos = j;
                }
            min_t[i] = min;
            min_m[i] = pos;
        }
        int min = INT_MAX, pos = -1;
        for(int i = 0; i < nt; i++)
            if(min_t[i] < min)
            {
                min = min_t[i];
                pos = i;
            }
        task[++ptr] = pos;
        mach[ptr] = min_m[pos];
        time[ptr] = temp[min_m[pos]][pos];
        if(min > total)
            total = min;
        for(int i = 0; i < nm; i++)
            for(int j = 0; j <nt; j++)
            {
                if(j == task[ptr])
                    data[i][j] = INT_MAX;
                else if(i == mach[ptr] && data[i][j] != INT_MAX)
                    data[i][j] += min;
                else
                    continue;
            }
    }
    cout<<"\n\nScheduled tasks are:\n\nTask\tMachine\tTime";
    for(int i = 0; i < nt; i++)
        cout<<"\n"<<task[i] + 1<<"\t"<<mach[i] + 1<<"\t"<<time[i];
    cout<<"\n\nCompletion time = "<<total;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    cout<<"Enter Number Of Process :";
    int N;
    cin>>N;
    int at[N],pid[N],bt[N],ct[N],tat[N],rt[N],process_flag[N],btc[N];
    for(int i=0;i<N;i++){
        cout<<"Enter AT,BT for process "<<i+1<<" ";
        cin>>at[i]>>bt[i];
        pid[i]=i;
        btc[i]=bt[i];
        process_flag[i]=0;
    }
    cout<<"Enter time quantom ";
    int quantom;
    cin>>quantom;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(at[j]>at[j+1]){
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
                swap(pid[j],pid[j+1]);
            }
        }
    }
    vector<int> process_queue;
    int cpu_time=at[0];
    bool flag = false;
    while(true){
        for(int i=0;i<N;i++){
            if(!process_flag[i] && at[i]<=cpu_time){
                process_queue.push_back(i);
                process_flag[i]=1;
            }
        }
        int currrent_process = process_queue.front();
        // cout<<pid[currrent_process]<<" ("<<cpu_time<<")("<<bt[currrent_process]<<")|";
        cout<<pid[currrent_process]+1<<" |";
        vector<int>::iterator  it = process_queue.begin();
        process_queue.erase(it);
        if(bt[currrent_process] <= quantom){
            // process get complete
            cpu_time += bt[currrent_process];
            ct[currrent_process] = cpu_time;
            bt[currrent_process] = 0;
        }else{
            cpu_time += quantom;
            bt[currrent_process] -= quantom;
            for(int i=0;i<N;i++){
                if(!process_flag[i] && at[i]<=cpu_time){
                    process_queue.push_back(i);
                    process_flag[i]=1;
                }
            }
            process_queue.push_back(currrent_process);
        }
        if(process_queue.size() == 0){
            break;
        }
    }

    cout<<"\nPID\tAT\tBT\tCT\n";
    for(int i=0;i<N;i++){
        cout<<pid[i]<<"\t"<<at[i]<<"\t"<<btc[pid[i]]<<"\t"<<ct[i]<<"\n";
    }
    return 0;
}
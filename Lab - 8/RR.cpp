#include<bits/stdc++.h>

using namespace std;

vector<int> cpu_queue,Process_queue;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

float calculate_average(int t[], int n)
{
	int sum=0;
	for(int i=0; i<n; i++)
		sum += t[i];
	float avg = (float)sum/n;
	return avg;
}


int main(){
    int n;
    cout<<"Enter Number Of Process : ";
    cin>>n;

    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n],pid[n],btc[n],pidc[n];
    int time_quantom;

    for(int i=0 ; i<n ; i++){
            cout<<"For Process ID = "<<i<<endl;
            pid[i]=i;
            pidc[i]=i;
            cout<<"Arival time :";
            cin>>at[i];
            cout<<"Burst Time :";
            cin>>bt[i];
            btc[i]=bt[i];
            cout<<endl;
    }
    cout<<"Enter Time Quantom : ";
    cin>>time_quantom;

    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(at[j] > at[j+1]){
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
                swap(btc[j],btc[j+1]);
                swap(pid[j],pid[j+1]);
                swap(pidc[j],pidc[j+1]);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
            pid[i]=i;
            at[i]=at[i];
            bt[i]=bt[i];
            btc[i]=bt[i];
    }
    cout<<endl<<"Pid\tAT\tBT"<<endl;

	for(int i=0; i<n; i++){
		cout<<pid[i]<<"\t"<<at[i]<<"\t"<<btc[i]<<endl;
	}	
    for(int i=0;i<n;i++){
        Process_queue.push_back(pid[i]);
    }
    // int first_process = pid[0];
    // cout<<"First Process =  "<<first_process<<endl;
    int current_cpu_process;
    int cpu_time = at[0];

    cout<<"check_1"<<endl;
    
    
    int i=20;
    while(i--){
        cout<<"check-2"<<endl;
        bool completion_flag = false;
        cout<<cpu_time<<endl;
        if(cpu_queue.size() != 0){
            // cpu_queue is not empty
            current_cpu_process = cpu_queue.front();
            cout<<"Current Process"<<current_cpu_process<<endl;
            cpu_queue.erase(cpu_queue.begin());
            cout<<"check-2.1"<<endl;
            if(bt[current_cpu_process]<time_quantom){
                cout<<"check-2.2"<<endl; 
                // process time is less then time quantom  
                ct[current_cpu_process] = cpu_time + bt[current_cpu_process];
                cpu_time += bt[current_cpu_process];
                bt[current_cpu_process] = 0;
                // process complete

            }else if(bt[current_cpu_process]==time_quantom){
                cout<<"check-2.3"<<endl;
                // process time is equal to the time quantom
                cpu_time += time_quantom;
                ct[current_cpu_process] = cpu_time;
                bt[current_cpu_process] = 0;
                // process complete 

            }else{
                cout<<"check-2.4"<<endl;
                // process time is grater then time quantom
                bt[current_cpu_process] -= time_quantom;
                completion_flag = true;
                cpu_time += time_quantom;
                // Process needs more cpu 
            }
        }else if(cpu_queue.size() == 0 && cpu_time != at[0]){
            // cpu_queue is empty
            cout<<"check-2.5"<<endl;
            cpu_time += 1;
        }else if(cpu_queue.size() == 0 && cpu_time == at[0]){

            cpu_queue.push_back(Process_queue.front());
            Process_queue.erase(Process_queue.begin());
        }

        cout<<"check-3"<<endl;
        if(cpu_time <= at[n-1] && Process_queue.size() != 0){
            // cpu_time is less then arrival time of last process and 
            // there is process in process_queue
            cout<<"check-3.1"<<endl;
            while(at[Process_queue[0]] <= cpu_time && Process_queue.size() != 0){
                cout<<"check-3.2 for process : "<<Process_queue.front()<<endl;
                cpu_queue.push_back(pid[Process_queue.front()]);
                Process_queue.erase(Process_queue.begin());
                cout<<"check-4"<<endl;
            }
        }
        if(completion_flag == true){
            // if completin flag = False 
            // process needs to go in cpu_queue
            cout<<"check-4.1"<<endl;
            cpu_queue.push_back(current_cpu_process);
        }
        if(Process_queue.size() == 0 && cpu_queue.size() == 0){
            break;
        }
    }
    for(int i=0; i<n; i++){
		tat[i] = ct[i] - at[i];
	}
	for(int i=0; i<n; i++){
		wt[i] = tat[i] - btc[i];
		rt[i] = tat[i] - btc[i];
	}

    cout<<endl<<"Pid\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;

	for(int i=0; i<n; i++){
		cout<<pidc[i]<<"\t"<<at[i]<<"\t"<<btc[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<rt[i]<<endl;
	}	
	cout<<endl<<"Average Turn Around Time = "<<calculate_average(tat,n);
	cout<<endl<<"Waiting Time = "<<calculate_average(wt,n)<<endl;
	cout<<"Throughput = "<<(float)n/(float)ct[n-1]<<endl;
}
#include<bits/stdc++.h>

using namespace std;

vector<int> cpu_queue,Process_queue;

bool byat(const tuple<int,int,int,int,int,int>& a,const tuple<int,int,int,int,int,int>& b){
     return (get<1>(a) < get<1>(b)); 
}

bool bybt(const tuple<int,int,int,int,int,int>& a,const tuple<int,int,int,int,int,int>& b){
     return (get<2>(a) < get<2>(b)); 
}
bool bypid(const tuple<int,int,int,int,int,int>& a,const tuple<int,int,int,int,int,int>& b){
     return (get<0>(a) < get<0>(b)); 
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
    // pid,at,bt,ct,tat,wt
    vector<tuple<int,int,int,int,int,int>> Process;
    for(int i=0 ; i<n ; i++){
            int at,bt;
            cout<<"For Process ID = "<<i<<endl;
            cout<<"Arival time :";
            cin>>at;
            cout<<"Burst Time :";
            cin>>bt;
            cout<<endl;
            Process.push_back(make_tuple(i,at,bt,0,0,0));
    }
    
    sort(Process.begin(),Process.end(),byat);
    int CPU_time=get<1>(Process[0]);
    vector<tuple<int,int,int,int,int,int>> arreved_process,completed_process;
    while(true){
        if(arreved_process.size() != 0){
            if(get<1>(arreved_process[0]) <= CPU_time){
            // start working on process
                sort(arreved_process.begin(),arreved_process.end(),bybt);
                CPU_time +=  get<2>(arreved_process[0]);
                get<3>(arreved_process[0]) += CPU_time;
                completed_process.push_back(arreved_process[0]);
                arreved_process.erase(arreved_process.begin());
            }else{
                // increase time only
                CPU_time++;
            }
        }else{
            while(CPU_time >= get<1>(Process[0]) && Process.size() != 0){
                arreved_process.push_back(Process[0]);
                Process.erase(Process.begin());
            }
        }
        if(completed_process.size() == n){
            break;
        }
    }

    for(int i=0; i<n; i++){
        get<4>(completed_process[i]) = get<3>(completed_process[i]) - get<1>(completed_process[i]); 
    }
    for(int i=0; i<n; i++){
        get<5>(completed_process[i]) = get<4>(completed_process[i]) - get<2>(completed_process[i]); 
    }
    sort(completed_process.begin(),completed_process.end(),bypid);
    cout<<endl<<"Pid\tAT\tBT\tCT\tTAT\tWT"<<endl;
	for(int i=0; i<n; i++){
		cout<<get<0>(completed_process[i])<<"\t"<<get<1>(completed_process[i])<<"\t"<<get<2>(completed_process[i])<<"\t"<<get<3>(completed_process[i])<<"\t"<<get<4>(completed_process[i])<<"\t"<<get<5>(completed_process[i])<<endl;
	}	
    
}
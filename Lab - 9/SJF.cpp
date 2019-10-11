#include<bits/stdc++.h>

using namespace std;

vector<int> cpu_queue,Process_queue;

bool byat(const tuple<int,int,int,int,int,int>& a,const tuple<int,int,int,int,int,int>& b){
     return (get<1>(a) < get<1>(b)); 
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
    int CPU_time=0;
    vector<tuple<int,int,int,int,int,int>> arreved_process;
    while(true){
        if(min_element())
    }

    cout<<endl<<"Pid\tAT\tBT\tCT\tTAT\tWT"<<endl;
	for(int i=0; i<n; i++){
		cout<<get<0>(Process[i])<<"\t"<<get<1>(Process[i])<<"\t"<<get<2>(Process[i])<<"\t"<<get<3>(Process[i])<<"\t"<<get<4>(Process[i])<<"\t"<<get<5>(Process[i])<<endl;
	}	
}
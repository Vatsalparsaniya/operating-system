#include<bits/stdc++.h>
#define N 10
using namespace std;

string processid[N] = {"p1","p2","p3","p4","p5","p6","p7","p8","p9","p10"};
int arrival_time[N] = {1 , 4 ,5 ,2 ,5 ,3 ,0 ,5, 7, 4};
int Burst_time[N] = {5 ,8 ,4 ,5 , 3 ,4 , 3, 5, 6, 8};
int completion_time[N];

void get_data(){
	cout<<"Enter Process_id , arrival_time , Burst_time (Saperated by space)"<<endl;
	for(int i=0;i<N;i++){
		cout<<"For Process "<<i+1<<" : "<<endl;
		cin>>processid[i];
		cin>>arrival_time[i];
		cin>>Burst_time[i];
	}
}


void print_data(){
	cout<<"|"<<setw(10)<<"Process ID"<<"|"<< setw(20)<<"arrival_time"<<"|"<<setw(20)<<"Burst_time  |"<<endl;
	for(int i=0;i<N;i++){
		cout<<"|"<<setw(10)<<processid[i]<<"|"<< setw(20)<<arrival_time[i]<<"|"<<setw(20)<<Burst_time[i]<<"|"<<endl;
	}
}

void get_completion_time(){
	int time = 0;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-i-1;j++){
			if(arrival_time[j+1] < arrival_time[j]){
				swap(arrival_time[j], arrival_time[j+1]);
				swap(processid[j], processid[j+1]);
				swap(Burst_time[j], Burst_time[j+1]);	
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(i==0) completion_time[i] = Burst_time[i];
		else if(0		
	}
}

int main(){
	//get_data();
	print_data();
	get_completion_time();
	print_data();
}

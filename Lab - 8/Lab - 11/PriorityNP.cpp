#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
	cout<<"Enter number of processes : ";cin>>n;

    int AT[n],BT[n],CT[n],TAT[n],WT[n],P[n];
	int totalBT = 0,minATi=0;

	cout<<"\nEnter Details of the processes : \n";
    
	for(int i=0;i<n;i++){
        cout<<"Enter Arrival time of process("<<i<<") : ";cin>>AT[i];
        cout<<"Enter Brust time of process("<<i<<") : ";cin>>BT[i];
        cout<<"Enter Priority of the process("<<i<<") : ";cin>>P[i];

		totalBT += BT[i];

		if(AT[i]<AT[minATi]){
            minATi = i;
       	}else if(AT[i]==AT[minATi] && P[i]>P[minATi]){
			minATi = i;
		}

        cout<<"\n";
    }

    int visited[n];memset(visited,0,sizeof(visited));
	int ES[n];	
	visited[minATi] = 1;ES[0] = minATi;
	int lastTime = AT[minATi] + BT[minATi];
	CT[minATi] = AT[minATi] + BT[minATi];

    for(int i=1;i<n;i++){
		int mini = -1;
		for(int j=0;j<n;j++){
			if(visited[j]==0 && AT[j]<=lastTime){
				if(mini==-1){
					mini = j;
				}
				else if(P[j]>P[mini]){
					mini = j;
				}
			}
		}
		if(mini==-1){
			for(int j=0;j<n;j++){
				if(visited[j]==0){
					if(mini==-1){
						mini = j;
					}
					else if(AT[mini]>AT[j]){
						mini = j;
					}
				}
			}
		}
		ES[i] = mini;
		CT[mini] = max(AT[mini],lastTime) + BT[mini];
		lastTime = CT[mini];
		visited[mini] = 1;
	}
	
	cout<<"Execution Seq : \n";
	for(int i=0;i<n;i++){
		cout<<ES[i]<<" ";
	}cout<<"\n";

	double averageTAT = 0;
	for(int i=0;i<n;i++){
		TAT[i] = CT[i] - AT[i];
		averageTAT += (double)TAT[i];
	}averageTAT /= (double)n;

    double averageWT = 0;
	for(int i=0;i<n;i++){
		WT[i] = TAT[i] - BT[i];
        averageWT += (double)WT[i];
	}averageWT /= (double)n;

	cout<<"\nPriority Scheduling NP : \n";
    cout<<"P_id\tPr\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t"<<P[i]<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<"\n";
    }

    cout<<"\nAverage Waiting time : "<<averageWT<<"\n";
    cout<<"\nAverage Turn around time: "<<averageTAT<<"\n";

return 0;
}
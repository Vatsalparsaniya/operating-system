#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
	cout<<"Enter number of processes : ";cin>>n;

    int AT[n],BT[n],CT[n],TAT[n],WT[n],P[n],ABT[n];
	int totalBT = 0,minATi=0;

	cout<<"\nEnter Details of the processes : \n";
    
	for(int i=0;i<n;i++){
        cout<<"Enter Arrival time of process("<<i<<") : ";cin>>AT[i];
        cout<<"Enter Brust time of process("<<i<<") : ";cin>>BT[i];
        cout<<"Enter Priority of the process("<<i<<") : ";cin>>P[i];

        ABT[i] = BT[i];
		totalBT += BT[i];

		if(AT[i]<AT[minATi]){
            minATi = i;
       	}else if(AT[i]==AT[minATi] && P[i]>P[minATi]){
			minATi = i;
		}

        cout<<"\n";
    }

    int lastT = AT[minATi],nextP = minATi;
	while(totalBT){
		cout<<nextP<<" ";
		
		lastT = max(AT[nextP],lastT);
		BT[nextP] -= 1;
		totalBT -= 1;
		
		if(!BT[nextP]){
			CT[nextP] = lastT + 1;
		}
		lastT += 1;
		
		int maxP = -1,maxPi = -1;		
		for(int i = 0;i<n;i++){
			if(BT[i] && AT[i]<=lastT){
				if(maxP<P[i]){
					maxP = P[i];
					maxPi = i;
				}
			}
		}
		if(maxPi==-1){
			minATi = -1;
			for(int i=0;i<n;i++){
				if(BT[i] && AT[i]>lastT){
					if(minATi==-1){
						minATi = i;
					}else if(AT[i]<AT[minATi]){
						minATi = i;
					}else if(AT[i]==AT[minATi] && P[i]>P[minATi]){
						minATi = i;
					}
				}
			}
			nextP = minATi;
		}else{
			nextP = maxPi;
		}
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

	cout<<"\nPriority Scheduling P : \n";
    cout<<"P_id\tPriority\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t"<<P[i]<<"\t"<<AT[i]<<"\t"<<ABT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<"\n";
    }

    cout<<"\nAverage Waiting time : "<<averageWT<<"\n";
    cout<<"\nAverage Turn around time: "<<averageTAT<<"\n";

return 0;
}
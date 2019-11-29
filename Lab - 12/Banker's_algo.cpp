#include <bits/stdc++.h>
using namespace std;

bool logic(int availabel[],int r_need[],int R){
    bool flag = true;
    for(int i=0;i<R;i++){
        if(availabel[i]-r_need[i]<0){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    cout<<"Enter No of Processes :";
    int N;
    cin>>N;
    cout<<"Enter No resource :";
    int R;
    cin>>R;
    int Allocation_matrix[N][R]={0};
    int Max_need[N][R]={0};
    int availabel[R] = {0};
    int remaining_need[N][R] = {0};
    bool process_flag[N];
    for(int i=0;i<N;i++){
        cout<<"Enter Allocation for "<<R<<" Resource :";
        for(int j=0;j<R;j++){
            cin>>Allocation_matrix[i][j];
        }
        cout<<"Enter Max Availabel for "<<R<<" Resource :";
        for(int j=0;j<R;j++){
            cin>>Max_need[i][j];
        }
    }
    cout<<"Enter Availablity for "<<R<<" Resource :";
    for(int i=0;i<R;i++){
        cin>>availabel[i];
    }
    // count Remaining Need
    for(int i=0;i<N;i++){
        for(int j=0;j<R;j++){
            remaining_need[i][j] = Max_need[i][j] - Allocation_matrix[i][j]; 
        }
    }
    int Process_completed = 0;
    int process_index = 0; // because we are starting frm zero
    while(true){
        // for Each process we have to do something 
        if(Process_completed == N){
            break;
        }
        if(logic(availabel,remaining_need[process_index],R) && !process_flag[process_index]){
            int current_process = process_index;
            cout<<"P"<<current_process+1<<" ";
            for(int j=0;j<R;j++){
                availabel[j] +=  Allocation_matrix[current_process][j];  
            }
            
            Process_completed += 1;
            process_flag[current_process] = true;
            process_index = (process_index+1)%N;
        }else{
            process_index = (process_index+1)%N;
        }
        
    }
    return 0;

}
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <array>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <ctype.h>
using namespace std;
using std::begin;

struct Job{
	int num; // 編號 
	int process;
	int deadline;
};

bool compare_process(Job a, Job b){ // 小到大  
	if(a.process < b.process)
		return 1;
	else 
		return 0;
};

bool compare_deadline(Job a, Job b){ // 小到大 
	if(a.deadline < b.deadline)
		return 1;
	else 
		return 0;
};


inline bool operator<(const Job &lhs, const Job &rhs)
{
	return lhs.process < rhs.process;
}

void Greedy(Job d_arr[], int n){
		int end_time=0,profit=0;
	int k=0;

	priority_queue <Job> pq;
	Job ans[n];
	Job j; 

	// 開始排
	for(int i=1; i<=n; i++){ // deadline 小的先排 
		end_time = end_time + d_arr[i].process;
		
		pq.push(d_arr[i]);
		
		if(end_time<=d_arr[i].deadline){ // 可以放 
			//schdule[k] = d_arr[i].num;
			profit++;
		}
		if(end_time>d_arr[i].deadline){ // 不能放 
			j = pq.top();
			pq.pop();
			end_time = end_time - j.process; // 不要減錯人了 
		}
	} 
	
	for(int i=0; i<profit; i++){
		ans[i] = pq.top();
		pq.pop();
	}
	
	std::sort(ans,ans+profit,compare_deadline); // 按照deadline由小到大排
	for(int i=0; i<profit; i++){
		cout << ans[i].num << " ";
	}
}

int main(){

	int n=0,p=0,d=0; 
	cin >> n;
	Job jobs[n+1], p_arr[n+1], d_arr[n+1];
	int schdule[n]; // 儲存排程
	 
	for(int i=0; i<n; i++){ //初始歸零 
		schdule[i] = 0;
	}
	
	for(int j=1; j<=n; j++){
		cin >> p >> d;
		if(1<=p && p <= 100000 && 1<=d && d <= 100000){
			jobs[j].process = p;
			jobs[j].deadline = d;
			jobs[j].num = j;
		}
	} 
	
	for(int i=1; i<=n; i++){ // copy
		d_arr[i].num  = jobs[i].num; 
		d_arr[i].process = jobs[i].process;
		d_arr[i].deadline = jobs[i].deadline;
	}
	
	std::sort(d_arr+1,d_arr+n+1,compare_deadline); // 按照deadline由小到大排
	
	Greedy(d_arr,n);
	
	return 0;	
}

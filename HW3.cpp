#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <bits/stdc++.h>
using std::string;
using namespace std;

struct store{
	long long value;
	string ans;
};

bool isOperator(char op){
	return (op == '+' || op == '*' || op == '-' );
}

long long max_exp(long long a, long long b, long long c, long long d){
	return std::max(std::max(std::max(a,b),c),d);
}

long long min_exp(long long a, long long b, long long c, long long d){
	return std::min(std::min(std::min(a,b),c),d);
}

void print(string exp)
{
	vector<long long> num;
	vector<char> opr;
	string tmp = "";

	for (int i=0; i<exp.length(); i++)
	{
		if (isOperator(exp[i]))
		{
			opr.push_back(exp[i]);
			num.push_back(atoi(tmp.c_str()));
			tmp = "";
		}
		else
		{
			tmp += exp[i];
		}
	}

	num.push_back(atoi(tmp.c_str()));

	int len = num.size();
	store min[len][len];
	store max[len][len];

	for (int i=0; i<len; i++){
		for (int j=0; j<len; j++){
			min[i][j].value = 0;
			max[i][j].value = 0;
			if (i==j){
				min[i][j].value = max[i][j].value = num[i];
				max[i][j].ans= to_string(num[i]);
				min[i][j].ans= to_string(num[i]);
			}
		}
	}

	for (int L=2; L<=len; L++){
		for (int i=0; i<len-L+1; i++){
			int j=i+L-1;
			for (int k=i; k<j; k++){
				long long minTmp = 0, maxTmp = 0;
				long long a=0, b=0, c=0, d=0;
				string op="", tmp_minAns="", tmp_maxAns="";
				
				if(opr[k] == '+'){
					
					a = min[i][k].value + min[k + 1][j].value;
					b = max[i][k].value + max[k + 1][j].value;
					c = max[i][k].value + min[k + 1][j].value;
					d = min[i][k].value + max[k + 1][j].value;
					
					minTmp = std::min(std::min(std::min(a,b),c),d);
					maxTmp = std::max(std::max(std::max(a,b),c),d);
					op="+";
					
					if(min_exp(a,b,c,d)==a) tmp_minAns = "(" + min[i][k].ans + op + min[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==b) tmp_minAns = "(" + max[i][k].ans + op + max[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==c) tmp_minAns = "(" + max[i][k].ans + op + min[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==d) tmp_minAns = "(" + min[i][k].ans + op + max[k + 1][j].ans + ")";
					
					if(max_exp(a,b,c,d)==a) tmp_maxAns = "(" + min[i][k].ans + op + min[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==b) tmp_maxAns = "(" + max[i][k].ans + op + max[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==c) tmp_maxAns = "(" + max[i][k].ans + op + min[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==d) tmp_maxAns = "(" + min[i][k].ans + op + max[k + 1][j].ans + ")";
				}
				
				if(opr[k] == '-'){
				
					a = min[i][k].value - min[k + 1][j].value;
					b = max[i][k].value - max[k + 1][j].value;
					c = max[i][k].value - min[k + 1][j].value;
					d = min[i][k].value - max[k + 1][j].value;
					
					minTmp = std::min(std::min(std::min(a,b),c),d);
					maxTmp = std::max(std::max(std::max(a,b),c),d);
					op="-";
					
					if(min_exp(a,b,c,d)==a) tmp_minAns = "(" + min[i][k].ans + op + min[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==b) tmp_minAns = "(" + max[i][k].ans + op + max[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==c) tmp_minAns = "(" + max[i][k].ans + op + min[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==d) tmp_minAns = "(" + min[i][k].ans + op + max[k + 1][j].ans + ")";
					
					if(max_exp(a,b,c,d)==a) tmp_maxAns = "(" + min[i][k].ans + op + min[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==b) tmp_maxAns = "(" + max[i][k].ans + op + max[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==c) tmp_maxAns = "(" + max[i][k].ans + op + min[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==d) tmp_maxAns = "(" + min[i][k].ans + op + max[k + 1][j].ans + ")";
				}

				if(opr[k] == '*'){
				
					a = min[i][k].value * min[k + 1][j].value;
					b = max[i][k].value * max[k + 1][j].value;
					c = max[i][k].value * min[k + 1][j].value;
					d = min[i][k].value * max[k + 1][j].value;
					
					minTmp = std::min(std::min(std::min(a,b),c),d);
					maxTmp = std::max(std::max(std::max(a,b),c),d);
					op="*";
					
					if(min_exp(a,b,c,d)==a) tmp_minAns = "(" + min[i][k].ans + op + min[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==b) tmp_minAns = "(" + max[i][k].ans + op + max[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==c) tmp_minAns = "(" + max[i][k].ans + op + min[k + 1][j].ans + ")";
					if(min_exp(a,b,c,d)==d) tmp_minAns = "(" + min[i][k].ans + op + max[k + 1][j].ans + ")";
					
					if(max_exp(a,b,c,d)==a) tmp_maxAns = "(" + min[i][k].ans + op + min[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==b) tmp_maxAns = "(" + max[i][k].ans + op + max[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==c) tmp_maxAns = "(" + max[i][k].ans + op + min[k + 1][j].ans + ")";
					if(max_exp(a,b,c,d)==d) tmp_maxAns = "(" + min[i][k].ans + op + max[k + 1][j].ans + ")";
				}

				if (minTmp < min[i][j].value || (minTmp > min[i][j].value && min[i][j].value == 0)){
					min[i][j].value = minTmp;
					min[i][j].ans = tmp_minAns;
					tmp_minAns = " ";
				}
					
				if (maxTmp > max[i][j].value || (maxTmp < max[i][j].value && max[i][j].value == 0)){
					max[i][j].value = maxTmp;
					max[i][j].ans = tmp_maxAns;
					tmp_maxAns = " ";
				}
			}
		
		}
	}

	cout << max[0][len - 1].value << "\n" << max[0][len - 1].ans;
}


int main(){

	string expression; 
	cin >> expression;

	print(expression);
	return 0;
}

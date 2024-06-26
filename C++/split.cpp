#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){
	
	vector<string> ret;
	long long pos = 0;
	string token = "";
	
	while((pos = input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	
	return ret;
}



int main(){
	
	string str = "apple banana cherry kiwi melon watermelon strawberry mongo", d = " ";
	vector<string> res = split(str, d);
	
	for(string x : res) cout << x << "\n";
	
	return 0;
}

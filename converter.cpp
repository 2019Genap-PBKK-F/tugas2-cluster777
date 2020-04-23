#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream infile;
	ofstream outfile;
	infile.open("converted.csv");
	outfile.open("sqlconv.txt");
	char f;
	while(infile>>noskipws>>f){
		if(f=='\n'){
			outfile<<"\")\nvalues(\"";
		}
		else if(f==';'){
			outfile<<"\",\"";
		}
		else if(f=='\"'){
			while(infile>>noskipws>>f){
				if(f=='\n')continue;
				if(f!='\"')outfile<<f;
				else break;
			}
		}
		else outfile<<f;
	}
}

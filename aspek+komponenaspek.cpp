#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream infile;
	ofstream outfile;
	vector<string>aspek;
	set<string>aspeks;

	infile.open("converted.csv");
	outfile.open("aspeks.txt");
	char f;
	int counter;
	string str="insert into aspek(aspek,komponen_aspek)values(\"";
	while(infile>>noskipws>>f){
		
		if(f==';')counter++;
		if(f==';' && counter==2){
			str+="\",\"";	
			continue;
		}
		if(f==';' && counter==3){
			str+="\")";
			if(!aspeks.count(str)){
				aspeks.insert(str);
				aspek.push_back(str);
			}	
			str="insert into aspek(aspek,komponen_aspek)values(\"";
		}
		if(f=='\"'){
			while(infile>>noskipws>>f){
				if(f=='\"')break;
			}
		}
		if(counter==1||counter==2)str+=f;
		if(f=='\n')counter=0;
		
	}
	
	
	for(int i=0;i<aspek.size();i++){
		
		outfile<<aspek[i]<<endl;
	}
	
}

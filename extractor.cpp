#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream infile;
	ofstream outfile;
	vector<string>pembilang;
	set<string>pembilangs;
	set<string>penyebuts;
	vector<string>penyebut;
	infile.open("converted.csv");
	outfile.open("listingpembpeny.txt");
	char f;
	int counter;
	string str="";
	while(infile>>noskipws>>f){
		if(f==';' && counter==5){
			if(!pembilangs.count(str)){
				pembilangs.insert(str);
				pembilang.push_back(str);
			}	
			str="";
		}
		if(f==';' && counter==6){
			if(!pembilangs.count(str)){
				pembilang.push_back(str);
				pembilangs.insert(str);
			}
			str="";
		}
		if(f==';')counter++;
		if(f=='\"'){
			while(infile>>noskipws>>f){
				if(f=='\"')break;
			}
		}
		if(counter==5||counter==6)str+=f;
		if(f=='\n')counter=0;
		
	}
	
	outfile<<"pembilang------------------------\n";
	for(int i=0;i<pembilang.size();i++){
		
		outfile<<"insert into datadasar(id,nama)("<<i<<",\""<<pembilang[i]<<"\")"<<endl;
	}

}

#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream infile;

	ifstream buruk;
	ofstream sip;
	vector<string>pembilang;
	set<string>pembilangs;
	set<string>penyebuts;
	vector<string>penyebut;
	infile.open("converted.csv");

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
	//pembilang list pembilang penyebut

	buruk.open("sqlconv.txt");
	sip.open("sipok.txt");
	counter=-1;
	
	while(buruk>>noskipws>>f){

		if(f=='\n'){
			sip<<f;
			
			counter=0;	
		}
		else if(f==','){
			sip<<f;
			counter++;
		}
		else if(f=='\"' && (counter==9||counter==10||counter==11)){
		
			string strf=";";
			while(buruk>>noskipws>>f){
				
				if(f=='\"')break;
				strf+=f;
			}

			for(int i=0;i<pembilang.size();i++){

				if(strf==pembilang[i]){
					sip<<i;
				}
			}
		}
		else if(f=='\"' &&( counter<10||counter>11)){
			sip<<f;
			
			while(buruk>>noskipws>>f){
				sip<<f;

				if(f=='\"')break;
			}	
		}
		
		else sip<<f;
		
	}
	//koma ke 10/11
	
}

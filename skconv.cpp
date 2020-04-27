#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream infile;
	ofstream outfile;
	infile.open("SatuanKerja.csv");
	outfile.open("skconv.txt");
	char f;
	int counter=0;
	while(infile>>noskipws>>f){
		if(f=='\n'){
			counter=0;
			outfile<<"\",Getdate(),Getdate(),Getdate())\ninsert into SatuanKerja(id,nama,email,id_induk_satker,id_ins_satker,create_date,last_update,expired_date)values(\"";
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

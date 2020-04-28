#include<bits/stdc++.h>
#include<string>

using namespace std;
string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}
int main(){
	ifstream infile;
	ofstream outfile;

	outfile.open("indikperid.txt");
	for(int i=1;i<=81;i++){
		outfile<<"insert into indikator_periode(id,id_master,id_periode,bobot)select "+itos(i)+","+itos(i)+",1,MI.default_bobot from masterindikator where id="+itos(i)<<endl;
	}
}

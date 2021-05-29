#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main(int argc, char *argv[]){
	fstream fileR;
	fstream fileW;
	string complex[2];
	float Re[2], Ima[2];
	string ans;
	
	fileR.open(argv[1], ios::in);
	fileW.open(argv[2], ios::out);
	if (!fileR){
		cout<<"cant read"<<endl;
		return(-1);
	}
	if (!fileW){
		cout<<"cant write"<<endl;
		return(-1);
	}
	
	int i=0; 
	int j=0; 
	int k=0;
	int startCount=0;
	int buf;
	while(getline(fileR, complex[i])){
		
		if (complex[i][0]=='-'){
			j++;
		}
		for (j;j<complex[i].size();j++){
			if (complex[i][j]=='-' || complex[i][j]=='+' ){
				Re[i]=stof(complex[i].substr(startCount, j+1-startCount));
				startCount=j;
			}
			if (complex[i][j]=='i'){
				Ima[i]=stof(complex[i].substr(startCount, j+1-startCount));
				startCount=j;
			}
		}
		i++;
		j=0;
		startCount=0;
	}

	//+
	if ((Ima[0]+Ima[1])>0)
		ans =to_string(Re[0]+Re[1])+'+'+to_string(Ima[0]+Ima[1])+'i';
	else
		ans =to_string(Re[0]+Re[1])+to_string(Ima[0]+Ima[1])+'i';
	fileW << ans <<endl;
	//-
	if ((Ima[0]-Ima[1])>0)
		ans =to_string(Re[0]-Re[1])+'+'+to_string(Ima[0]-Ima[1])+'i';
	else
	ans =to_string(Re[0]-Re[1])+to_string(Ima[0]-Ima[1])+'i';
	fileW << ans <<endl;
	//*
	if ((Re[0]*Ima[1]+Ima[0]*Re[1])>0)
		ans =to_string(Re[0]*Re[1]-Ima[0]*Ima[1])+'+'+to_string(Re[0]*Ima[1]+Ima[0]*Re[1])+'i';
	else
		ans =to_string(Re[0]*Re[1]-Ima[0]*Ima[1])+to_string(Re[0]*Ima[1]+Ima[0]*Re[1])+'i';
	fileW << ans <<endl;
	// /
	buf = Re[1]*Re[1]+Ima[1]*Ima[1];
	if ((Re[0]*Ima[1]-Ima[0]*Re[1])>0)
		ans =to_string((Re[0]*Re[1]+Ima[0]*Ima[1])/buf)+'+'+to_string((Re[0]*Ima[1]-Ima[0]*Re[1])/buf)+'i';
	else
		ans =to_string((Re[0]*Re[1]+Ima[0]*Ima[1])/buf)+to_string((Re[0]*Ima[1]-Ima[0]*Re[1])/buf)+'i';
	fileW << ans <<endl;
	return 0;
}
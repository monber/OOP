#include <iostream>
#include <fstream>
#include <string>
#include "lab1-1.h"

using namespace std;
using namespace Complex;

void ReadTextFile(char *argv,Cplex &a,Cplex &b);
Cplex ComplexOperation(Cplex a, Cplex b, char ope);
void PrintComplex(char *argv, Cplex *results);


int main(int argc, char *argv[]){
	Cplex a, b;
	ReadTextFile(argv[1], a,b);
	Cplex results[4];

	results[0]=ComplexOperation(a, b, '+');
	results[1]=ComplexOperation(a, b, '-');
	results[2]=ComplexOperation(a, b, '*');
	results[3]=ComplexOperation(a, b, '/');
	
	PrintComplex(argv[2], results);
	
	return 0;
}

void ReadTextFile(char *argv,Cplex &a,Cplex &b){
	fstream fileR;
	string complex;
	
	fileR.open(argv, ios::in);
	if (!fileR){
		cout<<"cant read"<<endl;
		exit(-1);
	}
	
	int i=0; 
	int j=0; 
	int k=0;
	int startCount=0;

	
	while(getline(fileR, complex, '\n')){
		if (complex[0]=='-'){
			j=1;
		}
		for (j;j<complex.size();j++){
			if (complex[j]=='-'  ){
				if (i==0)
					a.real=stod(complex.substr(startCount, j+1-startCount));
				else if (i==1)
					b.real=stod(complex.substr(startCount, j+1-startCount));
				startCount=j;
			}
			if (complex[j]=='+' ){
				if (i==0)
					a.real=stod(complex.substr(startCount, j-startCount));
				else if (i==1)
					b.real=stod(complex.substr(startCount, j-startCount));
				startCount=j+1;
			}
			if (complex[j]=='i'){
				if (i==0)
					a.image=stod(complex.substr(startCount, j-startCount));
				else if (i==1)
					b.image=stod(complex.substr(startCount, j-startCount));
			}
		}
		i++;
		j=0;
		startCount=0;
		
	}
	fileR.close();	
}

Cplex ComplexOperation(Cplex a, Cplex b, char ope){
	Cplex ret;
	switch(ope){
		case '+':
			ret.real=a.real+ b.real;
			ret.image=a.image+ b.image;
			break;
		case '-':
			ret.real=a.real- b.real;
			ret.image=a.image- b.image;
			break;
		case '*':
			ret.real=a.real* b.real- a.image*b.image;
			ret.image=a.real*b.image+ a.image*b.real;
			break;
		case '/':
			ret.real=(a.real* b.real+ a.image*b.image)/(b.real*b.real+b.image*b.image);
			ret.image=(-a.real*b.image+ a.image*b.real)/(b.real*b.real+b.image*b.image);
			break;
		default:
			break;
	}

	return ret;
}

void PrintComplex(char *argv, Cplex *results){
	fstream fileW;
	fileW.open(argv, ios::out);
	if (!fileW){
		cout<<"cant write"<<endl;
		exit(-1);
	}
	int i=0;
	for (i; i<4; i++ ){
		if (results[i].image>=0)
			fileW << results[i].real <<'+'<< results[i].image <<'i'<< endl;
		else
			fileW << results[i].real << results[i].image << 'i'<<endl;
	}
	fileW.close();
}
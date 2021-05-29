const int MAX=1000;
typedef struct{
	char coeff[10];
	int power;
}Items
typedef struct{
	Items items[MAX];
	int num_items;
}Poly;

int main (int argc, char *argv[]){
	Poly eq;
	ReadTextFile(argv[1], eq);
	DifferentationPoly(eq);
	PrintComplex(argv[2], eq);
	return 0;
}
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
  

void encrypt(char msg[], int e, int n, int size){
    int i;
    double c;
    
    printf("\nEncrypted data: ");
    for( i = 0; i < size; i++){
    	c = pow(msg[i]-64, e);
    	c = fmod(c, n);
    	msg[i] = c;
	}
	displayChar(msg, size);
}

void decrypt(char msg[], int d, int n, int size){
    int i;
	double m; 
    
	printf("\nOriginal Message: ");
    for( i = 0; i < size; i++){
    	m = pow(msg[i], d);
    	msg[i] = fmod(m, n);
	}
	displayChar(msg, size);
}

void displayChar(char msg[], int size){
	int i;
	
	for(i = 0; i < size; i++){
		printf("%c", msg[i] + 64);
	}
}

//void getCapital(char msg[], int size){
//	int i;
//	
//	for(i = 0; i < size; i++){
//		msg[i] = toupper(msg[i]);
//	}
//}
int main()
{
	int p,q,n,e,z,d,size;
	char msg[] = "LOVE";
	
    p = 5;
    q = 7;
	n = p*q;
    e = 5;
    z = (p-1)*(q-1);
    size = strlen(msg);
    
//    getCapital(msg,size);
    for(d = z; fmod(((d*e)-1), z) != 0; d++){}
    
	encrypt(msg,e,n,size);
	decrypt(msg,e,n,size);
    return 0;
}

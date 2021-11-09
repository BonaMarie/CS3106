#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 1000
 

int prime(long int);
void getE(long int , long int*, long int *, long int p, long int q);
long int getD(long int, long  int t);
void encrypt(char *, long int *, long int *, long int *, long int n);
void decrypt(long int *,long int *, long int*, long int n,long int*);
 
void main() {
	long int p,q,n,t,flag,e[MAX],d[MAX],j,m[MAX],en[MAX],i;
	char msg[MAX];	
	 
	printf("\nEnter your first prime number: ");
	scanf("%d",&p);
 
	flag = prime(p);
	if(flag == 0) {
		printf("\nWRONG INPUT");
		getch();
		exit(1);
	}
 
	printf("\nEnter your second prime number: "); 
	scanf("%d",&q);
 
	flag = prime(q);
	if(flag == 0 || p == q) {
 		printf("\nWRONG INPUT");
		getch();
		exit(1);
	}
 
	printf("\nEnter word to be encrypted: ");
	fflush(stdin);
	scanf("%s",msg);
 
	for (i = 0 ; msg[i] != 0;i++){
		m[i] = msg[i];
		n = p * q;
		t = (p-1)*(q-1);
	}

	printf("\n\n-----------------------------------------------\n");
	getE(t, e, d, p, q);	 
	encrypt(msg, e, en, m,n);
	decrypt(e, en, m,n,d);
	printf("\n\n-----------------------------------------------");
 
}
 
int prime(long int pr) {
 
	int i,j, retVal = 1;
 
	j = sqrt(pr);
 
	for (i = 2 ; i <= j ; i++) {
		if(pr % i == 0){
			retVal = 0;
		    break;
		}
	}
 
	return retVal;
 
}
 
void getE(long int t, long int e[], long int d[], long int p, long int q) {
 
	int k = 0,i,flag;
 
	for (i = 2 ; i < t ; i++) {
 		if(t % i == 0)
		    continue;
 
		flag = prime(i);
		if(flag == 1 && i != p && i != q) {
			e[k] = i;
			flag = getD(e[k], t);
			if(flag > 0) {
				d[k] = flag;
				k++;
			}
			if(k == 99)
			    break;
		}
	}
}
 
long int getD(long int x,long int t) {
 
	long int k = 1;
 
	while(1) { 
		k = k + t;
		if(k % x == 0)
		    return(k/x);
	}
}
 
void encrypt(char msg[], long int e[], long int en[], long int m[], long int n) {
 
	long int pt, ct, key = e[0], k, len, temp[100];
 
	int i = 0, j;
	len = strlen(msg);
 
	while( i != len) {
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (j = 0 ; j < key ; j++) {
			k *= pt;
			k %= n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}

	en[i] =- 1; 

	printf("\nEncrypted Message: ");
	for (i = 0 ; en[i] != -1 ; i++){
		printf("%c",en[i]);
	}
	
 
}
 
void decrypt(long int e[], long int en[], long int m[], long int n, long int d[]) {
 
	long int pt, ct, key = d[0], k, temp[100];
 
	int i = 0,j;
 
	while(en[i] != -1) {
 		ct = temp[i];
		k = 1;
 
		for (j = 0 ; j < key ; j++) {
			k *= ct;
			k %= n;
		}

		pt = k + 96; 
		m[i] = pt;
		i++;
	}
 
	m[i] = -1;
	printf("\nDecrypted Message: ");
	for (i = 0 ; m[i] != -1 ; i++){
		printf("%c",m[i]);
	}
	
}
 

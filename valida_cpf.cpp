#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char cpf[12];
	int cont, let[11], contB=11, soma1, soma2=0, num1,num2=0;
	char tmp[2];
	float res1,res2;
		
	printf("Insira seu CPF:");
	gets(cpf);
	fflush(stdin);
	
	for ( cont = 0 ; cont < 11 ; cont++ ) {
		tmp[0] = cpf[cont];
		let[cont] = atoi(tmp);
	}
	
	for ( cont = 0 ; cont <= 8 ; cont++ ) { //calculo do 9 digito
		contB--;
		soma1 = soma1 + let[cont] * contB; 
	}
	
	res1 = soma1 % 11;
	num1 = 11 - res1;
	if ( num1 >= 10 ) {
		num1 = 0;
	}
	
	contB = 12;
	
	for ( cont = 0 ; cont <= 9 ; cont++ ) {
		contB--;
		soma2 = soma2 + let[cont] * contB; 
	}
	
	res2 = soma2 % 11;
	num2 = 11 - res2;
	if ( num2 >= 10 ) {
		num2 = 0;
	}
	
	if ( num2 != let[10] ) {
		printf("CPF inválido \n");
	} else {
		printf("CPF válido \n");
	}
	
	system("pause");
	return 0;
}


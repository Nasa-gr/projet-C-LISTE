#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "l1.h"
#include "l1.c"
int main(){
	
	FILE *source = NULL;
	FILE *copie = NULL;
	FILE *absent = NULL;
	FILE *personnel = NULL;
	FILE *utilise = NULL;
	infoPC L1[75 ];
	
	int choix_utilisation;
	choix_utilisation = choixD_utilisation();	
	traitementPremierInstruction( choix_utilisation ,source,copie ,absent ,personnel ,utilise , L1);
	
	return 0;
}

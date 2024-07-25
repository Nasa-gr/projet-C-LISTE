#include "l1.h"
int  choixD_utilisation(){
	int choix;
	printf("     ENVOYER DES INSTRUCTIONS\n");
	printf("\t1.Faire le presence\n\t2.Utilisation du programme\n\t3.Quitter\n");
	scanf("%d", &choix);
	return choix;
}
int Presentation(){
	int suitePresentation;
	printf("\t\t\t\t\t\tAIDE\n");
	printf("1)Pour cet programme, on l'utilise pour faire le presence de chaque eleve de la classe\n");
	printf("Pendant lequel vous ecrit l'un des 3 cas possible a chaque eleve que vous cherche son numero de classe.\n ");
	printf("Voici les 3 cas:\n\tOUI : pour les eleve qui va prendre un ordinateur.\n\tABS : pour les eleve qui est absent.\n\tPERSO : pour les eleve qui utilise son ordinateur personnel et qui est present.\n"); 
	printf("\n2)Pour quitter le programme,tape seulement   q   .\n");
	printf("\n\n\t1:Passer a la presence\n\t2:Voir la liste de presence\n\t0:Quiter\n");
	scanf("%d", &suitePresentation);
	return suitePresentation;
	}
void RemplirStructure(FILE *Source , infoPC *L1){
	int i = 1;
	while (i <= 75  && (fgets( L1[i].nom,100 , Source))){
		i++;
	}
}
void traitementPremierInstruction(int choix_utilisation ,FILE *Source,FILE *Copie ,FILE *Absent ,FILE *Personnel ,FILE *Utilise , infoPC *L1){
		/***************************************************************************/
		switch (choix_utilisation){
		case 1:

			Source = fopen("/home/fifaliana/listeL1.txt", "r");
			Copie = fopen("/home/fifaliana/presence.txt", "a");
			Absent = fopen("/home/fifaliana/abs", "a");
			Personnel = fopen("/home/fifaliana/perso", "a");
			Utilise = fopen("/home/fifaliana/oui", "a");
			
			RemplirStructure(Source , L1);
			EnleveRetourLigne(L1);

			EcrireDate(Copie , Absent ,Personnel ,Utilise);
			
			PresencePC(Copie , Absent ,Personnel ,Utilise , L1);
			
			fclose(Source);
			fclose(Copie);
			fclose(Absent);
			fclose(Personnel);
			fclose(Utilise);

			break;
		
		case 2:
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			switch (Presentation()){
			case 1:
				Source = fopen("/home/fifaliana/listeL1.txt", "r");
				Copie = fopen("/home/fifaliana/presence.txt", "a");
				Absent = fopen("/home/fifaliana/abs", "a");
				Personnel = fopen("/home/fifaliana/perso", "a");
				Utilise = fopen("/home/fifaliana/oui", "a");
				
				RemplirStructure(Source , L1);
				EnleveRetourLigne(L1);

				EcrireDate(Copie , Absent ,Personnel ,Utilise);
				
				PresencePC(Copie , Absent ,Personnel ,Utilise , L1);
				
				fclose(Source);
				fclose(Copie);
				fclose(Absent);
				fclose(Personnel);
				fclose(Utilise);

			break;
		case 2:
		int suite2;
			Source = fopen("/home/fifaliana/listeL1.txt", "r");
			
		int i = 1;
			while (i <= 75  && (fgets( L1[i].nom,100 , Source))){
				printf("%d %s",i, L1[i].nom);
				i++;
		}
				fclose(Source);
			printf("\n\n\tEnvoyer  des instructions:\n\t\t1.Passer a la presence\n\t\t0.Quitter\n");
			scanf("%d", &suite2);
					switch(suite2){
						case 1:
							Source = fopen("/home/fifaliana/listeL1.txt", "r");
							Copie = fopen("/home/fifaliana/presence.txt", "a");
							Absent = fopen("/home/fifaliana/abs", "a");
							Personnel = fopen("/home/fifaliana/perso", "a");
							Utilise = fopen("/home/fifaliana/oui", "a");
							
							RemplirStructure(Source , L1);
							EnleveRetourLigne(L1);

							EcrireDate(Copie , Absent ,Personnel ,Utilise);
							
							PresencePC(Copie , Absent ,Personnel ,Utilise , L1);
							
							fclose(Source);
							fclose(Copie);
							fclose(Absent);
							fclose(Personnel);
							fclose(Utilise);

						break;
						case 0:
							exit(1);
							break;
						
						
						}
			break;
		case 0:
				exit(1);
				break;
		default :
				printf("Erreur\n");
				exit(1);
			break;
			}
			break;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 3:
				exit(1);
			break;
		default :
			printf("Erreur \n");
			exit(1);
	}
	/***************************************************************************/
}
void EcrireDate(FILE *Copie ,FILE *Absent ,FILE *Personnel ,FILE *Utilise){
	fprintf(Copie , "\t\tDate du %s\n", __DATE__);
	fprintf(Absent , "\t\tDate du %s\n", __DATE__);
	fprintf(Personnel , "\t\tDate du %s\n", __DATE__);
	fprintf(Utilise , "\t\tDate du %s\n", __DATE__);
}
void PresencePC(FILE *Copie ,FILE *Absent ,FILE *Personnel ,FILE *Utilise , infoPC *L1){
		int i = 0 ;
		int numero = 0;
		printf("\tPRESENCE %s\n", __DATE__);
		
	while (i <= nombre_eleve  ){
		printf("Eleve numero : ");
		scanf("%d", &numero);
		if(numero == 0){
			exit(1);
		}
		printf("%s\t",  L1[numero].nom);
		scanf("%s", L1[i].choix);
		
		fprintf(Copie , "%s",L1[numero].nom ) ;
			for(int e = (strlen(L1[numero].nom )); e < 55 ; e++){
				fprintf(Copie , " ");
				}
		fprintf(Copie , "%d\t%s\t%s\t%s\n" ,  numero, L1[i].choix,__DATE__,__TIME__ );
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if ((strcmp(L1[i].choix , "OUI")) == 0){
			fprintf(Utilise , "%s", L1[numero].nom ) ;
			for(int e = (strlen(L1[numero].nom )); e < 55 ; e++){
				fprintf(Utilise , " ");
				}
			fprintf(Utilise , "%d\t%s\t%s\t%s\n" ,  numero, L1[i].choix,__DATE__,__TIME__ );
			}
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if ((strcmp(L1[i].choix , "PERSO")) == 0){
			fprintf(Personnel , "%s",L1[numero].nom ) ;
			for(int e = (strlen(L1[numero].nom )); e < 55 ; e++){
				fprintf(Personnel  , " ");
				}
			fprintf(Personnel  , "%d\t%s\t%s\t%s\n" ,  numero, L1[i].choix,__DATE__,__TIME__ );
		
		}
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		i++;
	}	
}

void EnleveRetourLigne(infoPC *L1){
	char *c = NULL;
	int i = 1;
	while (i <= 75 ){
		c = strchr (L1[i].nom , '\n');
		if(c){
			*c = '\0';
		}
		i++;
	}
}
void debug(){
	int d;
	while ((d = getchar()) != '\n' && d != EOF);
};

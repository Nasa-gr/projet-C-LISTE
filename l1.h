#ifndef L1_H
#define L1_H
#define nombre_eleve 75
typedef struct {
	char nom[100];
	char choix[7];
}infoPC;

int  choixD_utilisation();
void RemplirStructure(FILE *Source , infoPC *L1);
void EcrireDate(FILE *Copie ,FILE *Absent ,FILE *Personnel ,FILE *Utilise);
void PresencePC(FILE *Copie ,FILE *Absent ,FILE *Personnel ,FILE *Utilise , infoPC *L1  );
void EnleveRetourLigne(infoPC *L1);
int Presentation();
void traitementPremierInstruction(int choix_utilisation ,FILE *Source,FILE *Copie ,FILE *Absent ,FILE *Personnel ,FILE *Utilise , infoPC *L1);
#endif

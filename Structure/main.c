#include <stdio.h>
#include <stdlib.h>
#define n 3

struct student{
 	int number;
 	char name[25];
 	char surname[25];
 	float midtermGrade;
 	float finalGrade;
	double averageGrade;
 } ;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j;
    struct student *std=(struct student *)malloc(sizeof(struct student)*n);
    for(i=0; i<n; i++){
	       	printf("=> Student %d \n",i+1);
	     	printf(" Student no : ");
 	    	scanf("%d",&std[i].number);
     		printf(" Student name : ");
     		scanf("%s",std[i].name);
     		printf(" Student surname : ");
     		scanf("%s",std[i].surname);
     		printf(" Student midterm not : ");
     		scanf("%f",&std[i].midtermGrade);
     		printf(" Student final not : ");
     		scanf("%f",&std[i].finalGrade);
			std[i].averageGrade=(std[i].midtermGrade*0.4)+(std[i].finalGrade*0.6);
	} 
	printf("\n=>  Writing before sorting...\n");
    printf("\n********************************\n");
 	for(i=0; i<n; i++){
		printf(" Student no : %d\n",(std+i)->number);
		printf(" Student name : %s\n",std[i].name);
		printf(" Student surname : %s\n",std[i].surname);
		printf(" Student midterm not : %.2f\n",std[i].midtermGrade);
		printf(" Student final not : %.2f\n",std[i].finalGrade);
		printf(" Student average not : %.2f\n",std[i].averageGrade);
		printf("\n********************************\n");
	}
	struct student temp;
    //Siralama islemi
	for(i=0;i<n-1;i++){
     	for(j=0;j<n-1-i;j++){
             if(strcmp(std[j].name,std[j+1].name)>0){
	             temp=std[j];
	             std[j]=std[j+1];
	             std[j+1]=temp;
             } 
         }
     }
     printf("\n=> Writing after sorting...\n");
    printf("\n********************************\n");
 	for(i=0; i<n; i++){
		printf(" Student no : %d\n",std[i].number);
		printf(" Student name : %s\n",std[i].name);
		printf(" Student surname : %s\n",std[i].surname);
		printf(" Student midterm not : %.2f\n",std[i].midtermGrade);
		printf(" Student final not : %.2f\n",std[i].finalGrade);
		printf(" Student average not : %.2f\n",std[i].averageGrade);
		printf("\n********************************\n");
	}
	char searched[25];
	searching:
	printf("=> Enter name to search : ");
	scanf("%s",searched);
	for(i=0;i<n;i++){
		if(strcmp(searched,std[i].name)==0){
			printf("\n=> Searched name found.\n");
			//Aranan elemani ekrana yazdirma
			printf(" Student no : %d\n",std[i].number);
	    	printf(" Student name : %s\n",std[i].name);
	    	printf(" Student surname : %s\n",std[i].surname);
	    	printf(" Student midterm not : %.2f\n",std[i].midtermGrade);
	    	printf(" Student final not : %.2f\n",std[i].finalGrade);
			printf(" Student average not : %.2f\n",std[i].averageGrade); break;
	    	printf("\n********************************\n");
		}
		
		if(i==n-1)printf("=> Searched name not found...\n");
		
     }
	goto searching; 
	return 0;
}


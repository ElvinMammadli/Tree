#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 40
struct Node{
int kimlik;//kimlik numarasi
char AdSoyad[MAX];//Ad soyad char dizisi
int arkadas[MAX];//arkadaslarinin dizisi
 struct Node *sol;
struct Node *sag;
};
int elemanSayi(struct Node *tree);

int  contain (struct Node *tree ,int no);
struct Node * inserNewUser( struct Node *tree , int kimlikNo);
int travel (struct Node * tree);
struct Node * delete(struct Node * tree, int no);
struct Node* min(struct Node * tree);
struct Node* max(struct Node * tree);

struct Node* delete(struct Node* root, int no);

int main()
{

 FILE *fp;
   char birkelime[100];
   int sati=0;
   char *c='d';
   char soyad[34];
   char name[34];

  fp = fopen("input1.txt","r+");
    c = fgets(birkelime,80,fp);
        sscanf(birkelime,"%d" ",%s" " %s"  ",%s",&sati,name,soyad);

   while (c != NULL){
         printf("%s\n",soyad);

        c = fgets(birkelime,80,fp);
        sscanf(birkelime,"%d" ",%s" " %s"    ",%s",&sati,name,soyad);
   }
   fclose(fp);














  struct  Node * tree= NULL;
    tree=inserNewUser(tree,56);
    tree=inserNewUser(tree,26);
    tree=inserNewUser(tree,200);
  tree=inserNewUser(tree,23);
    tree=inserNewUser(tree,3);
    tree=inserNewUser(tree,45);
    tree=inserNewUser(tree,543);
    tree=inserNewUser(tree,43);
    tree=inserNewUser(tree,1);
    tree=inserNewUser(tree,17);
        tree=inserNewUser(tree,543);

      contain ( tree,17);
       contain ( tree,12);
        printf("%d\n",elemanSayi(tree));



   // contain(tree , 45);
  // printf("%d minimum deger",min(tree)->kimlik);
  // printf("%d max deger",max(tree)->kimlik);



      //tree=delete(tree,200);

   printf("\n");
   printf("\n");

  travel(tree);



    return 0;
}

int elemanSayi(struct Node *tree){
    static int c=0;
    if(tree==NULL){
        return c;
    }
        elemanSayi(tree->sol);
        elemanSayi(tree->sag);
        c++;

}

int contain (struct Node *tree ,int no){
if(tree==NULL){
        return 1;}
        contain(tree->sol,no);
            if(tree->kimlik==no){
            printf("Var");
            }


        contain(tree->sag,no);


}





struct Node * inserNewUser( struct Node *tree , int kimlikNo){
    if(tree==NULL){
      struct Node *yeni =  (struct Node *)malloc(sizeof(struct Node));
      yeni->kimlik=kimlikNo;
        yeni->sag=NULL;
        yeni->sol=NULL;
        return yeni;
    }
  if((tree->kimlik)<kimlikNo){
            tree->sag = inserNewUser(tree->sag,kimlikNo);
            return tree;
        }
       tree->sol=inserNewUser(tree->sol,kimlikNo);
             return tree;
}


int travel (struct Node * tree){
    if(tree==NULL){
        return 1;
    }
        travel(tree->sol);
        printf("%d   ",tree->kimlik);
        travel(tree->sag);
}

struct Node * min(struct Node*tree){
 while(tree->sol!=NULL){
    tree =tree->sol;
}
    return tree;
}

struct Node* max(struct Node * tree){
     while(tree->sag!=NULL){
        tree =tree->sag;
     }
   return tree;
}



struct Node * delete(struct Node * tree, int no){
   struct Node * tmp;
    if(tree==NULL){
        return NULL;
    }
    if((tree->kimlik)==no){
            if((tree->sol==NULL)&&(tree->sag==NULL)){
                return NULL;
            }
                    if(tree->sag!=NULL){

                tmp=min(tree->sag);

                tree->kimlik=tmp->kimlik;
                int i=0;
                int j=0;

                for(i=0;i<MAX;i++){
                    int b=tree->arkadas[i];
                    tmp->arkadas[i]=b;
                }

                strcpy(tree->AdSoyad,tmp->AdSoyad);

                tree->sag=delete(tree->sag,min(tree->sag)->kimlik);

                return tree;
            }
        tmp=max(tree->sol);
                tree->sag=tmp->sag;
                int i=0;
                int j=0;
                 for(i=0;i<MAX;i++){
                    int b=tree->arkadas[i];
                    tmp->arkadas[i]=b;
                }
                strcpy(tree->AdSoyad,tmp->AdSoyad);


        tree->sol=delete(tree->sol,max(tree->sol)->kimlik);
                        tree=tmp;

        return tree;
    }
    if(tree->kimlik<no){
        tree->sag=delete(tree->sag,no);
        return tree;
    }
    tree->sol=delete(tree->sol,no);
    return tree;

}




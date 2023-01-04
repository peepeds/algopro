#include <stdio.h>
#include <string.h>

struct revolusi{
    char planet[100];
    double waktu ;
} r[2] ;

struct gravitasi{
    char planet[100];
    double percepatan;
} g[2] ;
int main(){
    FILE *fp1 ; 
    FILE *fp2 ; 
    FILE *fp ; 
    int stat1 =0, stat2=0,stats , i, p;
    double umur , beratbadan;
    double masa , umur1;
    double beratBadan , usia ;
    char s[100] ,s1[100];

    fp1 = fopen("gravitasi planet.txt","r");
    fp2 = fopen("revolusi planet.txt","r");
    stat1 = ferror(fp1);
    stat2 = ferror(fp2);
    if(stat1 !=0){
        printf("Terjadi error dalam membuka file gravitasi planet.txt\n");
    } 
    if(stat2 !=0){ 
        printf("Terjadi error dalam membuka file revolsi planet.txt\n");
    }
    printf("Kamu tinggal di planet apa ?\n>>");
    scanf("%s",s);
    printf("Kamu ingin tinggal di planet apa ?\n>>");
    scanf("%s",s1);
    printf("Berapa berat badanmu ?\n>>");
    scanf("%lf",&beratbadan);
    printf("Berapa umur mu sekarang ?\n>>");
    scanf("%lf",&umur);
    p = strlen(s);

    for(i=0 ; i < p ;i++){
        if(s[i]>= 65 && s[i]<= 90){
            s[i]+= 32 ;
        }
    }
    while(fscanf(fp1,"%s %lf",g[0].planet,&g[0].percepatan)!=EOF){
        if(strcmp(g[0].planet,s)==0){
            break ;
        }
    }
    while(fscanf(fp2,"%s %lf",r[0].planet,&r[0].waktu)!=EOF){
        if(strcmp(r[0].planet,s)==0){
            break ;
        }
    }
   
    umur1 = umur /r[0].waktu;
    masa = beratbadan /g[0].percepatan; 
    printf("%lf ",masa);

    while(fscanf(fp1,"%s %lf",g[1].planet,&g[1].percepatan)!=EOF){
        if(strcmp(g[1].planet,s1)==0){
            break ;
        }
    }
    while(fscanf(fp2,"%s %lf",r[1].planet,&r[1].waktu)!=EOF){
        if(strcmp(r[1].planet,s1)==0){
            break ;
        }
    }
    beratBadan = masa* g[1].percepatan; 
    usia = umur1 * r[1].waktu  ;

    printf("berikut ini adalah data perolehan apabila kamu ingin tinggal di %s\n",s1);
    printf("usia mu sekarang akan berubah menjadi %lf\n",usia);
    printf("beratmu akan menjadi %lf\n",beratBadan);
   

}
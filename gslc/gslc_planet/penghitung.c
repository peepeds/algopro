#include <stdio.h>
#include <string.h>

struct revolusi{
    char planet[100];
    double waktu ; // waktu revolusi 
} r[2] ;  // r[0] untuk menangkap planet awal , r[1] untuk menangkap planet tujuan 

struct gravitasi{
    char planet[100];
    double percepatan; // percepatan gravitasi 
} g[2] ;
int main(){
    FILE *fp1 ; 
    FILE *fp2 ; 
 
    int stat1 =0, stat2=0,stats , i, p;
    double umur , beratAsal;
    double masa , umurAsal;
    double beratTujuan , umurTujuan ;
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
    scanf("%lf",&beratAsal);
    printf("Berapa umur mu sekarang ?\n>>");
    scanf("%lf",&umur);
    p = strlen(s);

    for(i=0 ; i < p ;i++){
        if(s[i]>= 65 && s[i]<= 90){
            s[i]+= 32 ;
        }
    }
    while(!feof(fp1)){
        fscanf(fp1,"%s %lf",g[0].planet,&g[0].percepatan);
         if(strcmp(g[0].planet,s)==0){
            break ;
        }
    }
  
   while(!feof(fp2)){
        fscanf(fp2,"%s %lf",r[0].planet,&r[0].waktu);
        if(strcmp(r[0].planet,s)==0){
            break ;
        }
   }
 
    umurAsal = umur /r[0].waktu;
    masa = beratAsal /g[0].percepatan; 
  

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
    beratTujuan = masa* g[1].percepatan; 
    umurTujuan = umurAsal * r[1].waktu  ;

    printf("berikut ini adalah data perolehan apabila kamu ingin tinggal di %s\n",s1);
    printf("usia mu sekarang akan berubah menjadi %lf Tahun.\n",umurTujuan);
    printf("beratmu akan menjadi %lf Joule.\n",beratTujuan);
    fclose(fp1), fclose(fp2);
   

}

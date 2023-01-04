#include <stdio.h>
#include <string.h>

int main(){

    FILE *fp ;
    char s[100];
    int i , len  , j = 1;
    double gravitasi , stats = 0;
 
    while (j <= 8){
        scanf("%s %lf",s,&gravitasi); 

        len = strlen(s);

        for(i=0 ; i < len ;i++){
            if(s[i]>= 65 && s[i]<= 90){
                s[i]+= 32 ;
            }
        }
        fp = fopen("planet.txt","a+");
        stats = ferror(fp);
        if(stats!=0){
            printf("Terjadi error pada proses pembacaan / penulisan file\n");
        }
        fprintf(fp ,"%s %lf\n",s ,gravitasi);
        j++;
    }
    stats = ferror(fp);
    if(stats==0){
        printf("File berhasil ditulis tanpa ada kesalahan.\n");
    }
    fclose(fp);
}
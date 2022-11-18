#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[10];
    char p[10];
    int mark;
} student;
int main() {
    student l[4];
    FILE*f;
    if((f=fopen("students.txt","r"))==0) {
        printf("error");
        exit(1);
    }
    printf("good:\n");
    for (int i=0; i < 4; i++)
    {
        fscanf(f,"%s%s%d",l[i].name,l[i].p,&l[i].mark);
        if (l[i].mark==4||l[i].mark==5)
        {
            if (strcmp(l[i].p,"man")==0)
            {
                printf("%s\n",l[i].name);
            }
        }
    }
    fclose(f);
    return 0;
}
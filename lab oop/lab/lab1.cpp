
#include <cstdio>
#include<iostream>

using namespace std;

int suma(char *sir)
{
    int num = 0;
    while(*sir && *sir>='0' && *sir<='9')
    {
      num=num*10+(*sir-'0');
      *sir++;
    }
    
    return num;
}

int main()
{
    FILE *file;
    char merge[1000];
    int sum = 0;

    file = fopen("in.txt", "r");

    if (file == NULL)
    {
        printf("NU MERGE TREABA");
        return 1;
    }

    while (fgets(merge, sizeof(merge), file))
        sum += suma(merge);

    fclose(file);
    printf("%d\n", sum); 

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare( const void *a, const void *b) {
   char *cuv1=*(char **)a;
   char *cuv2= *(char **)b;

    int lung1 = strlen(cuv1);
    int lung2 = strlen(cuv2);

    
    if (lung1 != lung2) {
        return lung2 - lung2; 
    } 
    else {
        
        return strcmp(cuv1, cuv2);
    }
}

int main() {
    char dialog[1000];
    scanf("%[^\n]", dialog);

    char *words[100];
    char *aux = strtok(dialog, " ");
    int numWords = 0;

    while (aux != NULL) {
        words[numWords++] = strdup(aux);
        aux = strtok(NULL, " ");
    }
    qsort(words, numWords, sizeof(*words), compare);

    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}



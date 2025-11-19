# Exercicis amb C - Apuntadors i structs

## Recull de preguntes d’examens i exercicis pràctics per a practicar amb C

**Quin serà el resultat d’aquesta execució?**

```c
#include<stdio.h>
int main(){
    int x = 5;
    int *p;
    p=&x;
    x++;
    printf("%d\n", *p);
}
```

El resultat serà 6.

**Completar el codi següent:**

```c
#include <stdio.h>
int main(){
    const char *s = "";
    char str[] = "Hola";
    s = str;
    while(*s)
        printf("%c", ???);
    return 0;
}
```

```c
#include <stdio.h>
int main(){
    const char *s = "";
    char str[] = "Hola";
    s = str;
    while(*s)
        printf("%c", *s);
    return 0;
}
```

**Analitzeu el següent codi i mostreu el contingut de la memòria durant l’execució del programa.**

```c
int main(){

    struct pokemon {
        int id;
        char* name;
    };

    struct pokemon p1 = {1, "Bulbasaur"};

    printf("Id: %d\n", p1.id);
    printf("Name: %s\n", p1.name);

}
```

El resultat a memòria durant l'execució serà:

|       |     |
| ----- | --- |
| @p1   | @id |
| @id   | 1   |
| @name | 'B' |
|       | 'u' |
|       | 'l' |
|       | 'b' |
|       | 'a' |
|       | 's' |
|       | 'a' |
|       | 'u' |
|       | 'r' |

**Analitza el codi següent i digues quin és el resultat de la seva execució.**

```c
int main(){
    char * s = "Hola";
    char * t = "Adéu";
    char * u;

    s = t;
    u = strdup(s);

    // Nota: strdup retorna un punter a una nova cadena de caràcters que és una còpia exacta de la cadena de caràcters     passada com a argument.

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    printf("u: %s\n", u);
}
```

El resultat serà:

s: Adéu
t: Adéu
u: Adéu

**Analitza el codi següent i digues quin és el resultat de la seva execució.**

```c
int main(){

    int n = 3;
    char* noms[n];
    char* nom = (char*)malloc(20*sizeof(char));

    for(int i = 0; i < n; i++){
        printf("Introdueix el teu nom: ");
        scanf("%s", nom);
        noms[i] = nom;
    }

    printf("Noms introduïts:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", noms[i]);
    }

    return 0;
}
```

Alba
Anna
Maria

El resultat serà:

Noms introduïts:
Maria
Maria
Maria

**Analitza el codi següent i digues quin és el resultat de la seva execució.**

```c
#include <stdio.h>
int main()
{
    int k = 5;
    int *p = &k;
    int **m = &p;
    **m = 6;
    printf("%d\n", k);
}
```

El resultat serà 6.

**Quina serà la sortida?**

```c
#include <stdio.h>
struct p
{
    int x;
    int y;
};

// sizeof(int) == 2 bytes?
// sizeof(int) == 4 bytes?

int main()
{
    struct p p1[] = {
        {1, 92},
        {3, 94},
        {5, 96}
    };

    int x = (sizeof(p1) / 3);

    printf("%ld\n",sizeof(int));

    if (x == 8)
        printf("true\n");
    else
        printf("false\n");
}
```

Si sizeof(int) == 2 bytes, la sortida serà true.
Si sizeof(int) == 4 bytes, la sortida serà false.

**Completa el codi següent:**

```c
int main(){
int (*ptr)();
return 0;
}
```

```c
int sum(){
    return 5;
}
int main(){
    int (*ptr)();
    ptr = sum;
    printf("%d\n", ptr());
    return 0;
}
```

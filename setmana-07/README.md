## Setmana 7 – Pipes i redirecció d’entrada/sortida

### Resum de la setmana

- Estudi de la **comunicació entre processos** mitjançant **pipes** (anònimes i nominals) per transmetre dades entre processos pare i fills.  
- Introducció a la **redirecció d’entrada i sortida** utilitzant descriptors de fitxer i funcions com `dup2()`.  
- Ús combinat de **fork()**, **exec()** i **pipes** per crear processos col·laboratius i canals de comunicació.  
- Ús de **senyals** (`SIGALRM`, `SIGUSR1`) per sincronitzar i controlar l’execució dels processos.  

### Activitats i laboratoris realitzats

- **Pipes i redirecció d’entrada/sortida** → Material teòric amb exemples sobre la comunicació i redirecció de fluxos entre processos.  
- **Laboratori 10 · Escape Room entre processos amb Pipes** → Implementació d’un joc amb processos pare i fills que es comuniquen mitjançant pipes i senyals. (`./lab12`)
- **Exercicis de Pipes en C** → Pràctiques sobre comunicació, redirecció i execució de comandes en C utilitzant pipes i processos. (`./loteria-pipe.c`)

### Reflexió i conclusions

Aquesta setmana he après com comunicar processos mitjançant pipes i redireccions, i com combinar `fork()` i `exec()` per reproduir comandes de Linux. Les pràctiques m’han ajudat a entendre millor la gestió dels descriptors i la sincronització entre processos.

## Setmana 4 – Gestió de processos, Kernel i seguretat

### Resum de la setmana

- Profundització en la **programació de mòduls per al Kernel de Linux**, aprenent com es dissenyen i integren mòduls senzills dins de l’espai del kernel.  
- Estudi de tècniques d’**anàlisi i intercepció de crides a sistema**, amb discussió sobre implicacions de seguretat i els riscos associats a l’execució de codi amb privilegis elevats.  
- Apendre els **processos a Linux** per a la comprensió de la creació, execució i finalització d'aquests processos.  

### Activitats i laboratoris realitzats

- **Laboratori 9 · Programació de mòduls per al Kernel de Linux** → Introducció pràctica a la creació i càrrega de mòduls del kernel; exemples senzills per entendre la interfície amb el kernel i com es gestionen els recursos dins del mode kernel.  
- **Laboratori 10 · Escalada de privilegis (anàlisi educativa)** → Estudi d’un exemple d’intercepció d’una crida a sistema amb finalitat d’aprenentatge sobre vulnerabilitats i riscos.
- **Processos a Linux** → Materials de la Unitat 3 de Sistemes Operatius que han complementat la part teòrica i han presentat la pràctica introductòria.  
- **Pràctica 01: Manipulació de Cadenes de Caràcters en C** → Presentació sobre funcions per operar amb *strings* en C, gestió segura de memòria dinàmica (malloc/calloc/realloc/free) i disseny de llibreries modulars.
- **RMSF · Implementant una paperera de reciclatge a Linux** →  Hem acabat aquesta activitat i hem implementat:
  - `./RMSF/mystat.c` → Comprovació de l’existència d’un directori amb `stat()`.
  - `./RMSF/concat.c` → Programa per concatenar el directori home de l’usuari amb la carpeta de la paperera i imprimir la ruta resultant.
  - `./RMSF/mkd.c` → Creació d’un directori si no existeix.
  - `./RMSF/mymv.c` → Programa per moure fitxers a la paperera.  

### Reflexió i conclusions

Aquesta setmana he aprofundit en la programació del kernel i en la gestió de processos a Linux, entenent millor com el sistema operatiu controla els recursos i la comunicació entre processos. Les pràctiques amb mòduls del kernel i crides a sistema m’han ajudat a veure la relació entre el codi d’usuari i el nucli.

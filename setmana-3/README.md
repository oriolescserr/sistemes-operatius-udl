## Setmana 3 – Programació en C, Kernel i crides a sistema

### Resum de la setmana

- Estudi del **Kernel de Linux**, incloent gestió de processos, memòria, sistemes de fitxers i dispositius.  
- Diferència entre **mode usuari** i **mode kernel**, amb èmfasi en la protecció de l’espai d’adreces.  
- Rol del Kernel com a intermediari entre aplicacions i maquinari.  
- Les crides a sistema (syscalls) permeten als processos d’usuari accedir a serveis del kernel.  
- El dispatcher de Linux (`do_syscall_64`) gestiona les syscalls: identifica el número, valida arguments i crida la rutina corresponent.  
- Flux d’execució: Usuari → Trap/syscall → Dispatcher → Rutina → Kernel → Retorn → Usuari; les excepcions i interrupcions són l’únic mecanisme d’accés al kernel.

## Activitats i laboratoris realitzats

- **Laboratori 6 · Punters, Stack i Heap en C** → Pràctica amb punters i diferència entre memòria d’apil i de munt.  
- **Laboratori 7 · Espiant el Kernel** → Primer contacte amb les crides a sistema i com el kernel gestiona la interacció amb el programari d’usuari.  
- **Laboratori 8 · Analitzant crides a sistema** → Ús d’un programa en C per veure quines syscalls es realitzen en diferents processos. (`./lab8.c`)  
- **Exercicis amb C** → Resolució de petits programes per reforçar el treball amb punters, funcions i fitxers. (`./exercicis-amb-c.md`)  
- **RMSF · Implementant una paperera de reciclatge a Linux** → Inici de la implementació amb la primera part (`./whoami.c`), utilitzant les crides a sistema `getuid()` i `getpwuid()` per identificar l’usuari i el seu directori home.  

## Reflexió i conclusions

Aquesta setmana he aprofundit en com els processos d’usuari interactuen amb el Kernel de Linux a través de les crides a sistema. He entès que les syscalls són l’únic mecanisme que permet als programes accedir a serveis del kernel, i com el dispatcher gestiona aquestes crides, valida els arguments i executa la rutina corresponent.

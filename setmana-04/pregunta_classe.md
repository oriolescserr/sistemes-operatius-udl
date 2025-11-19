# Pot un kernel desactivar les interrupcions?

**Resposta curta:**  
Sí, el kernel pot desactivar les interrupcions en determinats moments.

## Explicació

Quan el processador està **atenent una interrupció**, normalment es **desactiven automàticament les interrupcions del mateix nivell o de menor prioritat**.  
Això evita que una nova interrupció interrompi el codi que ja s’està executant i pugui causar inconsistències.

Tot i així:  
- Les **interrupcions de major prioritat** poden seguir arribant, depenent de l’arquitectura i del disseny del controlador d’interrupcions.  
- El kernel pot **desactivar totes les interrupcions explícitament** (per exemple amb instruccions com `cli` en x86) quan necessita protegir una secció crítica. Després les torna a habilitar amb una altra instrucció (`sti`).  

## Resum

- ✅ Sí, el kernel pot desactivar interrupcions.  
- 🔹 Durant una interrupció, les d’igual o menor prioritat normalment queden bloquejades.  
- 🔹 També pot passar fora d’una interrupció, quan el kernel decideix protegir dades compartides o seccions crítiques.  

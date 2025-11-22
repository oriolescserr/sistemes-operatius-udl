# Problemes avançats de planificació de processos

Solució problema 1 — EEVDF (sense prioritzar el lag)

```text
t = 0: J2 (D més petita)
t = 1: J2
t = 2: J2
t = 3: J2

v(0) = 0
v(1) = 1 / (1 + 3) = 1/4
v(2) = 1/4 + 1/4 = 1/2 (J3 encara no ha arribat, mires abans d'arribar al moment 3)
v(3) = 1/2 + 1/6 = 2/3

D1 (J1) = 1/4 + 6/1
   (J2) = 1/4 + 2/3

D2 (J1) = 1/2 + 6 (Aquí mires quan ja ha arribat J3)
   (J2) = 1/2 + 1/3
   (J3) = 1/2 + 4/2

D3 (J1) = 2/3 + 6
   (J2) = 2/3 + 
   (J3) = 2/3 + 2


.
.
.

```

Solució problema 2 — EEVDF (prioritzant el lag positiu)

Problema 2: EEVDF (prioritzant el lag positiu)

```text
T / (T + (T*S) / Q)
```

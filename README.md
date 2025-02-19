//315CA-Gilma Sebastian Mihai
# Proiect Procesare Imagini

## Descriere
Acest proiect implementează diverse operații de procesare a imaginilor, inclusiv încărcare, salvare, selecție, aplicare de filtre, rotire, decupare și egalizare a histogramei.

## Fișiere și Funcționalitate

### `main.c`
- Citește în mod repetat un string și verifică cazul corespunzător.
- Dacă se ajunge la cazul "select" și acesta este invalidat, se păstrează selecția precedentă.
- În cazul "apply", se verifică dacă există vreun parametru după comandă.
- La final, se eliberează memoria utilizată.

### `load.c`
- Încarcă o imagine în memorie.
- Utilizează funcțiile `read_P2`, `read_P3`, `read_P5`, `read_P6` pentru a citi datele în funcție de format.
- Dacă fișierul este binar, citirea se face byte cu byte.
- Dacă fișierul este text, citirea se face ca o matrice normală.
- Dacă funcția `load` este apelată din nou, memoria veche este eliberată și se creează o nouă matrice.

### `rotate1.c`
- Verifică dacă operația de rotire este posibilă.
- Dacă este selectată întreaga matrice și aceasta nu este pătratică, se creează o nouă matrice cu dimensiuni inversate.
- Rotirea se face prin transpunerea matricei și inversarea coloanelor.

### `select.c`
- Citește un șir de caractere folosind `fgets` și verifică validitatea acestuia.
- Verifică dacă șirul conține 4 numere sau string-ul "ALL".
- Dacă este invalid, selecția este anulată.
- Extrage numerele folosind `atoi` și verifică dacă sunt în limitele permise.

### `save.c`
- Salvează imaginea într-un fișier.
- Verifică tipul de date și decide dacă salvează în format text sau binar.
- Extrage numele fișierului destinație și verifică dacă este specificat "ascii" pentru salvare în format text.
- Dacă este binar, salvează datele byte cu byte.

### `histogram.c`
- Citește un string cu `fgets`, prelucrează-l și extrage numerele cu `atoi`.
- Creează un vector de apariții și determină maximul acestuia.
- Determină numărul de binuri pentru histogramă.
- Calculează numărul de stele pentru reprezentarea histogramei.

### `apply.c`
- Conține două funcții: una pentru prelucrarea datelor de intrare și alta pentru aplicarea efectivă a filtrului.
- Filtrul este aplicat doar pe elementele care nu sunt pe marginea imaginii.
- Ajustează valorile pentru a se încadra în limitele permise.
- Operațiile sunt efectuate într-o matrice copie, care apoi înlocuiește matricea principală.

### `crop.c`
- Creează o copie a unei porțiuni din matricea inițială, conform coordonatelor specificate.
- Înlocuiește matricea inițială cu noua copie.
- Eliberează memoria ocupată de matricea veche și actualizează indicii.

### `equalizer.c`
- Creează un vector de apariții al pixelilor din imagine.
- Calculează suma tuturor valorilor mai mici decât pixelul curent.
- Aplică formula `(255 / aria imaginii) * suma` pentru a normaliza intensitățile pixelilor.
- Înlocuiește valorile pixelilor cu cele nou calculate pentru a îmbunătăți contrastul imaginii.

## Concluzie
Acest proiect oferă o suită de funcționalități pentru manipularea imaginilor, permițând încărcarea, procesarea și salvarea acestora în diverse formate, inclusiv aplicarea unor filtre și transformări esențiale.


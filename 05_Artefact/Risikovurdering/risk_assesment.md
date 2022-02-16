[comment]: <> (Projektet omhandler en autonom båd der skal sejle ved hjælp af strøm fra solceller. Båden skal indsamle data i en sø og sende disse data via et LoRa-modul.)
[comment]: <> (Derefter skal data sendes til en webserver. De målte data skal være temperatur og ilt-indhold i vandet. Båden skal ydermere bruge et ekkolod til at dybdemåle.)
# Risikovurdering
## Produktet

| Risikobeskrivelse | Risiko | Konsekvens | Trin for at formindske risiko | Trin for at formindske konsekvens | ny risiko | ny konsekvens | ID |
|-------------------|--------|------------|-------------------------------|-----------------------------------|-----------|---------------|----|
| Mangel på GPS-presition | 3 | 3 | Undersøg GPS-modul grundigt inden implementering | Evnt. kombiner flere forskellige positions-sensor | 2 | 1 | 1 |
| Accelerometer forværre position | 2 | 3 | Undersøg algoritmer for positionering ved sammenspil mellem GPS og accelerometer | Evnt. ikke bruge accelerometer | 2 | 1 | 2 |
| Motor ikke kraftig nok| 4 | 4 | Undersøg hvor meget kraft det kræver at holde båden i samme position | Undersøg om motoren er tilstrækkelig - ellers skift denne. Hvis det stadig ikke er nok skal der måske flere solceller på. | 3 | 2 | 3 |
| Propel/skrue ikke god nok | 2 | 3 | Undersøg egenskaber for propeller i vand / skruer - skal man have fat i nogle specifikke eller er gængse droneting tilstrækkelige? | N/A | 1 | 2 | 4 |
| Controller ikke strømeffektiv nok | 3 | 3 | Overvej hvor meget man skal designe selv. | Hvis vi ikke kan designe en tilstrækkelig controller kan vi blive nødt til at bruge en 3. parts. | 2 | 1 | 5 |
| Flydeegenskaber er dårlige og gør båden ustabil | 4 | 4 | Kig på andre designs og se hvad andre folk har gjort | Afprøv jævnligt bådens stabilitet | 2 | 2 | 6 |
| Elektronikken er ikke sikret mod elementerne | 3 | 5 | Undersøg de bedste måder at sikre elektronik og solceller | N/A | 2 | 5 | 7 |
| Wirespil sætter sig fast | 4 | 5 | Brug ekkolod jævnligt under sænkning af wiren for at holde styr på omgivelserne | N/A | 2 | 5 | 8 |
| Ekkolod fungerer ikke i beskidt vand | 4 | 5 | Test i laboratorie om ekkoloddet er præcis i beskidt vand | N/A | 2 | 4 | 9 |
| Dårlig måle nøjagtighed Temperatur| 1 | 5 | god sensor / kalibrering | N/A | 1 | 5 | 10 |
| Dårlig måle nøjagtighed pH| 3 | 5 | god sensor | vi fravælger pH data | 1 | 5 | 11 |
| Dårlig måle nøjagtighed O2| 2 | 5 | bruge bedre sensor | N/A | 1 | 5 | 12 |
| Dårlig kommunikation mellem båd og sensorer | 4 | 5 | Lav dybdegående tests i forskellige omgivelser og isolér støj i ledninger til sensorer | Måske noget analog filtrering af datasignalerne | 2 | 5 | 13 |
| Dårlig kommunikation ml. | | | | | | | 14 |
| Begrænset brug af LoRa | 3 | 5 | undersøge LoRa og mulighederne | N/A | 1| 5| 15 | 
| Mangel på penge | 4 | 4 | søge penge fra en fond |||||
| Mangel på komponenter | 4 | 4 | bestille hjem i god tid |||||
---

## Processen:
| Risikobeskrivelse | Risiko | Konsekvens | Trin for at formindske risiko | Trin for at formindske konsekvens | ny risiko | ny konsekvens | ID |
|-------------------|--------|------------|-------------------------------|-----------------------------------|-----------|---------------|----|
| Brug af ny process (SCRUM) | 3 | 4 | SCRUM kursus | dokumenter alt så det stadig er klart hvad vi har lavet | 2 | 2 | P1 |

---

## Gruppen:
| Risikobeskrivelse | Risiko | Konsekvens | Trin for at formindske risiko | Trin for at formindske konsekvens | ny risiko | ny konsekvens | ID |
|-------------------|--------|------------|-------------------------------|-----------------------------------|-----------|---------------|----|
| Konflikter | 2 | 4 | Be nice over for hinanden | Konflikter skal løses ASAP | 1 | 2 | G1 |
| Tidspress | 3 | 3 | Planlægning | Sprints der producerer noget | 1 | 2 | G2 |
| Gruppemedlemsfrafald | 2 | 4 | hjælpe gruppemedlemmer med at holde fast i studiet | vidensdeling | 1 | 1 | G3 |

---





- Placeringsstyring
        - Hvor præcist er det?
        - Hvordan sørger vi for, at båden har en præcis placering?
- Mekanisk opbygning af båd
        - 4 pontoner og en roterende propel i midten?
- Sensorpod
        - Skal den kunne tage vand-samples?
        - Hvor dybt skal den kunne gå?
- Sensorer?
        - Iltsensor => Køb
        - Temperatur med PSoC på pod'en => Sender digitalsignal til båden
- Digital signal fra podden?
        - Hvor kraftigt skal signalet være? => Er RS232 nok?
        - Skal der være en MCU, så alt data bliver sendt samtidigt


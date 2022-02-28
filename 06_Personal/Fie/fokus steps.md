# Krav
## Bevægelse
- M: Bevæge sig i 2D plan i alle retninger (Aktuator)
- S: Sejle til gps koordinater
- C: Pathfinding/undgå forhindringer
- S: Beskyttelse af motor mod fremmeslegemer
- M: Holde position = forskellig precition
- M: Kende GPS-lokation

## UI
- M: TUI
- S: GUI (Interraktiv map)
- M: Lokation
- M: Sensor data
- C: Display koordinatsæt(lon/lat) på map
- C: Display pathfinding
- S: Tasktracker
- M: Intereragere med båd

## Power
- M: Lade batteri fra sol
- S: Selvforsynende energi
- S: Sleep mode
- S: Måle strømforbrug
- C: Kende kapacitet
  
## Projektrammer
- M: Sejle i sø uden forhindringer
- S: Sejle i søer med øer
- C: Undgå flydende forhindringer
- W: Ikke sejle i overskyet og stormvejr

## Sensor
- M: Måle temperatur
- S: Ledningsevne
- C: PH
- C: O2
- M: Måle i flere dybder
- S: Sonar til at finde dybde
- S: Måle tæt på bund
- M: Brug af PSoC
- M: kommunikaton mellem båd og pod

## Land unit
- C: Mobile netværker
- M: Uploade sensordata
- C: Live position
- S: Status på båd
- C: Snakke med webserver 
- M: Save csv af data
- M: Linux embbeded på rpi
- M: LoRa til båden
- M: Local webserver

## Ikke funktionelle krav
- M: PH 2 decimal
- M: Temp 1 decimal
- M: Ilt 1 decimal + % mætning i vand

---
---
# prototype

## Båden V.0.1
- Sensor: Temp
- Aktuator: Motor

## LandUnit V.0.1
- Rpi med linux på
- Lokal webserver + TUI
- Køre på elnet

---
---
# Backlog
## Båd V.0.1
- Send DATA via LoRa til LU
- Modtage kommando LoRa fra LU
  - Fortolke kommando
- Undersøg LoRa på PSoC
- Opsæt PSoC til C++ std::20

## Hardware
- Vælg temperatur sensor
  - Byg/opstil forstærker kreds
  - Test sensor
- Et eller andet skrog
- Ror/Roterende motor
  - Motortype
  - Mekanik
  - Ledninger ved rotation
- Propel/motor
  - Motortype
  - Mekanik
  - Vandtæt


---
- Temperatur Sensor
  - vælg
  - vælg kreds
  - Design kreds
  - opbyg kreds
  - Test kreds
  - Lav PSoC-SW
  - Test PSoC m. Sensor 

## LandUnit V.0.
- Install Linux image
  - Opsæt Apache2 på ovenstående
- Undersøg n curses til TUI
- Send besked via LoRa til båd
- Modtage data via LoRa fra båd
- SW arkitektur
  - Kommunikations protokol fra LoRa
  - (Applikations model)
- Undersøg LoRa på rpi
# CryptTool

## Contents
- [CryptTool](#crypttool)
- [Requirements](#requirements)
- [Features](#features)
- [User Documentation](#user-documentation)
- [Developer Documentation](#developer-documentation)

## Requirements
- OS: Linux or Windows
- For Development purpose IDE: CLion
- Enough RAM to Encrypt or Decrypt

## Features
- Detect all mounted drives on Windows
- Detect all mounted drives at ``/mnt/..`` on Linux
- Encrypt with a generated Key
- Decrypt with a generated Key

## User Documentation 
Dokumentation für den Anwender

Das CryptTool ist für die ver- und entschlüsselung von Dateien zuständig. Dies wird wie folgt erreicht:

1. 	Der Anwender bekommt in der Kommandozeile eine Auswahl eine Datei
      zu entschlüsseln, verschlüsseln und eine Key Datei zu erstellen um
      die Dateien überhaupt verschlüsseln oder entschlüsseln zu können.
      Außerdem werden alle Laufwerke aufgelistet.


2. 	Danach muss das Programm wissen auf welchen 		
      Laufwerk es die Datei
      erstellen/verschlüsseln/entschlüsseln soll.


3. 	Es wird nach dem Pfad gefragt wo die Datei stehen 	
      soll oder ist. Bsp.: C:\CryptTool\BEISPIELDATEI.TXT

3.1 	Eine Besonderheit ist hier, dass wenn man ein Key erstellen 				möchte, der Ordner "CryptTool" angelegt werden sollte. 
	

## Developer Documentation
We have a documentation for every part of the CryptTool program
- [DriveSelector](https://github.com/LukasLJL/CryptTool/blob/master/src/README.md)
- [CryptLib](https://github.com/LukasLJL/CryptTool/blob/master/cryptlib/README.md)

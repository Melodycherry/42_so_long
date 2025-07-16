# 🎮 so_long — Jeu 2D avec MiniLibX

## 🎯 Objectifs

- Créer un petit jeu 2D basé sur un fichier `.ber` représentant une **carte**.
- L’objectif du joueur : **collecter tous les objets** (collectibles) puis **sortir** par l’unique issue.
- Les graphismes sont affichés dans une **fenêtre MiniLibX**.
- Le joueur peut se déplacer avec les touches `W`, `A`, `S`, `D

## 🗺️ Règles de la carte

Le fichier `.ber` contient une **map rectangulaire** composée des éléments suivants :

| Symbole | Signification          |
|---------|-------------------------|
| `1`     | Mur                    |
| `0`     | Espace vide            |
| `C`     | Collectible            |
| `E`     | Sortie                 |
| `P`     | Position de départ     |

*Exemple de map valide :*  
`111111`  
`1P0C01`  
`1000E1`  
`111111`    

### ⚠️ Contraintes :

- Une seule sortie (`E`)
- Une seule position de départ (`P`)
- Au moins **un** collectible (`C`)
- La carte doit être **fermée par des murs**
- La carte doit être **rectangulaire**
- Il doit exister un **chemin valide** entre le joueur, tous les collectibles et la sortie

## 🕹️ Mécanique de jeu

- Vue **2D** (du dessus ou de côté)
- Le joueur peut se déplacer :
  - ⬅️ Gauche (`A`)
  - ➡️ Droite (`D`)
  - ⬆️ Haut (`W`)
  - ⬇️ Bas (`S`)
- À **chaque mouvement**, le nombre de déplacements est affiché dans le terminal.
- Le joueur ne peut pas traverser les **murs** (`1`).
- Le jeu **se termine** une fois tous les collectibles ramassés et la sortie atteinte.

## 🖼️ Graphismes & Fenêtre

---

**🧠 Ce que j’ai appris**:  

•	📐 Représenter un monde en 2D dans une structure de données  
•	🎨 Charger et afficher des images (textures, sprites) avec MiniLibX  
•	🎮 Gérer des entrées clavier et les événements  
•	🧮 Mettre en place des algorithmes de vérification de chemin valide  
•	🛠️ Créer un parser de fichier .ber robuste  
•	❌ Gérer les erreurs proprement et éviter les fuites mémoire  

---

✅ **STATUT:**  
📅 Date de rendu : 02.04.2025    
📝 Note obtenue : 100/100

---

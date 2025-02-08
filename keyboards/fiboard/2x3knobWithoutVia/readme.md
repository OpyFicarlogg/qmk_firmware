# fiboard

![fiboard](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Samuel FUCHS](https://github.com/OpYFicarloGG)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make fiboard:default

Flashing example for this keyboard:

    make fiboard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available



# Création de la board 


## Installation des outils 

- Télécharger visual code 
- Télécharger [Toolbox](https://github.com/qmk/qmk_toolbox)
- Télécharger [QMK_MSYS](https://github.com/qmk/qmk_distro_msys/releases/tag/1.7.2) (éditeur ligne de commande)
- Faire un fork du repository [QMK_firmware](https://github.com/qmk/qmk_firmware) sur son git 
- Cloner le nouveau repo sur son poste `git clone --recurse-submodules https://github.com/qmk/qmk_firmware`
- Définir le chemin du repo pour qmk avec la commande `qmk setup -H <path>\qmk_firmware`



## Tester l'installation 

Le mieux est de se placer dans le dossier du firmware `cd /d/AppData/QMK/qmk_firmware`
- Exécuter la commande `qmk compile -kb clueboard/66/rev3 -km default`

Il est possible d'éxécuter la commande `qmk doctor` pour vérifier l'état de l'installation 

Si il y a un problème avec l'installation sur l'upstram, il suffit d'exécuter la commande `git remote add upstream https://github.com/qmk/qmk_firmware`

## Créer un nouveau clavier 
- Pour créer un nouveau clavier, exécuter la commande `qmk new-keyboard`
- Ensuite ouvrir visual code avec la commande `code keyboards/monclavier/ &`

## Création d'une nouvelle keymap 
- Avec le clavier par défaut `qmk new-keymap`
- Si on a plusieurs claviers `qmk new-keymap -kb monclavier` 

## Définir le clavier et keymap par défaut 
- `qmk config user.keyboard=monclavier`
- `qmk config user.keymap=default`

## Compiler le clavier 
- Si l'environnement est correctement défini `qmk compile`
- Sinon `qmk compile -kb monclavier -km default`

Exemple: `qmk compile -kb fiboard -km default`

Le firmware se trouve ensuite dans le dossier `D:\AppData\QMK\qmk_firmware\.build`

## Upload du firmware 

Pour upload le firmware, il y deux façon 
- Avec QMK toolbox (cocher autoflash avec le bootloader caterina, car ne laisse que 7 secondes après le reset)
- En ligne de commande `make fiboard:default:flash`

Dans tous les cas, il faut lancer la commande ou l'outil, en ayant la carte de connectée, puis lancer connecter le pin reset avec le ground

Avec

## Liens
- [basic-qmk-keyboard](https://johnmu.com/basic-qmk-keyboard/)
- [qmk tutorial](https://docs.qmk.fm/#/newbs_building_firmware)
- [impression 3D](https://www.thingiverse.com/thing:4416966)

## Fonctionner avec via 

- Créer un fichier .json qui correspond au layer pour VIA. Il sera à charger à chaque fois dans l'onglet `Design` tant qu'il n'a pas été ajouté officielement par via. 

- Créer une nouvelle keymap `via`
- Créer un fichier `rules.mk` avec `VIA_ENABLE = yes`
- Créer 4 layers au moins dans le `keymap.c`
- Dans config.h, ajouter le vendor_id, product_id
- 
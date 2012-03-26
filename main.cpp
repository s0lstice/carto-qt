/**
 * \file main.cpp
 * \brief debut du programme de catographie
 * \author Guillaume Lastecoueres & Mickael Puret
 * \version 0.1
 *
 *
 */

/*! \mainpage Cartographie de lieux
 *
 * \section intro Introducation
 * Se projet s'inscrit dans l'apprentissage du cpp et de Qt.
 *
 Le but de cette application et la mise en place d'une catre interactive sur la quelle se situent differant lieux, designe par une categorie, un nom, une description et des coordonnees
 Le langage de programmation et le Cpp Qt, la base de donnee est une SQlite.

 * \section ch1 Utilisation du logiciel

 * \subsection sub1 Creation et reutilisation de la base de donnee

Le logiciel de cartographie à besoin d'une base de donnée pour fonctionner. Pour cela il va demander au démarrage si l'utilisateur souhaite créer ou selectionner une base de donnée déjà existante. Dans cette base est contenu les différentes informations concernants les points d'intérets.

\image html bddstart.jpeg

Sur cette fenêtre il y a :
une combobox : Dans celle ci se trouve les noms des fichiers *.db dans le répertoire de l?exécutable. Elle permet aussi à l'utilisateur de rentrer le nom d'une base de donnée ainsi que son chemin.
Quatre boutons :  +Le bouton créer permet de créer une nouvelle base de donnée avec le 		nom fournit dans la combobox. Si une base existe déjà avec le même nom 		alors nous allons simplement ouvrir celle qui existe déjà
     + Le bouton Sélectionner lui permet de reprendre une base de donnée déjà existante. Si celle-ci n'existe pas nous en créons une nouvelle totalement vide.
                + Le bouton Quitter permet tout simplement de quitter.
                + Le bouton avec trois petits point permet d'ouvrir un explorateur de 			      fichier dans le but de faciliter la sélection des fichiers de base de données. 			      Une fois un fichier choisit son chemin et son nom sont inscrits dans la 			      combobox.

Il est possible plus tard de rappeler cette fenêtre via l'interface de navigation. Cela permet de changer à tout instant la base de donnée que l'on souhaite utiliser.

 * \subsection sub2 Navigation et gestion des points

L'interface de navigation est la fenêtre principale. Elle permet de faire la majorité des taches du logiciel. Elle est constitué de menu qui permettent de contrôler l'application. La majorité des options de navigation se trouvent ici. C'est la fenêtre ou l'utilisateur passera normalement le plus clair de son temps.


\image html intnav.jpeg

L'interface est composé de très nombreux éléments :

Une carte sur laquelle nous affichons les points autour de la croix. Celle ci représente  l'endroit que souhaite voir l'utilisateur. Les Points sont dessinés dessus en temps réel au fur et a mesure que l'utilisateur se promène sur la carte.
Une ListeBox à droite. Elle permet d'afficher le nom des points représentés sur la carte. Il y a deux interactions possibles avec la liste box. Le double clic sur un item ouvre une fenêtre qui permet de décrire le point sélectionné.
Une fois qu'un point à était sélectionné dans la liste il est possible de cliquer sur le bouton centrer dans le but de centrer la carte sur le point.
Le bouton centrer qui comme dit précédemment permet de centrer la carte sur un point défini.
Une SpinBox qui prend par défaut la valeur 10. Elle permet de choisir le nombre de points que l'on souhaite afficher sur la carte. Il est possible d'aller de 0 à 99999. Il est important de remarquer qu'à partir de 1000 la fluidité commence à être compromise.
Le TextBox chaine de Recherche permet de taper une chaine qui va servir de filtre à la fois sur le nom et sur la déscription des points. Seuls les points ayant dans leur nom ou leur description la chaine seront affichés.
La combobox catégorie permet de choisir une seule et unique catégorie à afficher sur la carte.

Important : Il est nécessaire faire remarquer à l'utilisateur que les contraintes sont cumulatives. Chaîne et catégorie sont prises en compte simultanément.
Une ProgressBar indique l'avancement du téléchargement des points ainsi que leurs mise en place dans la base de donnée.
Le bouton télécharger permet de télécharger les 100 points les plus proches autour du centre de la carte. Cela signifie que lorsque l'utilisateur souhaite avoir des points à l'endroit ou il est et si il n'y en a pas dans la base donné, il doit cliquer sur le bouton télécharger.
La CheckBox auto téléchargement permet lorsqu'elle est coché d'activer le streaming des points en temps réel. Lorsque l'utilisateur se déplace et qu'il n'y a pas de point à l'endroit ou celui ci est. L'application télécharge automatiquement les points de manière transparente.
Il existe aussi un slider verticale qui permet de choisir le niveau de zoom. Celui-ci est représenté par le chiffre à coté. Le zoom va de 0 à 17.
L'interface est aussi constituée de trois menus.
Le menu « menu » permet de quitter l'application
Le menu BDD permet d'accéder d'accéder au choix de la BDD, à la gestion de la BDD ou à l'export de celle-ci en fichier .csv

 * \subsection sub3 visualisation d'un point


\image html visu.jpeg

Cette interface est accessible par deux chemins. En cliquant sur un point représenté sur la carte ou en double cliquant sur le nom d'un point.
Celle ci permet d'afficher les informations concernants ce point.
Aucun des éléments n'est éditable l'interface n'a pour but que d'afficher les caractéristiques du point.
Pas de les modifier.

 * \subsection sub4 Ajout et edition des points


 \image html bddg.jpeg

Cette interface est accessible en cliquant sur gestion BDD dans le menu BDD dans la fenêtre de navigation. C'est via cette fenêtre que nous pouvons voir , ajouter et éditer des points.
Il y a plusieurs parties. La première partie concerne les points.
Elle est composé :
    -D'une table qui affiche tous les points dans la base de données avec toutes ces caractéristiques sauf les horaires qui font l'objet de la deuxième partie. Tout les champs sont éditables. Cela permet de modifier à la volé un point en modifiant ces attributs directement dans la table.
    -D'une groupbox contenant les éléments nécessaire à l'affichage des informations sur le point. Elle permet aussi l'édition de ces informations. Dans cette groupbox il y a deux boutons.

\image html catg.jpeg

Le premier permet la gestion des catégories. Il affiche une fenêtre composé d'une table regroupant toutes les catégories. Ainsi que de trois boutons :
Le bouton modifier permet de modifier le nom d'une catégorie.
Le bouton ajouter permet d'ajouter une catégorie.
Le bouton supprimer permet de supprimer une catégorie. Attention comme il est affiché sur la fenêtre d'édition il est possible que cela détruise la cohérence de la base de données si certains points utilisent encore la catégorie supprimé.
Le deuxième bouton permet simplement de récupérer les coordonnées actuel sur la carte de l'interface principale dans le but de les appliquer au point en cours.

Dans cette première partie il y a trois boutons importants :
Le bouton ajouter permet d'ajouter une point contenant des informations de base. Pour le compléter il suffit de le sélectionner puis d'éditer ses champs.
Le bouton supprimer permet de supprimer un point et toutes ces informations.
Le bouton mettre à jour permet de sauvegarder toutes les modifications effectuées sur les points dans la base de données.

Il y a une deuxième partie dans cette fenêtre celle de la gestion des horaires.

Elle est composé d'une table qui permet d'afficher les horaires d'un point sélectionné dans la table des points.

Ainsi qu'une combobox qui permet de choisir un jour et deux TextBox(s) pour pouvoir entrer l'heure de début et l'heure de fin.
Les champs dans la table sont éditables.

Il y a aussi comme d'habitude trois boutons. Un pour ajouter , un pour supprimer et un dernier pour mettre à jour les horaires.

 * \section ch2 Structure de la base de donnÃ©e
La base de donnÃ©es est constituÃ©e de plusieurs tables permettant dâ€™avoir une structure cohÃ©rente est ainsi dâ€™utiliser les modÃ¨les proposÃ©s par Qt.\n
Notre application se repose sur quatre tables :
-          La table points qui contient toutes les informations sur un point
-          La table categories, qui contient le nom des diffÃ©rentes catÃ©gories, elle est en relation avec la table points
-          La table heures, qui contient les informations heures dâ€™ouverture et de fermeture ainsi que le jour. Cette table est en relation avec la table points.\n
-          La table jours, contient les jours de la semaine, cette table et en relation avec la table heures.
Cette structure permet donc de gÃ¨re un nombre infini de points dÃ©finis par :
-          Un nom, une catÃ©gorie, une latitude, une longitude, un nombre infini de plages horaires et une description.\n
Le diagramme suivant montre la structure de la base de donnÃ©es :\n

\image html bdd.jpeg

 *
 * \section ch3 Structure du programme

Cette documentation est complÃ¨te, diagrammes uml, commentaires des fonctions publiques et privÃ©es, notes d'utilisations et incorporation du code source.\n
Il est cependant intÃ©ressant de souligner quelques points :
\subsection ch31 La classe application
Cette classe a Ã©tÃ© Ã©crite en vue d'une traduction dynamique de l'application et pour faciliter l'utilisation des paramÃ¨tres propre Ã  l'application (QSetings).
En effet, la traduction d'un document fait appelle aux mÃ©thodes translate et installTranslator de la classe QApplication. Cette classe est nÃ©cessaire dÃ¨s l'initialisation du programme.
Or, pour une traduction dynamique, il est nÃ©cessaire de possÃ©der l'instanciation de cette classe qui est propre au programme.
C'est pour quoi nous avons crÃ©er une classe singleton nomÃ©e application, cette deniÃ¨re hÃ©rite de QApplication est permet donc de rÃ©cupÃ¨rer la classe principale n'importe oÃ¹ dans le programme.\n

En ce qui concerne les QSetings, dans notre cas, ils sont utilisÃ©s dÃ¨s l'ouverture de l'application et ils doivent Ãªtre enregistrÃ©s Ã  la fermeture de celle-ci.
Pour ce faire, nous utilisons le constructeur de la classe application et son destructeur. Pour mieux visualiser cet enjeu, rendez vous Ã  l'explication de la classe application : \ref application .

\subsection ch32 Gestions de la base de donnÃ©es
Au cours de la vie du programme, de nombreuses bases de donnÃ©es sont amenÃ©es a crÃ©Ã© et utilisÃ©, de nombreuses requÃªtes seront effectuÃ©es.
Du point de vue de la conception du logiciel, cela posait des problÃ¨mes d'accÃ¨s et le descripteur de base de donnÃ©es devait Ãªtre transmis de classe en classe ...\n
Pour rÃ©soudre ces problÃ¨mes, nous avons crÃ©Ã© une classe database qui est un singleton, ainsi, nous avons accÃ¨s Ã  notre base Ã  tout moment, et ce en toute sÃ©curitÃ© pour elle et les donnÃ©es.
Pour plus d'information sur cette classe, regardez l'explication de la classe database : \ref database .\n

En ce qui concerne l'implÃ©mentation des mÃ©thodes de gestion des tables, elles ont Ã©tÃ© dissociÃ©es dans plusieurs bibliothÃ¨ques et non dans des classes, car on ne peut hÃ©ritÃ© d'un singleton
(la seule solution est de "frender" les deux classes, ce qui n'est conceptuellement pas envisageable). De plus l'emploi de mÃ©thodes et non de fonctions Ã©tÃ© plus lord d'utilisation et n'apporter rien.
Pour mieux cerner cette explication regardez les bibliothÃ¨ques :\n
-\link data_points.h data_points.h \endlink \n
-\link data_jours.h data_jours.h \endlink \n
-\link data_heures.h data_heures.h \endlink \n
-\link data_categories.h data_categories.h \endlink \n

*/
#include <QtGui/QApplication>
#include <QSettings>
#include "askdatabase.h"
#include <QObject>
#include "data_categories.h"
#include "application.h"



/*!
  @brief Initialise le programme
  \note Nous appellons un objet de la classe application qui herite de la classe Qapplication. Cela est fait pour permettre les traductions ainsi que mettre aux propres les QSettings.
*/
int main(int argc, char *argv[])
{
    application  *app = application::appInit(argc, argv);
    AskDataBase w;
    w.show();
    app->exec();
    app->appExit();
    return 0 ;

}

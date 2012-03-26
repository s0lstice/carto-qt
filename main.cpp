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

Le logiciel de cartographie � besoin d'une base de donn�e pour fonctionner. Pour cela il va demander au d�marrage si l'utilisateur souhaite cr�er ou selectionner une base de donn�e d�j� existante. Dans cette base est contenu les diff�rentes informations concernants les points d'int�rets.

\image html bddstart.jpeg

Sur cette fen�tre il y a :
une combobox : Dans celle ci se trouve les noms des fichiers *.db dans le r�pertoire de l?ex�cutable. Elle permet aussi � l'utilisateur de rentrer le nom d'une base de donn�e ainsi que son chemin.
Quatre boutons :  +Le bouton cr�er permet de cr�er une nouvelle base de donn�e avec le 		nom fournit dans la combobox. Si une base existe d�j� avec le m�me nom 		alors nous allons simplement ouvrir celle qui existe d�j�
     + Le bouton S�lectionner lui permet de reprendre une base de donn�e d�j� existante. Si celle-ci n'existe pas nous en cr�ons une nouvelle totalement vide.
                + Le bouton Quitter permet tout simplement de quitter.
                + Le bouton avec trois petits point permet d'ouvrir un explorateur de 			      fichier dans le but de faciliter la s�lection des fichiers de base de donn�es. 			      Une fois un fichier choisit son chemin et son nom sont inscrits dans la 			      combobox.

Il est possible plus tard de rappeler cette fen�tre via l'interface de navigation. Cela permet de changer � tout instant la base de donn�e que l'on souhaite utiliser.

 * \subsection sub2 Navigation et gestion des points

L'interface de navigation est la fen�tre principale. Elle permet de faire la majorit� des taches du logiciel. Elle est constitu� de menu qui permettent de contr�ler l'application. La majorit� des options de navigation se trouvent ici. C'est la fen�tre ou l'utilisateur passera normalement le plus clair de son temps.


\image html intnav.jpeg

L'interface est compos� de tr�s nombreux �l�ments :

Une carte sur laquelle nous affichons les points autour de la croix. Celle ci repr�sente  l'endroit que souhaite voir l'utilisateur. Les Points sont dessin�s dessus en temps r�el au fur et a mesure que l'utilisateur se prom�ne sur la carte.
Une ListeBox � droite. Elle permet d'afficher le nom des points repr�sent�s sur la carte. Il y a deux interactions possibles avec la liste box. Le double clic sur un item ouvre une fen�tre qui permet de d�crire le point s�lectionn�.
Une fois qu'un point � �tait s�lectionn� dans la liste il est possible de cliquer sur le bouton centrer dans le but de centrer la carte sur le point.
Le bouton centrer qui comme dit pr�c�demment permet de centrer la carte sur un point d�fini.
Une SpinBox qui prend par d�faut la valeur 10. Elle permet de choisir le nombre de points que l'on souhaite afficher sur la carte. Il est possible d'aller de 0 � 99999. Il est important de remarquer qu'� partir de 1000 la fluidit� commence � �tre compromise.
Le TextBox chaine de Recherche permet de taper une chaine qui va servir de filtre � la fois sur le nom et sur la d�scription des points. Seuls les points ayant dans leur nom ou leur description la chaine seront affich�s.
La combobox cat�gorie permet de choisir une seule et unique cat�gorie � afficher sur la carte.

Important : Il est n�cessaire faire remarquer � l'utilisateur que les contraintes sont cumulatives. Cha�ne et cat�gorie sont prises en compte simultan�ment.
Une ProgressBar indique l'avancement du t�l�chargement des points ainsi que leurs mise en place dans la base de donn�e.
Le bouton t�l�charger permet de t�l�charger les 100 points les plus proches autour du centre de la carte. Cela signifie que lorsque l'utilisateur souhaite avoir des points � l'endroit ou il est et si il n'y en a pas dans la base donn�, il doit cliquer sur le bouton t�l�charger.
La CheckBox auto t�l�chargement permet lorsqu'elle est coch� d'activer le streaming des points en temps r�el. Lorsque l'utilisateur se d�place et qu'il n'y a pas de point � l'endroit ou celui ci est. L'application t�l�charge automatiquement les points de mani�re transparente.
Il existe aussi un slider verticale qui permet de choisir le niveau de zoom. Celui-ci est repr�sent� par le chiffre � cot�. Le zoom va de 0 � 17.
L'interface est aussi constitu�e de trois menus.
Le menu � menu � permet de quitter l'application
Le menu BDD permet d'acc�der d'acc�der au choix de la BDD, � la gestion de la BDD ou � l'export de celle-ci en fichier .csv

 * \subsection sub3 visualisation d'un point


\image html visu.jpeg

Cette interface est accessible par deux chemins. En cliquant sur un point repr�sent� sur la carte ou en double cliquant sur le nom d'un point.
Celle ci permet d'afficher les informations concernants ce point.
Aucun des �l�ments n'est �ditable l'interface n'a pour but que d'afficher les caract�ristiques du point.
Pas de les modifier.

 * \subsection sub4 Ajout et edition des points


 \image html bddg.jpeg

Cette interface est accessible en cliquant sur gestion BDD dans le menu BDD dans la fen�tre de navigation. C'est via cette fen�tre que nous pouvons voir , ajouter et �diter des points.
Il y a plusieurs parties. La premi�re partie concerne les points.
Elle est compos� :
    -D'une table qui affiche tous les points dans la base de donn�es avec toutes ces caract�ristiques sauf les horaires qui font l'objet de la deuxi�me partie. Tout les champs sont �ditables. Cela permet de modifier � la vol� un point en modifiant ces attributs directement dans la table.
    -D'une groupbox contenant les �l�ments n�cessaire � l'affichage des informations sur le point. Elle permet aussi l'�dition de ces informations. Dans cette groupbox il y a deux boutons.

\image html catg.jpeg

Le premier permet la gestion des cat�gories. Il affiche une fen�tre compos� d'une table regroupant toutes les cat�gories. Ainsi que de trois boutons :
Le bouton modifier permet de modifier le nom d'une cat�gorie.
Le bouton ajouter permet d'ajouter une cat�gorie.
Le bouton supprimer permet de supprimer une cat�gorie. Attention comme il est affich� sur la fen�tre d'�dition il est possible que cela d�truise la coh�rence de la base de donn�es si certains points utilisent encore la cat�gorie supprim�.
Le deuxi�me bouton permet simplement de r�cup�rer les coordonn�es actuel sur la carte de l'interface principale dans le but de les appliquer au point en cours.

Dans cette premi�re partie il y a trois boutons importants :
Le bouton ajouter permet d'ajouter une point contenant des informations de base. Pour le compl�ter il suffit de le s�lectionner puis d'�diter ses champs.
Le bouton supprimer permet de supprimer un point et toutes ces informations.
Le bouton mettre � jour permet de sauvegarder toutes les modifications effectu�es sur les points dans la base de donn�es.

Il y a une deuxi�me partie dans cette fen�tre celle de la gestion des horaires.

Elle est compos� d'une table qui permet d'afficher les horaires d'un point s�lectionn� dans la table des points.

Ainsi qu'une combobox qui permet de choisir un jour et deux TextBox(s) pour pouvoir entrer l'heure de d�but et l'heure de fin.
Les champs dans la table sont �ditables.

Il y a aussi comme d'habitude trois boutons. Un pour ajouter , un pour supprimer et un dernier pour mettre � jour les horaires.

 * \section ch2 Structure de la base de donnée
La base de données est constituée de plusieurs tables permettant d’avoir une structure cohérente est ainsi d’utiliser les modèles proposés par Qt.\n
Notre application se repose sur quatre tables :
-          La table points qui contient toutes les informations sur un point
-          La table categories, qui contient le nom des différentes catégories, elle est en relation avec la table points
-          La table heures, qui contient les informations heures d’ouverture et de fermeture ainsi que le jour. Cette table est en relation avec la table points.\n
-          La table jours, contient les jours de la semaine, cette table et en relation avec la table heures.
Cette structure permet donc de gère un nombre infini de points définis par :
-          Un nom, une catégorie, une latitude, une longitude, un nombre infini de plages horaires et une description.\n
Le diagramme suivant montre la structure de la base de données :\n

\image html bdd.jpeg

 *
 * \section ch3 Structure du programme

Cette documentation est complète, diagrammes uml, commentaires des fonctions publiques et privées, notes d'utilisations et incorporation du code source.\n
Il est cependant intéressant de souligner quelques points :
\subsection ch31 La classe application
Cette classe a été écrite en vue d'une traduction dynamique de l'application et pour faciliter l'utilisation des paramètres propre �  l'application (QSetings).
En effet, la traduction d'un document fait appelle aux méthodes translate et installTranslator de la classe QApplication. Cette classe est nécessaire dès l'initialisation du programme.
Or, pour une traduction dynamique, il est nécessaire de posséder l'instanciation de cette classe qui est propre au programme.
C'est pour quoi nous avons créer une classe singleton nomée application, cette denière hérite de QApplication est permet donc de récupèrer la classe principale n'importe où dans le programme.\n

En ce qui concerne les QSetings, dans notre cas, ils sont utilisés dès l'ouverture de l'application et ils doivent être enregistrés �  la fermeture de celle-ci.
Pour ce faire, nous utilisons le constructeur de la classe application et son destructeur. Pour mieux visualiser cet enjeu, rendez vous �  l'explication de la classe application : \ref application .

\subsection ch32 Gestions de la base de données
Au cours de la vie du programme, de nombreuses bases de données sont amenées a créé et utilisé, de nombreuses requêtes seront effectuées.
Du point de vue de la conception du logiciel, cela posait des problèmes d'accès et le descripteur de base de données devait être transmis de classe en classe ...\n
Pour résoudre ces problèmes, nous avons créé une classe database qui est un singleton, ainsi, nous avons accès �  notre base �  tout moment, et ce en toute sécurité pour elle et les données.
Pour plus d'information sur cette classe, regardez l'explication de la classe database : \ref database .\n

En ce qui concerne l'implémentation des méthodes de gestion des tables, elles ont été dissociées dans plusieurs bibliothèques et non dans des classes, car on ne peut hérité d'un singleton
(la seule solution est de "frender" les deux classes, ce qui n'est conceptuellement pas envisageable). De plus l'emploi de méthodes et non de fonctions été plus lord d'utilisation et n'apporter rien.
Pour mieux cerner cette explication regardez les bibliothèques :\n
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

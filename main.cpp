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

 * \subsection sub2 Navigation et gestion des points

 * \subsection sub3 Ajout et edition des points

 * \subsection sub4 Charger et exporter de base de donnee

 * \subsection sub5 Traduction dinamique de l'application

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
Cette classe a été écrite en vue d'une traduction dynamique de l'application et pour faciliter l'utilisation des paramètres propre à l'application (QSetings).
En effet, la traduction d'un document fait appelle aux méthodes translate et installTranslator de la classe QApplication. Cette classe est nécessaire dès l'initialisation du programme.
Or, pour une traduction dynamique, il est nécessaire de posséder l'instanciation de cette classe qui est propre au programme.
C'est pour quoi nous avons créer une classe singleton nomée application, cette denière hérite de QApplication est permet donc de récupèrer la classe principale n'importe où dans le programme.\n

En ce qui concerne les QSetings, dans notre cas, ils sont utilisés dès l'ouverture de l'application et ils doivent être enregistrés à la fermeture de celle-ci.
Pour ce faire, nous utilisons le constructeur de la classe application et son destructeur. Pour mieux visualiser cet enjeu, rendez vous à l'explication de la classe application : \ref application .

\subsection ch32 Gestions de la base de données
Au cours de la vie du programme, de nombreuses bases de données sont amenées a créé et utilisé, de nombreuses requêtes seront effectuées.
Du point de vue de la conception du logiciel, cela posait des problèmes d'accès et le descripteur de base de données devait être transmis de classe en classe ...\n
Pour résoudre ces problèmes, nous avons créé une classe database qui est un singleton, ainsi, nous avons accès à notre base à tout moment, et ce en toute sécurité pour elle et les données.
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

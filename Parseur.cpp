


void Parseur::Parser(QString path,float posx,float posy,float zoom ,Carte* carteA)
{

    QList<POI*> QLP;


    data_points datapoints = data_points();
    QDomDocument doc;
  //********************************
  // Read the DOM tree form file
  //********************************
 qDebug()<<"debut Parsage" << endl;
  QFile file(path);
  if(!file.open(QFile::ReadOnly | QFile::Text)){
   // qDebug()<<"oups ::" << "fichier introuvable" << endl;
      throw("toto");
  }

  doc.setContent(&file);
  file.close();

  //********************************
  // Parse the DOM tree
  //********************************
  QDomElement kml=doc.documentElement();
  //desente de deux niveaux
  QDomElement document = kml.firstChild().toElement();
  QDomElement Placemark = document.firstChild().toElement();
  QDomElement node;
  QDomElement childnode;

  //parcourt des lieux
  while(!Placemark.isNull())
  {
      POI* PointOfInterest = new POI();

      node = Placemark.firstChild().toElement();

      while(!node.isNull()){

          if(node.tagName() == "categorie"){
            PointOfInterest->SetCat(node.text());

          }
          else if(node.tagName() == "nom"){
              PointOfInterest->SetName(node.text());

          }
          else if(node.tagName() == "Point"){
              childnode = node.firstChild().toElement();
              if(childnode.tagName() == "coordinates"){
                  PointOfInterest->Setlat(QString(childnode.text().split(",")[0]).toFloat());
                  PointOfInterest->Setlong(QString(childnode.text().split(",")[1]).toFloat());
                  }
          }

          node = node.nextSibling().toElement();
      }

      Placemark = Placemark.nextSibling().toElement();
      QLP.append(PointOfInterest);
  }
   int i;
   for(i=0;i<QLP.count();i++)
   {
        datapoints.addPoint(QLP.value(i)->GetCat(),QLP.value(i)->GetName(),QLP.value(i)->Getlat(),QLP.value(i)->Getlon());
   }

   QVector<POI> VPOI;

   VPOI = datapoints.getPointImp(posx,posy,zoom);

carteA.AjouterPoints(VPOI);
}

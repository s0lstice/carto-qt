var NAVTREE =
[
  [ "Cartographie de lieux", "index.html", [
    [ "Cartographie de lieux", "index.html", null ],
    [ "Liste des classes", "annotated.html", [
      [ "application", "a00001.html", null ],
      [ "AskDataBase", "a00002.html", null ],
      [ "Carte", "a00003.html", null ],
      [ "data_categories", "a00004.html", null ],
      [ "data_csv", "a00005.html", null ],
      [ "data_heures", "a00006.html", null ],
      [ "data_jours", "a00007.html", null ],
      [ "data_points", "a00008.html", null ],
      [ "database", "a00009.html", null ],
      [ "edit_point_gui", "a00010.html", null ],
      [ "edite_categories", "a00011.html", null ],
      [ "heure", "a00012.html", null ],
      [ "MontrerPoint", "a00013.html", null ],
      [ "POI", "a00014.html", null ],
      [ "QApplication", "a00015.html", null ],
      [ "QDialog", "a00016.html", null ],
      [ "QMainWindow", "a00017.html", null ],
      [ "Ui::AskDataBase", "a00018.html", null ],
      [ "Ui::Carte", "a00019.html", null ],
      [ "Ui::edit_point", "a00020.html", null ],
      [ "Ui::MontrerPoint", "a00021.html", null ],
      [ "Ui_AskDataBase", "a00022.html", null ],
      [ "Ui_Carte", "a00023.html", null ],
      [ "Ui_edit_point", "a00024.html", null ],
      [ "Ui_MontrerPoint", "a00025.html", null ]
    ] ],
    [ "Index des classes", "classes.html", null ],
    [ "Hiérarchie des classes", "hierarchy.html", [
      [ "data_categories", "a00004.html", null ],
      [ "data_csv", "a00005.html", null ],
      [ "data_heures", "a00006.html", null ],
      [ "data_jours", "a00007.html", null ],
      [ "data_points", "a00008.html", null ],
      [ "database", "a00009.html", null ],
      [ "heure", "a00012.html", null ],
      [ "POI", "a00014.html", null ],
      [ "QApplication", "a00015.html", [
        [ "application", "a00001.html", null ]
      ] ],
      [ "QDialog", "a00016.html", [
        [ "edit_point_gui", "a00010.html", null ],
        [ "edite_categories", "a00011.html", null ],
        [ "MontrerPoint", "a00013.html", null ]
      ] ],
      [ "QMainWindow", "a00017.html", [
        [ "AskDataBase", "a00002.html", null ],
        [ "Carte", "a00003.html", null ]
      ] ],
      [ "Ui_AskDataBase", "a00022.html", [
        [ "Ui::AskDataBase", "a00018.html", null ]
      ] ],
      [ "Ui_Carte", "a00023.html", [
        [ "Ui::Carte", "a00019.html", null ]
      ] ],
      [ "Ui_edit_point", "a00024.html", [
        [ "Ui::edit_point", "a00020.html", [
          [ "edit_point_gui", "a00010.html", null ]
        ] ]
      ] ],
      [ "Ui_MontrerPoint", "a00025.html", [
        [ "Ui::MontrerPoint", "a00021.html", null ]
      ] ]
    ] ],
    [ "Membres de classe", "functions.html", null ],
    [ "Liste des fichiers", "files.html", [
      [ "application.cpp", "a00026.html", null ],
      [ "application.h", "a00027.html", null ],
      [ "askdatabase.cpp", "a00028.html", null ],
      [ "askdatabase.h", "a00029.html", null ],
      [ "carte.cpp", "a00030.html", null ],
      [ "carte.h", "a00031.html", null ],
      [ "data_categories.cpp", "a00032.html", null ],
      [ "data_categories.h", "a00033.html", null ],
      [ "data_csv.cpp", "a00034.html", null ],
      [ "data_csv.h", "a00035.html", null ],
      [ "data_heures.cpp", "a00036.html", null ],
      [ "data_heures.h", "a00037.html", null ],
      [ "data_jours.cpp", "a00038.html", null ],
      [ "data_jours.h", "a00039.html", null ],
      [ "data_points.cpp", "a00040.html", null ],
      [ "data_points.h", "a00041.html", null ],
      [ "database.cpp", "a00042.html", null ],
      [ "database.h", "a00043.html", null ],
      [ "edit_point_gui.cpp", "a00044.html", null ],
      [ "edit_point_gui.h", "a00045.html", null ],
      [ "edite_categories.cpp", "a00046.html", null ],
      [ "edite_categories.h", "a00047.html", null ],
      [ "heure.cpp", "a00048.html", null ],
      [ "heure.h", "a00049.html", null ],
      [ "main.cpp", "a00050.html", null ],
      [ "montrerpoint.cpp", "a00051.html", null ],
      [ "montrerpoint.h", "a00052.html", null ],
      [ "POI.h", "a00053.html", null ],
      [ "ui_askdatabase.h", "a00054.html", null ],
      [ "ui_carte.h", "a00055.html", null ],
      [ "ui_edition_point.h", "a00056.html", null ],
      [ "ui_montrerpoint.h", "a00057.html", null ]
    ] ],
    [ "Membres de fichier", "globals.html", null ]
  ] ]
];

function createIndent(o,domNode,node,level)
{
  if (node.parentNode && node.parentNode.parentNode)
  {
    createIndent(o,domNode,node.parentNode,level+1);
  }
  var imgNode = document.createElement("img");
  if (level==0 && node.childrenData)
  {
    node.plus_img = imgNode;
    node.expandToggle = document.createElement("a");
    node.expandToggle.href = "javascript:void(0)";
    node.expandToggle.onclick = function() 
    {
      if (node.expanded) 
      {
        $(node.getChildrenUL()).slideUp("fast");
        if (node.isLast)
        {
          node.plus_img.src = node.relpath+"ftv2plastnode.png";
        }
        else
        {
          node.plus_img.src = node.relpath+"ftv2pnode.png";
        }
        node.expanded = false;
      } 
      else 
      {
        expandNode(o, node, false);
      }
    }
    node.expandToggle.appendChild(imgNode);
    domNode.appendChild(node.expandToggle);
  }
  else
  {
    domNode.appendChild(imgNode);
  }
  if (level==0)
  {
    if (node.isLast)
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2plastnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2lastnode.png";
        domNode.appendChild(imgNode);
      }
    }
    else
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2pnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2node.png";
        domNode.appendChild(imgNode);
      }
    }
  }
  else
  {
    if (node.isLast)
    {
      imgNode.src = node.relpath+"ftv2blank.png";
    }
    else
    {
      imgNode.src = node.relpath+"ftv2vertline.png";
    }
  }
  imgNode.border = "0";
}

function newNode(o, po, text, link, childrenData, lastNode)
{
  var node = new Object();
  node.children = Array();
  node.childrenData = childrenData;
  node.depth = po.depth + 1;
  node.relpath = po.relpath;
  node.isLast = lastNode;

  node.li = document.createElement("li");
  po.getChildrenUL().appendChild(node.li);
  node.parentNode = po;

  node.itemDiv = document.createElement("div");
  node.itemDiv.className = "item";

  node.labelSpan = document.createElement("span");
  node.labelSpan.className = "label";

  createIndent(o,node.itemDiv,node,0);
  node.itemDiv.appendChild(node.labelSpan);
  node.li.appendChild(node.itemDiv);

  var a = document.createElement("a");
  node.labelSpan.appendChild(a);
  node.label = document.createTextNode(text);
  a.appendChild(node.label);
  if (link) 
  {
    a.href = node.relpath+link;
  } 
  else 
  {
    if (childrenData != null) 
    {
      a.className = "nolink";
      a.href = "javascript:void(0)";
      a.onclick = node.expandToggle.onclick;
      node.expanded = false;
    }
  }

  node.childrenUL = null;
  node.getChildrenUL = function() 
  {
    if (!node.childrenUL) 
    {
      node.childrenUL = document.createElement("ul");
      node.childrenUL.className = "children_ul";
      node.childrenUL.style.display = "none";
      node.li.appendChild(node.childrenUL);
    }
    return node.childrenUL;
  };

  return node;
}

function showRoot()
{
  var headerHeight = $("#top").height();
  var footerHeight = $("#nav-path").height();
  var windowHeight = $(window).height() - headerHeight - footerHeight;
  navtree.scrollTo('#selected',0,{offset:-windowHeight/2});
}

function expandNode(o, node, imm)
{
  if (node.childrenData && !node.expanded) 
  {
    if (!node.childrenVisited) 
    {
      getNode(o, node);
    }
    if (imm)
    {
      $(node.getChildrenUL()).show();
    } 
    else 
    {
      $(node.getChildrenUL()).slideDown("fast",showRoot);
    }
    if (node.isLast)
    {
      node.plus_img.src = node.relpath+"ftv2mlastnode.png";
    }
    else
    {
      node.plus_img.src = node.relpath+"ftv2mnode.png";
    }
    node.expanded = true;
  }
}

function getNode(o, po)
{
  po.childrenVisited = true;
  var l = po.childrenData.length-1;
  for (var i in po.childrenData) 
  {
    var nodeData = po.childrenData[i];
    po.children[i] = newNode(o, po, nodeData[0], nodeData[1], nodeData[2],
        i==l);
  }
}

function findNavTreePage(url, data)
{
  var nodes = data;
  var result = null;
  for (var i in nodes) 
  {
    var d = nodes[i];
    if (d[1] == url) 
    {
      return new Array(i);
    }
    else if (d[2] != null) // array of children
    {
      result = findNavTreePage(url, d[2]);
      if (result != null) 
      {
        return (new Array(i).concat(result));
      }
    }
  }
  return null;
}

function initNavTree(toroot,relpath)
{
  var o = new Object();
  o.toroot = toroot;
  o.node = new Object();
  o.node.li = document.getElementById("nav-tree-contents");
  o.node.childrenData = NAVTREE;
  o.node.children = new Array();
  o.node.childrenUL = document.createElement("ul");
  o.node.getChildrenUL = function() { return o.node.childrenUL; };
  o.node.li.appendChild(o.node.childrenUL);
  o.node.depth = 0;
  o.node.relpath = relpath;

  getNode(o, o.node);

  o.breadcrumbs = findNavTreePage(toroot, NAVTREE);
  if (o.breadcrumbs == null)
  {
    o.breadcrumbs = findNavTreePage("index.html",NAVTREE);
  }
  if (o.breadcrumbs != null && o.breadcrumbs.length>0)
  {
    var p = o.node;
    for (var i in o.breadcrumbs) 
    {
      var j = o.breadcrumbs[i];
      p = p.children[j];
      expandNode(o,p,true);
    }
    p.itemDiv.className = p.itemDiv.className + " selected";
    p.itemDiv.id = "selected";
    $(window).load(showRoot);
  }
}


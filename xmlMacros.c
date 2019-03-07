const xmlChar* extractWidgetProperty(const xmlChar* widgetName, const xmlChar* property)
{
	//	Charge l'arborescence du fichier XML dans la memoire
	xmlDoc *doc = xmlReadFile(PROPS,NULL,0);
	
	//	Verifier si le fichier a bien été chargé
	if(doc == NULL)
	{
		printf("Le fichier contenant les propriétés n'a pu être chargé");
		exit(1);
	}
	
	//	Retrouver le noeud pere 
	xmlNode *root = xmlDocGetRootElement(doc);
	
	//	Retrouver le noeud contenant les propriétés du widget
	xmlNode *widgetNode = root->children;
	for( ; widgetNode; widgetNode = widgetNode->next)
	{
		if((!xmlStrcmp(widgetNode->name,(const xmlChar*)widgetName)))
		{
			break;
		}
	}
	
	//	Verifier si le widget existe dans le fichier
	if(widgetNode == NULL)
	{
		printf("Les propriétés du noeud %s n'ont pas été trouvé", widgetName);
		exit(1);
	}
	
	//	Retrouver le noeud correspondant à la propriété recherchée
	xmlNode noeudPropriete = widgetNode->children;
	for( ; noeudPropriete; noeudPropriete = noeudPropriete->next)
	{
		if((!xmlStrcmp(noeudPropriete->name,(const xmlChar*)property)))
		{
			break;
		}
	}
	
	//	Verifier si le widget existe dans le fichier
	if(noeudPropriete == NULL)
	{
		printf("La propriété %s du widget %s n'existe pas", property, widgetName);
		exit(1);
	}
	
	const xmlChar* propertyContent = xmlNodeGetContent(noeudPropriete);
	
	if(propertyContent == NULL)
	{
		printf("La propriété %s du widget %s est vide", property, widgetName);
		exit(1);
	}
	
	return propertyContent;
	
}
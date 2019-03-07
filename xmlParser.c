#include <libxml/tree.h>
#include <libxml/parser.h>

const xmlChar* extractWidgetProperty(const xmlChar* widgetName, const xmlChar* property)
{
	//	Charge l'arborescence du fichier XML dans la memoire
	xmlDoc *doc = xmlReadFile("widgetProperties.xml",NULL,0);

	//	Verifier si le fichier a bien �t� charg�
	if(doc == NULL)
	{
		printf("Le fichier contenant les propri�t�s n'a pu �tre charg�");
		exit(1);
	}

	//	Retrouver le noeud pere
	xmlNode *root = xmlDocGetRootElement(doc);

	//	Retrouver le noeud contenant les propri�t�s du widget
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
		printf("Les propri�t�s du noeud %s n'ont pas �t� trouv�", widgetName);
		exit(1);
	}

	//	Retrouver le noeud correspondant � la propri�t� recherch�e
	xmlNode *noeudPropriete = widgetNode->children;
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
		printf("La propri�t� %s du widget %s n'existe pas", property, widgetName);
		exit(1);
	}

	const xmlChar *propertyContent = xmlNodeGetContent(noeudPropriete);

	if(propertyContent == NULL)
	{
		printf("La propri�t� %s du widget %s est vide", property, widgetName);
		exit(1);
	}

	return propertyContent;
}


int extractWidgetNumericProperty(const xmlChar* widgetName, const xmlChar* property)
{
	//	Charge l'arborescence du fichier XML dans la memoire
	xmlDoc *doc = xmlReadFile("widgetProperties.xml",NULL,0);

	//	Verifier si le fichier a bien �t� charg�
	if(doc == NULL)
	{
		printf("Le fichier contenant les propri�t�s n'a pu �tre charg�");
		exit(1);
	}

	//	Retrouver le noeud pere
	xmlNode *root = xmlDocGetRootElement(doc);

	//	Retrouver le noeud contenant les propri�t�s du widget
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
		printf("Les propri�t�s du noeud %s n'ont pas �t� trouv�", widgetName);
		exit(1);
	}

	//	Retrouver le noeud correspondant � la propri�t� recherch�e
	xmlNode *noeudPropriete = widgetNode->children;
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
		printf("La propri�t� %s du widget %s n'existe pas", property, widgetName);
		exit(1);
	}

	const xmlChar *propertyContent = xmlNodeGetContent(noeudPropriete);

	if(propertyContent == NULL)
	{
		printf("La propri�t� %s du widget %s est vide", property, widgetName);
		exit(1);
	}

	return (int)atoi((char*)propertyContent);

}

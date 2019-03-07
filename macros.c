
#include "xmlParser.c"

GtkWidget* createWindow(const xmlChar* widgetName)
{

    GtkWidget *window;
    int choice = extractWidgetNumericProperty(widgetName,"windowType");
    printf("choice : %d\n", choice);
    // type de la fenêtre
    if(choice)
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    else
        window = gtk_window_new(GTK_WINDOW_POPUP);

    choice = (char)extractWidgetNumericProperty(widgetName,"position");

    switch((int)choice)
    {
    case 1:
        gtk_window_set_position(window,GTK_WIN_POS_NONE);
    case 2:
        gtk_window_set_position(window,GTK_WIN_POS_CENTER );
    case 3:
        gtk_window_set_position(window,GTK_WIN_POS_MOUSE);
    case 4:
        gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    case 5:
        gtk_window_set_position(window,GTK_WIN_POS_CENTER_ON_PARENT);
    }


    int width, height;
    width = extractWidgetNumericProperty(widgetName,"width");
    height = extractWidgetNumericProperty(widgetName,"height");
    printf("width : %d height : %d", width, height);
    gtk_window_set_default_size(window,width,height);

    char* title = extractWidgetProperty(widgetName,"title");
    printf("\ntitle: %s", title);
    gtk_window_set_title(GTK_WINDOW(window),title);



    return window;
}

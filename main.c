#include <stdio.h>
#include <gtk/gtk.h>
#include "macros.c"

int main(int argc,char **argv)
{
    //  Initialisation de GTK
    gtk_init(&argc,&argv);

    //  Declaration de la fenêtre principale
    GtkWidget *mainWindow = createWindow("mainWindow");


    //  Affichage de tous les widgets
    gtk_widget_show_all(mainWindow);

    //  La boucle principale de la lib GTK
    gtk_main();
    return 0;
}

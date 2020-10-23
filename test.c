#include <gtk/gtk.h>

gboolean on_button_press(GtkWidget* widget,
  GdkEventButton *event, GdkWindowEdge edge) {
      
  printf("%d\n", event->type);
  
  return TRUE;
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(on_button_press), NULL);
  g_signal_connect(G_OBJECT(window), "button-release-event", G_CALLBACK(on_button_press), NULL);
  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

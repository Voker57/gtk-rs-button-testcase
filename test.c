#include <gtk/gtk.h>

static void
rotate_begin_cb (GtkGesture       *gesture,
                double          start_x,
               double          start_y,
               gpointer        user_data)
{
  printf("hi %f %f\n", start_x, start_y);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  
  GtkGesture *gesture = gtk_gesture_drag_new (window);
  gtk_gesture_single_set_touch_only (GTK_GESTURE_SINGLE (gesture), FALSE);
  gtk_event_controller_set_propagation_phase (GTK_EVENT_CONTROLLER (gesture),
                                              GTK_PHASE_TARGET);
  g_signal_connect (gesture, "drag-begin",
                    G_CALLBACK (rotate_begin_cb), NULL);

  /* Attach the gesture as widget data, or optionally unref when destroying the widget */
//   g_object_set_data_full (G_OBJECT (entry), "foobar-custom-gesture",
//                           gesture, g_object_unref);

  

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

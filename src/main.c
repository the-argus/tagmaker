#include <gtk/gtk.h>

static void button_callback(GtkWidget *widget, gpointer data) {
  g_print("Hello World");
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;

  window = gtk_application_window_new(app);
  // GTK_WINDOW() is a macro which casts to GtkWindow but checks
  // if (window) is already a GtkWindow and emits a warning if so
  gtk_window_set_title(GTK_WINDOW(window), "Tagmaker");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);

  // create a box whose text is aligned to center
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  // create button
  button = gtk_button_new_with_label("testing button fr!");

  // connect signals
  g_signal_connect(button, "clicked", G_CALLBACK(button_callback), NULL);
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy),
                           window);

  gtk_widget_show(window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("Tagmaker", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}

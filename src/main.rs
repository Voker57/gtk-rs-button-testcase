extern crate gtk;
extern crate gio;

// To import all needed traits.
use gtk::prelude::*;
use gio::prelude::*;

use std::env;

fn main() {
    let uiapp = gtk::Application::new(Some("org.gtkrsnotes.demo"),
                                      gio::ApplicationFlags::FLAGS_NONE)
                                 .expect("Application::new failed");
    uiapp.connect_activate(|app| {
        // We create the main window.
        let win = gtk::ApplicationWindow::new(app);

        // Then we set its size and a title.
        win.set_default_size(320, 200);
        win.set_title("Basic example");

        let scrolled = gtk::ScrolledWindow::new(
		Some(&gtk::Adjustment::new(10000.,0.,9000.,1.,1.,1000.)),
		Some(&gtk::Adjustment::new(10000.,0.,9000.,1.,1.,1000.))
	);
        let fixed = gtk::Fixed::new();
        fixed.set_size_request(6e6 as i32, 6e6 as i32);
        scrolled.add(&fixed);
        win.add(&scrolled);
        
        // Don't forget to make all widgets visible.
        win.show_all();
    });
    uiapp.run(&env::args().collect::<Vec<_>>());
}

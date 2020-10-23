use gtk::prelude::*;
use gio::prelude::*;

fn main() {
	let application = gtk::Application::new(Some("org.gtk.example"), Default::default()).unwrap();


	application.connect_activate(move |app| {
		let window = gtk::ApplicationWindow::new(app);
		window.set_title("Window");
		window.set_default_size(200, 200);
		
		let gesture_drag = gtk::GestureDrag::new(&window);
		gesture_drag.set_touch_only(false);
 		gesture_drag.set_propagation_phase(gtk::PropagationPhase::Target);
		gesture_drag.connect_drag_begin(move |g_d, x, y| {
			println!("hi {} {}", x, y);
		});
		
		window.show_all();
	});

	application.run(&[]);
} 

use gtk::prelude::*;
use gio::prelude::*;

fn main() {
	let application = gtk::Application::new(None, Default::default()).unwrap();


	application.connect_activate(move |app| {
		let window = gtk::ApplicationWindow::new(app);
		window.set_title("testcase");
				
		window.connect_button_press_event(move |window, ev| {
			println!("{:?}", ev.get_event_type());
			gtk::Inhibit(false)
		});
		window.connect_button_release_event(move |window, ev| {
			println!("{:?}", ev.get_event_type());
			gtk::Inhibit(false)
		});
		window.show_all();
	});

	application.run(&[]);
} 

#ifndef XCAPTURE_H
#define XCAPTURE_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

#include "xwinref.h"

namespace godot {

class XCapture : public RefCounted {
	GDCLASS(XCapture, RefCounted)

private:

protected:
	static void _bind_methods();

public:
	XCapture();
	~XCapture();

	Display* display_pointer;
	Window* window_pointer;

	static Ref<XCapture> initialize(Ref<XWinRef> win_ref);

	Ref<Image> render_window();
};

}

#endif

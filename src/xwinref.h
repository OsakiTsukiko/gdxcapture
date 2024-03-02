#ifndef XWINREF_H
#define XWINREF_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref_counted.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/extensions/Xcomposite.h>

namespace godot {

class XWinRef : public RefCounted {
	GDCLASS(XWinRef, RefCounted)

private:

protected:
	static void _bind_methods();

public:
	XWinRef();
	~XWinRef();

    static Array get_win_array();
    static Ref<XWinRef> initialize(u_int32_t id);

    Display* display_pointer;
    Window* window_pointer;
};

}

#endif

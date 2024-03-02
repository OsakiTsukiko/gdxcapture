#include "xwinref.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void XWinRef::_bind_methods() {
    ClassDB::bind_static_method("XWinRef", D_METHOD("get_win_array"), &XWinRef::get_win_array);
    ClassDB::bind_static_method("XWinRef", D_METHOD("initialize", "window_id"), &XWinRef::initialize);
}

XWinRef::XWinRef() {
	// Initialize any variables here.
}

XWinRef::~XWinRef() {
	// Add your cleanup here.
}

Array XWinRef::get_win_array() {
    Array return_array;
    
    Display* display = XOpenDisplay(NULL);
    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    Window root_return, parent_return, *children;
    unsigned int nchildren;
    XQueryTree(display, root, &root_return, &parent_return, &children, &nchildren);

    for (int i = 0; i < nchildren; i += 1) {
        XWindowAttributes attrs;
        XGetWindowAttributes(display, children[i], &attrs);
        if (attrs.map_state == IsViewable && attrs.width > 0 && attrs.height > 0) {
            char* name = NULL;
            XFetchName(display, children[i], &name);
            // printf("%d %s\n", i, (name ? name : "(null)"));
            return_array.append(String((name ? name : "(null)")));
            XFree(name);
        }
    }

    XFree(children);
    XFree(display);

    return return_array;
}

Ref<XWinRef> XWinRef::initialize(u_int32_t id) {
    Display* display = XOpenDisplay(NULL);
    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    Window root_return, parent_return, *children;
    unsigned int nchildren;
    XQueryTree(display, root, &root_return, &parent_return, &children, &nchildren);

    if (id >= nchildren) {
        id = nchildren - 1;
    }

    Ref<XWinRef> r_xwref = {memnew(XWinRef)};

    r_xwref->display_pointer = display;
    r_xwref->window_pointer = (children + id);
    XFree(children);

    return r_xwref;
}
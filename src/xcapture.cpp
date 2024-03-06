#include "xcapture.h"
#include <godot_cpp/core/class_db.hpp>

#include <stdio.h>

using namespace godot;

void XCapture::_bind_methods() {
    ClassDB::bind_static_method("XCapture", D_METHOD("initialize", "win_ref"), &XCapture::initialize);
	ClassDB::bind_method(D_METHOD("render_window"), &XCapture::render_window);
}

XCapture::XCapture() {
	// Initialize any variables here.
}

XCapture::~XCapture() {
	// Add your cleanup here.
}

Ref<XCapture> XCapture::initialize(Ref<XWinRef> win_ref) {
	Ref<XCapture> r_xcap = {memnew(XCapture)};
	r_xcap->display_pointer = win_ref->display_pointer;
	r_xcap->window_pointer = win_ref->window_pointer;
	return r_xcap;
}

Ref<Image> XCapture::render_window() {
    PackedByteArray img_data;

    XCompositeRedirectWindow(display_pointer, *window_pointer, CompositeRedirectAutomatic);
    XSync(display_pointer, False);

    XWindowAttributes attrs;
    XGetWindowAttributes(display_pointer, *window_pointer, &attrs);

    XImage* img = XGetImage(display_pointer, *window_pointer, 0, 0, attrs.width, attrs.height, AllPlanes, ZPixmap);

    for (int i = 0; i < img->width*img->height; i += 1) {
        int idx = i * 4;
        img_data.append(img->data[idx+2]);
        img_data.append(img->data[idx+1]);
        img_data.append(img->data[idx+0]);
        img_data.append(img->data[idx+3]);
    }
    
    XDestroyImage(img);

    return Image::create_from_data(attrs.width, attrs.height, false, Image::FORMAT_RGBA8, img_data);
}
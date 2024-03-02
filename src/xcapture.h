#ifndef XCAPTURE_H
#define XCAPTURE_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/texture2d.hpp>

namespace godot {

class XCapture : public Texture2D {
	GDCLASS(XCapture, Texture2D)

private:

protected:
	static void _bind_methods();

public:
	XCapture();
	~XCapture();
};

}

#endif

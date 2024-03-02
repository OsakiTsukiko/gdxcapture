#ifndef GDXCAPTURE_H
#define GDXCAPTURE_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/texture2d.hpp>

namespace godot {

class GDXCapture : public Texture2D {
	GDCLASS(GDXCapture, Texture2D)

private:

protected:
	static void _bind_methods();

public:
	GDXCapture();
	~GDXCapture();
};

}

#endif

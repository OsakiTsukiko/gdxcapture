extends Node3D

@onready var screen = $MeshInstance3D2/Screen
@onready var sphere_screen = $SphereScreen
@onready var torus_screen = $TorusScreen

var xcomp: XCapture
var mat := StandardMaterial3D.new()

func _ready():
	var idk := XWinRef.get_win_array()
	var ref := XWinRef.initialize(2)
	xcomp = XCapture.initialize(ref)
	mat.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	screen.set_surface_override_material(0, mat)
	sphere_screen.set_surface_override_material(0, mat)
	torus_screen.set_surface_override_material(0, mat)

func _process(delta):
	mat.albedo_texture = ImageTexture.create_from_image(xcomp.render_window())

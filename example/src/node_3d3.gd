extends Node3D

@onready var screen = $MeshInstance3D2/Screen

var xcomp: XCapture
var mat := StandardMaterial3D.new()

func _ready():
	var idk := XWinRef.get_win_array()
	var ref := XWinRef.initialize(3)
	xcomp = XCapture.initialize(ref)
	screen.set_surface_override_material(0, mat)

func _process(delta):
	mat.albedo_texture = ImageTexture.create_from_image(xcomp.render_window())

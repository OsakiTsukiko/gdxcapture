extends Control

@onready var sv = $SubViewport

func _ready():
	var img = sv.get_texture().get_image()
	img.flip_y()
	img.save_png("test.png")
	
func _physics_process(delta):
	var img = sv.get_texture().get_image()
	# img.flip_y()
	img.save_png("test.png")

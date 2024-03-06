extends Control

@onready var text_rect = $TextureRect

var xcomp: XCapture

func _ready():
	var idk := XWinRef.get_win_array()
	var ref := XWinRef.initialize(3)
	xcomp = XCapture.initialize(ref)
	

func _process(delta):
	#if Input.is_action_just_pressed("ui_accept"):
	text_rect.texture = ImageTexture.create_from_image(xcomp.render_window())
		

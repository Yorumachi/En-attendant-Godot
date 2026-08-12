extends Knight

const SPEED = 300.0
const JUMP_VELOCITY = -400.0
var v: Vector2 = Vector2();


func _physics_process(delta: float) -> void:
	# Add the gravity.
	if not is_on_floor():
		v += get_gravity() * delta

	# Handle jump.
	if Input.is_action_just_pressed("up") and is_on_floor():
		v.y = JUMP_VELOCITY

	# Get the input direction and handle the movement/deceleration.
	# As good practice, you should replace UI actions with custom gameplay actions.
	var direction := Input.get_axis("ui_left", "ui_right")
	if direction:
		v.x = direction * SPEED
	else:
		v.x = move_toward(v.x, 0, SPEED)
	velocity = v

	move_and_slide()

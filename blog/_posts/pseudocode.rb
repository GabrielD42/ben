Robot.describe do
  has_a :left_motor do
    on_pin 16
  end

  has_a :right_motor do
    on_pin 17
  end

  (0..(2 * Math::PI)).step(Math::PI / 4).with_index do |theta, pin|
    has_a :distance_sensor do
      on_pin pin
      at_angle theta
    end
    has_a :bump_sensor do
      on_pin pin + 8
      at_angle theta
    end
  end
end

Robot.define :choose_route do |destination|
  # A* search algorithm
  # store commands in stack
  commands << [:turn_left, Math::PI / 2]
  commands << [:go_forwards, 10]
end

Robot.when :hit_wall do |sensor|
  2.times { turn_left(Math::PI / 2) }
  # cm, m, motor steps?
  go_forwards 10
  full_scan
  choose_route destination
  follow_orders
end

# when programming is exiting. better term?
Robot.when :destroyed do |data|
  # save data
end

Robot.choose_route Point.new(5, 5)
Robot.follow_orders

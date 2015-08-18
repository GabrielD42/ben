require 'pi_piper'

puts "Watching pin 17..."

module PiPiper
  def wait_for_change(options, &block)
    pin = PiPiper::Pin.new(options)
    pin.wait_for_change
    if block.arity > 0
      block.call pin
    else
      pin.instance_exec &block
    end
  end

  def once_after(options, &block)
    options[:trigger] = options.delete(:goes) == :high ? :rising : :falling
    wait_for_change options, &block
  end
end

# PiPiper.wait_for_change pin: 17 do |pin|
#   puts "Pin changed from #{pin.last_value} to #{pin.value}"
# end

# PiPiper.once_after pin: 17, goes: :high do
#   puts "Button pressed"
# end

ti, tf = 0, 0
PiPiper.once_after pin: 17, goes: :high do
    ti = Time.now
    puts "Starting timer..."
end
PiPiper.once_after pin: 17, goes: :low do
    tf = Time.now
    puts "Stopping timer..."
end
puts "Button pressed for #{tf - ti} seconds"

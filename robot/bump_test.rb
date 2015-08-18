require 'pi_piper'

puts "Watching pin 17..."

# PiPiper.watch pin: 17 do |pin|
#   puts "Pin changed from #{pin.last_value} to #{pin.value}"
# end

# PiPiper.after pin: 17, goes: :high do
#   puts "Button pressed"
# end

def watch(options, &block)
  new_thread = Thread.new do
    pin = PiPiper::Pin.new(options)
    pin.wait_for_change
    if block.arity > 0
      block.call pin
    else
      pin.instance_exec &block
    end
  end
  new_thread.abort_on_exception = true
  new_thread
end

watch pin: 17 do |pin|
  puts "Pin changed from #{pin.last_value} to #{pin.value}"
end

PiPiper.wait

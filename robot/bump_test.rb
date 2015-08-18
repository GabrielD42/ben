require 'pi_piper'

puts "Watching pin 17..."

# PiPiper.watch pin: 17 do |pin|
#   puts "Pin changed from #{pin.last_value} to #{pin.value}"
# end

# PiPiper.after pin: 17, goes: :high do
#   puts "Button pressed"
# end

module PiPiper
  def wait_for_change(options, &block)
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

  def once_after(options, &block)
    options[:trigger] = options.delete(:goes) == :high ? :rising : :falling
    wait_for_change options, &block
  end
end

# PiPiper.wait_for_change pin: 17 do |pin|
#   puts "Pin changed from #{pin.last_value} to #{pin.value}"
# end

PiPiper.once_after pin: 17, goes: :high do
  puts "Button pressed"
end

puts "Out of block"

PiPiper.wait

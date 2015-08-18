require 'pi_piper'

puts "Watching pin 17..."

# PiPiper.watch pin: 17 do |pin|
#   puts "Pin changed from #{pin.last_value} to #{pin.value}"
# end

# PiPiper.wait

PiPiper.after pin: 17, goes: :high do
  puts "Button pressed"
end

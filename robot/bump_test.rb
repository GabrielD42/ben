require 'pi_piper'
include PiPiper

# watch :pin => 23 do
#   puts "Pin changed from #{last_value} to #{value}"
# end

#Or

after pin: 17, goes: :high do
  puts "Button pressed"
end

PiPiper.wait

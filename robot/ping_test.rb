require 'pi_piper'

# // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
# // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
# digitalWrite(triggerPin, LOW);
# delayMicroseconds(2);
# digitalWrite(triggerPin, HIGH);
# delayMicroseconds(5);
# digitalWrite(triggerPin, LOW);

# // The echo pin is used to read the signal from the PING))): a HIGH
# // pulse whose duration is the time (in microseconds) from the sending
# // of the ping to the reception of its echo off of an object.
# duration = utils::pulseIn(echoPin, HIGH, 100000L);

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

def sleep_microseconds(t)
  sleep t * (10**-6)
end

def distance(trigger_pin, echo_pin)
  trigger_pin = PiPiper::Pin.new(pin: trigger_pin, direction: :out)
  trigger_pin.off
  sleep_microseconds 2
  trigger_pin.on
  sleep_microseconds 5
  trigger_pin.off

  ti, tf = 0, 0
  PiPiper.once_after(pin: echo_pin, goes: :high) { ti = Time.now }
  PiPiper.once_after(pin: echo_pin, goes: :low)  { tf = Time.now }
  puts "Distance: #{(tf - ti) / 29 / 2} cm"
end

loop { distance 17, 18 }

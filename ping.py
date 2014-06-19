import RPi.GPIO as GPIO
import time.sleep

triggerPin = 24
echoPin = 25

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(echoPin, GPIO.IN)
    GPIO.setup(triggerPin, GPIO.OUT)

def loop():
    GPIO.output(triggerPin, GPIO.LOW)
    time.sleep(0.000002)
    GPIO.output(triggerPin, GPIO.HIGH)
    time.sleep(0.000005)
    GPIO.output(triggerPin, GPIO.LOW)
    start = time.time()
    while GPIO.input(echoPin) == 0:
        start = time.time()
    while GPIO.input(echoPin) == 1:
        stop = time.time()
    elapsed = stop - start
    print("Distance: " + elapsed / 74 / 2)

#main
setup()
while True:
    loop()

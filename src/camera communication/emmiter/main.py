from pyb import UART, LED
import sensor
import time

# sensor.reset()  # Reset and initialize the sensor.
# sensor.set_pixformat(sensor.RGB565)  # Set pixel format to RGB565 (or GRAYSCALE)
# sensor.set_framesize(sensor.VGA)  # Set frame size to QVGA (320x240)
# sensor.skip_frames(time=2000)  # Wait for settings take effect.

uart = UART(1, 115200)
led = LED(3)

def send_data(data):
    if not isinstance(data, str):
        data = str(data)
    final_data = data + "\n"
    uart.write(final_data)

while True:
    led.toggle()
    # time.sleep(0.1)
    data = "a" + "," + str(10)
    send_data(data)
    # print(f"Sended data: {data}")
    time.sleep(0.1)
    # led.toggle()

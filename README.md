- Set up Raspberry PI 4 
    - For Raspberry PI 4 set up you will need
        - Raspberry Pi 4
        - Mouse and Keyboard
        - microSD card or a pendrive
        - power supply 15w
        - micro-HDMI to HDMI cable
    - **Set up Raspberry PI OS: Raspbian**  
        - For Windows computers download the raspberry pi Imager tool from the given link. [https://www.raspberrypi.com/software/](https://www.raspberrypi.com/software/) 
        - Install the setup in your system
        - ![](https://remnote-user-data.s3.amazonaws.com/QodGJwEfAJLdjZgkDEzNBWOVihNKrXBA5efd7Iox5i4w_7IUVpt93lv84TpkdV5m_jdVEe8Jcu05YQSzgu3IVS-ecI138-W7Fo33dOEwSPOY686KFS5Xbd7Y-0dtt9VH.png) 
        - Select Raspberry PI OS (32 bit).
        - Mount your microSD card and select in storage options.
        - Click on write, This can take 5 to 10 mins.
    - **Booting up Raspberry PI 4**
        - Connect the keyboard, mouse and monitor cable.
            - use regular USB keyboard and mouse
        - Mount your microSD card or pendrive on RPI.
        - Plug in your Raspberry Pi power supply.
        - When Raspbian boots up for the first time, you will see this Welcome screen:
        - ![](https://remnote-user-data.s3.amazonaws.com/kMlEdJa1TguC5bvqMwC45d1WGL0qkxvbA5bwepzvLMsNVdpMYwU42wnUNUzg5ePrKvXXYnB-UalpeLK6ja_Uoei84BZO-37i6X2elCXZJT96b-ebzelCKtq7MLA5i2sg.png) 
        - select your time zone.
        - preferred language.
        - create a login password.
        - Choose your WiFi network.
        - Now you are ready to start using Raspberry Pi.
    - **Enable VNC server on RPI**  
        - Go to Menu > Preferences > Raspberry Pi Configuration > Interfaces.
        - Enable VNC there
        - ![](https://remnote-user-data.s3.amazonaws.com/P-BgV2J7oT9NLzQhlQyEfjjma_g-j85TmOtCd6lvWrvYDiW5jibVazE7ZndwEseet89iygC80OtmCY1gSOWYyoV-ThziT9yUK638ZtQwCcivyqsBimmT4zyuIpInSp8V.png) 
    - **Setup VNC in your laptop**
        - Download VNC viewer on your laptop using this link. [https://www.realvnc.com/en/connect/download/viewer/windows/](https://www.realvnc.com/en/connect/download/viewer/windows/) 
        - Install VNC viewer setup.
        - Open VNC viewer on your laptop.
        - Type in the IP address of RPI 4.
        - ![](https://remnote-user-data.s3.amazonaws.com/dw6Ruu6B5pScs72x6H9xqBak8K9HBBcyG84FPJfWx3zKUNdYvmOUe0mRNUMyqsyo0zXQyW-E9wIjap8DhEhh-soI69V9lZPx1oZ8h7rwR6FFhRxHYdGpRYnKC_tdCHue.png) 
        - Enter user name "pi".
        - In the password field enter your password that you created earlier for RPI setup.
        - The Raspbian desktop will appear inside a window on your computer.
        - ![](https://remnote-user-data.s3.amazonaws.com/73QQYNQr3aLNrFrC7Y4Cp3V6DwFzJcYsBM8yAwcEcSyyCF5sZFoGIzu4qh88uOQ80XDt75G_jDeyKjDL3DB5wihZt7LO7U7Pyel3e77V8zWnrU7ccj958egtByckXqPV.png) 
- Create ThingsBoard Account  
    - Create a new account on  [https://demo.thingsboard.io/devices](https://demo.thingsboard.io/devices).
    - ![](https://remnote-user-data.s3.amazonaws.com/pO4pPuLGhwWTprIIVpAm5mhNLBhYph2SLyql4XEQQBRqa1vNP70tMEW2GyvVOXBNTAWHfNvE-gTku_YebOZmWBRoDOZelziWlWw9Hts0gv5rGo1kFTl5p_1wjjfqgN2p.png) 
    - Add a new device by clicking on Devices
    - ![](https://remnote-user-data.s3.amazonaws.com/Xe42onEnh2DC9jeTzqexxVsVVQcm7IcEeHfDXeYFB6TFrJk-Nddb8YX2p0TC1nmdGQdIjX5KZ48dMBZaT1gQUYuHgKfJH-3yaNcZ05T_tTRoSlBDAZJrgZDfYdUQCBaT.png) 
    - Give a name and Label.
    - select existing device profile as default.
    - Now click on Add.
    - ![](https://remnote-user-data.s3.amazonaws.com/MAbSm401C5de_ehruDGqKMiNldfCxnE5LW01ExOKZC57nJplxLcRTl9uINvCJkVcM9RZ1DE7YBaI-VfLUnGA5KgNYwXhpnziJSDijWwU9wu7Vlg9iKsFvLoSn0_0mGi7.png) 
    - Click on Access token and copy your device access token.
- Interface DHT11 sensor with Raspberry PI 
    - Plug in your RPI and connect VNC viewer on your laptop
    - Open terminal and create a new directory 
    - ```bash
mkdir demo
``` Change directory to  demo
    - ```bash
cd demo
``` Create a new python file
    - ```bash
nano demo.py
``` Write the code given below
    - ```python
import adafruit_dht
import paho.mqtt.client as paho
import json
import time
import board


ACCESS_TOKEN = "enter-your-access-token-here"
broker = "demo.thingsboard.io"
port = 1883

def on_publish(client.userdata.result):
	print("Data published to thingsboard")
	
client1 = paho.Client("control1")
client1.on_publish = on_publish
client1.username_pw_set(ACCESS_TOKEN)
client1.connect(broker,port,keepalive=60)
sensor = adafruit_dht.DHT11(board.D18)

while True:
	payload = {"Temperature": sensor.temperature, "Humidity":sensor.humidity}
	payload_json = json.dumps(payload)
	
	client1.publish("v1/devices/me/telemetry", payload)
	time.sleep(30)
``` Add your access token that we have copied earlier.
    - press "CTRL+X" to close the editor, press "enter" and then press "y".
    - now lets install required libraries 
    - ```bash
pip install adafruit_dht
``` type the command in terminal
    - ```bash
pip install paho-mqtt
``` 
    - Now connect the DHT11 Sensor with RPI 
        - DHT11 VCC to RPI VCC
        - DHT11 GND to RPI GND
        - DHT11 SIG to RPI GPIO 18
        - ![](https://remnote-user-data.s3.amazonaws.com/D-6y2fvmLtYn1Mq5k5lPb2hRCYmAfWaP-KzcXjyZWWmJa3gIBR1gaaED1fVf4muOUO7nY6lW0-oZJ9OdpYyxd8_A6PRLKZB2y4FCFzNTYQxajqXYEKKFs3EmxCvzoyqh.png) 
    - Now Run the python script
    - ```bash
python demo.py
``` 
    - Open ThingsBoard Dashboard > Devices > select device that we created earlier > Latest Telemetry
    - ![](https://remnote-user-data.s3.amazonaws.com/buiQ01_lO4nwHwLZGvnmILSXOV1Nfu4smm4tKwMV-4HlCIW8IYPB3dVYdkpnKXA7zkZ1xxni0DmrgoOenizqaobFgPCIdFu9NZj4webxRBDFPf8PgH4hRRRYvT50FTUM.png) 
    - If you're able to see Humidity and Temperature value updated then you have successfully connected RPI to ThingsBoard.

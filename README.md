## Basic HTTP Server running on RaspberryPI to handle IO output requests

**Build**

1) Clone repo ``git clone https://github.com/houseofbits/rpi-io-server``

``cd rpi-io-server``

2) Check out libraries

``git submodule init``
``git submodule update``

3) Make & run ``make`` ``./rpiioserver``

4) Create systemd service

``cd /etc/systemd/system``

``sudo nano io-server.service``

```
[Unit]
Description=IO Server
After=network.target

[Service]
ExecStart=/home/pi/Documents/rpi-io-server/rpiioserver
WorkingDirectory=/home/pi/Documents/rpi-io-server
StandardOutput=inherit
StandardError=inherit
Restart=always
User=pi

[Install]
WantedBy=multi-user.target
```

5) Test the service & enable

``sudo systemctl start io-server.service``

``sudo systemctl enable io-server.service``


6) Make HTTP requests to the PI

``http://hostname:8888/set-port-pins?port=[0,1]&pin[0:16]=[0,1]``


**Hardware**

IO Pi Plus from https://www.abelectronics.co.uk
 
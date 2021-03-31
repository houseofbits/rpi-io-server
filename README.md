## Basic HTTP Server running on RaspberryPI to handle IO output requests

**Build**

1) Clone repo ``git clone https://github.com/houseofbits/rpi-io-server``

``cd rpi-io-server``

2) Check out libraries

``git submodule init``
``git submodule update``

3) Make & run ``make`` ``./rpiioserver``

**HTTP Request structure**

``http://hostname:8888/set-port-pins?port=[0,1]&pin[0:16]=[0,1]``

**Hardware**

RPI IO https://www.abelectronics.co.uk/ expansion boards are used
- IO Pi Plus
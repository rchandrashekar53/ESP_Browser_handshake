# ESP_Browser_handshake
Websockets and Microservices to get status of list of devices and browsers accessing ESP device in WLAN network

Implementation:

1. index.h
------------
  
  a) setInteral() will be broadcast the status of browser, WiFi from devices accessing ESP services on the network
  b) this information is relayed to ESP every 1 sec.


2. ESP_BroswerStatus.ino
-------------------------
  a) this recieves the status every 1 sec.
  b) User can implement their additional logice (example - sleep/standby (or) any mode based on the feedback).


# ECSE3038_Lab6
## Aim
This lab is meant to get students more accustomed to the technologies used in designing and implementing an embedded module as part of an IoT system and RESTful API server. As such, the system should consists of an embedded client as well as a server. A detailed outline of the requirements of the lab can be found [here](https://www.notion.so/Lab-6-ccedf972a8ec48e1932ac53df59de8ce).
## Client
The client should consist of an atmega based microcontroller  and an ESP8266 WiFi module. Post requests should constantly be sent from the client to the server. The post request should be programmatically constructed.
## Server
The server should accept a POST request on the path "/tank". The server should take the data sent to it and store that data in a database.

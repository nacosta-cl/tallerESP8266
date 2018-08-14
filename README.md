# tallerESP8266
Codigo y material diseñado para el taller del ESP8266

Distribuido bajo licencia GPLv3: Leer implicancias (Especialmente atribuir autoria y compartir todo el codigo fuente)

Taller proyecto-céntrico diseñado a nivel introductorio-medio para alumnos de universidad y superior que ya hayan tenido exito con un taller en arduino

El codigo esta hecho en ingles!

Taller ESP - Topicos

Proyecto principal: Sensor de temperatura IoT
MOD 1 => Inicio - IOT - sockets
	Incio
		Requiere arduino
		Presentacion programa
	Que es el IoT
		Descripcion
		Aparatos
		Protocolos
		why iot
		Fabricantes involucrados con el IoT
	ESP8266
		Intro
		capacidades
		specs electricas
			3.3v
			consumo
			fuente
		Costos
		WeMos
		ESP8285
		SDK vs Arduino
		OLED
			EJ Dibuja en la OLED
			Fallas comunes en l ESP
	Wifi
		Arquitectura del Wifi
		Modelo de redes
		Router
		EJ scanner
		SSID
		RSSI
		IP
		EJ conectarse a una red y mostrar data DONE
		EJ ipscan DONE
		EJ yield()
		API wifi
			Funciones
			Handlers
	EJ Socket a python: Hello socket
	EJ NTP (directo?)
	EJ ESP8266 a ESP8266
	Energy management
		Sleeps
		EJ deep sleep
		ventajas
MOD 2 => sockes v2 - HTTP - HTML - HTTP Server
	La internet
		Estructura
		IP protocol
			EJ ping en PC
			EJ tracert en PC
			EJ ipconfig/ifconfig/iwconfig 
	Protoclos de la internet
		TCP
		UDP
	OTA firmware
		EJ cargar soft desde el PC
		EJ carga directa via esptool.py
	API
	API REST
		EJ enviar temperatura a adafruit
	JSON
	HTTP cliente
		GET
		EJ google maps API rq
		EJ API
MOD 3 => HTTP Server - SPIFFS - Protocolos
	HTTP Server
		URI
		Rutas
		Forms
			POST
			GET
		HTML
			Tags
				head
				body
				div
				table
			Send svg
			EJ sitio sencillo para led
			CSS
			EJ2 sitio sencillo con estilo
			img
			SD!
	Ethernet
	SD
	Data almacenada
		Info
			ESP.getFlashChipRealSize();
			ESP.getFlashChipSize();
			ESP.getFlashChipMode();
			ESP.getFlashChipId();
			ESP.getFlashChipSpeed();
		SPIFFS
			Estructura
			Data handling
			EJ Logger mensajes
			Data en masa
	mDNS & LLMNR
		EJ montar server
	
MOD 4 => Paquetes - MQTT - MESH - BLE (ESP32)
	EJ NTP (directo?)
	EEPROM
	Sys functions
	SDK
	MQTT
		EJ conn server lunanet
		
	Mesh
	WiFi vs BLE
	Dispositivos con BLE
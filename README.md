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
		Porque aprender del IoT
		Fabricantes involucrados con el IoT
	ESP8266
		Intro
		Arduino AVR vs ESP
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
			Fallas comunes en el ESP
	La internet
		Estructura
		IP protocol
			EJ ping en PC
			EJ tracert en PC
			EJ ipconfig/ifconfig/iwconfig
		HTTP
			Intro a HTTP
		API
			JSON
			EJ Cosumo basico de una API
		Protoclos de la internet
			TCP
			UDP
	Energy management
		Sleeps
		EJ deep sleep
		ventajas
MOD 2 => sockets v2 - HTTP - HTML - HTTP Server
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
	Más API
		REST
		EJ Twitter api thingspeak
	Socket
		EJ Socket a python: Hello socket
	EJ NTP (directo?)
	EJ ESP8266 a ESP8266
	OTA firmware
		EJ cargar soft desde el PC
		EJ carga directa via esptool.py
	HTTP v2
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
			funciones de memoria
				stdio
					snprintf
					memset
					strncpy
					strlen
			Tags
				head
				body
				div
				table
			Send svg
			EJ sitio sencillo para led
			CSS
			EJ2 sitio sencillo con estilo
			EJ3 snprintf
			img
			SD!
	Ethernet
	SD
	
	mDNS & LLMNR
		EJ montar server
	
MOD 4 => Paquetes - MQTT - MESH - BLE (ESP32)
	EJ NTP (directo?)
	SPIFFS
		Manejo de spiffs, datos
	Sys functions
	SDK
	MQTT
		EJ Conectarse a un server y ver otros aparatos
		
	Mesh
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
    BLE
		WiFi vs BLE
		Dispositivos con BLE
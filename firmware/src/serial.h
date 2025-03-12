#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <stdint.h>

#define SERIAL_MAX_PAYLOAD_SIZE 512

// #ifndef SERIAL_TX_PIN
// #define SERIAL_TX_PIN 20
// #endif

// #ifndef SERIAL_RX_PIN
// #define SERIAL_RX_PIN 21
// #endif

// #ifndef SERIAL_CTS_PIN
// #define SERIAL_CTS_PIN 26
// #endif

// #ifndef SERIAL_RTS_PIN
// #define SERIAL_RTS_PIN 27
// #endif

#ifdef HID_REMAPPER_BOARD

#define SERIAL_TX_PIN 24 
#define SERIAL_RX_PIN 25 
#define SERIAL_CTS_PIN 26 
#define SERIAL_RTS_PIN 23

#elif defined WAVESHARE_RP2040_ZERO_REMAPPER

#define SERIAL_TX_PIN 1 
#define SERIAL_RX_PIN 2 
#define SERIAL_CTS_PIN 3 
#define SERIAL_RTS_PIN 4

#else

#define SERIAL_TX_PIN 20 
#define SERIAL_RX_PIN 21 
#define SERIAL_CTS_PIN 26 
#define SERIAL_RTS_PIN 27

typedef bool (*msg_recv_cb_t)(const uint8_t* data, uint16_t len);

void serial_init();
bool serial_read(msg_recv_cb_t callback);
bool serial_write(const uint8_t* data, uint16_t len, bool drop_if_blocking = false);
bool serial_write_nonblocking(const uint8_t* data, uint16_t len);

#endif

#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <stdint.h>

#define SERIAL_MAX_PAYLOAD_SIZE 512

#ifndef SERIAL_TX_PIN
#define SERIAL_TX_PIN 4 //20
#endif

#ifndef SERIAL_RX_PIN
#define SERIAL_RX_PIN 5 //21
#endif

#ifndef SERIAL_CTS_PIN
#define SERIAL_CTS_PIN 6 //26
#endif

#ifndef SERIAL_RTS_PIN
#define SERIAL_RTS_PIN 7 //27
#endif

typedef bool (*msg_recv_cb_t)(const uint8_t* data, uint16_t len);

void serial_init();
bool serial_read(msg_recv_cb_t callback);
bool serial_write(const uint8_t* data, uint16_t len, bool drop_if_blocking = false);
bool serial_write_nonblocking(const uint8_t* data, uint16_t len);

#endif

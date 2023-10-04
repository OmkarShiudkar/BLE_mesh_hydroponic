#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/peripheral@50000000/clock@5000:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_80[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 2 : /soc/peripheral@50000000/gpio@842800:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_9[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 3 : /soc/peripheral@50000000/gpio@842500:
 * Supported:
 *    - /soc/peripheral@50000000/spi@a000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_8[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 8, DEVICE_HANDLE_ENDS };

/* 4 : /soc/peripheral@50000000/uart@8000:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_119[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /ipc/ipc0:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/mbox@2a000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_23[] = { 7, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/peripheral@50000000/flash-controller@39000:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_127[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/peripheral@50000000/mbox@2a000:
 * Supported:
 *    - /ipc/ipc0
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_22[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 5, DEVICE_HANDLE_ENDS };

/* 8 : /soc/peripheral@50000000/spi@a000:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/gpio@842500
 * Supported:
 *    - /soc/peripheral@50000000/spi@a000/mx25r6435f@0
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_142[] = { 3, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 9, DEVICE_HANDLE_ENDS };

/* 9 : /soc/peripheral@50000000/spi@a000/mx25r6435f@0:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/spi@a000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_143[] = { 8, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

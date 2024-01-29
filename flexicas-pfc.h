#ifndef CM_FLEXICAS_PFC_HPP
#define CM_FLEXICAS_PFC_HPP

#define FLEXICAS_PFC_START 0x8000000000000000ull
#define FLEXICAS_PFC_STOP  0x8000000000000001ull

#define FLEXICAS_PFC_ADDR       0x00ffffffffffffffull
#define FLEXICAS_PFC_ADDR_SIGN  0x0080000000000000ull
#define FLEXICAS_PFC_ADDR_NEGF  0xff00000000000000ull
#define FLEXICAS_PFC_QUERY 0x9000000000000000ull
#define FLEXICAS_PFC_FLUSH 0x9100000000000000ull

#define FLEXICAS_PFC_EXTRACT_ADDR(cmd) \
  ((cmd & FLEXICAS_PFC_ADDR_SIGN) ? (FLEXICAS_PFC_ADDR_NEGF | (cmd & FLEXICAS_PFC_ADDR)) \
                                  : (cmd & FLEXICAS_PFC_ADDR))

#endif

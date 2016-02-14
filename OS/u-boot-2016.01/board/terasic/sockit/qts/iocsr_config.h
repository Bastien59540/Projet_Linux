/*
 * Altera SoCFPGA IOCSR configuration
 *
 * SPDX-License-Identifier:	BSD-3-Clause
 */

#ifndef __SOCFPGA_IOCSR_CONFIG_H__
#define __SOCFPGA_IOCSR_CONFIG_H__

#define CONFIG_HPS_IOCSR_SCANCHAIN0_LENGTH	764
#define CONFIG_HPS_IOCSR_SCANCHAIN1_LENGTH	1719
#define CONFIG_HPS_IOCSR_SCANCHAIN2_LENGTH	955
#define CONFIG_HPS_IOCSR_SCANCHAIN3_LENGTH	16766

const unsigned long iocsr_scan_chain0_table[] = {
	0x00000000,
	0x00000000,
	0x0FF00000,
	0xC0000000,
	0x0000003F,
	0x00008000,
	0x00060180,
	0x18060000,
	0x18000000,
	0x00018060,
	0x00000000,
	0x00004000,
	0x000300C0,
	0x0C030000,
	0x0C000000,
	0x00000030,
	0x0000C030,
	0x00002000,
	0x00018060,
	0x06018000,
	0x06000000,
	0x00000018,
	0x00006018,
	0x00001000,
};

const unsigned long iocsr_scan_chain1_table[] = {
	0x00100000,
	0x300C0000,
	0x300000C0,
	0x000000C0,
	0x000300C0,
	0x00008000,
	0x00080000,
	0x20000000,
	0x00000000,
	0x00000080,
	0x00020000,
	0x00004000,
	0x000300C0,
	0x10000000,
	0x0C000000,
	0x00000030,
	0x0000C030,
	0x00002000,
	0x06018060,
	0x06018000,
	0x01FE0000,
	0xF8000000,
	0x00000007,
	0x00001000,
	0x0000C030,
	0x0300C000,
	0x03000000,
	0x0000300C,
	0x0000300C,
	0x00000800,
	0x00000000,
	0x00000000,
	0x01800000,
	0x00000006,
	0x00002000,
	0x00000400,
	0x00000000,
	0x00C03000,
	0x00000003,
	0x00000000,
	0x00000000,
	0x00000200,
	0x00601806,
	0x00000000,
	0x80600000,
	0x80000601,
	0x00000601,
	0x00000100,
	0x00300C03,
	0xC0300C00,
	0xC0300000,
	0xC0000300,
	0x000C0300,
	0x00000080,
};

const unsigned long iocsr_scan_chain2_table[] = {
	0x300C0300,
	0x00000000,
	0x0FF00000,
	0x00000000,
	0x0C0300C0,
	0x00008000,
	0x18060180,
	0x18060000,
	0x18000000,
	0x00018060,
	0x00018060,
	0x00004000,
	0x000300C0,
	0x0C030000,
	0x00000030,
	0x00000000,
	0x0300C030,
	0x00002000,
	0x00018060,
	0x06018000,
	0x06000000,
	0x00000018,
	0x00006018,
	0x00001000,
	0x0000C030,
	0x00000000,
	0x03000000,
	0x0000000C,
	0x00C0300C,
	0x00000800,
};

const unsigned long iocsr_scan_chain3_table[] = {
	0x0C420D80,
	0x082000FF,
	0x0A804001,
	0x07900000,
	0x08020000,
	0x00100000,
	0x0A800000,
	0x07900000,
	0x08020000,
	0x00100000,
	0xC8800000,
	0x00003001,
	0x00C00722,
	0x00000000,
	0x00000021,
	0x82000004,
	0x05400000,
	0x03C80000,
	0x04010000,
	0x00080000,
	0x05400000,
	0x03C80000,
	0x05400000,
	0x03C80000,
	0xE4400000,
	0x00001800,
	0x00600391,
	0x800E4400,
	0x00000001,
	0x40000002,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x72200000,
	0x80000C00,
	0x003001C8,
	0xC0072200,
	0x1C880000,
	0x20000300,
	0x00040000,
	0x50670000,
	0x00000010,
	0x24590000,
	0x00001000,
	0xA0000034,
	0x0D000001,
	0x40680208,
	0x41034051,
	0x12481A00,
	0x802080D0,
	0x34051406,
	0x01A02490,
	0x080D0000,
	0x51406802,
	0x02490340,
	0xD000001A,
	0x0680A280,
	0x10040000,
	0x00200000,
	0x10040000,
	0x00200000,
	0x15000000,
	0x0F200000,
	0x15000000,
	0x0F200000,
	0x01FE0000,
	0x00000000,
	0x01800E44,
	0x00391000,
	0x007F8006,
	0x00000000,
	0x0A800001,
	0x07900000,
	0x0A800000,
	0x07900000,
	0x0A800000,
	0x07900000,
	0x08020000,
	0x00100000,
	0xC8800000,
	0x00003001,
	0x00C00722,
	0x00000FF0,
	0x72200000,
	0x80000C00,
	0x05400000,
	0x02480000,
	0x04000000,
	0x00080000,
	0x05400000,
	0x03C80000,
	0x05400000,
	0x03C80000,
	0x6A1C0000,
	0x00001800,
	0x00600391,
	0x800E4400,
	0x1A870001,
	0x40000600,
	0x02A00040,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x02A00000,
	0x01E40000,
	0x72200000,
	0x80000C00,
	0x003001C8,
	0xC0072200,
	0x1C880000,
	0x20000300,
	0x00040000,
	0x50670000,
	0x00000010,
	0x24590000,
	0x00001000,
	0xA0000034,
	0x0D000001,
	0x40680208,
	0x49034051,
	0x12481A02,
	0x80A280D0,
	0x34030C06,
	0x01A00040,
	0x280D0002,
	0x5140680A,
	0x02490340,
	0xD012481A,
	0x0680A280,
	0x10040000,
	0x00200000,
	0x10040000,
	0x00200000,
	0x15000000,
	0x0F200000,
	0x15000000,
	0x0F200000,
	0x01FE0000,
	0x00000000,
	0x01800E44,
	0x00391000,
	0x007F8006,
	0x00000000,
	0x99300001,
	0x34343400,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x01000000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x0002A000,
	0x0001E400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0xC880090C,
	0x00003001,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00002000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x04864000,
	0x59647A01,
	0xD32CA3DE,
	0xF551451E,
	0x034CD348,
	0x821A0000,
	0x0000D000,
	0x05140680,
	0xD669A47A,
	0x1ED32CA3,
	0x48F55E79,
	0x00034C92,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x00003FC2,
	0x00820000,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x00008000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x00020080,
	0x00000400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0x0000090C,
	0x00000010,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00015000,
	0x0000F200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00600391,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x14864000,
	0x59647A05,
	0x9228A3DE,
	0xF65E791E,
	0x034CD348,
	0x821A0186,
	0x0000D000,
	0x00000680,
	0xD669A47A,
	0x1E9228A3,
	0x48F65E79,
	0x00034CD3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x00008000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x0002A000,
	0x0001E400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0xC880090C,
	0x00003001,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00002000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F3690D,
	0x1A041414,
	0x00D00000,
	0x0C864000,
	0x79E47A03,
	0xB2AAA3D1,
	0xF551451E,
	0x035CD348,
	0x821A0000,
	0x0000D000,
	0x00000680,
	0xD159647A,
	0x1ED32CA3,
	0x48F55145,
	0x00035CD3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0xAA0D4000,
	0x01C3A800,
	0x00040100,
	0x00000800,
	0x00000000,
	0x00001208,
	0x00482000,
	0x00008000,
	0x00000000,
	0x00410482,
	0x0006A000,
	0x0001B400,
	0x00020000,
	0x00000400,
	0x00020080,
	0x00000400,
	0x5506A000,
	0x00E1D400,
	0x00000000,
	0x0000090C,
	0x00000010,
	0x90400000,
	0x00000000,
	0x2020C243,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x2A835000,
	0x0070EA00,
	0x00010040,
	0x00000200,
	0x00000000,
	0x00000482,
	0x00120800,
	0x00400000,
	0x80000000,
	0x00104120,
	0x00000200,
	0xAC0D5F80,
	0xFFFFFFFF,
	0x14F1690D,
	0x1A041414,
	0x00D00000,
	0x04864000,
	0x69A47A01,
	0x9228A3D6,
	0xF65E791E,
	0x034C9248,
	0x821A0000,
	0x0000D000,
	0x00000680,
	0xDE59647A,
	0x1ED32CA3,
	0x48F55E79,
	0x00034CD3,
	0x00080200,
	0x00001000,
	0x00080200,
	0x00001000,
	0x000A8000,
	0x00075000,
	0x541A8000,
	0x03875001,
	0x10000000,
	0x00000000,
	0x0080C000,
	0x41000000,
	0x04000002,
	0x00820000,
	0x00489800,
	0x801A1A1A,
	0x00000200,
	0x80000004,
	0x00000200,
	0x80000004,
	0x00000200,
	0x80000004,
	0x00000200,
	0x00000004,
	0x00040000,
	0x10000000,
	0x00000000,
	0x00000040,
	0x00010000,
	0x40002000,
	0x00000100,
	0x40000002,
	0x00000100,
	0x40000002,
	0x00000100,
	0x40000002,
	0x00000100,
	0x00000002,
	0x00020000,
	0x08000000,
	0x00000000,
	0x00000020,
	0x00008000,
	0x20001000,
	0x00000080,
	0x20000001,
	0x00000080,
	0x20000001,
	0x00000080,
	0x20000001,
	0x00000080,
	0x00000001,
	0x00010000,
	0x04000000,
	0x00FF0000,
	0x00000000,
	0x00004000,
	0x00000800,
	0xC0000001,
	0x00041419,
	0x40000000,
	0x04000816,
	0x000D0000,
	0x00006800,
	0x00000340,
	0xD000001A,
	0x06800000,
	0x00340000,
	0x0001A000,
	0x00000D00,
	0x40000068,
	0x1A000003,
	0x00D00000,
	0x00068000,
	0x00003400,
	0x000001A0,
	0x00000401,
	0x00000008,
	0x00000401,
	0x00000008,
	0x00000401,
	0x00000008,
	0x00000401,
	0x80000008,
	0x0000007F,
	0x20000000,
	0x00000000,
	0xE0000080,
	0x0000001F,
	0x00004000,
};


#endif /* __SOCFPGA_IOCSR_CONFIG_H__ */

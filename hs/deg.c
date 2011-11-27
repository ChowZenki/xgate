
Graph_RGB(pal, i, r, g, b)
	BYTE *pal, i;
	BYTE *r,*g,*b;
{
	static unsigned rpl[] = {
// 反汇编后的调色盘:
			// 前16份调色板
			0x000000, 0x000080, 0x008000, 0x008080, 0x800000,
			0x800080, 0x808000, 0xC0C0C0, 0xC0DCC0, 0xF0CAA6,
			0x0000DE, 0x005FFF, 0xA0FFFF, 0xD25F00, 0xFFD250,	/* 0xF */
			0x28E128,
			// 后16份调色板
			0x96C3F5, 0x5FA0E1, 0x467DC3, 0x1E559B, 0x374146,
			0x1E2328, 0xF0FBFF, 0xA4A0A0, 0x808080, 0x0000FF,
			0x00FF00, 0x00FFFF, 0xFF0000, 0xFF00FF, 0xFFFF00,
			0xFFFFFF						/* 0xFF */

// 野风信子的调色盘:
//			// 前16份调色板
//			0x000000, 0x000080, 0x008000, 0x008080, 0x800000,
//			0x800080, 0x808000, 0xC0C0C0, 0xC0DCC0, 0xF0CAA6,
//			0x0000DE, 0x005FFF, 0xA0FFFF, 0xD25F00, 0xFFD250,
//			0x28E128,						/* 0xF */
//			// 后16份调色板
//			0x96C3F5, 0x5FA01E, 0x467DC3, 0x1E559B, 0x374146,
//			0x1E2328, 0xF0FBFF, 0xA56E3A, 0x808080, 0x0000FF,
//			0x00FF00, 0x00FFFF, 0xFF0000, 0xFF80FF, 0xFFFF00,
//			0xFFFFFF						/* 0xFF */
	};
	if (i<=15) {
		*b = rpl[i] >> 16;
		*g = (rpl[i] >> 8) & 0xFF;
		*r = rpl[i] & 0xFF;
	} else if (i>=240) {
		*b = rpl[i-=240-16] >> 16;
		*g = (rpl[i] >> 8) & 0xFF;
		*r = rpl[i] & 0xFF;
	} else {
		i-=16;
		*b = pal[i * 3];
		*g = pal[i * 3 + 1];
		*r = pal[i * 3 + 2];
	}
}
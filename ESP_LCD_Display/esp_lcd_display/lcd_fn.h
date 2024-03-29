  #include <U8g2lib.h>
#include <Wire.h> // library required for IIC communication

void setup_lcd();
void clear_lcd();
void draw_human(int col,int row,int frame);
void display_lcd();




// '_a_frm0,40', 15x15px
const unsigned char epd_bitmap__a_frm0_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xd0, 0x06, 
	0xc0, 0x00, 0xc0, 0x01, 0x20, 0x01, 0x20, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm1,40', 15x15px
const unsigned char epd_bitmap__a_frm1_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xd0, 0x06, 
	0xc0, 0x00, 0xc0, 0x01, 0x80, 0x01, 0x20, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm2,50', 15x15px
const unsigned char epd_bitmap__a_frm2_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xf0, 0x02, 
	0xd0, 0x04, 0xc0, 0x00, 0x80, 0x01, 0x20, 0x01, 0x30, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm3,40', 15x15px
const unsigned char epd_bitmap__a_frm3_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x02, 
	0xf0, 0x04, 0xc0, 0x00, 0x80, 0x01, 0x20, 0x01, 0x30, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm4,40', 15x15px
const unsigned char epd_bitmap__a_frm4_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x02, 
	0xe0, 0x06, 0xc0, 0x00, 0x80, 0x01, 0x20, 0x01, 0x30, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm5,40', 15x15px
const unsigned char epd_bitmap__a_frm5_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
	0xe0, 0x02, 0xc0, 0x00, 0x80, 0x01, 0x20, 0x01, 0x30, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm6,40', 15x15px
const unsigned char epd_bitmap__a_frm6_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
	0xe0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0xa0, 0x01, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm7,40', 15x15px
const unsigned char epd_bitmap__a_frm7_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm8,50', 15x15px
const unsigned char epd_bitmap__a_frm8_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm9,40', 15x15px
const unsigned char epd_bitmap__a_frm9_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm10,40', 15x15px
const unsigned char epd_bitmap__a_frm10_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm11,40', 15x15px
const unsigned char epd_bitmap__a_frm11_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm12,40', 15x15px
const unsigned char epd_bitmap__a_frm12_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x01, 0xc0, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm13,40', 15x15px
const unsigned char epd_bitmap__a_frm13_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x01, 0xc0, 0x00, 0xc0, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm14,50', 15x15px
const unsigned char epd_bitmap__a_frm14_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xd0, 0x00, 
	0xc0, 0x01, 0xc0, 0x00, 0x40, 0x00, 0x40, 0x01, 0x60, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm15,40', 15x15px
const unsigned char epd_bitmap__a_frm15_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xd0, 0x00, 0xc0, 0x01, 
	0xc0, 0x03, 0xc0, 0x00, 0x40, 0x00, 0x40, 0x01, 0x60, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm16,40', 15x15px
const unsigned char epd_bitmap__a_frm16_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xd0, 0x00, 0xc8, 0x01, 
	0xc0, 0x02, 0xc0, 0x00, 0x40, 0x01, 0x40, 0x01, 0x60, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm17,40', 15x15px
const unsigned char epd_bitmap__a_frm17_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xd0, 0x01, 
	0xc0, 0x03, 0xc0, 0x00, 0xc0, 0x00, 0x40, 0x01, 0x60, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm18,40', 15x15px
const unsigned char epd_bitmap__a_frm18_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x01, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm19,40', 15x15px
const unsigned char epd_bitmap__a_frm19_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm20,50', 15x15px
const unsigned char epd_bitmap__a_frm20_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0xc0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm22,40', 15x15px
const unsigned char epd_bitmap__a_frm22_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm21,40', 15x15px
const unsigned char epd_bitmap__a_frm21_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm23,40', 15x15px
const unsigned char epd_bitmap__a_frm23_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xc0, 0x00, 0xc0, 0x00, 0x80, 0x01, 0xc0, 0x01, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm24,40', 15x15px
const unsigned char epd_bitmap__a_frm24_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
	0xe0, 0x00, 0xc0, 0x00, 0x80, 0x01, 0x60, 0x01, 0xa0, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm25,40', 15x15px
const unsigned char epd_bitmap__a_frm25_40 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
	0xe0, 0x02, 0xc0, 0x01, 0x80, 0x01, 0x60, 0x01, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm26,50', 15x15px
const unsigned char epd_bitmap__a_frm26_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xf0, 0x02, 
	0xd0, 0x00, 0xc0, 0x01, 0x80, 0x01, 0x20, 0x01, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00
};
// '_a_frm27,50', 15x15px
const unsigned char epd_bitmap__a_frm27_50 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xd0, 0x06, 
	0xc0, 0x00, 0xc0, 0x01, 0xa0, 0x01, 0x20, 0x01, 0x30, 0x01, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1344)
const int epd_bitmap_allArray_LEN = 28;
const unsigned char* epd_bitmap_allArray[28] = {
	epd_bitmap__a_frm0_40,
	epd_bitmap__a_frm1_40,
	epd_bitmap__a_frm2_50,
	epd_bitmap__a_frm3_40,
	epd_bitmap__a_frm4_40,
	epd_bitmap__a_frm5_40,
	epd_bitmap__a_frm6_40,
	epd_bitmap__a_frm7_40,
	epd_bitmap__a_frm8_50,
	epd_bitmap__a_frm9_40,
	epd_bitmap__a_frm10_40,
	epd_bitmap__a_frm11_40,
	epd_bitmap__a_frm12_40,
	epd_bitmap__a_frm13_40,
	epd_bitmap__a_frm14_50,
	epd_bitmap__a_frm15_40,
	epd_bitmap__a_frm16_40,
	epd_bitmap__a_frm17_40,
	epd_bitmap__a_frm18_40,
	epd_bitmap__a_frm19_40,
	epd_bitmap__a_frm20_50,
	epd_bitmap__a_frm21_40,
	epd_bitmap__a_frm22_40,
	epd_bitmap__a_frm23_40,
	epd_bitmap__a_frm24_40,
	epd_bitmap__a_frm25_40,
	epd_bitmap__a_frm26_50,
	epd_bitmap__a_frm27_50,
	
};

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // initialization for the used OLED display

void setup_lcd(){
  u8g2.begin();
}

void clear_lcd(){
  u8g2.clearBuffer();
}

void draw_human(int col,int row,int frame){
  u8g2.drawXBMP(8+32*col, 16*row, 15, 15, epd_bitmap_allArray[frame]);
}

void display_lcd(){
  u8g2.sendBuffer();
}
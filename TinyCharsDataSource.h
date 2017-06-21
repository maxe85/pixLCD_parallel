const char tinyNumSet[] PROGMEM = {
// 0x00	0 1
B01100010,
B10010110,
B10110010,
B11010010,
B10010010,
B10010010,
B01100010,
// 0x01 2 3
B01100110,
B10011001,
B00010001,
B00100110,
B01000001,
B10001001,
B11110110,
// 0x02 4 5
B00101111,
B01101000,
B10101000,
B11110110,
B00100001,
B00101001,
B00100110,
// 0x03 6 7
B01101111,
B10010001,
B10000001,
B11100010,
B10010010,
B10010100,
B01100100,
// 0x04 8 9
B01100110,
B10011001,
B10011001,
B01100111,
B10010001,
B10011001,
B01100110,
// 0x05 + -
B00000000,	
B00000000,
B00100000,
B01110111,
B00100000,
B00000000,
B00000000,
// 0x06 x /
B00000001,
B00000001,
B01010010,
B00100010,
B01010010,
B00000100,
B00000100,
// 0x07 yokto zepto
B00000000,
B00000000,
B01010111,
B01010001,
B00100010,
B00100100,
B00100111,
// 0x08 atto femto
B00000001,
B00000010,
B01100111,
B00010010,
B01110010,
B10010010,
B01110010,
// 0x09  pico nano
B00000000,
B00000000,
B01111110,
B01011001,
B01101001,
B01001001,
B01001001,
// 0x0A	micro
B00000000,
B00000000,
B00010010,
B00010010,
B00010010,
B00011101,
B00010000,
// 0x0B	milli
B00000000,
B00000000,
B00011010,
B00010101,
B00010101,
B00010101,
B00010101,
// 0x0C  %
B00001001,
B00010101,
B00001010,
B00000100,
B00001010,
B00010101,
B00010010,
// 0x0D Kilo
B00010001,
B00010010,
B00010100,
B00011000,
B00010100,
B00010010,
B00010001,
// 0x0E Mega
B00010001,
B00011011,
B00010101,
B00010101,
B00010001,
B00010001,
B00010001,
// 0x0F Giga
B00001110,
B00010001,
B00010000,
B00010011,
B00010001,
B00010001,
B00001110,
// 0x10 Terra
B00011111,
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
// 0x11 Peta
B00011110,	
B00010001,
B00010001,
B00011110,
B00010000,
B00010000,
B00010000,
// 0x12 Exa
B00011111,
B00010000,
B00010000,
B00011111,
B00010000,
B00010000,
B00011111,
// 0x13 Zetta
B00011111,
B00000001,
B00000010,
B00000100,
B00001000,
B00010000,
B00011111,
// 0x14 Yotta
B00010001,
B00001010,
B00001010,
B00000100,
B00000100,
B00000100,
B00000100
};



const char tinyCharSet[] PROGMEM = {
// zero defines the end of a string
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x01 aka Ä
B10110101,
B00000100,
B00001010,
B00001110,
B00001010,
B00010001,
B00010001,
// 0x02 aka Ö
B10110001,
B00000000,
B00001110,
B00010001,
B00010001,
B00010001,
B00001110,
// 0x03 aka Ü
B10001001,
B00000000,
B00001001,
B00001001,
B00001001,
B00001001,
B00000110,
// 0x04 aka ä
B10000101,
B00000000,
B00000110,
B00000001,
B00000111,
B00001001,
B00000111,
// 0x05 aka ö
B10001001,
B00000000,
B00000110,
B00001001,
B00001001,
B00001001,
B00000110,
// 0x06 aka ü  
B01100101,
B00000000,
B00000101,
B00000101,
B00000101,
B00000101,
B00000011,
// 0x07 aka  ligature ß
B10000010,
B00000101,
B00001001,
B00001110,
B00001001,
B00001001,
B00001010,
// 0x08 aka Æ
B10101111,
B00010100,
B00010100,
B00011111,
B00010100,
B00010100,
B00010111,
// 0x09 aka tab
0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x0A aka new line
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
// 0x0B aka Ø
B10101101,
B00010010,
B00010101,
B00010101,
B00010101,
B00001001,
B00010110,
// 0x0C aka Å 
B10100100,
B00001010,
B00000100,
B00001010,
B00001110,
B00010001,
B00010001,
// 0x0D aka æ
B10100000,
B00000000,
B00011010,
B00000101,
B00001110,
B00010100,
B00001011,
// 0x0E aka ø
B10100000,
B00000000,
B00001110,
B00010011,
B00010101,
B00011001,
B00001110,
// 0x0F aka å
B10000010,
B00000101,
B00000010,
B00000001,
B00000111,
B00001001,
B00000111,
// 0x10 aka triangel right
B01100000,
B00000100,
B00000110,
B00000111,
B00000110,
B00000100,
B00000000,
// 0x11 aka triangel left
B01100000,
B00000001,
B00000011,
B00000111,
B00000011,
B00000001,
B00000000,
// 0x12 aka arrow up and down
B10100100,
B00001110,
B00011111,
B00000100,
B00011111,
B00001110,
B00000100,
// 0x13 aka double excalmation
B01100101,
B00000101,
B00000101,
B00000101,
B00000101,
B00000000,
B00000101,
// 0x14 aka pilcrow
B10101111,
B00010101,
B00001101,
B00000101,
B00000101,
B00000101,
B00000101,
// 0x15 aka section sign
B10101110,
B00010001,
B00001100,
B00001010,
B00000110,
B00010001,
B00001110,
// 0x16 aka fat underline
B01100000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000111,
B00000111,
// 0x17 aka arrow up with baseline
B10101000,
B00011100,
B00101010,
B00001000,
B00001000,
B00001000,
B00111110,
// 0x18 aka arrow up
B10100000,
B00000100,
B00001110,
B00010101,
B00000100,
B00000100,
B00000000,
// 0x19 aka arrow down
B10100000,
B00000100,
B00000100,
B00010101,
B00001110,
B00000100,
B00000000,
// 0x1A aka arrow right
B10100000,
B00001000,
B00000100,
B00111110,
B00000100,
B00001000,
B00000000,
// 0x1B aka arrow left
B10100000,
B00000100,
B00001000,
B00011111,
B00001000,
B00000100,
B00000000,
// 0x1C aka ???
B10000000,
B00000000,
B00001000,
B00001111,
B00000000,
B00000000,
B00000000,
// 0x1D aka spanish question mark
B10000100,
B00000000,
B00000100,
B00000010,
B00000001,
B00001001,
B00000110,
// 0x1E aka triangel up
B10100000,
B00000100,
B00001110,
B00011111,
B00000000,
B00000000,
B00000000,
// 0x1F aka triangel down
B10100000,
B00000000,
B00000000,
B00011111,
B00001110,
B00000100,
B00000000,
// 0x20 aka whitespace
0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 0x21 aka !
B00100001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000000,
B00000001,
// 0x22 aka "
B01100101,
B00000101,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
// 0x23 aka #
B10100000,
B00001010,
B00011111,
B00001010,
B00011111,
B00001010,
B00000000,
// 0x24 aka $
B10100100,
B00001111,
B00010000,
B00001110,
B00000001,
B00011110,
B00000100,
// 0x25 aka %
B10101001,
B00010101,
B00001010,
B00000100,
B00001010,
B00010101,
B00010010,
// 0x26 aka &
B10100100,
B00001010,
B00000100,
B00001000,
B00010100,
B00010010,
B00001101,
// 0x27 aka '
B00100001,
B00000001,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
// 0x28 aka (
B01000001,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000001,
// 0x29 aka )
B01000010,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000010,
// 0x2A aka *
B01100101,
B00000010,
B00000101,
B00000000,
B00000000,
B00000000,
B00000000,
// 0x2B aka +
B10100000,
B00000000,
B00000100,
B00001110,
B00000100,
B00000000,
B00000000,
// 0x2C aka ,
B01000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000001,
B00000010,
// 0x2D aka -
B10100000,
B00000000,
B00000000,
B00001110,
B00000000,
B00000000,
B00000000,
// 0x2E aka .
B00100000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000001,
// 0x2F aka /
B01100001,
B00000001,
B00000010,
B00000010,
B00000010,
B00000100,
B00000100,
// 0x30 aka 0
B10000110,
B00001001,
B00001011,
B00001101,
B00001001,
B00001001,
B00000110,
// 0x31 aka 1
B10000010,
B00000110,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
// 0x32 aka 2
B10000110,
B00001001,
B00000001,
B00000010,
B00000100,
B00001000,
B00001111,
// 0x33 aka 3
B10000110,
B00001001,
B00000001,
B00000110,
B00000001,
B00001001,
B00000110,
// 0x34 aka 4
B10000010,
B00000110,
B00001010,
B00001111,
B00000010,
B00000010,
B00000010,
// 0x35 aka 5
B10001111,
B00001000,
B00001000,
B00000110,
B00000001,
B00001001,
B00000110,
// 0x36 aka 6
B10000110,
B00001001,
B00001000,
B00001110,
B00001001,
B00001001,
B00000110,
// 0x37 aka 7
B10001111,
B00000001,
B00000001,
B00000010,
B00000010,
B00000100,
B00000100,
// 0x38 aka 8
B10000110,
B00001001,
B00001001,
B00000110,
B00001001,
B00001001,
B00000110,
// 0x39 aka 9
B10000110,
B00001001,
B00001001,
B00000111,
B00000001,
B00001001,
B00000110,
// 0x3A aka :
B00100000,
B00000000,
B00000001,
B00000000,
B00000000,
B00000001,
B00000000,
// 0x3B aka ;
B01000000,
B00000000,
B00000001,
B00000000,
B00000000,
B00000001,
B00000010,
// 0x3C aka <
B10000001,
B00000010,
B00000100,
B00001000,
B00000100,
B00000010,
B00000001,
// 0x3D aka =
B01100000,
B00000000,
B00000111,
B00000000,
B00000111,
B00000000,
B00000000,
// 0x3E aka >
B10001000,
B00000100,
B00000010,
B00000001,
B00000010,
B00000100,
B00001000,
// 0x3F aka ?
B10000110,
B00001001,
B00000001,
B00000010,
B00000100,
B00000000,
B00000100,
// 0x40 aka @
B10101110,
B00010001,
B00010001,
B00010111,
B00010111,
B00010000,
B00001111,
// 0x41 aka A
B10100100,
B00000100,
B00001010,
B00001010,
B00001110,
B00010001,
B00010001,
// 0x42 aka B
B10001110,
B00001001,
B00001001,
B00001110,
B00001001,
B00001001,
B00001110,
// 0x43 aka C
B10000110,
B00001001,
B00001000,
B00001000,
B00001000,
B00001001,
B00000110,
// 0x44 aka D
B10001110,
B00001001,
B00001001,
B00001001,
B00001001,
B00001001,
B00001110,
// 0x45 aka E
B01100111,
B00000100,
B00000100,
B00000111,
B00000100,
B00000100,
B00000111,
// 0x46 aka F
B01100111,
B00000100,
B00000100,
B00000111,
B00000100,
B00000100,
B00000100,
// 0x47 aka G
B10000110,
B00001001,
B00001000,
B00001011,
B00001001,
B00001001,
B00000110,
// 0x48 aka H
B10001001,
B00001001,
B00001001,
B00001111,
B00001001,
B00001001,
B00001001,
// 0x49 aka I
B00100001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
// 0x4A aka J
B01100111,
B00000001,
B00000001,
B00000001,
B00000001,
B00000101,
B00000010,
// 0x4B aka K
B10001001,
B00001001,
B00001010,
B00001100,
B00001010,
B00001001,
B00001001,
// 0x4C aka L
B01100100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000100,
B00000111,
// 0x4D aka M
B10110001,
B00011011,
B00010101,
B00010101,
B00010001,
B00010001,
B00010001,
// 0x4E aka N
B10110001,
B00011001,
B00011101,
B00010101,
B00010111,
B00010011,
B00010001,
// 0x4F aka O
B10101110,
B00010001,
B00010001,
B00010001,
B00010001,
B00010001,
B00001110,
// 0x50 aka P
B10001110,
B00001001,
B00001001,
B00001110,
B00001000,
B00001000,
B00001000,
// 0x51 aka Q
B10000110,
B00001001,
B00001001,
B00001001,
B00001001,
B00001010,
B00000101,
// 0x52 aka R
B10001110,
B00001001,
B00001001,
B00001110,
B00001100,
B00001010,
B00001001,
// 0x53 aka S
B10000110,
B00001001,
B00001000,
B00000110,
B00000001,
B00001001,
B00000110,
// 0x54 aka T
B01100111,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
// 0x55 aka U
B10001001,
B00001001,
B00001001,
B00001001,
B00001001,
B00001001,
B00000110,
// 0x56 aka V
B10001001,
B00001001,
B00001010,
B00001010,
B00001010,
B00000100,
B00000100,
// 0x57 aka W
B10110001,
B00010001,
B00010101,
B00010101,
B00001010,
B00001010,
B00001010,
// 0x58 aka X
B10110001,
B00010001,
B00001010,
B00000100,
B00001010,
B00010001,
B00010001,
// 0x59 aka Y
B10110001,
B00001010,
B00001010,
B00000100,
B00000100,
B00000100,
B00000100,
// 0x5A aka Z
B10111111,
B00000001,
B00000010,
B00000100,
B00001000,
B00010000,
B00011111,
// 0x5B aka [
B01000011,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000011,
// 0x5C aka  \    *
B01100100,
B00000100,
B00000010,
B00000010,
B00000010,
B00000001,
B00000001,
// 0x5D aka ]
B01000011,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000011,
// 0x5E aka ^
B10100100,
B00001010,
B00010001,
B00000000,
B00000000,
B00000000,
B00000000,
// 0x5F aka _
B10000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00001111,
// 0x60 aka `
B01000010,
B00000001,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
// 0x61 aka a
B10000000,
B00000000,
B00000110,
B00000001,
B00000111,
B00001001,
B00000111,
// 0x62 aka b
B10001000,
B00001000,
B00001110,
B00001001,
B00001001,
B00001001,
B00000110,
// 0x63 aka c
B01100000,
B00000000,
B00000011,
B00000100,
B00000100,
B00000100,
B00000011,
// 0x64 aka d
B10000001,
B00000001,
B00000111,
B00001001,
B00001001,
B00001001,
B00000110,
// 0x65 aka e
B10000000,
B00000000,
B00000110,
B00001001,
B00001111,
B00001000,
B00000110,
// 0x66 aka f
B01100001,
B00000010,
B00000111,
B00000010,
B00000010,
B00000010,
B00000010,
// 0x67 aka g
B10000000,
B00000000,
B00000111,
B00001001,
B00000111,
B00000001,
B00000110,
// 0x68 aka h
B10001000,
B00001000,
B00001110,
B00001001,
B00001001,
B00001001,
B00001001,
// 0x69 aka i
B00100001,
B00000000,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
// 0x6A aka j
B01000001,
B00000000,
B00000001,
B00000001,
B00000001,
B00000001,
B00000010,
// 0x6B aka k
B01100100,
B00000101,
B00000101,
B00000110,
B00000101,
B00000101,
B00000101,
// 0x6C aka l
B01000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000001,
// 0x6D aka m
B10100000,
B00000000,
B00011010,
B00010101,
B00010101,
B00010101,
B00010101,
// 0x6E aka n
B10000000,
B00000000,
B00001110,
B00001001,
B00001001,
B00001001,
B00001001,
// 0x6F aka o
B10000000,
B00000000,
B00000110,
B00001001,
B00001001,
B00001001,
B00000110,
// 0x70 aka p
B01100000,
B00000000,
B00000111,
B00000101,
B00000110,
B00000100,
B00000100,
// 0x71 aka q
B10000000,
B00000000,
B00000110,
B00001001,
B00001001,
B00001010,
B00000101,
// 0x72 aka r
B01100000,
B00000000,
B00000101,
B00000110,
B00000100,
B00000100,
B00000100,
// 0x73 aka s
B01100000,
B00000000,
B00000011,
B00000100,
B00000010,
B00000001,
B00000110,
// 0x74 aka t
B01100010,
B00000010,
B00000111,
B00000010,
B00000010,
B00000010,
B00000011,
// 0x75 aka u
B10000000,
B00000000,
B00001001,
B00001001,
B00001001,
B00001001,
B00000111,
// 0x76 aka v
B01100000,
B00000000,
B00000101,
B00000101,
B00000101,
B00000101,
B00000010,
// 0x77 aka w
B10100000,
B00000000,
B00010001,
B00010001,
B00010101,
B00010101,
B00001010,
// 0x78 aka x
B01100000,
B00000000,
B00000101,
B00000101,
B00000010,
B00000101,
B00000101,
// 0x79 aka y
B01100000,
B00000000,
B00000101,
B00000101,
B00000010,
B00000010,
B00000010,
// 0x7A aka z
B01100000,
B00000000,
B00000111,
B00000001,
B00000010,
B00000100,
B00000111,
// 0x7B aka {
B01100001,
B00000010,
B00000010,
B00000100,
B00000010,
B00000010,
B00000001,
// 0x7C aka |
B00100001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
// 0x7D aka }
B01100100,
B00000010,
B00000010,
B00000001,
B00000010,
B00000010,
B00000100,
// 0x7E aka ~
B10101000,
B00010101,
B00000010,
B00000000,
B00000000,
B00000000,
B00000000,
// 0x7F aka house
B10100000,
B00000000,
B00000100,
B00001010,
B00010001,
B00010001,
B00011111
};


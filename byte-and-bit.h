typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);

void show_bytes_r(byte_pointer start, int len);

void s_show_bits(byte_pointer start, int len, unsigned char *s);

void show_bits(byte_pointer start, int len);

void show_int(int x);

void show_float(float x);

void show_pointer(void *x);

void test_show_bytes(int val);

void print_space(int n);

void print_bits(unsigned char *p, int len);

void s_show_bit(unsigned char x, unsigned char *s);


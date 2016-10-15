
void lcd_init(void);
void lcd_backlight(void);
void lcd_putchar(char ch);
void lcd_command(char cmd);
void lcd_gotoxy(char x, char y);
void lcd_clear(void);
void lcd_clear_line(char y);
void lcd_shift_left(int n);
void lcd_shift_right(int n);
void lcd_puts(int num);
void lcd_putsf(char* data);
void lcd_define_char(const char *pc,char char_code);
void cursor_off(void);
void backlight_off(void);
void backlight_on(void);
void delay (int cnt);
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

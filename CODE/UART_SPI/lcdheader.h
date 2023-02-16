
#define RS (1<<10)
#define	RW (1<<12)
#define	EN (1<<13)
#define DATAPINS (0xff<<15)


void LcdInit(void);
void LcdCmd(int cmd);
void LcdData(char data);
void LcdString(char *str);
void LcdNum(int num);

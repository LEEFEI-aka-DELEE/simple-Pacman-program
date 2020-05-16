enum ArrowKey { keyENTER = 13, keyESC = 27, keyUP = 72, keyDOWN = 80, keyLEFT = 75, keyRIGHT = 77  };
enum ForegroundColor {fgBLACK = 0, fgNORMAL = 7, fgGRAY, fgBLUE, fgGREEN, fgCYAN, fgRED, fgPINK, fgYELLOW, fgWHITE};
enum BackgroundColor {bgBLACK = 0, bgBLUE = 16, bgGREEN = 32, bgCYAN = 48, bgRED = 64, bgPINK = 80, bgYELLOW = 96, bgWHITE = 112};
int getcha();
void setcolor(int fg = fgNORMAL, int bg = bgBLACK);


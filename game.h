int speed;
int dir;
int deg;
int windowWidth;
int windowHeight;
int gameCols;
int gameRows;
float hudHeight;
char* cells[20][20];
int cellColors[10][3];

void speedUp();
void speedDown();
void directionChange();

void colorCell(int, int);

void gameSetup(int, int);
void gameText();
void gameLoop();
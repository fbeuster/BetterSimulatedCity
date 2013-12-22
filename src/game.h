/**
\file
\brief definition of a lot of gmaing functions and variables
*/

/*** some old stuff ***/
int speed;	/**< \brief rotation speed */
int dir;	/**< \brief rotation direction */
int deg;	/**< \brief rotation angle */

/*** game reltated variables ***/
int windowWidth;	/**< \brief window width */
int windowHeight;	/**< \brief window height */
int hudHeight;	/**< \brief height of the HUD */
int gameCols;			/**< \brief columns in the game grid */
int gameRows;			/**< \brief rows in the game grid */
int cellWidth;		/**< \brief width of a game cell */
int cellHeigth;		/**< \brief heigth of a game cell */
char* cells[20][20];	/**< \brief 3-dim array to hold cell states */
int cellColors[10][3];	/**< \brief holder for colors */

/*** some old functions ***/
void speedUp();			/**< \brief increase speed */
void speedDown();		/**< \brief decrease speed */
void directionChange();	/**< \brief change direction (no music) */

/*** game related functions ***/
int isInCell(int, int);
void colorCell(int, int);	/**< \brief Set the color of a cell */
void gameSetup(int, int);	/**< \brief A basic game setup */
void gameText();			/**< \brief Render HUD */
void gameLoop();			/**< \brief The basic game render loop */
/**
\file
\brief definition of a lot of gmaing functions and variables
*/

/*** game reltated variables ***/
extern int windowWidth;		/**< \brief window width */
extern int windowHeight;		/**< \brief window height */
extern int hudHeight;			/**< \brief height of the HUD */
extern int gameCols;			/**< \brief columns in the game grid */
extern int gameRows;			/**< \brief rows in the game grid */
extern int cellWidth;			/**< \brief width of a game cell */
extern int cellHeigth;			/**< \brief heigth of a game cell */
extern char cells[20][20][5];	/**< \brief 3-dim array to hold cell states */
extern int cellColors[10][3];	/**< \brief holder for colors */
extern int mouseX;				/**< \brief current mouse postion X */
extern int mouseY;				/**< \brief current mouse postion y */
extern int mouseOverWindow;	/**< \brief mouse in window (1 or 0) */

/*** some old stuff ***/
extern int speed;	/**< \brief rotation speed */
extern int dir;	/**< \brief rotation direction */
extern int deg;	/**< \brief rotation angle */

/*** some old functions ***/
void speedUp();			/**< \brief increase speed */
void speedDown();		/**< \brief decrease speed */
void directionChange();	/**< \brief change direction (no music) */

/*** game related functions ***/
int isInCell(int, int);
void colorCell(int, int, char);	/**< \brief Set the color of a cell */
void gameSetup(int, int);	/**< \brief A basic game setup */
void gameText();			/**< \brief Render HUD */
void gameLoop();			/**< \brief The basic game render loop */
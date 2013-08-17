#ifndef BOARD_H_DEFINED
#define BOARD_H_DEFINED

#include <vector>
#include "Tile.hpp"
#include "Level.hpp"
#include "Shapes.hpp"

/// The game board, where all the action happens.
///
class Board
{
public:
    /// Creates a new empty board with *width* and *height*.
    ///
    /// @note *haveBorders* defines if the board will kill
    ///       the snake or teleport it upon collision.
    ///       By default it teleports.
    Board(Rectangle box, bool haveBorders=false);

    virtual ~Board();

    /// Empties the inner board, getting a fresh new one of
    /// *width* and *height*.
    void clear(Rectangle box);

    /// Loads the default level.
    ///
    /// It is simply a box of borders, with *this->width* and
    /// *this->height*.
    void loadDefaultLevel();

    /// Returns the pointer to the tile at index *x* *y*.
    Tile& at(int x, int y);

    /// Shows the whole board on the screen based on it's
    /// position at *box*.
    void render();

    int getWidth();  ///< Returns the board's width.
    int getHeight(); ///< Returns the board's height.

    void setBorders(bool option);

    /// Tells if the player dies or teleports when colliding
    /// with the border of this Board.
    bool hasBorders();

    // TODO find out how to overload operators
    //      to make *board* access intuitive
    //      (just like at())

    /// Returns the max length any snake may have inside this board.
    ///
    /// Obviously it's the "usable" size inside the board.
    int maxLengthInsideMe();

    /// Loads the level on *filename*, populating the board.
    bool loadFile(std::string filename);

    /// Returns the *Level* related to the board.
    ///
    /// @note This is a BAD practice. I only use it on
    ///       the snake constructor, to place it at the
    ///       starting positions of the level.
    Level* getLevel();

    /// Tells if a point *x* *y* is inside the game map.
    ///
    /// @note It fails under very strange maps!
    bool isInsideMap(int x, int y);

    /// Returns how many players the current board supports.
    int getSupportedPlayers();

    void setSpeed(int speed);
    int getSpeed();

    void increaseSpeed();

    int getTimeout();

    std::string getLevelName();

    void setX(int x);
    void setY(int y);

private:

    /// Matrix containing all the tiles of the game.
    std::vector<std::vector<Tile> > board;

    /// The currently loaded level.
    Level level;

    /// The current game's speed (how fast the snake goes).
    int speed;

    /// How much miliseconds we have to wait to update the
    /// snake,  according to *this->speed*.
    int timeout;

    /// The board's x/y position and width/height.
    Rectangle box;

    /// Tells if the borders are solid or teleportable.
    ///
    /// @note Does this word even exists?
    bool borders;
};

#endif //BOARD_H_DEFINED





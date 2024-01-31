

class game{
    private:
    
    bool blue_ghost_state;

    short playerOrentation = up;
    bool playerState;

    int playerlastX;
    int playerlastY;

    public:

    int playerX = spawnX;
    int playerY = spawnY;

    void spawnPlayer(int X, int Y);
     
     void deletePlayer(int X, int Y);

    void rotatePlayer(short direction){playerOrentation = direction;}

    void movePlayer(){

        deletePlayer(playerlastX, playerlastY);

        switch (playerOrentation){
            case up:
                playerY--;
                break;
            case left:
                playerX--;
                break;
            case down:
                playerY++;
                break;
            case right:
                playerX++;
                break;            
        };

        spawnPlayer(playerX,playerY);

    }
    

    void test(){
        std::cout << "player X - " << playerX << "  player Y - " << playerY << "\n";
        std::cout << "orentation - " << playerOrentation << "\n"; 
    }
};
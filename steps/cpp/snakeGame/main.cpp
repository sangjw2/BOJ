#include <iostream>
#include <ctime>
#include <conio.h>
#define OBJECT_SCORE 20
#define GAMEBOX_SIZE 10
#define REFRESH_RATE 0.3

// x와 y를 바꿔서 생각. x->y. y->x. [행][열] 식으로 배열 생성되는걸 깜빡함.
using namespace std;

class Snake {
private:
    int length{1};
    int bodyMax;
    int x{0},y{0};
    int appleX;
    int appleY;
    bool headCol{true};
    int movPosivite{1};
    char gameBox[GAMEBOX_SIZE+3][GAMEBOX_SIZE+3];
    int gameBoxLife[GAMEBOX_SIZE][GAMEBOX_SIZE]{0,};
    char dirct{0};
    time_t originalTime,curTime;
public:
    Snake() {}
    ~Snake() {
    }

    void endGame() {
        cout << "Your Score is " << length << ", well done." << endl;
        system("pause");
        exit(0);
    }

    void startGame() {
        genGameBox();

        originalTime = (int)clock();

        while(1) {
            curTime = clock();


            if((float)(curTime-originalTime)/CLOCKS_PER_SEC > REFRESH_RATE) {
                originalTime = curTime;
                system("cls");
                calcGame();

            }


            if(kbhit()) {
                dirct = getch();

                switch(dirct) {
                    case 'w':
                        if(movPosivite==1 && headCol) break; // 온 방향(몸통쪽 향하지 못함
                        movPosivite = -1;
                        headCol = true;
                        break;
                    case 's':
                        if(movPosivite==-1 && headCol) break;
                        movPosivite = 1;
                        headCol = true;
                        break;
                    case 'a':
                        if(movPosivite==1 && !headCol) break;
                        movPosivite = -1;
                        headCol = false;
                        break;
                    case 'd':
                        if(movPosivite==-1 && !headCol) break;
                        movPosivite = 1;
                        headCol = false;
                        break;
                }
            }
        }
    }

    void calcGame() {
        if(length>=OBJECT_SCORE) endGame();


        for(auto& row:gameBoxLife) { // 게임판 복사한 배열의 지나간 부분 수명 감소시키기
            for(auto& i : row) {
                if(i!=0) i--;
            }
        }


        if(headCol) x += movPosivite;
        else y += movPosivite;

        if(x==GAMEBOX_SIZE) x=0;
        else if(x == -1) x=9;
        if(y==GAMEBOX_SIZE) y=0;
        else if(y == -1) y=9;




        if(x==appleX && y==appleY) { // 사과를 먹었을 때
            length++;
            generateApple();

        }



        setField();
        drawField();
    }


    void genGameBox();
    void setField();
    void drawField();
    void generateApple();
};

void Snake::generateApple() {
    appleX= rand()%10;
    appleY = rand()%10;
    if(gameBoxLife[appleX][appleY]!=0) generateApple();
}


void Snake::genGameBox() {

    generateApple(); // 초기 apple 위치 설정

    //가로 테두리
    for(int j=0;j<GAMEBOX_SIZE+2;j+=GAMEBOX_SIZE+1){
        for(int i=0;i<GAMEBOX_SIZE+2;i++) {
            gameBox[j][i] = '=';
        }
    }
    // 세로 테두리
    for(int i=0;i<GAMEBOX_SIZE+1;i++) {
        for(int j=0;j<GAMEBOX_SIZE+2;j+=GAMEBOX_SIZE+1) {
            gameBox[i][j] = '|';
        }
    }

    // 빈공간 채우기
    for(int i=0;i<GAMEBOX_SIZE;i++) {
        for(int j=0;j<GAMEBOX_SIZE;j++) {
            gameBox[i+1][j+1] =  '.';
        }
    }

    // Draw Snake
    gameBox[x+1][y+1] = 'O';

    //Draw Apple
    gameBox[appleX+1][appleY+1] = 'x';


}

void Snake::setField() {
    // 빈공간 .으로 채우기
    bodyMax=length;
    for(int i=0;i<GAMEBOX_SIZE;i++) {
        for(int j=0;j<GAMEBOX_SIZE;j++) {
            if(bodyMax>0 && gameBox[i+1][j+1]=='O') { // length개 만큼 몸통 흔적 남기기
                if(!gameBoxLife[i][j]) gameBoxLife[i][j]=length;
                bodyMax--;

                if(gameBoxLife[i][j]==1) { // 수명이 다 된 꼬리 자르기
                    gameBox[i+1][j+1]='.';
                }
                continue;
            }


            gameBox[i+1][j+1] =  '.';
        }
    }

    if(gameBox[x+1][y+1]=='o') endGame(); // 자기 몸에 닿았을 경우

    // set Snake Head
    if(gameBox[x+1][y+1]=='O') endGame();
    gameBox[x+1][y+1] = 'O';


    // set Apple
    gameBox[appleX+1][appleY+1] = 'x';
}

void Snake::drawField() {
    for(int i=0;i<GAMEBOX_SIZE+2;i++) {
        for(int j=0;j<GAMEBOX_SIZE+2;j++){
            cout << gameBox[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Score: " << length << " Object Score: " << OBJECT_SCORE <<endl;
}



// 10 x 10

int main() {
    srand((unsigned int)time(NULL));

    Snake snake;

    snake.startGame();

    return 0;
}

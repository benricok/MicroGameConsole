#include <pong.h>

const unsigned long PADDLE_RATE = 33;
const unsigned long BALL_RATE = 20;
const uint8_t PADDLE_HEIGHT = 24;
int MAX_SCORE = 8;

int CPU_SCORE = 0;
int PLAYER_SCORE = 0;

uint8_t ball_x = 64, ball_y = 32;
uint8_t ball_dir_x = 1, ball_dir_y = 1;

boolean gameIsRunning = true;
boolean resetBall = false;

unsigned long ball_update;
unsigned long paddle_update;

const uint8_t CPU_X = 12;
uint8_t cpu_y = 16;

const uint8_t PLAYER_X = 85;
uint8_t player_y = 16;

void initPong()
{
    ball_update = millis();
    paddle_update = ball_update;
    ball_x = random(25, 65);
    ball_y = random(3, 63);
}

void loopPong()
{
    unsigned long time = millis();
    static bool up_state = false;
    static bool down_state = false;

    up_state |= (digitalRead(UP_BUTTON) == LOW);
    down_state |= (digitalRead(DOWN_BUTTON) == LOW);

    if (resetBall)
    {
        ball_x = random(25, 70);
        ball_y = random(3, 63);
        do
        {
            ball_dir_x = random(-1, 2);
        } while (ball_dir_x == 0);

        do
        {
            ball_dir_y = random(-1, 2);
        } while (ball_dir_y == 0);

        resetBall = false;
    }

    if (time > ball_update && gameIsRunning)
    {
        uint8_t new_x = ball_x + ball_dir_x;
        uint8_t new_y = ball_y + ball_dir_y;

        // Check if we hit the vertical walls
        if (new_x == 0) //Player Gets a Point
        {
            PLAYER_SCORE++;
            if (PLAYER_SCORE == MAX_SCORE)
            {
                gameOver();
            }
            else
            {
                showScore();
            }
        }

        // Check if we hit the vertical walls
        if (new_x == 95) //CPU Gets a Point
        {
            CPU_SCORE++;
            if (CPU_SCORE == MAX_SCORE)
            {
                gameOver();
            }
            else
            {
                showScore();
            }
        }

        // Check if we hit the horizontal walls.
        if (new_y == 0 || new_y == 63)
        {
            ball_dir_y = -ball_dir_y;
            new_y += ball_dir_y + ball_dir_y;
        }

        // Check if we hit the CPU paddle
        if (new_x == CPU_X && new_y >= cpu_y && new_y <= cpu_y + PADDLE_HEIGHT)
        {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        // Check if we hit the player paddle
        if (new_x == PLAYER_X && new_y >= player_y && new_y <= player_y + PADDLE_HEIGHT)
        {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        d.drawPixel(ball_x, ball_y, BLACK);
        d.drawPixel(new_x, new_y, WHITE);
        ball_x = new_x;
        ball_y = new_y;

        ball_update += BALL_RATE;
    }

    if (time > paddle_update && gameIsRunning)
    {
        paddle_update += PADDLE_RATE;

        // CPU paddle
        d.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, BLACK);
        const uint8_t half_paddle = PADDLE_HEIGHT >> 1;
        if (cpu_y + half_paddle > ball_y)
        {
            cpu_y -= 1;
        }
        if (cpu_y + half_paddle < ball_y)
        {
            cpu_y += 1;
        }
        if (cpu_y < 1)
            cpu_y = 1;
        if (cpu_y + PADDLE_HEIGHT > 63)
            cpu_y = 63 - PADDLE_HEIGHT;
        d.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, RED);

        // Player paddle
        d.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, BLACK);
        if (up_state)
        {
            player_y -= 1;
        }
        if (down_state)
        {
            player_y += 1;
        }
        up_state = down_state = false;
        if (player_y < 1)
            player_y = 1;
        if (player_y + PADDLE_HEIGHT > 63)
            player_y = 63 - PADDLE_HEIGHT;
        d.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, GREEN);
    }
}

void showScore()
{
    gameIsRunning = false;
    d.fillScreen(BLACK);
    drawCourt();

    d.setCursor(15, 4);
    d.setTextColor(WHITE);
    d.setTextScale(2);
    d.print("Score");

    d.setCursor(20, 30);
    d.setTextColor(RED);
    d.setTextScale(3);
    d.print(String(CPU_SCORE));

    d.setCursor(60, 30);
    d.setTextColor(GREEN);
    d.setTextScale(3);
    d.print(String(PLAYER_SCORE));

    delay(2000);
    unsigned long start = millis();

    d.fillScreen(BLACK);
    drawCourt();
    while (millis() - start < 2000)
        ;
    ball_update = millis();
    paddle_update = ball_update;
    gameIsRunning = true;
    resetBall = true;
}

void gameOver()
{
    gameIsRunning = false;
    d.fillScreen(BLACK);
    drawCourt();
    if (PLAYER_SCORE > CPU_SCORE)
    {
        d.setCursor(5, 4);
        d.setTextColor(WHITE);
        d.setTextScale(2);
        d.print("You Won");
    }
    else
    {
        d.setCursor(5, 4);
        d.setTextColor(WHITE);
        d.setTextScale(2);
        d.print("CPU WON");
    }

    d.setCursor(20, 30);
    d.setTextColor(RED);
    d.setTextScale(3);
    d.print(String(CPU_SCORE));

    d.setCursor(60, 30);
    d.setTextColor(GREEN);
    d.setTextScale(3);
    d.print(String(PLAYER_SCORE));

    delay(2000);

    while (digitalRead(UP_BUTTON) == HIGH && digitalRead(DOWN_BUTTON) == HIGH)
    {
        delay(100);
    }
    gameIsRunning = true;

    CPU_SCORE = PLAYER_SCORE = 0;

    unsigned long start = millis();
    d.fillScreen(BLACK);
    drawCourt();
    while (millis() - start < 2000)
        ;
    ball_update = millis();
    paddle_update = ball_update;
    gameIsRunning = true;
    resetBall = true;
}

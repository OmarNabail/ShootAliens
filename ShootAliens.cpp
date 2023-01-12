#include <stdio.h>
#include <math.h>
#include <iostream>
#include <random>
#include <glut.h>




bool win;

bool collectedPowerUp = false;
int aliensKilled = 0;

int alien1X = 350;
int alien1Y = 60;


int alien2X = 350;
int alien2Y = 60;


int shotX = 500;
int shotY = 60;



int powerUpX = 500;
int powerUpY = 60;



int humanX = 350;
int humanY = 60;


void drawBuildingsLevel1(int x, int y) {



	//Home
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(x, y);
	glVertex2f(x, y + 150);
	glVertex2f(x + 125, y + 150);
	glVertex2f(x + 125, y);
	glEnd();
	//Door
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(x + 45, y);
	glVertex2f(x + 45, y + 55);
	glVertex2f(x + 70, y + 55);
	glVertex2f(x + 70, y);
	glEnd();
	//window1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 15, y + 110);
	glVertex2f(x + 15, y + 140);
	glVertex2f(x + 30, y + 140);
	glVertex2f(x + 30, y + 110);
	glEnd();
	//window2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 95, y + 110);
	glVertex2f(x + 95, y + 140);
	glVertex2f(x + 110, y + 140);
	glVertex2f(x + 110, y + 110);
	glEnd();
	//roof

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x, y + 150);
	glVertex2f(x + 125, y + 150);
	int z = x + (125 / 2);
	glVertex2f(ceil(z), y + 250);
	glEnd();



}
void drawBuildingsLevel2(int x, int y) {

	//Home
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(x, y);
	glVertex2f(x, y + 350);
	glVertex2f(x + 130, y + 350);
	glVertex2f(x + 130, y);
	glEnd();
	//Door
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(x + 55, y);
	glVertex2f(x + 55, y + 55);
	glVertex2f(x + 75, y + 55);
	glVertex2f(x + 75, y);
	glEnd();
	//window1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 30, y + 100);
	glVertex2f(x + 30, y + 120);
	glVertex2f(x + 50, y + 120);
	glVertex2f(x + 50, y + 100);
	glEnd();
	//window2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 30, y + 200);
	glVertex2f(x + 30, y + 220);
	glVertex2f(x + 50, y + 220);
	glVertex2f(x + 50, y + 200);
	glEnd();
	//window3
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 30, y + 300);
	glVertex2f(x + 30, y + 320);
	glVertex2f(x + 50, y + 320);
	glVertex2f(x + 50, y + 300);
	glEnd();
	//window4
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 80, y + 100);
	glVertex2f(x + 80, y + 120);
	glVertex2f(x + 100, y + 120);
	glVertex2f(x + 100, y + 100);
	glEnd();
	//window5
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 80, y + 200);
	glVertex2f(x + 80, y + 220);
	glVertex2f(x + 100, y + 220);
	glVertex2f(x + 100, y + 200);
	glEnd();
	//window6
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x + 80, y + 300);
	glVertex2f(x + 80, y + 320);
	glVertex2f(x + 100, y + 320);
	glVertex2f(x + 100, y + 300);
	glEnd();
	//Line1
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x + 15, y + 100);
	glVertex2f(x + 15, y + 320);
	glEnd();

	//Line2
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x + 65, y + 100);
	glVertex2f(x + 65, y + 320);
	glEnd();
	//Line3
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(x + 115, y + 100);
	glVertex2f(x + 115, y + 320);
	glEnd();



}

void drawShots(int shotX, int shotY) {

	//head
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(shotX - 11, shotY + 50);
	glVertex2f(shotX, shotY + 65);
	glVertex2f(shotX + 11, shotY + 50);
	glEnd();

	//body
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(shotX, shotY);
	glVertex2f(shotX, shotY + 50);
	glEnd();



}

void drawPowerUp(int powerUpX, int powerUpY) {

	//part1
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(powerUpX - 20, powerUpY - 10);
	glVertex2f(powerUpX, powerUpY + 5);
	glVertex2f(powerUpX + 20, powerUpY - 10);
	glEnd();
	//part2
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(powerUpX, powerUpY, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, 10, 50, 50);
	glPopMatrix();



}

void drawHuman(int humanX, int humanY) {
	//upperBody
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(humanX - 15, humanY - 30);
	glVertex2f(humanX - 15, humanY - 8);
	glVertex2f(humanX + 15, humanY - 8);
	glVertex2f(humanX + 15, humanY - 30);
	glEnd();
	//leftLeg
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(humanX - 15, humanY - 50);
	glVertex2f(humanX - 15, humanY - 30);
	glVertex2f(humanX - 5, humanY - 30);
	glVertex2f(humanX - 5, humanY - 50);
	glEnd();
	//rightLeg
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(humanX + 5, humanY - 50);
	glVertex2f(humanX + 5, humanY - 30);
	glVertex2f(humanX + 15, humanY - 30);
	glVertex2f(humanX + 15, humanY - 50);
	glEnd();
	//leftHand
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(humanX - 30, humanY - 32);
	glVertex2f(humanX - 15, humanY - 8);
	glVertex2f(humanX - 15, humanY - 19);
	glVertex2f(humanX - 24, humanY - 34);
	glEnd();
	//rightHand
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(humanX + 15, humanY - 19);
	glVertex2f(humanX + 15, humanY - 8);
	glVertex2f(humanX + 30, humanY - 32);
	glVertex2f(humanX + 24, humanY - 34);
	glEnd();
	//hat
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(humanX - 10, humanY + 6);
	glVertex2f(humanX, humanY + 16);
	glVertex2f(humanX + 10, humanY + 6);
	glEnd();
	//head
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(humanX, humanY, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, 6, 50, 50);
	glPopMatrix();
}

void drawAliens1(int alien1X, int alien1Y) {
	//upperBody
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(alien1X - 15, alien1Y - 30);
	glVertex2f(alien1X - 15, alien1Y);
	glVertex2f(alien1X + 15, alien1Y);
	glVertex2f(alien1X + 15, alien1Y - 30);
	glEnd();
	//leftLeg
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien1X - 15, alien1Y - 50);
	glVertex2f(alien1X - 15, alien1Y - 30);
	glVertex2f(alien1X - 5, alien1Y - 30);
	glVertex2f(alien1X - 5, alien1Y - 50);
	glEnd();
	//rightLeg
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien1X + 5, alien1Y - 50);
	glVertex2f(alien1X + 5, alien1Y - 30);
	glVertex2f(alien1X + 15, alien1Y - 30);
	glVertex2f(alien1X + 15, alien1Y - 50);
	glEnd();
	//hand1
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien1X - 38, alien1Y - 14);
	glVertex2f(alien1X - 15, alien1Y - 8);
	glVertex2f(alien1X - 15, alien1Y - 19);
	glVertex2f(alien1X - 32, alien1Y - 20);
	glEnd();
	//hand2
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien1X - 30, alien1Y - 52);
	glVertex2f(alien1X - 15, alien1Y - 15);
	glVertex2f(alien1X - 15, alien1Y - 23);
	glVertex2f(alien1X - 24, alien1Y - 54);
	glEnd();
	//hand3
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien1X + 15, alien1Y - 19);
	glVertex2f(alien1X + 15, alien1Y - 8);
	glVertex2f(alien1X + 38, alien1Y - 14);
	glVertex2f(alien1X + 32, alien1Y - 20);
	glEnd();
	//hand4
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien1X + 15, alien1Y - 23);
	glVertex2f(alien1X + 15, alien1Y - 15);
	glVertex2f(alien1X + 30, alien1Y - 52);
	glVertex2f(alien1X + 24, alien1Y - 54);
	glEnd();
	//head
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(alien1X - 10, alien1Y);
	glVertex2f(alien1X, alien1Y + 12);
	glVertex2f(alien1X + 10, alien1Y);
	glEnd();





}
void drawAliens2(int  alien2X, int  alien2Y) {
	//head
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien2X - 7, alien2Y - 29);
	glVertex2f(alien2X - 7, alien2Y - 12);
	glVertex2f(alien2X + 7, alien2Y - 12);
	glVertex2f(alien2X + 7, alien2Y - 29);
	glEnd();
	//leftLeg
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien2X - 8, alien2Y - 90);
	glVertex2f(alien2X - 4, alien2Y - 60);
	glVertex2f(alien2X - 2, alien2Y - 90);
	glEnd();
	//rightLeg
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien2X + 2, alien2Y - 90);
	glVertex2f(alien2X + 4, alien2Y - 60);
	glVertex2f(alien2X + 8, alien2Y - 90);
	glEnd();
	//leftHand
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien2X - 38, alien2Y - 45);
	glVertex2f(alien2X - 8, alien2Y - 40);
	glVertex2f(alien2X - 8, alien2Y - 35);
	glVertex2f(alien2X - 32, alien2Y - 55);
	glEnd();
	//rightHand
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(alien2X + 8, alien2Y - 40);
	glVertex2f(alien2X + 38, alien2Y - 45);
	glVertex2f(alien2X + 32, alien2Y - 55);
	glVertex2f(alien2X + 8, alien2Y - 35);
	glEnd();
	//upperBody
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(alien2X, alien2Y - 45, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, 16, 50, 50);
	glPopMatrix();




}

void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}



struct Bullet
{
	Bullet(int x, int y, int curX, int curY)
	{
		this->x = x;
		this->y = y;
		dirX = curX - x;
		dirY = curY - y;
	}

	int x = 0, y = 0;
	int dirX = 0, dirY = 0;

	void Draw()
	{
		drawShots(x, y);
	}

	void increment()
	{
		x += dirX;
		y += dirY;
	}
};

struct Alien
{
	Alien(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x = 0, y = 0;
	bool powerUP = false;
	void Draw()
	{
		if (powerUP)
		{
			drawPowerUp(x, y);
			return;
		}
		if (aliensKilled < 15)
			drawAliens1(x, y);
		else
			drawAliens2(x, y);
	}

	void fall()
	{
		y--;
	}
};

std::vector<Bullet> bullets;
std::vector<Alien> aliens;


int distance(int x1, int y1, int x2, int y2)
{
	return std::sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
bool lose = false;
void Display() {
	glClearColor(1, 1, 0, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//drawPowerUp(225, 50);
	//drawShots(humanX, humanY);

	if (lose)
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1000, 0);
		glVertex3f(1000, 1000, 0);
		glVertex3f(1000, 0, 0);
		glEnd();
		glColor3f(1, 0, 0);
		char* p0s[20];
		sprintf((char*)p0s, "Score: %d", aliensKilled);
		print(410, 300, (char*)p0s);
		sprintf((char*)p0s, " You Lost :(");
		print(500, 300, (char*)p0s);
	}
	else if (aliensKilled > 30) {
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1000, 0);
		glVertex3f(1000, 1000, 0);
		glVertex3f(1000, 0, 0);
		glEnd();
		glColor3f(1, 0, 0);
		char* p0s[20];
		sprintf((char*)p0s, "Score: %d", aliensKilled);
		print(410, 300, (char*)p0s);
		sprintf((char*)p0s, " You Won :D");
		print(500, 300, (char*)p0s);

	}
	else
	{
		if (aliensKilled < 15) {



			drawBuildingsLevel1(40, 150);


			drawBuildingsLevel1(190, 150);


			drawBuildingsLevel1(340, 150);

			drawBuildingsLevel1(490, 150);
		}
		else
		{
			glClearColor(1, 0, 1, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			drawBuildingsLevel2(50, 150);


			drawBuildingsLevel2(250, 150);


			drawBuildingsLevel2(450, 150);

			drawBuildingsLevel2(650, 150);
		}
		drawHuman(humanX, humanY);

		for (auto& b : bullets)
		{
			b.Draw();
			for (int i = 0; i < aliens.size(); i++)
				if (distance(aliens[i].x, aliens[i].y, b.x, b.y) < 85)
				{
					if (aliens[i].powerUP)
						collectedPowerUp = true;

					aliens.erase(aliens.begin() + i);

					return;
				}
		}

		for (auto& a : aliens)
		{
			a.Draw();
			if (a.y < 50 && !a.powerUP)
				lose = true;
		}

	}

	glutSwapBuffers();
}

bool Fire = false;
void timerBullet(int) {
	glutPostRedisplay();
	glutTimerFunc(1000, timerBullet, 0);

	Fire = true;

}

void timerPowerUp(int) {
	glutPostRedisplay();
	glutTimerFunc(10000, timerPowerUp, 0);

	int randomX = (1 + (rand() % 100)) * 7;
	Alien a = Alien(randomX, 700);
	a.powerUP = true;
	aliens.push_back(a);

}


void timerBulletMove(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 10, timerBulletMove, 0);

	for (auto& b : bullets)
		b.increment();

}


//Alien Creator
void timerCreateAlien(int) {
	glutPostRedisplay();
	glutTimerFunc(2500, timerCreateAlien, 0);
	int randomX = (1 + (rand() % 100)) * 7;
	aliens.push_back(Alien(randomX, 700));
	aliensKilled++;
}


//Aliens Faller
void timerA1(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timerA1, 0);

	for (auto& a : aliens)
		a.fall();
}
void timerA2(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timerA2, 0);

	if (alien2Y > 1000)
		alien2Y = 0;
	alien2Y += 8;

	if (alien2Y < 0)
		alien2Y = 1000;
	alien2Y -= 10;
}



void actM(int button, int state, int x, int y)//mouse function takes 4 parameters: button: which button has been clicked (GLUT_RIGHT_BUTTON or GLUT_LEFT_BUTTON),
											//state wether the button is clicked or released (GLUT_UP or GLUT_DOWN)
											// x and y are the position of the mouse cursor
{
	if (Fire && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//if the left button has been clicked then translate the square to the mouse position
	{

		std::cout << "x: " << x << " y: " << y << std::endl;
		bullets.push_back(Bullet(humanX, humanY, x, 700 - y));
		Fire = false;


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && collectedPowerUp)//if the left button has been clicked then translate the square to the mouse position
	{
		aliensKilled += aliens.size();
		aliens.clear();


		collectedPowerUp = false;
	}


	glutPostRedisplay();//redisplay to update the screen with the new paraeters
}

void key(unsigned char k, int x, int y)//keyboard function, takes 3 parameters
									// k is the key pressed from the keyboard
									// x and y are mouse postion when the key was pressed.
{
	if (k == 'd')//if the letter d is pressed, then the object will be translated in the x axis by 1 (moving to the right).
		if (humanX < 700) {
			humanX += 5;
		}
	if (k == 'a')//if the letter a is pressed, then the object will be translated in the x axis by -1 (moving to the left).
		if (humanX > 0) {
			humanX -= 5;
		}
	glutPostRedisplay();//redisplay to update the screen with the changes
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(150, 50);
	glutCreateWindow("Game");
	glutDisplayFunc(Display);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glPointSize(9.0);
	glLineWidth(9.0);
	gluOrtho2D(0.0, 700, 0.0, 700);
	//glutIdleFunc(Anim);
	glutKeyboardFunc(key);

	glutMouseFunc(actM);
	glutTimerFunc(1000, timerA2, 0);
	glutTimerFunc(1000, timerA1, 0);
	glutTimerFunc(1000, timerBullet, 0);
	glutTimerFunc(1000, timerBulletMove, 0);
	glutTimerFunc(200, timerCreateAlien, 0);
	glutTimerFunc(5000, timerPowerUp, 0);


	glutMainLoop();
}

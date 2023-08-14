#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void sea();
void submarine();
void submarine1();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void update1();
void update2();
void fish();
void ship();
void control();
void my_mouse(int button, int state, int x, int y);
//initialising variables
GLint a=300,b=-300,c=350,flag=0,traffic_regulator=1,control_keyl,control_keyr,ab=70;
GLfloat red=0.1,blue=0.8,green=0.3;
GLfloat yel1=1.0,yel2=0.9,yel3=0.0;
GLfloat red1=0.0,blue1=1.0,green1=1.0;
GLfloat p=0,q=0,r=0;
bool showInnerPart = false;
int M_PI=3.141592653589793238462643383279502884197;
//-----------
void *currentfont;
//this is to create small fishes

GLubyte fishh[] = {
0x00, 0x60, 0x01, 0x00,
0x00, 0x90, 0x01, 0x00,
0x03, 0xf8, 0x02, 0x80,
0x1c, 0x37, 0xe4, 0x40,
0x20, 0x40, 0x90, 0x40,
0xc0, 0x40, 0x78, 0x80,
0x41, 0x37, 0x84, 0x80,
0x1c, 0x1a, 0x04, 0x80,
0x03, 0xe2, 0x02, 0x40,
0x00, 0x11, 0x01, 0x40,
0x00, 0x0f, 0x00, 0xe0,

};
//-----------draw fish


GLfloat randomFloat() {
return (GLfloat)rand() / ab;
}
void fishes() {
glPushMatrix();
glTranslated(a,20.0,0.0);
for (int i = 0; i < 50; i++) {//for pink fish
//group of fish along with fish
glColor3f(1,0,1);
glRasterPos3f(randomFloat(), randomFloat(), 0.0);//whre the next pixel will be drawn
glBitmap(27, 11, 0, 0, 0, 0, fishh);//array of pixels (picture elements), where each pixel represents a single point in an image.
}
for (int i = 0; i < 13; i++) {//for yellow fish
    //scattered fishes
glColor3f(1,1,0);
glTranslatef(100,0.0,0.0);
glRasterPos3f(randomFloat(), randomFloat(), 0.0);
glBitmap(27, 11, 0, 0, 0, 0, fishh);
}
glFlush();//immediately proceed function
glPopMatrix();

}

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}
void frontscreen(void)
{//for frontscreen
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,1.0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
drawstring(450.0,700.0,0.0,"CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY ");
glColor3f(0.7,0,1);
drawstring(330,650,0.0,"DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING");
glColor3f(1,0.5,0);
drawstring(530,600,0.0,"A MINI PROJECT ON");
glColor3f(1,0,0);
drawstring(530,550,0.0,"SUBMARINE IN THE SEA");
glColor3f(1,0.1,1);
drawstring(543,100,0.0,"PRESS ENTER TO START");
glFlush();
}


void myKeyboard( unsigned char key, int x, int y )

{
switch(key)
{
	case 13:
		if(flag==0) //Ascii of 'enter' key is 13
		{
	       flag=1;
	       mydisplay();
		}

	break;

	default:break;
}

}



void mydisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
  frontscreen ();
if(flag==1)
  display();
 glutSwapBuffers();
}

void update(int value)
{
a=a-4;//fishes speed right to left
b=b+4;//submarine ship speed left to right
//control();
/*making day to night*/
if(blue!=0&&green!=0)
{
blue-=.003;green-=.003;

}
}

void update1(int value)//sun to moon
{

/*making day to night*/

if(yel3!=1)
{
yel3+=.003;

}

glutPostRedisplay();
}

void update2(int value)
{

a=a-4;
b=b+4;
//control();
/*making day to night*/
if(blue1!=0&&green1!=0)
{
blue1-=.003;green1-=.003;

}
}
void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN) {
            showInnerPart = !showInnerPart; // Toggle the value
            glutPostRedisplay(); // Trigger a redraw to show/hide inner part
         }
         break;
      default:
         break;
   }
}
void display(void)
{
    glutTimerFunc(100,update,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(red,green,blue,0);/*back ground for sky*/
    sea();
    fishes();
    ship();
    if (showInnerPart) {
            submarine1();//show inner part of submarine
        // ...
    } else {
        submarine(); // show outer part of submarine
    }
glFlush();
}


void sea()
{//GLint n=-50;
glPushMatrix();
glScaled(40.0,40.0,0.0);
glPushMatrix();//for sun
glutTimerFunc(50,update1,0);//for changing to moon
glTranslated(10.0,15.0,0.0);
glColor3f(yel1,yel2,yel3);
//glTranslatef(0.0,b,0.0);
//glTranslatef(n,0.0,0.0);

glutSolidSphere(2.0,25,25);
glPopMatrix();//for sun

glPushMatrix();//for sea
glutTimerFunc(100,update2,0);//to show night effect
glColor3f(red1,blue1,green1);

glBegin(GL_POLYGON);
//OCEAN
glVertex2f(0,0);
glVertex2f(40,0);
glVertex2f(40,12);
glVertex2f(0,12);
glEnd();
glPopMatrix();
glPushMatrix();
glBegin(GL_POLYGON);

//skyblue border above sea
glTranslatef(0,50,0);
glVertex2f(0,12);
glVertex2f(40,12);
glVertex2f(40,12.5);
glVertex2f(0,12.5);
glEnd();
glPopMatrix();

///////yellow ground
glBegin(GL_POLYGON);
glColor3f(1,1,0);
glVertex2f(40,1);
glVertex2f(0,1);
glColor3f(1,0.5,0);
glVertex2f(0,0);
glVertex2f(40,0);
glEnd();
//////////three stones
glBegin(GL_POLYGON);
glColor3f(0.2,0.2,0.2);
glVertex2f(5, 0);
glVertex2f(6.5, 0);
glColor3f(0,0,0);
glVertex2f(6.5, 1);
glVertex2f(6, 1);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.2,0.2,0.2);
glVertex2f(15, 0);
glVertex2f(17, 0);
glColor3f(0,0,0);
glVertex2f(17, 1.5);
glVertex2f(16.5, 1.5);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.2,0.2,0.2);
glVertex2f(25, 0);
glVertex2f(27, 0);
glColor3f(0,0,0);
glVertex2f(27, 1.5);
glVertex2f(25.5, 1.5);
glEnd();
////Green plants
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(2, 2);
glVertex2f(3, 0);
glVertex2f(4, 2);
glVertex2f(3, 0);
glVertex2f(3, 0);
glVertex2f(3, 2);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(6, 2);
glVertex2f(7, 0);
glVertex2f(8, 2);
glVertex2f(7, 0);
glVertex2f(7, 0);
glVertex2f(7, 2);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(11, 2);
glVertex2f(12, 0);
glVertex2f(13, 2);
glVertex2f(12, 0);
glVertex2f(12, 0);
glVertex2f(12, 2);
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(14, 2);
glVertex2f(15, 0);
glVertex2f(15, 0);
glVertex2f(16, 2);
glVertex2f(15, 0);
glVertex2f(15, 2);
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(18, 2);
glVertex2f(19, 0);
glVertex2f(19, 0);
glVertex2f(20, 2);
glVertex2f(19, 0);
glVertex2f(19, 2);
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(21, 2);
glVertex2f(22, 0);
glVertex2f(22, 0);
glVertex2f(23, 2);
glVertex2f(22, 0);
glVertex2f(22, 2);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(26, 2);
glVertex2f(27, 0);
glVertex2f(28, 2);
glVertex2f(27, 0);
glVertex2f(27, 0);
glVertex2f(27, 2);
glEnd();
glPopMatrix();
////to draw big fish
glPushMatrix();
glTranslatef(a, 0, 0.0);
glBegin(GL_POLYGON); // draw body
    glColor3f(0.1, 0.1, 0.3); // Whale Color (Dark Blue)
    glVertex2i(40, 200);
    glVertex2i(120, 280);
    glVertex2i(320, 200);
    glVertex2i(100, 160);
glEnd();

glBegin(GL_POLYGON); // draw tail
    glColor3f(0.1, 0.1, 0.3); // Whale Color (Dark Blue)
    glVertex2i(320, 200);
    glVertex2i(360, 240);
    glVertex2i(340, 200);
    glVertex2i(360, 160);
    glVertex2i(320, 200);
glEnd();

glPopMatrix();
}
void ship()
{
glPushMatrix(); //making color for outer line
glTranslated(b,250.0,0.0);
glScaled(30.0,30.0,0.0);
//ship 1st part
glColor3f(0.6, 0.37, 0.16);
glBegin(GL_POLYGON);
glVertex2f(2,8.2);
glVertex2f(0,11);
glVertex2f(12,11);
glVertex2f(10,8.2);
glEnd();
//ship 2nd part
glColor3f(0.75, 0.75, 0.75);;
glBegin(GL_POLYGON);
glVertex2f(2,11);
glVertex2f(11,11);
glVertex2f(9,12);
glVertex2f(3,12);
glEnd();
//windows
glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(3.2,11.3);
glVertex2f(3.9,11.3);
glVertex2f(3.9,11.8);
glVertex2f(3.2,11.8);
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(4.2,11.3);
glVertex2f(4.9,11.3);
glVertex2f(4.9,11.8);
glVertex2f(4.2,11.8);
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(5.2,11.3);
glVertex2f(5.9,11.3);
glVertex2f(5.9,11.8);
glVertex2f(5.2,11.8);
glEnd();


glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(6.2,11.3);
glVertex2f(6.9,11.3);
glVertex2f(6.9,11.8);
glVertex2f(6.2,11.8);
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(7.2,11.3);
glVertex2f(7.9,11.3);
glVertex2f(7.9,11.8);
glVertex2f(7.2,11.8);
glEnd();

glColor3f(1, 1, 1);
glBegin(GL_POLYGON);
glVertex2f(8.2,11.3);
glVertex2f(8.9,11.3);
glVertex2f(8.9,11.8);
glVertex2f(8.2,11.8);
glEnd();
//ship 3rd part
glColor3f(0.85, 0.65, 0.40);
glBegin(GL_POLYGON);
glVertex2f(3,12);
glVertex2f(9,12);
glVertex2f(8,12.3);
glVertex2f(4,12.3);
glEnd();
//windows of 1st part
glColor3f(0.529, 0.808, 0.922);
glBegin(GL_POLYGON);
glVertex2f(2.5,9);
glVertex2f(3.5,9);
glVertex2f(3.5,10);
glVertex2f(2.5,10);
glEnd();

glColor3f(0.529, 0.808, 0.922);
glBegin(GL_POLYGON);
glVertex2f(4.5,9);
glVertex2f(5.5,9);
glVertex2f(5.5,10);
glVertex2f(4.5,10);
glEnd();

glColor3f(0.529, 0.808, 0.922);
glBegin(GL_POLYGON);
glVertex2f(6.5,9);
glVertex2f(7.5,9);
glVertex2f(7.5,10);
glVertex2f(6.5,10);
glEnd();

glColor3f(0.529, 0.808, 0.922);
glBegin(GL_POLYGON);
glVertex2f(8.5,9);
glVertex2f(9.5,9);
glVertex2f(9.5,10);
glVertex2f(8.5,10);
glEnd();
//upper ship pipe
glColor3f(1.0, 0.843, 0.0);
glBegin(GL_POLYGON);
glVertex2f(4.5,12.3);
glVertex2f(5,12.3);
glVertex2f(5,12.97);
glVertex2f(4.5,12.97);
glEnd();

glColor3f(1.0, 0.843, 0.0);
glBegin(GL_POLYGON);
glVertex2f(5.5,12.3);
glVertex2f(6,12.3);
glVertex2f(6,12.97);
glVertex2f(5.5,12.97);
glEnd();

glColor3f(1.0, 0.843, 0.0);
glBegin(GL_POLYGON);
glVertex2f(6.5,12.3);
glVertex2f(7,12.3);
glVertex2f(7,12.97);
glVertex2f(6.5,12.97);
glEnd();

glPopMatrix();
}


void submarine()//outer part of submarine
{
//////
glPushMatrix(); //making color for outer line
glTranslated(b,250.0,0.0);
glScaled(30.0,30.0,0.0);
//silver effect
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(7,7);
glVertex2f(5,5);
glVertex2f(22,5);
glVertex2f(20,7);
glEnd();
//
//body of submarine
glColor3f(0.2,0.2,0.2);
glBegin(GL_LINE);
glVertex2f(-1,3);
glVertex2f(0,3);
glEnd();

glBegin(GL_POLYGON);

glVertex2f(0,3);
glVertex2f(0,4);
glVertex2f(1,6);
glVertex2f(25,6);
glVertex2f(26,3);
glVertex2f(25,1);
glVertex2f(1,1);

glEnd();

////upper part of submarine
glColor3f(0.4,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2f(5,6);
glVertex2f(21,6);
glColor3f(0.1,0.1,0.1);
glVertex2f(20,7);
glVertex2f(6,7);
glEnd();
////border line for glass of windows
glColor3f(0.1,0.7,0.976471);
//For front window line
glBegin(GL_LINE_LOOP);
glVertex2f(22,3);
glVertex2f(22,5.5);
glVertex2f(24.5,5.5);
glVertex2f(25.5,3);
glVertex2f(24.5,3);
glEnd();
//small window line
glBegin(GL_LINE_LOOP);
glVertex2f(5,2);
glVertex2f(7,2);
glVertex2f(7,4);
glVertex2f(5,4);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(9,2);
glVertex2f(11,2);
glVertex2f(11,4);
glVertex2f(9,4);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(13,2);
glVertex2f(15,2);
glVertex2f(15,4);
glVertex2f(13,4);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(17,2);
glVertex2f(19,2);
glVertex2f(19,4);
glVertex2f(17,4);
glEnd();
///////////////
//pipe
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(19,10);
glColor3f(0.5,0.5,0.5);
glVertex2f(20,10);
glColor3f(1,1,1);
glVertex2f(21,10);
glColor3f(0.5,0.5,0.5);
glVertex2f(21,9);
glColor3f(0,0,0);
glVertex2f(20,9);
glColor3f(0.5,0.5,0.5);
glVertex2f(20,7);
glVertex2f(19,7);
glVertex2f(19,7);
glEnd();
//Pipe outline
glColor3f(0.1,0.1,0.1);
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex2f(19,7);
glVertex2f(19,10);
glColor3f(0,0,0);
glVertex2f(20,10);
glVertex2f(21,10);
glVertex2f(21,9);
glVertex2f(20,9);
glVertex2f(20,7);
glEnd();
//Front window body
glBegin(GL_POLYGON);
glColor3f(0,0,1);
glVertex2f(22,3);
glVertex2f(22,5.5);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(24.5,5.5);
glVertex2f(25.5,3);
glVertex2f(24.5,3);
glEnd();

////small windows body
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(5,2);
glVertex2f(7,2);
glColor3f(0,0,1);
glVertex2f(7,4);
glVertex2f(5,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(9,2);
glVertex2f(11,2);
glColor3f(0,0,1);
glVertex2f(11,4);
glVertex2f(9,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(13,2);
glVertex2f(15,2);
glColor3f(0,0,1);
glVertex2f(15,4);
glVertex2f(13,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(17,2);
glVertex2f(19,2);
glColor3f(0,0,1);
glVertex2f(19,4);
glVertex2f(17,4);
glEnd();
glPopMatrix();

glPushMatrix();

glTranslated(b,250.0,0.0);
glScalef(20,20,0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,1,1);
drawstring(8,7,0,"AQUATICA SUBMARINE 2023");
glPopMatrix();
////////////////////////////////////////////////////////////////////////////////////////////////
}
//for drawing human head
void drawCircle(float centerX, float centerY, float radius, int numSegments) {
    glColor3f(0.7, 0.4, 0.2);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the circle

    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0 * M_PI * i / numSegments;
        float x = radius * cos(angle) + centerX;
        float y = radius * sin(angle) + centerY;
        glVertex2f(x, y);
    }

    glEnd();
}
void submarine1()
{
//////
glPushMatrix(); //making color for outer line
glTranslated(b,250.0,0.0);
glScaled(30.0,30.0,0.0);
//silver effect
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(7,7);
glVertex2f(5,5);
glVertex2f(22,5);
glVertex2f(20,7);
glEnd();
//
//body of submarine
glColor3f(0.2,0.2,0.2);
glBegin(GL_LINE);
glVertex2f(-1,3);
glVertex2f(0,3);
glEnd();
glBegin(GL_POLYGON);

glVertex2f(0,3);
glVertex2f(0,4);
glVertex2f(1,6);
glVertex2f(25,6);
glVertex2f(26,3);
glVertex2f(25,1);
glVertex2f(1,1);
glVertex2f(1,1);

glEnd();

////upper part of submarine
glColor3f(0.4,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2f(5,6);
glVertex2f(21,6);
glColor3f(0.1,0.1,0.1);
glVertex2f(20,7);
glVertex2f(6,7);
glEnd();

//pipe
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(19,10);
glColor3f(0.5,0.5,0.5);
glVertex2f(20,10);
glColor3f(1,1,1);
glVertex2f(21,10);
glColor3f(0.5,0.5,0.5);
glVertex2f(21,9);
glColor3f(0,0,0);
glVertex2f(20,9);
glColor3f(0.5,0.5,0.5);
glVertex2f(20,7);
glVertex2f(19,7);
glVertex2f(19,7);
glEnd();
//pipe outline
glColor3f(0.1,0.1,0.1);
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex2f(19,7);
glVertex2f(19,10);
glColor3f(0,0,0);
glVertex2f(20,10);
glVertex2f(21,10);
glVertex2f(21,9);
glVertex2f(20,9);
glVertex2f(20,7);
glEnd();
//inner part
glColor3f(0.95, 0.87, 0.68);
glBegin(GL_POLYGON);

glVertex2f(0.5,3);
glVertex2f(1.5,1.5);
glVertex2f(24.5,1.5);
glVertex2f(25.5,3);
glVertex2f(24.5,5.6);
glVertex2f(1.5,5.6);
glVertex2f(0.5,4);

glEnd();
//Front window body
glBegin(GL_POLYGON);
glColor3f(0,0,1);
glVertex2f(22,3);
glVertex2f(22,5.5);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(24.5,5.5);
glVertex2f(25.5,3);
glVertex2f(24.5,3);
glEnd();

////small windows body
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(5,2);
glVertex2f(7,2);
glColor3f(0,0,1);
glVertex2f(7,4);
glVertex2f(5,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(9,2);
glVertex2f(11,2);
glColor3f(0,0,1);
glVertex2f(11,4);
glVertex2f(9,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(13,2);
glVertex2f(15,2);
glColor3f(0,0,1);
glVertex2f(15,4);
glVertex2f(13,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(17,2);
glVertex2f(19,2);
glColor3f(0,0,1);
glVertex2f(19,4);
glVertex2f(17,4);
glEnd();
//inner line
glColor3f(0.4,0.5,0.5);
glBegin(GL_LINES);
glVertex2f(0.5,4.2);
glVertex2f(25.1,4.2);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
//computer
glVertex2f(21.7,1.5);
glVertex2f(24.5,1.5);
glVertex2f(24.5,3.5);
glVertex2f(24,3.5);
glVertex2f(24,2.5);
glVertex2f(21.7,2.5);

glEnd();
//1st chair & human
glColor3f(0.4,0.5,0.5);
glBegin(GL_POLYGON);

glVertex2f(19.5,1.5);
glVertex2f(21.5,1.5);
glVertex2f(21.5,2);
glVertex2f(20.5,2);
glVertex2f(20.5,3);
glVertex2f(19.5,3);

glEnd();
//head of human
drawCircle(20.8, 3.4, .3, 100);
//hair of human
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);

glVertex2f(20.66,3.67);
glVertex2f(20.90,3.67);
glVertex2f(20.90,3.80);
glVertex2f(20.66,3.80);
glEnd();
//body of human
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);

glVertex2f(20.7,2);
glVertex2f(21.2,2);
glVertex2f(20.9,3.1);
glVertex2f(20.7,3.1);
glEnd();
//2nd chair
glColor3f(0.4,0.5,0.5);
glBegin(GL_POLYGON);

glVertex2f(17,1.5);
glVertex2f(19,1.5);
glVertex2f(19,2);
glVertex2f(18,2);
glVertex2f(18,3);
glVertex2f(17,3);

glEnd();
//3rd chair & human
glColor3f(0.4,0.5,0.5);
glBegin(GL_POLYGON);

glVertex2f(14.5,1.5);
glVertex2f(16.5,1.5);
glVertex2f(16.5,2);
glVertex2f(15.5,2);
glVertex2f(15.5,3);
glVertex2f(14.5,3);

glEnd();
//head of human
drawCircle(15.8, 3.4, .3, 100);
//hair of human
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);

glVertex2f(15.66,3.67);
glVertex2f(15.90,3.67);
glVertex2f(15.90,3.80);
glVertex2f(15.66,3.80);
glEnd();
//body of human
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);

glVertex2f(15.7,2);
glVertex2f(16.2,2);
glVertex2f(15.9,3.1);
glVertex2f(15.7,3.1);
glEnd();
//big wardrop
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);

glVertex2f(10,1.5);
glVertex2f(14,1.5);
glVertex2f(14,3.5);
glVertex2f(10,3.5);
glEnd();
//line of wardrope
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(11, 1.5);
    glVertex2f(11, 3.5);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(12, 1.5);
    glVertex2f(12, 3.5);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(13, 1.5);
    glVertex2f(13, 3.5);
    glEnd();

//upper 1st wardrope
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex2f(9,4.2);
glVertex2f(12,4.2);
glVertex2f(12,5.4);
glVertex2f(9,5.4);

glEnd();
//line of wardrope
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(9.5, 4.2);
    glVertex2f(9.5, 5.4);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(10.5, 4.2);
    glVertex2f(10.5, 5.4);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(11.5, 4.2);
    glVertex2f(11.5, 5.4);
    glEnd();
//upper 2nd wardrope
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);

glVertex2f(12.2,4.2);
glVertex2f(14,4.2);
glVertex2f(14,5.2);
glVertex2f(12.2,5.2);
glEnd();
//line of wardrope
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(12.3, 4.2);
    glVertex2f(12.3, 5.2);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(13, 4.2);
    glVertex2f(13, 5.2);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(13.7, 4.2);
    glVertex2f(13.7, 5.2);
    glEnd();
//bed
glColor3f(0.6, 0.3, 0.0);
glBegin(GL_POLYGON);

glVertex2f(18,4.2);
glVertex2f(21,4.2);
glVertex2f(21,4.5);
glVertex2f(18,4.5);
glEnd();
glColor3f(0.4, 0.4, 0.4);
glBegin(GL_POLYGON);

glVertex2f(21,4.2);
glVertex2f(21.3,4.2);
glVertex2f(21.3,4.9);
glVertex2f(21,4.9);
glEnd();

//stairs
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 1.5);
    glVertex2f(7, 5.4);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(8, 1.5);
    glVertex2f(8, 5.4);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 2.06);
    glVertex2f(8, 2.06);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 2.62);
    glVertex2f(8, 2.62);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 3.18);
    glVertex2f(8, 3.18);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 3.74);
    glVertex2f(8, 3.74);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 4.3);
    glVertex2f(8, 4.3);
    glEnd();
glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(7, 4.86);
    glVertex2f(8, 4.86);
    glEnd();
//cylinder
//red part
//4th no
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(4.6,1.5);
glVertex2f(4.9,1.5);
glVertex2f(5,1.6);
glVertex2f(5,2.9);
glVertex2f(4.9,3);
glVertex2f(4.6,3);
glVertex2f(4.5,2.9);
glVertex2f(4.5,1.6);
glEnd();
//black part of cylinder
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(4.6,3);
glVertex2f(4.9,3);
glVertex2f(4.9,3.3);
glVertex2f(4.6,3.3);
glEnd();
//3rd cylinder
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(3.8,1.5);
glVertex2f(4.1,1.5);
glVertex2f(4.2,1.6);
glVertex2f(4.2,2.9);
glVertex2f(4.1,3);
glVertex2f(3.8,3);
glVertex2f(3.7,2.9);
glVertex2f(3.7,1.6);
glEnd();

glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(3.8,3);
glVertex2f(4.1,3);
glVertex2f(4.1,3.3);
glVertex2f(3.8,3.3);
glEnd();

//2nd cylinder
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(3,1.5);
glVertex2f(3.3,1.5);
glVertex2f(3.4,1.6);
glVertex2f(3.4,2.9);
glVertex2f(3.3,3);
glVertex2f(3,3);
glVertex2f(2.9,2.9);
glVertex2f(2.9,1.6);
glEnd();

glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(3,3);
glVertex2f(3.3,3);
glVertex2f(3.3,3.3);
glVertex2f(3,3.3);
glEnd();

//1st cylinder
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(2.2,1.5);
glVertex2f(2.5,1.5);
glVertex2f(2.6,1.6);
glVertex2f(2.6,2.9);
glVertex2f(2.5,3);
glVertex2f(2.2,3);
glVertex2f(2.1,2.9);
glVertex2f(2.1,1.6);
glEnd();

glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);

glVertex2f(2.2,3);
glVertex2f(2.5,3);
glVertex2f(2.5,3.3);
glVertex2f(2.2,3.3);
glEnd();

glPopMatrix();
/////////////////////////////////////////////////////////////////////
///////////////////////////
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1346,728);
glutInitWindowPosition(0,0);
glutCreateWindow("SUBMARINE");
myinit();
glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboard);
 glutMouseFunc(my_mouse);
glutMainLoop();
}

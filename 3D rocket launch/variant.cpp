#include<windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
static double x=0.0,x1=0.0,Y1=0.1,z1=0.0,a1=0,y2=0,z2=0;
static double move=-60;
static bool seperate=false;
int flag=0;
int flag1=0;
void mykey();
void p();
static float cameraAngle=0.0f;
static float cameraRadius=90.0f;
int Cx=0;
int Cy=0;
int Cz=0;

void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
va_list args;
char buffer[200], *p;
va_start(args, format);
vsprintf(buffer, format, args);
va_end(args);
glPushMatrix();
glTranslatef(-2.5, y, 0);
glScaled(0.003, 0.005, 0.005);
for (p = buffer; *p; p++)
glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
glPopMatrix();
}

void satellite(){

glPushMatrix();


//Core

glPushMatrix();
glColor3f(1,1,0);
glTranslatef(0,2,0);
glScaled(0.3,1,0.3);
glRotatef(90,1,0,0);
if(x<=6)
glutSolidTorus(0.5,1,30,30);
else
{
glutSolidCube(1);
glPopMatrix();

// Solar Panel

glPushMatrix();
glColor3f(0.2,0.2,0.2);
glTranslatef(1,2,0);

if(x>=6){
glScaled(4,1.5,0.1);
}

else
glScaled(0,0,0);
glRotatef(-20,1,0,0);
glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();
glColor3f(0.2,0.2,0.2);
glTranslatef(-1,2,0);
if(x>=6){
glScaled(4,1.5,0.1);
}
else
glScaled(0,0,0);
glRotatef(-20,1,0,0);
glutSolidCube(0.5);
glPopMatrix();

glPopMatrix();
}
}

void rocket()
{
// Main top cone
glPushMatrix();

if(x<=5.5&&flag1==2){
glTranslatef(z2,-z2,z2);
glRotatef(a1,0,1,1);
}

glPushMatrix();
glTranslatef(0,2,0);
glColor3f(0,0,1);
glScaled(2.2 ,1.5,2.2);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();

glPopMatrix();
// Satelitte container
glPushMatrix();
if(x>=6.8&&flag1==2){

glTranslatef(2,0,0);
glRotatef(x*40,0,1,0);

}
if(flag1==2){satellite();
glPopMatrix();
}
glPushMatrix();
//throw at the screen
if(x>=5&&flag1==2){
glTranslatef(0,y2,y2);
glRotatef(a1,0,1,1);

}
//rocket middle part

glPushMatrix();
glColor3f(1,1,1);
glTranslatef(0,0.0,0);
glScaled(0.3,4.3,0.3);
glRotatef(90,1,0,0);
glutSolidTorus(0.5,1,30,30);
glPopMatrix();

glPushMatrix();
glTranslatef(0,-2.2,0);
glColor3f(0,0,1);
glScaled(3,1.5,3);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();

glPopMatrix();

// RightSide rocket
glPushMatrix();
if(flag1==2){
glTranslatef(x1,-Y1,z1);
glRotatef(a1,0,1,1);
}

glPushMatrix();
glTranslatef(0.7,1,0);
glColor3f(0,0,1);
glScaled(1.5 ,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();

glPushMatrix();
glTranslatef(0.7,-0.2,0);
glColor3f(0,1,1);
glScaled(0.2,6.5,0.2);
glRotatef(90,1,0,0);
glutSolidTorus(0.2,1,30,30);
glPopMatrix();

glPushMatrix();
glTranslatef(0.7,-2.0,0);
glColor3f(0,0,1);
glScaled(1.5,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();
glPopMatrix();

// LeftSide rocket

glPushMatrix();
if(flag1==2){
glTranslatef(-x1,-Y1,-z1);
glRotatef(-a1,0,1,1);
}
glPushMatrix();
glTranslatef(-0.7,1,0);
glColor3f(0,0,1);
glScaled(1.5 ,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.7,-0.2,0);
glColor3f(0,1,1);
glScaled(0.2,6.5,0.2);
glRotatef(90,1,0,0);


glutSolidTorus(0.2,1,30,30);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.7,-2.0,0);
glColor3f(0,0,1);
glScaled(1.5,1,1.5);
glRotatef(270,1,0,0);
glutSolidCone(0.2,1,30,30);
glPopMatrix();

glPopMatrix();
}
void stars(){

for(float s1=5;s1<=100; s1+=0.4){
for(float s2=-6;s2<=6;s2+=0.5){

glPushMatrix();
glBegin(GL_POINTS);


glVertex3f(s2,s1,0);

glEnd();
glPopMatrix();

}

}

for(float s3=5.2;s3<=100; s3+=0.3){
for(float s4=-6.2;s4<=6;s4+=0.3){
glPushMatrix();
glBegin(GL_POINTS);
glVertex3f(s4,s3,0);
glEnd();

glPopMatrix();

}

}


}

// Draw rocket

void rocket(double ang)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
if(Cx==1){
float cameraX=cameraRadius*sin(cameraAngle);
float cameraZ=cameraRadius*cos(cameraAngle);
float cameraY=0.0f;
gluLookAt(cameraX,cameraY,cameraZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}
if(Cy==1){

float cameraX=0.0f;
float cameraY=cameraRadius*cos(cameraAngle);
float cameraZ=cameraRadius*sin(cameraAngle);
gluLookAt(cameraX,cameraY,cameraZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}

glTranslatef(0.0f,0.0f,-13.0f);

glPushMatrix();
if(flag==1&&flag1==2){

if(ang>=2){
glRotatef(ang*30,1,0,0);
glTranslatef(0,-2+ang,0);
}
else{
glRotatef(60,1,0,0);
glTranslatef(0,0,0);
}
}

glScaled(0.5,0.5,0.5);

rocket();
glPopMatrix();



//Earth

glPushMatrix();
glColor3f(0,0,1);
if(x>=6.5){
glTranslatef(0,-18,-95);
glRotatef(10*x,0,1,0);

}else{
glTranslatef(0,-10-x,-10-15*x);
}


glutSolidSphere(10,100,100);
glPopMatrix();

// Create Stars
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(0,-ang,0);
stars();
glPopMatrix();

glFlush();
glutSwapBuffers();
}

void p()
{
cameraAngle+=0.005;
if(flag==1){
x+=0.01;

if(x>=3&&flag1==2){
x1+=0.1;
Y1+=0.1;
z1+=0.01;
a1+=3;
}

if(x>5&&flag1==2){
y2-=0.1;

}

if(x>5.5&&flag1==2){
z2+=0.1;
}
}
rocket(x);

}


void doInit()
{

/* Background and foreground color */
glClearColor(0.0,0.0,0.0,0);
glViewport(0,0,640,480);

/* Select the projection matrix and reset it then
setup our view perspective */

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(50.0f,(GLfloat)540/(GLfloat)480,0.1f,200.0f);

/* Select the modelview matrix, which we alter with rotatef() */
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glClearDepth(2.0f);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
}
void display()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
/*if(Cx==1){
float cameraX=cameraRadius*sin(cameraAngle);
float cameraZ=cameraRadius*cos(cameraAngle);
float cameraY=0.0f;
gluLookAt(cameraX,cameraY,cameraZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}
if(Cy==1){
float cameraX=cameraRadius*cos(cameraAngle);
float cameraZ=0.0f;
float cameraY=cameraRadius*sin(cameraAngle);
gluLookAt(cameraX,cameraY,cameraZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}
if(Cz==1){
float cameraX=0.0f;
float cameraZ=cameraRadius*sin(cameraAngle);
float cameraY=cameraRadius*cos(cameraAngle);
gluLookAt(cameraX,cameraY,cameraZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}*/
glTranslatef(0.0f,0.0f,-13.0f);

stroke_output(-2.0, 1.7, "p/P-->Launch the` Rocket");

GLfloat mat_ambient[]={1.0f,1.0f,1.0f,1.0f};
GLfloat mat_diffuse[]={0.0f,1.5f,1.5f,1.0f};
GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

GLfloat lightIntensity[]={2.0f,0.5f,0.0f,0.5f};
GLfloat light_position[]={1.0f,0.0f,0.0f,0.0f};

glLightfv(GL_LIGHT0,GL_POSITION,light_position);
glLightfv(GL_LIGHT0,GL_AMBIENT,lightIntensity);

glEnable(GL_COLOR_MATERIAL);

glFlush();
glutSwapBuffers();

}

void menu(int id)
{
switch(id)
{

case 1:glutIdleFunc(p);
break;
case 5:exit(0);
break;

}

glFlush();
glutSwapBuffers();
glutPostRedisplay();
}

void mykey(unsigned char key,int x,int y)
{

if(key=='p')
{
glutIdleFunc(p);
}

if(key=='q'||key=='Q')
{
exit(0);
}
if(key=='s'||key=='S')
{
flag=1;
}
if(key=='l'||key=='L'){
    flag1=2;
}
if(key=='x')
{
    Cx=1;
    Cy=0;
}
if(key=='y')
{
    if(Cx==1)
    {
        cameraAngle=0.0f;
        cameraRadius=100.0f;
    }
    Cy=1;
    Cx=0;
}
if(key=='z')
{
    Cz=1;
    Cx=0;
    Cy=0;
}
}

int main(int argc, char *argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(1000,480);
glutInitWindowPosition(0,0);
glutCreateWindow("Rocket");
glutDisplayFunc(display);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glutKeyboardFunc(mykey);
glutCreateMenu(menu);
glutAddMenuEntry("Launch 'p'",1);
glutAddMenuEntry("Start 's'",2);
glutAddMenuEntry("Quit 'q'",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
doInit();
glutMainLoop();
return 0;
}


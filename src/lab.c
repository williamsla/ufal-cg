
#include <GL/glut.h>

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//#include <iostream>

//using namespace std;

#include <SOIL.h>

// Qtd máxima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 7

#define CUBE_TEXTURE 0

// vetor com os números das texturas
GLuint texture_id[MAX_NO_TEXTURES];

int flag=0;

GLfloat door_angle=0;

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f, ly=0.0f; 
// XZ position of the camera
float x=0.0f,z=5.0f;

float comprimento = 5.00;
float altura = 3.00;
float largura = 0.15;

void pegador(){
    glBegin(GL_LINES);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.7f, 0.5f);
    glEnd();
    
    glBegin(GL_LINES);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, 0.4f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.5f, 0.4f);
        glVertex2f(0.7f, 0.4f);
    glEnd();
    }

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    glLoadIdentity();
    glClearColor(0,0,0,1);
    
    gluLookAt(  x,0.0f+ly,z+2,      //Eyer
                x+lx,0.0f,z+lz+2,   //Center
                0.0f,1.0f,0.0f);    

    //door
    // glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, texture_id[0] );     
    glPushMatrix();       
        glTranslatef (-2.5, 0.0, 2.5);
        glRotatef((GLfloat) door_angle, 0.0, 0.3, 0.0);
        glTranslatef (0.5, 0.0, 0.0);
        glScalef (comprimento-4, altura, largura);
        glutSolidCube (1.0);        
    glPopMatrix();

    glDisable(GL_TEXTURE_GEN_S);
    // glDisable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, 0);  

    //right wall
    
    //glColor3ub(224,224,224);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, texture_id[1] ); 
        
    glPushMatrix();
        glTranslatef (2.5, 0.0, 0.0);
        glRotatef (90, 0.0, 1.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);

        glPushMatrix();
            glScalef (comprimento, altura, largura);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();
    
    //left wall    
    glPushMatrix();
        glTranslatef (-2.5, 0.0, 0.0);
        glRotatef (90, 0.0, 1.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (comprimento, altura, largura);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();

    //glColor3ub(160.0,160.0,160.0);
   
    //back wall
    glPushMatrix();
        glTranslatef (0.0, 0.0, -2.5);
        glPushMatrix();
            glScalef (comprimento, altura, largura);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();

    //front wall
    //glColor3ub(100,100,100);
    glPushMatrix();
        glTranslatef (0.5, 0.0, 2.5);
        glPushMatrix();
            //glColor3ub(255.0,255.0,0);
            glScalef (comprimento-1, altura, largura);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, 0);

    //glColor3ub(128.0,128.0,128.0);

    //roof
    glPushMatrix();
        glTranslatef (0.0, 1.5, 0.0);
        glRotatef (90, 1.0, 0.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (comprimento, comprimento, largura);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();
    
    //floor
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, texture_id[2] ); 
    glPushMatrix();
        glTranslatef (0.0, -1.5, 0.0);
        glRotatef (90, 1.0, 0.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (comprimento, comprimento, largura);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, 0); 

    //Cylinder

    //glBindTexture ( GL_TEXTURE_2D, texture_id[4] ); 
    glPushMatrix();
        glTranslatef (2.0, -1.5, -2.0);
        glRotatef (-90, 1.0, 0.0, 0.0);
        glPushMatrix();
            glColor3ub(0,255.0,0);
            GLUquadricObj *obj = gluNewQuadric();
            gluCylinder(obj,    
                        0.1f,  //Base
                        0.2f,   //Top
                        0.4f,   //Height
                        32,     //Slices
                        32);    //Stacks
        glPopMatrix();
    glPopMatrix();
    
    //desks
    //mesas do fundo
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, texture_id[3] ); 
    glPushMatrix();    
        glTranslatef(0.0, -0.50, -2.0);
        glRotatef(90,1.0,0.0,0.0);
        glTranslatef(0.0,0.0,0.0);
        glPushMatrix();
            //glColor3ub(0,255,0);
            glScalef(5.0, 1.0, 0.1);
            glutSolidCube (1.0);
        glPopMatrix();        
    glPopMatrix();

    //pe da mesa do fundo
    glPushMatrix();
        glTranslatef (0.75, -1.00, -2.0);
        glPushMatrix();
            glScalef (0.1, 1.0, 1);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef (-0.75, -1.00, -2.0);
        glPushMatrix();
            glColor3ub(0,255,0);
            glScalef (0.1, 1.0, 1);
            glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();
    
    glColor3ub(255,255,255);

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, 0); 

    //armario do lado direito
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, texture_id[5] ); 
    //glColor3ub(70,130,180);
        glPushMatrix();
            glTranslatef (2.2, -0.75, -0.0);//-
            glPushMatrix();
                glScalef (0.5, 1.5, 0.5);//+
                glutSolidCube (1.0);
                //glColor3ub(255,255,180);
                glTranslatef (-1.0, -0.5, -0.2);
                pegador();
        glPopMatrix();
    glPopMatrix();

    //armario do lado esquerdo
    //glColor3ub(70,130,180);
    glPushMatrix();
        glTranslatef (-2.2, -0.75, -0.0);
        glPushMatrix();
            glScalef (0.5, 1.5, 0.5);
            glutSolidCube (1.0);
            //glColor3ub(255,255,180);
            glTranslatef (1.0, -0.5, 0.2);
            glRotatef(180,0.0,1.0,0.0);
            glTranslatef (0.0, 0.0, 0.0);
            pegador();
        glPopMatrix();
    glPopMatrix();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glBindTexture ( GL_TEXTURE_2D, 0); 

    //quadro
    //glColor3ub(255,255,255);
    // glEnable(GL_TEXTURE_GEN_S);
    // glEnable(GL_TEXTURE_GEN_T);

    glBindTexture ( GL_TEXTURE_2D, texture_id[6] ); 
        glPushMatrix();
        glTranslatef (1.0, 0.0, 2.45);
        glPushMatrix();
        glScalef (2, 1.5, 0.2);
        glutSolidCube (1.0);
        glPopMatrix();
    glPopMatrix();

    // glDisable(GL_TEXTURE_GEN_S);
    // glDisable(GL_TEXTURE_GEN_T);
    // glBindTexture ( GL_TEXTURE_2D, 0); 
    
    glutSwapBuffers();
    glutPostRedisplay(); //Add here
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }
}

void MyKeyboardFunc(unsigned char Key, int x, int y)
{
  switch(Key)
  {
    case 'a' :  //Open Door
        flag =1;
        if(door_angle<80)   door_angle +=10;
        break;
    case 'A' :  //Close door
        if(door_angle>0)    door_angle -=10;
        break;
    case 'w':   //cam to up
        ly -=0.1f;
        break;
    case 's':   //cam to down
        ly += 0.1f;
        break;  
    case 27:
        exit(1);
        break;
    }
}

void init(void){

    GLfloat luzAmbiente[4]={0.5 ,0.5, 0.5 ,1.0}; 
    GLfloat luzDifusa[4]={0.7, 0.7, 0.7, 1.0};    // "cor" 
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
    GLfloat posicaoLuz[4]={0.0, -2.0, 0.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
    GLint especMaterial = 60;

    glShadeModel(GL_SMOOTH);                // Habilita o modelo de colorização de Gouraud

    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);      // Define os parâmetros da luz de número 0

    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente); 
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz);

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);  
    // Habilita a luz de número 0
    glEnable(GL_LIGHT1);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);// Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_LIGHTING);      //Habilita o uso de iluminação
    glEnable(GL_LIGHT0);        // Habilita a luz de número 0

    angle=45;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // Set background color to black and opaque
    glClearDepth(1.0f);                     // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);                // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);                 // Set the type of depth-test
    
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
 }

 void loadTextureFromFile(char *filename,int index)
{

     int width, height;
   unsigned char* image =
       SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

             //printf("%d %d\n", width, height);

   glGenTextures(1, &texture_id[index]);
   glBindTexture(GL_TEXTURE_2D, texture_id[index]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

   glBindTexture(GL_TEXTURE_2D, 0);
}

void textures(){
    // Habilitar o uso de texturas 
    /*glEnable ( GL_TEXTURE_2D );
    // Definir a forma de armazenamento dos pixels na textura (1= alinhamento por byte) 
    glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );*/


    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    loadTextureFromFile("./textura/porta3.jpg", 0);    
    loadTextureFromFile("./textura/parede.jpg", 1);
    loadTextureFromFile("./textura/piso.jpg", 2);
    loadTextureFromFile("./textura/bancada.jpg", 3);
    loadTextureFromFile("./textura/lixeira.jpg", 4);
    loadTextureFromFile("./textura/armario.jpg", 5);
    loadTextureFromFile("./textura/quadro.jpg", 6);
}



int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glEnable(GL_DEPTH_TEST);

  glutInitWindowSize (800, 600);
  glutInitWindowPosition (100, 50);
  glutCreateWindow ("Ab2");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(MyKeyboardFunc);
  glutSpecialFunc(processSpecialKeys);

  init ();
  textures();

  glutMainLoop();

//  cout << angle << " ";
  return 0;
}
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <GL/glu.h>
#include <iostream>


//custom functions

#include "iutil.h"
#include "squares.h"
#include "peices.h"

using namespace std;

float _angle = 40;
float i;
int k = 0;

double rotate_y = 0; 
double rotate_x = 0;

float rotate_speed = 0.9f;

GLuint _textureId;
GLuint textureId;

GLuint displayList_blackArea;
GLuint displayList_whiteArea;
GLuint displayList_pawn1;
GLuint displayList_pawn2;
GLuint displayList_king1;
GLuint displayList_king2;
GLuint displayList_queen1;
GLuint displayList_queen2;
GLuint displayList_bishop1;
GLuint displayList_bishop2;
GLuint displayList_knight1;
GLuint displayList_knight2;
GLuint displayList_rook1;
GLuint displayList_rook2;
 
void handleKeypress(unsigned char key,int x,int y) {
    if (key == 'd')
        _angle -= 5;
    else if (key == 'a')
        _angle += 5;
    else if (key == 27)
        exit(0);
    glutPostRedisplay();
}
 
void handleResize(int w,int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200);
    gluLookAt(0.0f,5.5f, 15.0f,
              0.0f,0.0f,0.0f,
              0.0f,1.0f,0.0f);
}

GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId); //Make room for our texture
    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
    //Map the image to the texture

    glTexImage2D(GL_TEXTURE_2D,
                2,
                GL_RGB,
                image -> width,
                image->height,
                3,
                GL_RGB,
                GL_UNSIGNED_BYTE,
                image->pixels);

    return textureId; //Returns the id of the texture
}

void glTexture_draw(GLuint tex){ 
    glEnable(GL_TEXTURE_2D); 
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    float colour[4] = {0.0f, 0.0f, 1.0f, 1.0f};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, colour);
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    
    Image* image = loadBMP("src/textures/wht.bmp");
    _textureId = loadTexture(image);
    delete image;

    image = loadBMP("src/textures/1.bmp");
    textureId = loadTexture(image);
    delete image;


    glClearColor(0.01f,0.01f,0.01f,0.3f); 

    displayList_blackArea = glGenLists(1); 
    glNewList(displayList_blackArea, GL_COMPILE); 
    draw_BlackArea();
    glEndList();
     
    displayList_whiteArea = glGenLists(1); 
    glNewList(displayList_whiteArea, GL_COMPILE); 
    draw_WhiteArea();
    glEndList();

    displayList_pawn1 = glGenLists(1);
    glNewList(displayList_pawn1, GL_COMPILE);
    draw_Pawn(0.8, 0.9, 0.88);
    glEndList();

    displayList_pawn2 = glGenLists(1);
    glNewList(displayList_pawn2, GL_COMPILE);
    draw_Pawn(0.4, 0.5, 0.4);
    glEndList();

    displayList_king1 = glGenLists(1);
    glNewList(displayList_king1, GL_COMPILE);
    draw_King(0.8, 0.9, 0.88);
    glEndList();

    displayList_king2 = glGenLists(1);
    glNewList(displayList_king2, GL_COMPILE);
    draw_King(0.4, 0.5, 0.4);
    glEndList();

    displayList_queen1 = glGenLists(1);
    glNewList(displayList_queen1, GL_COMPILE);
    draw_Queen(0.8, 0.9, 0.88);
    glEndList();

    displayList_queen2 = glGenLists(1);
    glNewList(displayList_queen2, GL_COMPILE);
    draw_Queen(0.4, 0.5, 0.4);
    glEndList();

    displayList_bishop1 = glGenLists(1);
    glNewList(displayList_bishop1, GL_COMPILE);
    draw_Bishop(0.8, 0.9, 0.88);
    glEndList();

    displayList_bishop2 = glGenLists(1);
    glNewList(displayList_bishop2, GL_COMPILE);
    draw_Bishop(0.4, 0.5, 0.4);
    glEndList();

    displayList_knight1 = glGenLists(1);
    glNewList(displayList_knight1, GL_COMPILE);
    draw_Knight(0.8, 0.9, 0.88, 0);
    glEndList();

    displayList_knight2 = glGenLists(1);
    glNewList(displayList_knight2, GL_COMPILE);
    draw_Knight(0.4, 0.5, 0.4, 1);
    glEndList();

    displayList_rook1 = glGenLists(1);
    glNewList(displayList_rook1, GL_COMPILE);
    draw_Rook(0.8, 0.9, 0.88);
    glEndList();

    displayList_rook2 = glGenLists(1);
    glNewList(displayList_rook2, GL_COMPILE);
    draw_Rook(0.4, 0.5, 0.4);
    glEndList();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(1.0f);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
    glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-4*1.5, 0.0, 4*1.5);

    //black squares and pawn
    for(float j=0.0;j>(-8*1.5);j-=1.5) {
        k++;
        for(i=0.0;i<(4*3);i+=3) {

            if (i==9){
                glTexture_draw(textureId);
                glPushMatrix();
                glTranslatef(i,0.0,j);
                glCallList(displayList_pawn2);
                glPopMatrix();
                glDisable(GL_TEXTURE_2D);
            }
            
            if(k%2==0) {
                glPushMatrix();
                glTranslatef(i,0.0,j);
                glCallList(displayList_blackArea);
                glPopMatrix();
            }
            else {
                glPushMatrix();
                glTranslatef(i+1.5,0.0,j);
                glCallList(displayList_blackArea);
                glPopMatrix(); 
            }
        }
    }

    // king
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0,0.0,-4.5);
    glCallList(displayList_king1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0,-6.0);
    glCallList(displayList_king2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //queen
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0,0.0,-6);
    glCallList(displayList_queen1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0,-4.5);
    glCallList(displayList_queen2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    // bishop
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -7.5);
    glCallList(displayList_bishop1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //--
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -3);
    glCallList(displayList_bishop1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0,-3);
    glCallList(displayList_bishop2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //--

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0,-7.5);
    glCallList(displayList_bishop2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // knight
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -9);
    glCallList(displayList_knight1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //--
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -1.5);
    glCallList(displayList_knight1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0,-1.5);
    glCallList(displayList_knight2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //--

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0, -10.5);
    glCallList(displayList_knight2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    // rook
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -10.5);
    glCallList(displayList_rook1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //--
    glTexture_draw(_textureId);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0);
    glCallList(displayList_rook1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0,-0);
    glCallList(displayList_rook2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //--

    glTexture_draw(textureId);
    glPushMatrix();
    glTranslatef(1.5*7,0.0, -9);
    glCallList(displayList_rook2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    //white squares and pawns
    for(float j=0.0;j>(-8*1.5);j-=1.5) {
        k++;
        for(i=0.0;i<(4*3.0);i+=3.0) {
             if (i==0) {
                glTexture_draw(_textureId);
                glPushMatrix();
                glTranslatef(i+1.5,0.0,j);
                glCallList(displayList_pawn1);
                glPopMatrix();
                glDisable(GL_TEXTURE_2D); 
            }

            if(k%2!=0) {
                glPushMatrix();
                glTranslatef(i,0.0,j);
                glCallList(displayList_whiteArea);
                glPopMatrix();
            }
            else {
                glPushMatrix();
                glTranslatef(i+1.5,0.0,j);
                glCallList(displayList_whiteArea);
                glPopMatrix();    
            }
        }
    }

    glRotatef(rotate_x, 1.0, 0.0, 0.0 );
    glRotatef(rotate_y, 0.0, 1.0, 0.0 );
    glFlush();
    glutSwapBuffers();
}

void update(int value) {
    _angle += rotate_speed;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(5, update, 0);
}

int main(int argc,char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,800);
     
    glutCreateWindow("Chessboard");
    initRendering();
    glutFullScreen();
     
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);


    glutTimerFunc(0, update, 0);
     
    glutMainLoop();
     
    return 0;
}
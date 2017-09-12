#ifndef PAWN_h
#define PAWN_h

#include <cmath>


GLfloat x=0.8f, y=0.2f, z=-0.6f;

GLfloat Pawn_upper_sphere = 4.0f;
GLfloat Pawn_upper_spherex = 0.0f;
GLfloat Pawn_upper_ring = 3.30f;



struct point {
    float x;
    float y;
    float z;
};

point spherical(float alpha, float beta, float r) {
    point p;
    p.x = r*cos(alpha)*cos(beta);
    p.y = r*sin(alpha)*cos(beta);
    p.z = r*sin(beta);
    return p;
}



void drawSmoothUnityEllipsoidPatch(float a1, float a2, float b1, float b2) {
    int na = 32;
    int nb = 16;
    
    float alpha;
    float dalpha = (a2-a1)/na;
    float beta;
    float dbeta = (b2-b1)/nb;
    
    beta = b2;
    for(int j=0; j<nb; j++, beta-=dbeta) {
        alpha = a1;
        for(int i=0; i<na; i++, alpha+=dalpha) {
            point p;
            glBegin( GL_POLYGON );
            
            p = spherical(alpha,beta,1);
            glNormal3f(p.x,p.y,p.z);
            glVertex3f(p.x,p.y,p.z);
            
            p = spherical(alpha+dalpha,beta,1);
            glNormal3f(p.x,p.y,p.z);
            glVertex3f(p.x,p.y,p.z);
            
            p = spherical(alpha+dalpha,beta-dbeta,1);
            glNormal3f(p.x,p.y,p.z);
            glVertex3f(p.x,p.y,p.z);
            
            p = spherical(alpha,beta-dbeta,1);
            glNormal3f(p.x,p.y,p.z);
            glVertex3f(p.x,p.y,p.z);
            
            glEnd();
        }
    }
}

void draw_bottom(){
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.5, 1.5, 0.8);
    drawSmoothUnityEllipsoidPatch(0, 2*M_PI, 0, M_PI/2 );
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.4, 1.4, 1.0);
    drawSmoothUnityEllipsoidPatch(0, 2*M_PI, 0, M_PI/2 );
    glPopMatrix();
}

void draw_Pawn(float r , float g, float b) {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(r, g, b);

    glTranslatef(x, y, z);
    glScalef(0.29, 0.3, 0.29);
    
    // upper sphere
    glPushMatrix();
    glTranslatef(0, 4.0f, -0.0f);
    glutSolidSphere(0.7f, 50, 50);
    glPopMatrix();
    
    // upper ellipse ring
    glPushMatrix();
    glTranslatef(0, 3.3f, -0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.8f, 0.2f, 40, 40);
    glPopMatrix();
    glPopMatrix();
    
    //  cone
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glutSolidCone(1.0f, 3.4f, 50, 50);
    glPopMatrix();
    
    // bottom circle
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(1.0f, 0.3f, 50, 50);
    glPopMatrix();
     
    // bottom Ellipsoid
    draw_bottom();
    glPopMatrix();   
}

void draw_King(float r, float g, float b) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(r, g, b);
    

    glTranslatef(x, y, z);
    glScalef(0.29, 0.3, 0.29);
    
    // upper sphere
    glPushMatrix();
    glTranslatef(0.0f, 6.0f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.4);
    glutSolidTorus(0.5f, 0.2f, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 5.9f, 0.0f);
    glutSolidSphere(0.34f, 50, 50);
    glTranslatef(0.0f, 0.55f, 0.0f);
    glPushMatrix();
    glScalef(1.0f, 0.2f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
    glScalef(0.3f, 1.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    
    //glColor3f(400, 0, 00);
    
    // upper ellipse ring
    glPushMatrix();
    glTranslatef(0.0f, 4.10f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.3);
    glutSolidTorus(0.6f, 0.2f, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 4.30f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.4f, 0.2f, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 4.4f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.4f, 0.2f, 40, 40);
    glPopMatrix();
    
    //  cone
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glutSolidCone(1.05f, 5.1f, 50, 50);
    glRotated(-180, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glutSolidCone(0.7f, 5.6f, 50, 50);
    glPopMatrix();
    
    // bottom circle
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(1.0f, 0.3f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.8f, 0.3f, 50, 50);
    glPopMatrix();
    
    // bottom Ellipsoid
    draw_bottom();
    
    glPopMatrix();
}


void draw_Queen(float r, float g, float b) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(r, g, b);
    

    glTranslatef(x, y, z);
    glScalef(0.29, 0.3, 0.29);

    glPushMatrix();
    glTranslatef(0.0f, 5.9f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(0.4, 0.4, 0.4);
    glutSolidSphere(1, 50, 50);
    //   glutSolidTorus(0.5f, 0.2f, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 6.0f, 0.0f);
    glRotated(-90, 0.0f, 1.0f, 0.0f);
    glScalef(0.45, 0.1, 0.45);
    //    glutSolidTetrahedron();
    glutSolidDodecahedron();
    
    //   glutSolidIcosahedron();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 6.0f, 0.0f);
    glScalef(0.45, 0.1, 0.45);
    glutSolidDodecahedron();
    glPopMatrix();
    
    // upper ellipse ring
    glPushMatrix();
    glTranslatef(0.0f, 4.10f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.34);
    glutSolidTorus(0.6f, 0.2f, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 4.30f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.4f, 0.2f, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 4.4f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.4f, 0.2f, 40, 40);
    glPopMatrix();
    
    //  cone
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glutSolidCone(1.05f, 5.1f, 50, 50);
    glRotated(-180, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glutSolidCone(0.7f, 5.6f, 50, 50);
    glPopMatrix();
    
    // bottom circle
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(1.0f, 0.3f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.8f, 0.3f, 50, 50);
    glPopMatrix();
    
    
    // bottom Ellipsoid
    draw_bottom();
    
    
    glPopMatrix();
}

void draw_Bishop(float r, float g, float b) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(x, y, z);
    
    glScalef(0.29, 0.3, 0.29);
    
    // upper sphere
    glPushMatrix();
    glTranslatef(0.0f, 5.5f, 0.0f);
    glutSolidSphere(.2f, 40, 40);
    glPopMatrix();
    
    
    //glColor3f(400, 0, 00);
    
    // upper ellipse ring
    glPushMatrix();
    glTranslatef(0.0f, 3.10f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.25);
    glutSolidTorus(0.6f, 0.2f, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 3.1f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.24);
    // glutSolidTorus(0.5f, 0.2f, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 3.3f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.4f, 0.2f, 40, 40);
    glPopMatrix();
    
    //  cone
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.85f, 4.5f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    //    glRotated(-180, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 4.4f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(0.48,0.48 , 1.0);
    glutSolidSphere(1, 40, 40);
    //glutSolidCone(0.7f, 5.6f, 50, 50);
    glPopMatrix();
    // middle ring
    glPushMatrix();
    glTranslatef(0.0f, 3.71f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.25);
    glutSolidTorus(0.45f, 0.2f, 40, 40);
    glPopMatrix();
    
    
    // bottom circle
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.85f, 0.3f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.7f, 0.3f, 50, 50);
    glPopMatrix();
    
    
    // bottom Ellipsoid
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.4, 1.4, 0.8);
    drawSmoothUnityEllipsoidPatch(0, 2*M_PI, 0, M_PI /2 );
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.3, 1.3, 0.9);
    drawSmoothUnityEllipsoidPatch(0, 2*M_PI, 0, M_PI /2 );
    glPopMatrix();
    
    
    
    glPopMatrix();
}

void draw_Knight(float r, float g, float b, int rotate) {
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glColor3f(r, g, b);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    if(rotate==1)
        glRotatef(180, 0.0f, 1.0f, 0.0f);
    glScalef(0.29, 0.29, 0.29);
    
    
    glPushMatrix();
    glTranslatef(0.0f, 4.0f, 0.0f);
    // uff1
    GLfloat tm12=0.8f;
    glTranslatef(0, -0.05f, 0);
    glTranslatef(-0.2f, 0.0f, 0.0f);
    
    glPushMatrix();
    glScalef(0.8, 0.9, 0.8);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-0.8f, -2.5f, -tm12);
    glVertex3f(0.8f, -2.5f, -tm12);
    glVertex3f(0.4f, -1.2f, -tm12);
    glVertex3f(-0.4f, -0.5f, -tm12);
    glEnd();
    
    // back face /
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.2f, 0.0f);
    glVertex3f(-0.8f, -2.5f, -tm12);
    glVertex3f(-0.8f, -2.5f, tm12);
    glVertex3f(-0.4f, -0.5f, tm12);
    glVertex3f(-0.4f, -0.5f, -tm12);
    glEnd();
    
    // front face
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.2f, 0.0f);
    glVertex3f(0.8f, -2.5f, -tm12);
    glVertex3f(0.8f, -2.5f, tm12);
    glVertex3f(0.2f, -0.5f, tm12);
    glVertex3f(0.2f, -0.5f, -tm12);
    glEnd();
    
    
    tm12=-0.8f;
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.8f, -2.5f, -tm12);
    glVertex3f(0.8f, -2.5f, -tm12);
    glVertex3f(0.4f, -1.2f, -tm12);
    glVertex3f(-0.4f, -0.5f, -tm12);
    glEnd();
    
    
    tm12=.8f;
    
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(-0.4f, -0.5f, -tm12);
    glVertex3f(1.0f, 1.4f, -tm12);
    glVertex3f(1.0f, 1.4f, tm12);
    glVertex3f(-0.4f, -0.5f, tm12);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(1.0f, -0.4f, 0.0f);
    glVertex3f(0.4f, -1.2f, -tm12);
    glVertex3f(1.0f, 1.4f, -tm12);
    glVertex3f(1.0f, 1.4f, tm12);
    glVertex3f(0.4f, -1.2f, tm12);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 1.4f, -tm12);
    glVertex3f(0.4f, -1.2f, -tm12);
    glVertex3f(-0.4f, -0.5f, -tm12);
    glVertex3f(1.0f, 1.4f, -tm12);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.4f, tm12);
    glVertex3f(0.4f, -1.2f, tm12);
    glVertex3f(-0.4f, -0.5f, tm12);
    glVertex3f(1.0f, 1.4f, tm12);
    glEnd();
    // kte1
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.4f, tm12);
    glVertex3f(0.4f, -1.2f, tm12);
    glVertex3f(-0.4f, -0.5f, tm12);
    glVertex3f(1.0f, 1.4f, tm12);
    glEnd();
    
    
    // muh
    glPushMatrix();
    //top m
    glBegin(GL_QUADS);
    glNormal3f(0.3f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.4f, tm12);
    glVertex3f(1.0f, 1.4f, -tm12);
    glVertex3f(2.6f, 0.8f, -tm12+0.5f);
    glVertex3f(2.6f, 0.8f, tm12-0.5f);
    glEnd();
    //bot m
    glBegin(GL_QUADS);
    glNormal3f(-0.2f, -1.0f, 0.0f);
    glVertex3f(0.5f, -0.2f, tm12);
    glVertex3f(0.5f, -0.2f, -tm12);
    glVertex3f(2.6f, 0.4f, -tm12+0.5f);
    glVertex3f(2.6f, 0.4f, tm12-0.5f);
    glEnd();
    
    // left m
    glBegin(GL_QUADS);
    glNormal3f(0.2f, 0.0f, -1.0f);
    glVertex3f(0.5f, -0.2f, -tm12);
    glVertex3f(1.0f, 1.4f, -tm12);
    glVertex3f(2.6f, 0.8f, -tm12+0.5f);
    glVertex3f(2.6f, 0.4f, -tm12+0.5f);
    glEnd();
    // right m
    glBegin(GL_QUADS);
    glNormal3f(0.2f, 0.0f, 1.0f);
    glVertex3f(0.5f, -0.2f, tm12);
    glVertex3f(1.0f, 1.4f, tm12);
    glVertex3f(2.6f, 0.8f, tm12-0.5f);
    glVertex3f(2.6f, 0.4f, tm12-0.5f);
    glEnd();
    // front dakhan
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.6f, 0.4f, -tm12+0.5f);
    glVertex3f(2.6f, 0.8f, -tm12+0.5f);
    glVertex3f(2.6f, 0.4f, tm12-0.5f);
    glVertex3f(2.6f, 0.8f, tm12-0.5f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    
    
    
    // bottom Ellipsoid
    // bottom circle
    glPushMatrix();
    glTranslatef(0.0f, 1.6f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(0.86, 0.86, 0.25);
    glutSolidTorus(1.0f, 0.3f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.8f, 0.3f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(1.0f, 0.3f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.2);
    glutSolidTorus(0.8f, 0.3f, 50, 50);
    glPopMatrix();
    
    draw_bottom();
    glPopMatrix();

}


void draw_Rook(float r, float g, float b) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(x, y, z);
    
    glScalef(0.29, 0.30, 0.29);
    GLUquadricObj *quadratic;
    // topmost cylendar
    glPushMatrix();
    glTranslatef(0.0, 4.0, 0.0);
    quadratic = gluNewQuadric();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(quadratic,1.0f,1.0f,1.0f,32,32);
    //glRotated(-90, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.1);
    glutSolidTorus(0.9f, 0.1f, 50, 50);
    glPopMatrix();
    // top covering
    glPushMatrix();
    glTranslatef(0.0, 5.0, 0.0);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 0.1);
    glutSolidTorus(0.9f, 0.1f, 50, 50);
    glPopMatrix();
    
    
    // middle cylindar
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    quadratic = gluNewQuadric();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(quadratic,1.1f,0.6f,3.4f,32,32);
    glPopMatrix();
    
    // inverted cylindar
    glPushMatrix();
    glTranslatef(0.0, 4.5, 0.0);
    quadratic = gluNewQuadric();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(quadratic,0.85f,0.55f,3.4f,32,32);
    glPopMatrix();
    
    // middle covering
    glPushMatrix();
    glTranslatef(0.0, 3.4, 0.0);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.0, 1.0, 3.5);
    glutSolidTorus(0.455f, 0.3f, 50, 50);
    glPopMatrix();
    
    
    // bottom Ellipsoid
    draw_bottom();
    glPopMatrix();
}


#endif

#ifndef SQUARES_h
#define SQUARES_h

void draw_BlackArea() {
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glTranslatef(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.3f,0.0f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(1.5f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(1.5f,0.3f,0.0f);
    glEnd();
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(1.50f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(0.0f,0.3f,0.0f);
    glVertex3f(1.50f,0.3f,0.0f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();
}

void draw_WhiteArea() {

    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glTranslatef(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.3f,0.0f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(1.5f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(1.5f,0.3f,0.0f);
    glEnd();
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(1.50f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();
     
     
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glEnd();
    
     
    glBegin(GL_QUADS);
    glColor3f(1.6f,1.0f,0.7f);
    glVertex3f(0.0f,0.3f,0.0f);
    glVertex3f(1.50f,0.3f,0.0f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();
}

#endif
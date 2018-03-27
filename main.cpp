#include<stdlib.h>
#include<gl/glut.h>

    GLsizei wh=500,ww=500;
    GLfloat size=30.0;
    int quadradoCount = 0;

    void desenha()
    {
        glFlush();
    }

    void Inicializa()
    {
        glViewport(0,0,ww,wh);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
        glMatrixMode(GL_MODELVIEW);
        glClearColor(0.0,0.0,0.0,1.0);
     }

    void desenhaQuadrado(int x,int y)
    {
        y=wh-y;
        glBegin(GL_POLYGON);
        glVertex2f(x+size,y+size);
        glVertex2f(x-size,y+size);
        glVertex2f(x-size,y-size);
        glVertex2f(x+size,y-size);
        glEnd();
        glFlush();
    }
     void desenhaTriangulo (int x,int y)
    {
        y=wh-y;
        glBegin(GL_POLYGON);
        glVertex2f(x+size,y+size);
        glVertex2f(x-size,y+size);
        glVertex2f(x-size,y-size);
        glEnd();
        glFlush();
    }


    void CorAleatoria (){
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);


        glColor3f(r, g, b);

    }


    void quadradoPontoCentral(int x,int y){
        glClear(GL_COLOR_BUFFER_BIT);
         //   desenhaTriangulo(x,y);
         y=wh-y;
        glBegin(GL_LINE_LOOP);
        glVertex2f(250,250);
        glVertex2f(250,y);
        glVertex2f(x,y);
        glVertex2f(x,250);
        glEnd();
        glFlush();

    }

    void eventoMouse(int button,int state,int x,int y)
    {

        CorAleatoria();
        if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
            desenhaQuadrado(x,y);

        }
        else if (button==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN){
            quadradoPontoCentral(x, y);
        }
    }
    void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'R':
            case 'r':
                     glColor3f(1.0f, 0.0f, 0.0f);
                     break;
             }
              switch (key) {
            case 'A':
            case 'a':
                     glColor3f(0.0f, 1.0f, 0.0f);
                     break;
             }
              switch (key) {
            case 'W':
            case 'w':
                     glColor3f(0.0f, 0.0f, 1.0f);
                     break;
             }
 }


    void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_DOWN) {
            y=wh-y;
            glScalef(x,y, 0);
    }

}

    int main(int argc,char **argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(wh,ww);
        glutCreateWindow("Hierarchical Menus to Draw Squares");
        glutDisplayFunc(desenha);
        Inicializa();
        glutMouseFunc(eventoMouse);
        glutKeyboardFunc(GerenciaTeclado);
        glutSpecialFunc(TeclasEspeciais);
        glutMainLoop();
        return 0;
    }


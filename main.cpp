#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include "CarregarArquivo.cpp"

#define G 9.8
#define randomico() ((float) rand()/ RAND_MAX) //Numero aleatório entre 0 e1


CarregarArquivo corpo_tanque;
CarregarArquivo rodaTras_tanque;
CarregarArquivo rodadireita_tanque;
CarregarArquivo rodaesquerda_tanque;
CarregarArquivo basecanhao_tanque;
CarregarArquivo canhao_tanque;
GLint especMaterial;

//*****************************NOVO CODIGO *****************************************

typedef struct
{
    bool vis;
    float x;
    float y;
    float z;
    float x0;
    float y0;
    float z0;
    float forcax;
    float forcay;
    float forcaz;
    float xMax;
    float yMax;
    float zMax;
    float tempo;
    float vel;
    float norma;

} Bola;

Bola tiro;

int rodarHori = 0;
int rodarVert = 0;

float ventox;
float ventoz;

float forca = 1.0;

int n = 1;
int cont = 0;

double d_x, d_z;

int alvovis = 1;

//*****************************NOVO CODIGO *****************************************

using namespace std;
void EspecificaParametrosVisualizacao(void);
void PosicionaObservador(void);

GLubyte lado[2048][2048][3];

char repete = 0;

float movX = 0, movZ = 0;
int rodar = 0;

// Desativa interpolação linear da textura
GLint filtro = GL_NEAREST;

// Define valor final da coordenada de textura
float final = 1.0;

// Armazena identificação da textura
GLuint textura_id, textura_id2, textura_id3;


GLfloat angle, fAspect, rotX, rotY, transy, transz, giraRoda, rotacao, moverCameraz;
GLfloat transx = 180;
GLdouble obsX, obsY, obsZ;

GLfloat offset[3] = {50, 60, 0};
GLfloat objectPosition[3] = {movX, 0, movZ};
GLfloat cameraPosition[3];



void DefineIluminacao (void)
{
    GLfloat luzAmbiente[4]= {0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]= {0.7,0.7,0.7,1.0}; // "cor"
    GLfloat luzEspecular[4]= {1.0, 1.0, 1.0, 1.0}; // "brilho"
    GLfloat posicaoLuz[4]= {0.0, 50.0, 50.0, 1.0};
// Capacidade de brilho do material
    GLfloat especularidade[4]= {1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;
// Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
// Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
// Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
// Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}

void CarregaCorpo()
{
    glPushMatrix();
    //glScaled(2, 2, 2);
    glRotated(rotacao, 0, 1, 0);

<<<<<<< HEAD
=======

    //glTranslatef((-9.6) * movX, 0, (-9.6) * movZ);
    // glTranslatef(-movX, 0, -movZ);
    //glRotated(angloDrone, 0, 1, 0);
>>>>>>> 9cd2889f3c2b40a722d47686e6e43c4b3b1cb3d3
    glDisable(GL_TEXTURE_2D);
    for ( int j = 0; j < (corpo_tanque.faces).size(); ++j )
    {

        glBegin ( GL_POLYGON );

        for (int i = 0; i < (corpo_tanque.faces[j]).size() ; ++i )
        {


            GLfloat normal[3] = {(corpo_tanque.normais[corpo_tanque.faces[j][i][2]][0]),(corpo_tanque.normais[corpo_tanque.faces[j][i][2]][1]),(corpo_tanque.normais[corpo_tanque.faces[j][i][2]][2])};
            glNormal3fv(normal);
            //GLfloat textura[2] = {(corpo_tanque.texturas[corpo_tanque.faces[j][i][1]][0]),(corpo_tanque.texturas[corpo_tanque.faces[j][i][1]][1])};
            //glTexCoord2fv(textura);
            GLfloat vert[3] = {(corpo_tanque.vertices1[corpo_tanque.faces[j][i][0]][0]),(corpo_tanque.vertices1[corpo_tanque.faces[j][i][0]][1]),(corpo_tanque.vertices1[corpo_tanque.faces[j][i][0]][2])};
            glVertex3fv (vert);


        }

        glEnd( );
    }
    glColor3f(0.5f, 0.5f, 0.5f);

    for ( int j = 0; j < (rodaTras_tanque.faces).size(); ++j )
    {

        glBegin ( GL_POLYGON );

        for (int i = 0; i < (rodaTras_tanque.faces[j]).size() ; ++i )
        {

            GLfloat normal[3] = {(rodaTras_tanque.normais[rodaTras_tanque.faces[j][i][2]][0]),(rodaTras_tanque.normais[rodaTras_tanque.faces[j][i][2]][1]),(rodaTras_tanque.normais[rodaTras_tanque.faces[j][i][2]][2])};
            glNormal3fv(normal);
            GLfloat vert[3] = {(rodaTras_tanque.vertices1[rodaTras_tanque.faces[j][i][0]][0]),(rodaTras_tanque.vertices1[rodaTras_tanque.faces[j][i][0]][1]),(rodaTras_tanque.vertices1[rodaTras_tanque.faces[j][i][0]][2])};
            glVertex3fv (vert);

        }

        glEnd( );
    }
    glPopMatrix();


    glutPostRedisplay();

}

void CarregaRodaDireita()
{
    glPushMatrix();
    //glScaled(2, 2, 2);
    //glRotated(180, 0, 1, 0);
    glRotated(rotacao, 0, 1, 0);
    glTranslated(-1.48226,0.86792,+3.1956);
    //glTranslated(0, 0, transz);
    glRotated(giraRoda, 0, 1, 0);




    //glTranslatef((-9.6) * movX, 0, (-9.6) * movZ);
    // glTranslatef(-movX, 0, -movZ);
    //glRotated(angloDrone, 0, 1, 0);

    glColor3f(0.5f, 0.5f, 0.5f);

    for ( int j = 0; j < (rodadireita_tanque.faces).size(); ++j )
    {

        glBegin ( GL_POLYGON );

        for (int i = 0; i < (rodadireita_tanque.faces[j]).size() ; ++i )
        {

            GLfloat normal[3] = {(rodadireita_tanque.normais[rodadireita_tanque.faces[j][i][2]][0]),(rodadireita_tanque.normais[rodadireita_tanque.faces[j][i][2]][1]),(rodadireita_tanque.normais[rodadireita_tanque.faces[j][i][2]][2])};
            glNormal3fv(normal);
            GLfloat vert[3] = {(rodadireita_tanque.vertices1[rodadireita_tanque.faces[j][i][0]][0]),(rodadireita_tanque.vertices1[rodadireita_tanque.faces[j][i][0]][1]),(rodadireita_tanque.vertices1[rodadireita_tanque.faces[j][i][0]][2])};
            glVertex3fv (vert);

        }

        glEnd( );
    }

    glPopMatrix();


    glutPostRedisplay();
}

void CarregaRodaEsquerda()
{
    glPushMatrix();
   // glScaled(2, 2, 2);
    //glRotated(180, 0, 1, 0);
    glRotated(rotacao, 0, 1, 0);
    glTranslated(+1.50872,0.74939,+3.16875);
    //glRotated(rotacao, 0, 1, 0);
    //glTranslated(0, 0, transz);
    glRotated(giraRoda, 0, 1, 0);




    //glTranslatef((-9.6) * movX, 0, (-9.6) * movZ);
    // glTranslatef(-movX, 0, -movZ);
    //glRotated(angloDrone, 0, 1, 0);

    glDisable(GL_TEXTURE_2D);
    for ( int j = 0; j < (rodaesquerda_tanque.faces).size(); ++j )
    {

        glBegin ( GL_POLYGON );

        for (int i = 0; i < (rodaesquerda_tanque.faces[j]).size() ; ++i )
        {

            GLfloat normal[3] = {(rodaesquerda_tanque.normais[rodaesquerda_tanque.faces[j][i][2]][0]),(rodaesquerda_tanque.normais[rodaesquerda_tanque.faces[j][i][2]][1]),(rodaesquerda_tanque.normais[rodaesquerda_tanque.faces[j][i][2]][2])};
            glNormal3fv(normal);
            GLfloat vert[3] = {(rodaesquerda_tanque.vertices1[rodaesquerda_tanque.faces[j][i][0]][0]),(rodaesquerda_tanque.vertices1[rodaesquerda_tanque.faces[j][i][0]][1]),(rodaesquerda_tanque.vertices1[rodaesquerda_tanque.faces[j][i][0]][2])};
            glVertex3fv (vert);

        }

        glEnd( );
    }
    glPopMatrix();


    glutPostRedisplay();

}

void CarregaCanhao()
{
    glPushMatrix();
    //glScaled(2, 2, 2);
    glRotated(rotacao, 0, 1, 0);
    glTranslated(-1.13283,3.5033,-0.83108);
    glRotated(rodarHori, 0.0, 1.0, 0.0);
    glRotated(-rodarVert, 1.0, 0.0, 0.0);



    glDisable(GL_TEXTURE_2D);

    glColor3f(0.5f, 0.5f, 0.5f);

    for ( int j = 0; j < (canhao_tanque.faces).size(); ++j )
    {

        glBegin ( GL_POLYGON );

        for (int i = 0; i < (canhao_tanque.faces[j]).size() ; ++i )
        {

            GLfloat normal[3] = {(canhao_tanque.normais[canhao_tanque.faces[j][i][2]][0]),(canhao_tanque.normais[canhao_tanque.faces[j][i][2]][1]),(canhao_tanque.normais[canhao_tanque.faces[j][i][2]][2])};
            glNormal3fv(normal);
            GLfloat vert[3] = {(canhao_tanque.vertices1[canhao_tanque.faces[j][i][0]][0]),(canhao_tanque.vertices1[canhao_tanque.faces[j][i][0]][1]),(canhao_tanque.vertices1[canhao_tanque.faces[j][i][0]][2])};
            glVertex3fv (vert);

        }

        glEnd( );
    }
    glPopMatrix();


    glutPostRedisplay();

}

void CarregaBaseCanhao()
{
    glPushMatrix();
    //glScaled(2, 2, 2);

    glRotated(rotacao, 0, 1, 0);
    glTranslated(-1.13283,3.5033,-0.83108);
    glRotated(rodarHori, 0.0, 1.0, 0.0);


    glDisable(GL_TEXTURE_2D);

    glColor3f(0.5f, 0.5f, 0.5f);

    for ( int j = 0; j < (basecanhao_tanque.faces).size(); ++j )
    {

        glBegin ( GL_POLYGON );

        for (int i = 0; i < (basecanhao_tanque.faces[j]).size() ; ++i )
        {

            GLfloat normal[3] = {(basecanhao_tanque.normais[basecanhao_tanque.faces[j][i][2]][0]),(basecanhao_tanque.normais[basecanhao_tanque.faces[j][i][2]][1]),(basecanhao_tanque.normais[basecanhao_tanque.faces[j][i][2]][2])};
            glNormal3fv(normal);
            GLfloat vert[3] = {(basecanhao_tanque.vertices1[basecanhao_tanque.faces[j][i][0]][0]),(basecanhao_tanque.vertices1[basecanhao_tanque.faces[j][i][0]][1]),(basecanhao_tanque.vertices1[basecanhao_tanque.faces[j][i][0]][2])};
            glVertex3fv (vert);

        }

        glEnd( );
    }

    glPopMatrix();


    glutPostRedisplay();
}

void Trajetoria(void)
{
    float tempo = 0.0;

    float raio = 2.26811*cos((rodarVert*M_PI)/180.0);

    float y = 2.26811*sin((rodarVert*M_PI)/180.0);
    float x = -1.0*raio*sin((rodarHori*M_PI)/180.0);
    float z = -1.0*raio*cos((rodarHori*M_PI)/180.0);
    //teste
    float norma = sqrt(x*x + y*y + z*z);

    float  forcax = x/norma;
    float  forcay = y/norma;
    float  forcaz = z/norma;

    y += 3.1;
    x += 1.13283;
    z -= 0.83108;
    //glTranslated(-1.13283,3.5033,-0.83108);
    float x0 = x;
    float y0 = y;
    float z0 = z;

    glColor3f(0.5, 1.0,0.5);
    glBegin(GL_LINE_STRIP);
    do
    {
        x =    x0  + forca*forcax*tempo;
        y =    y0  + forca*forcay*tempo - 0.5*G*tempo*tempo;
        z =    z0  + forca*forcaz*tempo;
        glVertex3f(x,y,z);
        tempo += 0.01;
    }
    while(tempo < 30);
    glEnd();
}
// Função callback chamada para fazer o desenho
void Desenha(void)
{
    // Limpa a janela de visualização com a cor
    // de fundo definida previamente
    EspecificaParametrosVisualizacao();

    glViewport(0, 0, 1366, 768);// era 700/700

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DefineIluminacao();
    // Troca cor corrente para azul
    glColor3f(0.0f, 0.0f, 1.0f);

    glPushMatrix();

    glScaled(3.0,1.0,3.0);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textura_id2);
    // Desenha um cubo
    glBegin(GL_POLYGON); // Face posterior
    glNormal3f(0,0,1); // Normal da face
    glTexCoord2f(1.0/2, 2.0/3);
    glVertex3f(50.0, 50.0, 50.0);
    glTexCoord2f(1.0/4, 2.0/3);
    glVertex3f(-50.0, 50.0, 50.0);
    glTexCoord2f(1.0/4, 1.0/3);
    glVertex3f(-50.0, -50.0, 50.0);
    glTexCoord2f(1.0/2, 1.0/3);
    glVertex3f(50.0, -50.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON); // Face frontal
    glNormal3f(0,0,-1); // Normal da face
    glTexCoord2f(3.0/4, 2.0/3);
    glVertex3f(50.0, 50.0, -50.0);
    glTexCoord2f(3.0/4, 1.0/3);
    glVertex3f(50.0, -50.0, -50.0);
    glTexCoord2f(1.0, 1.0/3);
    glVertex3f(-50.0, -50.0, -50.0);
    glTexCoord2f(1.0, 2.0/3);

    glVertex3f(-50.0, 50.0, -50.0);
    glEnd();

    glBegin(GL_POLYGON);// Face lateral esquerda
    glNormal3f(-1,0,0); // Normal da face
    glTexCoord2f(1.0/4, 2.0/3);
    glVertex3f(-50.0, 50.0, 50.0);
    glTexCoord2f(0, 2.0/3);
    glVertex3f(-50.0, 50.0, -50.0);
    glTexCoord2f(0, 1.0/3);
    glVertex3f(-50.0, -50.0, -50.0);
    glTexCoord2f(1.0/4, 1.0/3);
    glVertex3f(-50.0, -50.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON); // Face lateral direita
    glNormal3f(1,0,0); // Normal da face
    glTexCoord2f(1.0/2, 2.0/3);
    glVertex3f(50.0, 50.0, 50.0);
    glTexCoord2f(1.0/2, 1.0/3);
    glVertex3f(50.0, -50.0, 50.0);
    glTexCoord2f(3.0/4, 1.0/3);
    glVertex3f(50.0, -50.0, -50.0);
    glTexCoord2f(3.0/4, 2.0/3);
    glVertex3f(50.0, 50.0, -50.0);
    glEnd();

    //glDisable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON); // Face superior
    glNormal3f(0,1,0); // Normal da face
    glTexCoord2f(1.0/4, 1.0);
    glVertex3f(-50.0, 49.0, -50.0);
    glTexCoord2f(1.0/4, 2.0/3);
    glVertex3f(-50.0, 49.0, 50.0);
    glTexCoord2f(1.0/2, 2.0/3);
    glVertex3f(50.0, 49.0, 50.0);
    glTexCoord2f(1.0/2, 1.0);
    glVertex3f(50.0, 49.0, -50.0);
    glEnd();

    //glBindTexture(GL_TEXTURE_2D, textura_id);
    glBegin(GL_POLYGON); // Face inferior
    glNormal3f(0,-1,0); // Normal da face
    glTexCoord2f(1.0/4,0);
    glVertex3f(-50.0, 0, -50.0);
    glTexCoord2f(1.0/2, 0);
    glVertex3f(50.0, 0, -50.0);
    glTexCoord2f(1.0/2, 1.0/3);
    glVertex3f(50.0, 0, 50.0);
    glTexCoord2f(1.0/4, 1.0/3);
    glVertex3f(-50.0, 0, 50.0);
    glEnd();
    glPopMatrix();
    // Execução dos comandos de desenho


    glRotated(180, 0, 1, 0);
    glTranslated(transx, 0, transz);
    glPushMatrix();
    CarregaCorpo();
    CarregaRodaDireita();
    CarregaRodaEsquerda();
    CarregaBaseCanhao();
    CarregaCanhao();
    glPopMatrix();

    //glRotated(180, 0, 1, 0);
    //glTranslated(1.13283,3.5033,-6.13108);
    glPushMatrix();
    glRotated(180, 0, 1, 0);
    glRotated(rotacao, 0, 1, 0);
    //glTranslated(1.12548,3.59078,-1.42164);
    if(!tiro.vis){
        Trajetoria();
    }else{
        glPushMatrix();
        glColor3f(0.0, 0.0,0.0);
        glTranslated(tiro.x, tiro.y, tiro.z);
        glutSolidSphere(0.2, 10, 10);
        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

// Inicialização
void Inicializa(void)
{

    corpo_tanque.Carregar("corpo.obj");//carrega o arquivo
    rodadireita_tanque.Carregar("roda_direita.obj");
    rodaesquerda_tanque.Carregar("roda_esquerda.obj");
    rodaTras_tanque.Carregar("roda_tras.obj");
    canhao_tanque.Carregar("canhao_cano.obj");
    basecanhao_tanque.Carregar("canhao_base.obj");

    /*******************************/
    srand(time(0));
    d_z = (25.0 * randomico()) + 25.0;
    d_x = (40.0 - (-40.0)) * randomico() + (-40.0);

    tiro.vis = false;
    ventox = (2.0 - (-2.0)) * randomico() + (-2.0);
    ventoz = (2.0 - (0.0)) * randomico() + (0.0);

    /*****************************/

// Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
// Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
//Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
// Habilita a luz de número 0
    glEnable(GL_LIGHT0);
// Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);

// Inicializa a variável que especifica o ângulo da projeção
// perspectiva
    angle=50;
// Inicializa as variáveis usadas para alterar a posição do
// observador virtual

    rotX = 30;
    rotY = 0;
    obsZ = 0;
    transx = 0;
    transy = 0;
    transz = 0;
    giraRoda = 0;
    rotacao = 0;
    moverCameraz = 0;


    try
    {
        ifstream arq2("chao.bmp",ios::binary);
        char c;
        if(!arq2)
            cout << "Erro abriu";

        for(int i = 0; i < 54 ; i++)
            c = arq2.get();
        for(int i = 0; i < 2048 ; i++)
            for(int j = 0; j < 2048 ; j++)
            {
                c = arq2.get();
                lado[i][j][2] = c;
                c =  arq2.get();
                lado[i][j][1] = c ;
                c =  arq2.get();
                lado[i][j][0] = c;
            }

        arq2.close();
        arq2.clear();



    }
    catch(...)
    {
        cout << "Erro ao ler imagem" << endl;
    }

    // Define os filtros de magnificação e minificação
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Seleciona o modo de aplicação da textura
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    // lado
    glGenTextures(1,&textura_id2);

    // Associa a textura aos comandos seguintes
    glBindTexture(GL_TEXTURE_2D, textura_id2);

    // Envia a textura para uso pela OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, 3,2048, 2048, 0, GL_RGB,GL_UNSIGNED_BYTE, lado);

    // Define os filtros de magnificação e minificação
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


    // Seleciona o modo de aplicação da textura
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
    // Especifica sistema de coordenadas do modelo

    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    // Especifica posição do observador e do alvo


    gluLookAt(0,0,48,0,15,0,0,1,0);

    glTranslatef(0,0,obsZ);
    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);
    DefineIluminacao();

    //printf("%f",rotX);
    //printf("%f",rotY);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    // Especifica sistema de coordenadas de projeção
    glViewport(0,0,1366,768);
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();

    // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
    gluPerspective(angle,fAspect,0.5,500);

    PosicionaObservador();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Para previnir uma divisão por zero
    if ( h == 0 ) h = 1;

    // Especifica as dimensões da viewport
    glViewport(0, 0, w, h);

    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;

    EspecificaParametrosVisualizacao();
}

// Callback para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN)
        {
            // Zoom-in
            if (angle >= 10)
                angle -= 5;
        }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN)
        {
            // Zoom-out
            if (angle <= 130)
                angle += 5;
        }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_LEFT:
    {
        if(giraRoda < 45)
        giraRoda++;
        break;
    }

    case GLUT_KEY_RIGHT:
    {
        if(giraRoda > -45)
        giraRoda--;
        break;
    }

    case GLUT_KEY_UP:
    {

        if(giraRoda > 0 ){
            if(giraRoda != rotacao)
            {
                rotacao++ ;
                giraRoda--;
            }
        }
        if(giraRoda < 0 ){
            if(giraRoda != rotacao)
            {
                rotacao-- ;
                giraRoda++;
            }

        }

        transx += sin(M_PI*rotacao/180);
        transz += cos(M_PI*rotacao/180);


        break;
    }

    case GLUT_KEY_DOWN:
    {

        if(giraRoda > 0 ){
            if(giraRoda != rotacao)
            {
                rotacao-- ;
                giraRoda--;
            }
        }
        if(giraRoda < 0 ){
            if(giraRoda != rotacao)
            {
                rotacao++ ;
                giraRoda++;
            }

        }

        transx -= sin(M_PI*rotacao/180);
        transz -= cos(M_PI*rotacao/180);

        break;
    }

    case GLUT_KEY_HOME:
        obsZ++;
        break;
    case GLUT_KEY_END:
        obsZ--;
        break;
    }


    PosicionaObservador();
    glutPostRedisplay();
}

void TeclasNormais (unsigned char key,int x, int y)
{

    if (key == 'a' && rodarHori < 90)
    {
        rodarHori = rodarHori + 1;
        rodarHori = rodarHori%360;
    }
    if (key == 'd' && rodarHori > -90)
    {
        rodarHori = rodarHori - 1;
        rodarHori = rodarHori%360;
    }
    if (key == 'w' && rodarVert < 90)
    {
        rodarVert = rodarVert + 1;
        rodarVert = rodarVert%360;
    }
    if (key == 's' && rodarVert > -45)
    {
        rodarVert = rodarVert - 1;
        rodarVert = rodarVert%360;
    }
    if (key == 'e' && !tiro.vis)
    {
        tiro.vis = true;
        tiro.tempo = 0.0;


        float raio = 2.26811*cos((rodarVert*M_PI)/180.0);

        tiro.y = 2.26811*sin((rodarVert*M_PI)/180.0);
        tiro.x = (-1.0*raio*sin((rodarHori*M_PI)/180.0));
        tiro.z = (-1.0*raio*cos((rodarHori*M_PI)/180.0));

        float norma = sqrt(tiro.x*tiro.x + tiro.y*tiro.y + tiro.z*tiro.z);

        tiro.norma = norma;


        tiro.forcax = tiro.x/norma;
        tiro.forcay = tiro.y/norma;
        tiro.forcaz = tiro.z/norma;

        //tiro.y = tiro.y + 2.0;
        tiro.y += 3.1;
        tiro.x += 1.13283;
        tiro.z -= 0.83108;

        tiro.vel = forca;

        tiro.x0 = tiro.x;
        tiro.y0 = tiro.y;
        tiro.z0 = tiro.z;

        tiro.xMax = 0.0;
        tiro.yMax = 0.0;
        tiro.zMax = 0.0;

        //PlaySound("sounds\\bomba.wav", NULL, 1);
    }
    if (key == '+')
    {
        if(forca < 25)
        {
            forca += 1.0;
            n++;
        }
    }
    if (key == '-')
    {
        if(forca > 1)
        {
            forca -= 1.0;
            n--;
        }

    }
    PosicionaObservador();
    glutPostRedisplay();
}


void Timer(int value)
{
    float angulo;
    float distancia;

    if(tiro.vis)
    {
        if(tiro.vel > 0.1)
        {

            tiro.x =    tiro.x0  + tiro.vel*tiro.forcax*tiro.tempo + ventox*tiro.tempo;
            tiro.y =    tiro.y0  + tiro.vel*tiro.forcay*tiro.tempo - 0.5*G*tiro.tempo*tiro.tempo;
            tiro.z =    tiro.z0  + tiro.vel*tiro.forcaz*tiro.tempo + (-1)*ventoz*tiro.tempo;

            if(tiro.y > tiro.yMax)
            {
                tiro.yMax = tiro.y;
                tiro.xMax = tiro.x;
                tiro.zMax = tiro.z;
            }

            if(tiro.y <0.2)
            {
                distancia = sqrt((tiro.x - tiro.xMax)*(tiro.x - tiro.xMax) + (tiro.z - tiro.zMax)*(tiro.z - tiro.zMax));
                angulo = atan(tiro.yMax/(distancia));

                tiro.forcay = ((2.0*sin(angulo))/tiro.norma);
                tiro.x0 = tiro.x;
                tiro.y0 = tiro.y;
                tiro.z0 = tiro.z;
                tiro.vel = tiro.vel*0.9;
                tiro.tempo = 0.0;
            }

            if ((tiro.vel < 0.1 || tiro.z < -50 || tiro.x < -50 || tiro.x > 50) && tiro.y < 0.2)
            {
                tiro.vis = false;
                //if(cont == 0)
                    //PlaySound("sounds\\errou.wav", NULL, 1);
                cont = 0;
                ventox = (2.0 - (-2.0)) * randomico() + (-2.0);
                ventoz = (2.0 - (0.0)) * randomico() + (0.0);
            }

            float d0 = 1.2;
            float d1 = sqrt(pow((d_x - tiro.x), 2) + pow((1.0 - tiro.y), 2) + pow((-d_z - tiro.z), 2));
            if(d1 < d0)
            {
                alvovis = 0;
                //PlaySound("sounds\\quebrou.wav", NULL, 1);
                cont++;
            }

        }
        tiro.tempo += 0.01;
    }

    glutTimerFunc(10,Timer,0);
    glutPostRedisplay();
}

void my_idle_callback() //No params
{
    glutPostRedisplay();
}

// Programa Principal
int main()
{
    int argc = 0;
    char *argv[] = { (char *)"gl", 0 };

    glutInit(&argc,argv);

    // Define do modo de operacao da GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(5,5);

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(1366,768);

    // Cria a janela passando como argumento o titulo da mesma
    glutCreateWindow("Textura");

    glutTimerFunc(10,Timer,0);

    // Registra a funcao callback de redesenho da janela de visualizacao
    glutDisplayFunc(Desenha);
    // Registra a funcao callback para tratamento das teclas especiais
    glutSpecialFunc(TeclasEspeciais);
    // Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);
    // Registra a funcao callback para tratamento do mouse
    glutKeyboardFunc(TeclasNormais);
    glutMouseFunc(GerenciaMouse);
    glutIdleFunc(my_idle_callback);

    Inicializa();
    glutMainLoop();

}

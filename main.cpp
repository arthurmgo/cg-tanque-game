#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "CarregarArquivo.cpp"

void PosicionaObservador(void);
void EspecificaParametrosVisualizacao(void);

GLfloat angle, fAspect, rotX, rotY;
GLdouble obsX, obsY, obsZ;
CarregarArquivo Tanque;

int figura = 0;

float r = 1.0;
float g = 1.0;
float b = 1.0;

GLubyte lado[2048][2048][3];

GLuint textura_id, textura_id2, textura_id3;


void DefineIluminacao (void)
{

    GLfloat luzAmbiente[4]= {0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]= {0.7,0.7,0.7,1.0}; // "cor"
    GLfloat luzEspecular[4]= {r, g, b, 1.0}; // "brilho"
    GLfloat posicaoLuz[4]= {0.0, 150.0, 150.0, 1.0};
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
    glEnable(GL_LIGHT0);
}

//void DesenhaTanque(void){
//        // Troca cor corrente para azul
//    glColor3f(1.0f, 0.0f, 0.0f);
//    //DefineIluminacao();
//
//    glScalef( 50.0, 10.0, 10.0);
//
//    for ( int j = 0; j < (Tanque.faces).size(); ++j )
//    {
//
//        glBegin ( GL_POLYGON );
//
//        for (int i = 0; i < (Tanque.faces[j]).size() ; ++i )
//        {
//            GLfloat vert[3] = {(Tanque.vertices1[Tanque.faces[j][i][0]][0]),(Tanque.vertices1[Tanque.faces[j][i][0]][1]),(Tanque.vertices1[Tanque.faces[j][i][0]][2])};
//            GLfloat norm[3] = {(Tanque.normais[Tanque.faces[j][i][2]][0]),(Tanque.normais[Tanque.faces[j][i][2]][1]),(Tanque.normais[Tanque.faces[j][i][2]][2])};
//            glNormal3fv ( norm );
//            glVertex3fv ( vert );
//        }
//
//        glEnd( );
//    }
//
//}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    // Limpa a janela de visualização com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    // Desenha um aviao

    // Limpa a janela de visualização com a cor
    // de fundo definida previamente
    EspecificaParametrosVisualizacao();
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
    glTexCoord2f(1.0/2 , 2.0/3);
    glVertex3f(50.0, 50.0, 50.0);
    glTexCoord2f(1.0/4 , 2.0/3);
    glVertex3f(-50.0, 50.0, 50.0);
    glTexCoord2f(1.0/4 , 1.0/3);
    glVertex3f(-50.0, -50.0, 50.0);
    glTexCoord2f(1.0/2 , 1.0/3);
    glVertex3f(50.0, -50.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON); // Face frontal
    glNormal3f(0,0,-1); // Normal da face
    glTexCoord2f(3.0/4 , 2.0/3);
    glVertex3f(50.0, 50.0, -50.0);
    glTexCoord2f(3.0/4 , 1.0/3);
    glVertex3f(50.0, -50.0, -50.0);
    glTexCoord2f(1.0 , 1.0/3);
    glVertex3f(-50.0, -50.0, -50.0);
    glTexCoord2f(1.0 , 2.0/3);

    glVertex3f(-50.0, 50.0, -50.0);
    glEnd();

    glBegin(GL_POLYGON);// Face lateral esquerda
    glNormal3f(-1,0,0); // Normal da face
    glTexCoord2f(1.0/4 , 2.0/3);
    glVertex3f(-50.0, 50.0, 50.0);
    glTexCoord2f(0 , 2.0/3);
    glVertex3f(-50.0, 50.0, -50.0);
    glTexCoord2f(0 , 1.0/3);
    glVertex3f(-50.0, -50.0, -50.0);
    glTexCoord2f(1.0/4 , 1.0/3);
    glVertex3f(-50.0, -50.0, 50.0);
    glEnd();

    glBegin(GL_POLYGON); // Face lateral direita
    glNormal3f(1,0,0); // Normal da face
    glTexCoord2f(1.0/2 , 2.0/3);
    glVertex3f(50.0, 50.0, 50.0);
    glTexCoord2f(1.0/2 , 1.0/3);
    glVertex3f(50.0, -50.0, 50.0);
    glTexCoord2f(3.0/4 , 1.0/3);
    glVertex3f(50.0, -50.0, -50.0);
    glTexCoord2f(3.0/4 , 2.0/3);
    glVertex3f(50.0, 50.0, -50.0);
    glEnd();

    //glDisable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON); // Face superior
    glNormal3f(0,1,0); // Normal da face
    glTexCoord2f(1.0/4 , 1.0);
    glVertex3f(-50.0, 50.0, -50.0);
    glTexCoord2f(1.0/4 , 2.0/3);
    glVertex3f(-50.0, 50.0, 50.0);
    glTexCoord2f(1.0/2 , 2.0/3);
    glVertex3f(50.0, 50.0, 50.0);
    glTexCoord2f(1.0/2 , 1.0);
    glVertex3f(50.0, 50.0, -50.0);
    glEnd();

    glBegin(GL_POLYGON); // Face inferior
    glNormal3f(0,-1,0); // Normal da face
    glTexCoord2f(1.0/4 ,0);
    glVertex3f(-50.0, -50.0, -50.0);
    glTexCoord2f(1.0/2 , 0);
    glVertex3f(50.0, -50.0, -50.0);
    glTexCoord2f(1.0/2 , 1.0/3);
    glVertex3f(50.0, -50.0, 50.0);
    glTexCoord2f(1.0/4 , 1.0/3);
    glVertex3f(-50.0, -50.0, 50.0);
    glEnd();
    glPopMatrix();
    // Execução dos comandos de desenho

    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 0.0f, 0.0f);
    glScalef( 20.0, 20.0, 20.0);

    for ( int j = 0; j < (Tanque.faces).size(); ++j )
        {

            glBegin ( GL_POLYGON );

            for (int i = 0; i < (Tanque.faces[j]).size() ; ++i )
            {


                GLfloat normal[3] = {(Tanque.normais[Tanque.faces[j][i][2]][0]),(Tanque.normais[Tanque.faces[j][i][2]][1]),(Tanque.normais[Tanque.faces[j][i][2]][2])};
                glNormal3fv(normal);

                GLfloat vert[3] = {(Tanque.vertices1[Tanque.faces[j][i][0]][0]),(Tanque.vertices1[Tanque.faces[j][i][0]][1]),(Tanque.vertices1[Tanque.faces[j][i][0]][2])};
                glVertex3fv ( vert );


            }

            glEnd( );
        }

    // Execução dos comandos de desenho

    glutSwapBuffers();

}


// Inicialização
void Inicializa(void)
{
    Tanque.Carregar("tanque.obj");//carrega o arquivo

    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);


    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial (GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE );
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);// normaliza as normais
    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);


// Inicializa a variável que especifica o ângulo da projeção
// perspectiva
    angle=50;
// Inicializa as variáveis usadas para alterar a posição do
// observador virtual
    rotX = 0;
    rotY = 0;

    obsX = 0.0;
    obsY = 0.0;
    obsZ = 180.0;
    try
    {
        ifstream arq2("sky.bmp" ,ios::binary);
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
   // DefineIluminacao();

    gluLookAt(obsX,obsY,obsZ,0,0,0,0,1,0);
    // Especifica posição do observador e do alvo
    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);

}


// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    // Especifica sistema de coordenadas de projeção
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
        rotY--;
        break;
    case GLUT_KEY_RIGHT:
        rotY++;
        break;
    case GLUT_KEY_UP:
        rotX++;
        break;
    case GLUT_KEY_DOWN:
        rotX--;
        break;
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

void Timer(int value)
{
    if(value > 0)
    {
        value--;
        glutTimerFunc(200,Timer,value);
        glutPostRedisplay();
    }
}

void Teclado(unsigned char key, int x, int y)
{

    if(key == ',')
    {
        glShadeModel(GL_SMOOTH);
    }
    if(key == '.')
    {
        glShadeModel(GL_FLAT);
    }
    if(key == '0'){
        figura = 0;
    }
    if(key == '1'){
        figura = 1;
    }
    if(key == 'r' && r >= 0.0){
        r -= 0.1;
    }
    if(key == 'R' && r <= 1.0){
        r += 0.1;
    }
    if(key == 'g' && g >= 0.0){
        g -= 0.1;
    }
    if(key == 'G' && g <= 1.0){
        g += 0.1;
    }
    if(key == 'b' && b >= 0.0){
        b -= 0.1;
    }
    if(key == 'B' && b <= 1.0){
        b += 0.1;
    }

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
    glutInitWindowSize(800,800);

    // Cria a janela passando como argumento o titulo da mesma
    glutCreateWindow("Desenho de um objeto com iluminação");

    // Registra a funcao callback de redesenho da janela de visualizacao
    glutDisplayFunc(Desenha);
    // Registra a funcao callback para tratamento das teclas especiais
    glutSpecialFunc(TeclasEspeciais);
    // Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);
    // Registra a funcao callback para tratamento do mouse
    glutMouseFunc(GerenciaMouse);
    glutKeyboardFunc(Teclado);

    Inicializa();
    glutMainLoop();
}

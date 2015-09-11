//
//  main.cpp
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/16/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

/* CS 3GC3 - Simple lighting example
 * by R. Teather
 *
 */

#include "common.h"

/* drawPolygon - takes 4 indices and an array of vertices
 *   and draws a polygon using the vertices indexed by the indices
 */
void drawPolygon(int a, int b, int c, int d, float v[8][3]){
	glBegin(GL_POLYGON);
    
    glTexCoord2f(0, 0);
    glVertex3fv(v[a]);
    
    glTexCoord2f(1, 0);
    glVertex3fv(v[b]);
    
    glTexCoord2f(1, 1);
    glVertex3fv(v[c]);
    
    glTexCoord2f(0, 1);
    glVertex3fv(v[d]);
	glEnd();
}

/* cube - takes an array of 8 vertices, and draws 6 faces
 *  with drawPolygon, making up a box
 */
void cube(float v[8][3], int marker)
{
  	glBindTexture(GL_TEXTURE_2D, textures[marker]);
	glColor3fv(cols[1]);
	drawPolygon(0, 3, 2, 1, v);
    
	
    glBindTexture(GL_TEXTURE_2D, 0);   //to make procedding colors correct
}


/* drawBox - takes centre point, width, height and depth of a box,
 *  calculates its corner vertices, and draws it with the cube function
 */
void drawBox(float* c, float w, float h, float d, int marker)
{
	float vertices[8][3] = { {c[0]-w/2, c[1]-h/2, c[2]+d/2},
        {c[0]-w/2, c[1]+h/2, c[2]+d/2},
        {c[0]+w/2, c[1]+h/2, c[2]+d/2},
        {c[0]+w/2, c[1]-h/2, c[2]+d/2},
        {c[0]-w/2, c[1]-h/2, c[2]-d/2},
        {c[0]-w/2, c[1]+h/2, c[2]-d/2},
        {c[0]+w/2, c[1]+h/2, c[2]-d/2},
        {c[0]+w/2, c[1]-h/2, c[2]-d/2} };
    
	cube(vertices, marker);
}

void createObjects(void){
    
    objects[0].set(46 , -1, 0, 100, 1, 1, 0, 1, 0, 1);
    
    objects[1].set(3,0, 0, 1, 1, 1, 0, 1, 1, 1);
    
    objects[2].set(4,0.5,0,1,2,1,1,0,0,1);
    
    objects[3].set(-3.5,4.5,0,1,10,1,0,1,0,1);
    
    objects[4].set(77,-1,0,50,1,1,0,1,0,1);
    
    //objects[5].set(0,0,-20,20,20,5,1,1,1,1);
    
    //objects[6].set(77,-1,0,50,1,1,0,1,0,1);
    
}

void keyboard(unsigned char key, int x, int y)
{
    
	/* key presses move the cube, if it isn't at the extents (hard-coded here) */
	switch (key)
	{
		case ' ':
			mainC.jump();
			break;
            
	}
    
	glutPostRedisplay();
}

void special(int key, int x, int y)
{
	/* arrow key presses move the camera */
	switch(key)
	{
		case GLUT_KEY_LEFT:
			mainC.changeDirection(-0.1, 0, 0);
			break;
            
		case GLUT_KEY_RIGHT:
			mainC.changeDirection(0.1, 0, 0);
			break;
            
            
	}
	glutPostRedisplay();
}

bool checkx(Character x, Object y){
    
    if ((x.position[0]+ 0.5) >= (y.position[0] - y.scale[0]/2) & (x.position[0] - 0.5) <= (y.position[0] + y.scale[0]/2)){
        return true;
    }
    return false;
}

bool checky(Character x, Object y){
    
    if ((x.position[1]+ 0.5) >= (y.position[1] - y.scale[1]/2) & (x.position[1] - 0.5) <= (y.position[1] + y.scale[1]/2)){
        return true;
    }
    return false;
}

bool checkz(Character x, Object y){
    
    if ((x.position[2]+ 0.5) >= (y.position[2] - y.scale[2]/2) & (x.position[2] - 0.5) <= (y.position[2] + y.scale[2]/2)){
        return true;
    }
    return false;
}

void gravity(void){
    
    
    Character test;
    
    test = mainC;
    
    test.updatePosistion();
    for (int i = 0 ; i <objectAmount; i++){
        
        
        
        bool y = checky(mainC,objects[i]);
        bool x = checkx(mainC,objects[i]);
        bool z = checkz(test,objects[i]);
        if (y&z&x) {
            mainC.setDirectionz(0);
            //mainC.setDirectionx(0);
            //mainC.setDirectiony(0);
        }
        y = checky(mainC,objects[i]);
        x = checkx(test,objects[i]);
        z = checkz(mainC,objects[i]);
        if (y&z&x) {
            //mainC.setDirectionz(0);
            mainC.setDirectionx(0);
            //mainC.setDirectiony(0);
        }
        y = checky(test,objects[i]);
        x = checkx(mainC,objects[i]);
        z = checkz(mainC,objects[i]);
        if (y&z&x) {
            //mainC.setDirectionz(0);
            //mainC.setDirectionx(0);
            mainC.setDirectiony(0);
        }
        
    }
    mainC.updatePosistion();
    mainC.changeDirection(0, g, 0);
    
}

void idle(void){
    
    gravity();
    //mainC.updatePosistion();
    glutPostRedisplay();
    
    if (mainC.position[1] < maxFallDistance){
        
        mainC.life += -1;
        mainC.reset();
        
        
    }
    
    if (mainC.life <= 0){
        printf("You Failed");
        exit(0);
        
    }
    
    if (mainC.position[0] > end.position[0]){
        
        printf("You Win");
        exit(0);
        
    }
    
    
    
}

/* LoadPPM -- loads the specified ppm file, and returns the image data as a GLubyte
 *  (unsigned byte) array. Also returns the width and height of the image, and the
 *  maximum colour value by way of arguments
 */
GLubyte* LoadPPM(char* file, int* width, int* height, int* max)
{
	GLubyte* img;
	FILE *fd;
	int n, m;
	int  k, size;
	char c;
	int i;
	char b[100];
	float s;
	int red, green, blue;

	//open the file in read mode
	fd = fopen(file, "r");

	//scan everything up to newline
	fscanf(fd,"%[^\n] ",b);

	//check if the first two characters are not P3, if not, it's not an ASCII PPM file
	if(b[0]!='P'|| b[1] != '3')
	{
		printf("%s is not a PPM file!\n",file);
		exit(0);
	}

	printf("%s is a PPM file\n", file);

	//read past the file comments: scan for lines that begin
	//  with #, and keep going until you find no more
	fscanf(fd, "%c",&c);
	while(c == '#')
	{
		fscanf(fd, "%[^\n] ", b);
		printf("%s\n",b);
		fscanf(fd, "%c",&c);
	}

	//rewind the read pointer one character, or we'll lose the size
	ungetc(c,fd);

	//read the rows, columns and max colour values
	fscanf(fd, "%d %d %d", &n, &m, &k);

	printf("%d rows  %d columns  max value= %d\n",n,m,k);

	//number of pixels is rows * columns
	size = n*m;

	//allocate memory to store 3 GLuints for every pixel
	img =  (GLubyte *)malloc(3*sizeof(GLuint)*size);

	//scale the colour in case maxCol is not 255
	s=255.0/k;

	//start reading pixel colour data
	for(i=0;i<size;i++)
	{
		fscanf(fd,"%d %d %d",&red, &green, &blue );
		img[3*size-3*i-3]=red*s;
		img[3*size-3*i-2]=green*s;
		img[3*size-3*i-1]=blue*s;
	}

	*width = n;
	*height = m;
	*max = k;

	return img;
}

void drawMarkers(void)
{
    glPushMatrix();
    glTranslatef(0,3, 0);
	drawBox(origin, 1, 1, 1, 0);
    glPopMatrix();
    
}

void lights(void){
    
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
    glEnable(GL_LIGHT1);
    
}

void init(void)
{
    mainC.life = lifes;
    
    end.set(ending);
    
    
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
    
	//turn on lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    
    lights();
    
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 1, 100);
    
	//enable texturing
	glEnable(GL_TEXTURE_2D);
    
	//generate 2 texture IDs, store them in array "textures"
	glGenTextures(3, textures);
    
	//load the texture (snail)
	marker1_tex = LoadPPM("target1_a.ppm", &width, &height, &max);
    
	//setup first texture (using snail image)
	glBindTexture(GL_TEXTURE_2D, textures[0]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//set texture parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	//create a texture using the "snail_tex" array data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, marker1_tex);
	
	//load the texture (marble)
	marker2_tex = LoadPPM("target2_a.ppm", &width, &height, &max);
    
	//setup second texture (using marble image)
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	//set texture parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//create a texture using the "tex" array
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, marker2_tex);
	
    
    //load the texture (marble)
	background_tex = LoadPPM("target2_a.ppm", &width, &height, &max);
    
	//setup second texture (using marble image)
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	//set texture parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//create a texture using the "tex" array
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, background_tex);

    
    createObjects();
    
}

void drawCharacters(void){
    
    mainC.drawCharacter();
    
}

void drawObjects(void){
    
    for (int i = 0; i < objectAmount; i++){
        
        objects[i].drawObject();
        
    }
    
}

void drawBackground(void){
    
    glPushMatrix();
    glTranslatef(0,0, -350);
	//drawBox(origin, 300, 300, 0, 2);
    glPopMatrix();
    
}

/* display function - GLUT display callback function
 *		clears the screen, sets the camera position, draws the ground plane and movable box
 */
void display(void)
{
    drawBackground();
    
	//some light properties
	float amb[4] = {1.0, 1, 1, 1};
	float diff[4] = {1,0,0, 1};
	float spec[4] = {0,0,1, 1};
    
	float m_amb[] = {0.6, .6, 0.6, 1.0};
	float m_dif[] = {0.78, 0.57, 0.11, 1.0};
	float m_spec[] = {0.99, 0.91, 0.81, 1.0};
	float shiny = 27;
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(mainC.position[0], camPos[1], camPos[2], mainC.position[0],mainC.position[1], mainC.position[2],0,1,0);
    glColor3f(1,1,1);
    
	//set materials
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m_dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, m_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
    
	//set light properties
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec);
    
    
    drawMarkers();
    
    drawCharacters();
    drawObjects();

	glutSwapBuffers();
}

/* main function - program entry point */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);		//starts up GLUT
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
    
	glutCreateWindow("Augmented Platformerer");	//creates the window
    
	glutDisplayFunc(display);	//registers "display" as the display callback function
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
    glutIdleFunc(idle);
    
	glEnable(GL_DEPTH_TEST);
	init();
    
    
    
	glutMainLoop();				//starts the event loop
    
	return(0);					//return may not be necessary on all compilers
}
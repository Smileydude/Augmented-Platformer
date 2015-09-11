//
//  Object.cpp
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/17/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

#include "Object.h"

#include <GLUT/glut.h>

#include <limits.h>



Object::Object(){
    
    position[0] = INT_MIN;
    position[1] = INT_MIN;
    position[2] = INT_MIN;
    
    scale[0] = NULL;
    scale[1] = NULL;
    scale[2] = NULL;
    
    color[0] = NULL;
    color[1] = NULL;
    color[2] = NULL;
    
    shape = NULL;
    
    
}

void Object::set(float x, float y, float z,float sx,float sy, float sz,float cx,float cy,float cz, int s) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
    
    scale[0] = sx;
    scale[1] = sy;
    scale[2] = sz;
    
    color[0] = cx;
    color[1] = cy;
    color[2] = cz;
    
    shape = s;
    
}

void Object::drawObject(void){
    
    glPushMatrix();
    
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, color);
    
    
    
    glTranslatef(position[0], position[1], position[2]);
    
    glScalef(scale[0],scale[1],scale[2]);
    
    glutSolidCube(1);
    
    glPopMatrix();
    
    
}



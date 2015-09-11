//
//  common.h
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/17/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

#ifndef AugmentedPlatformer_common_h
#define AugmentedPlatformer_common_h

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

#include "object.h"
#include "Character.h"
#include "endPoint.h"

#include <malloc/malloc.h>


float origin[3] = {0,0,0};

float light_pos[] = {5,10,5,1};
float light_pos1[] = {0,0,0,1};

float pos[] = {0,1,0};

float camPos[] = {5, 5, 10};
float angle = 0.0f;




Object objects[5]; //objects array ie number of objects allowed in scene
int objectAmount = sizeof(objects) / sizeof( objects[0]);

Character mainC;//main character

int lifes = 3;

float maxFallDistance = -10;

float g = -0.2;  //gravity constant


//an array for iamge data
GLubyte* marker1_tex;
GLubyte* marker2_tex;
GLubyte* background_tex;
int width, height, max;

GLuint textures[5];

float cols[6][3] = { {1,0,0}, {0,1,1}, {1,1,0}, {0,1,0}, {0,0,1}, {1,0,1} };

endPoint end;

float ending[] = {90,0,0};



#endif

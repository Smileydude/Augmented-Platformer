//
//  mainCharacter.h
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/16/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

#ifndef __AugmentedPlatformer__mainCharacter__
#define __AugmentedPlatformer__mainCharacter__

#include <iostream>

typedef struct
{
    float position[3];
    float direction[3];
    
}Character;

void drawMainC(void);

void updateMainC(void);

void directionMainC(float x, float y, float z);

void moveMainCv(float x[3]);

void moveMainC(float x, float y, float z);





#endif /* defined(__AugmentedPlatformer__mainCharacter__) */

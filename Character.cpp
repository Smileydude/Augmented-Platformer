//
//  Character.cpp
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/16/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

#include "Character.h"

#include <GLUT/glut.h>



void Character::move(float x, float y, float z) {
    position[0] += x;
    position[1] += y;
    position[2] += z;
    
}

void Character::reset(){
    
    position[0] =0;
    position[1] = 0;
    position[2] = 0;
    direction[0] = 0;
    direction[1] = 0;
    direction[2] = 0;
    
    
}



void Character::changeDirection(float x, float y, float z)
{
    direction[0] += x;
    direction[1] += y;
    direction[2] += z;
    
}

void Character::updatePosistion(){
    position[0] += direction[0];
    position[1] += direction[1];
    position[2] += direction[2];
    
}

void Character::drawCharacter(){
    
    glPushMatrix();
    
    glTranslatef(position[0], position[1], position[2]);
    
    glutSolidCube(1);
    
    glPopMatrix();
    
}

void Character::jump(void){
    
    direction[1] += 1.2;
    
}

void Character::setDirectionx(float x){
    
    direction[0] = x;

}

void Character::setDirectiony(float x){
    
    direction[1] = x;
    
}

void Character::setDirectionz(float x){
    
    direction[2] = x;
    
}
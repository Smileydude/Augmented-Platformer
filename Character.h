//
//  Character.h
//  AugmentedPlatformer
//
//  Created by Tom Woudenberg on 12/16/2013.
//  Copyright (c) 2013 Tom Woudenberg. All rights reserved.
//

#ifndef __AugmentedPlatformer__Character__
#define __AugmentedPlatformer__Character__

#include <iostream>

class Character{
    
    
public:
    float position[3];
    float direction[3];
    
    int life;
    
    
    void move(float, float, float);
    void changeDirection(float, float, float);
    void updatePosistion(void);
    void setDirectionx(float);
    void setDirectiony(float);
    void setDirectionz(float);
    void reset(void);
    
    void drawCharacter(void);
    
    void jump(void);
    
};

#endif /* defined(__AugmentedPlatformer__Character__) */

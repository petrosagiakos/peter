import pygame, sys, random, time; from pygame.locals import*
pygame.init()

#epif.blit()

class archer:
     def __init__(self, posx, posy,img,dead):
        self.posx=posx
        self.posy=posy
        self.img=img
        self.dead=dead
     def appear(self):
         epif.blit(self.img,(self.posx,self.posy,self.img.get_width(),self.img.get_height()))
     def move_forward(self):
         self.posx+=1
         epif.blit(self.img,(self.posx,self.posy,self.img.get_width(),self.img.get_height()))
     def move_backward(self):
         self.posx-=1
         epif.blit(self.img,(self.posx,self.posy,self.img.get_width(),self.img.get_height()))
class arrow:
    def __init__(self,x,y,img,left):
        self.x=x
        self.y=y
        self.img=img
        self.left=left
    def fire(self):
        self.x+=20
        epif.blit(self.img,(self.x,self.y,self.img.get_width(),self.img.get_height()))
        
    def destroy(self):
        if self.x>1000:
            self.left=False
class monster:
    def __init__(self,x,y,img,dead):
        self.x=x
        self.y=y
        self.img=img
        self.dead=dead
    def appear(self):
         epif.blit(self.img,(self.x,self.y,self.img.get_width(),self.img.get_height()))
    def move(self):
        self.x-=1
        epif.blit(self.img,(self.x,self.y,self.img.get_width(),self.img.get_height()))
    def kill():  
        pass   

class background:
    def __init__(self,img):
        self.img=img
    def set_bg(self):
        epif.blit(self.img,(0,0,self.img.get_width(),self.img.get_height()))
image=pygame.image.load('bg.png')
bg=background(image)
epif = pygame.display.set_mode((bg.img.get_width(),bg.img.get_height()))
pygame.display.set_caption("archery_game")

epif.fill((255,255,255))
bg.set_bg()
pygame.display.update()
archer1=archer(100,477,pygame.image.load("archer2.png"),False)
arrow1=arrow(100,100,pygame.image.load("arrow.png"),False)
monster1=monster(1100,477,pygame.image.load("skull.png"),False)
archer1.appear()
monster1.appear()
game=True

while game:
    bg.set_bg()
    if not archer1.dead:
        archer1.appear()
    if not monster1.dead:
        monster1.move()
    
    for event in pygame.event.get():
        if event.type==QUIT:
            game=False
       
              
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        
        arrow1.left=True
    if keys[pygame.K_RIGHT] and not archer1.dead and archer1.posx<bg.img.get_width()-75:
     
        archer1.move_forward()
     
    if keys[pygame.K_LEFT] and not archer1.dead and archer1.posx>0:
       
       archer1.move_backward()
        
    if arrow1.left:
        
       
        arrow1.fire()
    else:
        arrow1.x=archer1.posx
        arrow1.y=archer1.posy+35
    arrow1.destroy()
    if archer1.posx>=monster1.x and not monster1.dead:
        player_dead=True
        game=False
    elif arrow1.x>=monster1.x:
        monster1.dead=True
        monster1=monster(1100,477,pygame.image.load("skull.png"),False)
    pygame.display.update()
   
        
    

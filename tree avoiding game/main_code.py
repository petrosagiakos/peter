import pygame, sys, random, time; from pygame.locals import*

pygame.init()
epif = pygame.display.set_mode((1500,900))
pygame.display.set_caption("car")
epif.fill((255,255,255))
pygame.display.update()
#epif.blit()

class car:
     def __init__(self, posx, posy):
        self.posx=posx
        self.posy=posy
        self.img=pygame.image.load('car.png')
     def appear(self):
         epif.blit(self.img,(self.posx,self.posy,100,100))
     def drive(self):
         epif.fill((255,255,255))
         epif.blit(self.img,(self.posx,self.posy,100,100))

class obsticle:
     def __init__(self, posx, posy, car1):
        self.posx=posx
        self.posy=posy
        self.img=pygame.image.load('tree.png')
        self.c1=car1
     def appear(self):
         epif.blit(self.img,(self.posx,self.posy,100,100))
     def boom(self):
         if car1.posy<=self.posy+420 and car1.posy>=self.posy-180 and car1.posx<=self.posx+300 and car1.posx>=self.posx-40:
             return True
         else:
             return False
     def out_of_limit(self):
         if self.posy> 500:
             return True


pygame.display.update()
car1=car(650,500)
y=random.randint(-100,175)
ob1=obsticle(y,-300,car1)
y2=random.randint(825,900)
ob2=obsticle(y2,-500,car1)
game=True
while game:
   
   
    for event in pygame.event.get():
        if event.type==QUIT:
            game=False
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        ob2.posy += 1
        ob1.posy += 1
        car1.drive()
        ob1.appear()
        ob2.appear()
    if keys[pygame.K_DOWN]:
        ob2.posy -= 1
        ob1.posy -= 1
        car1.drive()
        ob1.appear()
        ob2.appear()
    if keys[pygame.K_RIGHT]:
        ob2.posy += 1
        car1.posx += 1
        ob1.posy += 1
        car1.drive()
        ob1.appear()
        ob2.appear()
    if keys[pygame.K_LEFT]:
        ob2.posy += 1
        car1.posx -= 1
        ob1.posy += 1
        car1.drive()
        ob1.appear
        ob2.appear()
    ob2.appear
    ob1.appear() 
    car1.appear()
    if ob1.boom() or ob2.boom():
        
        epif.fill((255,255,0))
        pygame.display.update()
        time.sleep(5)
        game=False

    if ob1.out_of_limit():
        y=random.randint(-100,300)
        ob1=obsticle(y,-300,car1)
    if ob2.out_of_limit():
        y2=random.randint(600,900)
        ob2=obsticle(y2,-500,car1)
    pygame.display.update()
   
        
    

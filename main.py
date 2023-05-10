import solution as slt
import pygame as pg
import sys


def main():
    pg.init()

    screen = pg.display.set_mode((1200, 900))
    font = pg.font.SysFont("Arial", 24)

    mix = slt.Solution()

    mix.chemicals.add(slt.Chemical("Water", 200))
    mix.chemicals.add(slt.Chemical("Salt", 50))
    mix.chemicals.add(slt.Chemical("Chloride", 2))

    mix.conditions.add(slt.Condition("Temperature", 21))
    mix.conditions.add(slt.Condition("Pressure", 1))


    clock = pg.time.Clock()
    while True:
        for ev in pg.event.get():
            if ev.type == pg.QUIT:
                pg.quit()
                sys.exit()
        
        screen.fill((128, 148, 200))

        for i, chem in enumerate(mix.chemicals):
            screen.blit(font.render(str(chem),True,(0,0,0)), (0, i*24))
        for i, cond in enumerate(mix.conditions):
            screen.blit(font.render(str(cond),True,(0,0,0)), (200, i*24))

        pg.display.update()

        clock.tick(60)




if __name__ == "__main__":
    main()
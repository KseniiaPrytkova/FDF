# FDF

[man mlx](https://github.com/qst0/ft_libgfx)

```
gcc -I /Users/kprytkov/FDF/go_MinilibX main.c -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
```

## STEP 1. Bresenham's line algorithm
A line connects two points. It is a basic element in graphics. To draw a line, you need two points between which you can draw a line. And an algorithm to do this. [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) can use integer calculations, so it works faster than approaches with floats. This algorithm is needed in order to draw a line at any angle and in any direction (and not just proceeding from the [origin](https://en.wikipedia.org/wiki/Origin_(mathematics))).
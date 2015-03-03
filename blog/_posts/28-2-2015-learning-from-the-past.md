---
title: Learning from the past

layout: page
---

> Anyone who has never made a mistake has never tried anything new.
>
> -Albert Einstein

Although my first robot **did** work, perhaps the most important knowledge I gained was on how **not** to build a robot. With that in mind, here are some of my goals for my second robot.

1. It should be designed with ease of access to its guts in mind. Although this will lead to a less aesthetically pleasing creation, it will be worth it. Making panels easily removable and the inside spacious and neat will make opening it up a pleasure rather than a chore.
2. It should be minimally hardware dependent. I would like the option to switch out hardware, for when I inevitable discover I have made a mistake or for when I want to experiment with something new. This will allow me to use the body for all sorts of robots, rather than a robot that can only perform one task, like my previous one.
3. In order to achieve number 2, the code should be written with a separation of concerns. There should be base, low level code for commanding the robot that can be used by any program, and specific, high level behaviors built on top of that base.
4. Debugging and documentation must come first. With EDWARD, I suffered from a lack of both of those. Debug information should be baked into the low level code, and always available in a variety of manners. Documentation should describe the assumptions of the code, and what it requires.

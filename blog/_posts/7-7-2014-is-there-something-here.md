---
title: Is there something here?

layout: page
---

Ping sensors are inaccurate. I had great troubles with this in my last robot. Either he would see too many walls or none at all. There are a few reasons this happened, and I am going to try to fix them all in this new robot. One issue was that EDWARD divided his world into 12" x 12" squares. This meant that any reading would (often erroneously) create a wall at an unnatural 90 degree angle. In order to fix that I am going to use smaller (1cm) squares. However, this amplifies the second, and major, problem: Sound travels in a wave, but ping sensors simply give you the distance to the nearest object, which means that no measurement is certain.

What to do? I decided that the best way to fix this problem is to make BEN based on probability. As my friend commented,

> I wouldn't want to be in a car driven by probability!

Neither would I. So I will put some bump sensors around the outside of the robot as an emergency stop. But ideally my algorithms will be good enough (and fast enough) so that they won't be necessary.

## How will it work?

The basic idea is that every square, rather than storing whether or not there is an object in it, will store the probability that there is something there. Since the robot will be navigating using the A* Search Algorithm, I can use a factor of the probability as the cost per square, instead of a flat rate.

However, design is only half the challenge. Now I needed to figure out a way to calculate this probability. After debating with my friend, we decided that the best way would be something like:

$$ \frac{numTimesObjectFound}{numTimesSquareScanned} * \frac{1}{errorRate} $$

where the error rate is the average number of squares scanned at once at the same time this square has been scanned. That means that

$$ \frac{1}{errorRate} $$

gives the probability that this square was the one with the object in it, whereas

$$ \frac{numTimesObjectFound}{numTimesSquareScanned} $$

gives the probability that the readings were correct on seeing something in the general area.

If we expand the error rate a little, we find that it is

$$ \frac{totalNumSquaresScanned}{numTimesSquareScanned} $$

which means that we can simplify our equation to

$$ \frac{numTimesObjectFound}{totalNumSquaresScanned} $$

since it is easy enough to keep track the number of times something has been found in a square, now all I had to do was find a way to calculate the total number of squares that were scanned at times when the current square was scanned as well.

## Theories about circles

Since we needed the total number of squares scanned, I figured I would record each position a square has been scanned from, and use that to find how many other squares were hit by the sensor's pulse at the same time. So I tried to look for patterns in circles: given a given radius, how many squares will the parameter cut through (since I know that the sensor's pulse is 15 degrees wide, from there it would be simple division). I thought I had found it, but I formula broke down as soon as I tried fractional values.

I came up with an algorithmic approach: find the very edges of the arc, two squares 15 degrees apart, at the appropriate radius. Then find their midpoint, and repeat the process recursively for each consecutive set of points until for every two points, both them and the one between them lie on the same square. That will ensure that we visit every square on the arc, giving us the number we need.

That left only one final problem: how to find the square that the midpoint of an arc lies on? My friend and I spent a few hours on it, and came upon the answer using trigonometry.

![](/images/arc.png)

Since we know what the initial angle is, all we have to do is find the isosceles triangle whose top angle is half of the current arc. The triangle is isosceles because the top is in the center of the circle (an arc is part of a circle) and both endpoints are on the circle. By dividing an isosceles triangle into two, we find right triangles, allowing us to find the point with simple right triangle trig. We eventually found that, given the angle, $$\Theta$$, the side of the triangle, or radius, $$r$$ and coordinates of one of the endpoints on the circle, $$(x, y)$$, the coordinates of the other side of the arc are

$$ (x + r * sin\frac{\Theta}{2}, y + r * cos\frac{\Theta}{2}) $$

Now I have the easy (cough, cough), of translating that into a recursive mess.

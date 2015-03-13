---
title: Pseudocode

layout: page
---

Writing some Ruby to flesh out the DSL requirements.

{% highlight ruby %}
{% include_relative pseudocode.rb %}
{% endhighlight %}

Besides some obvious work on algorithms (A\*), there are a few fine points that need to be fleshed out.

* Naming conventions for hooks, user-defined functionality as well as normal functions
* What level of functionality should be baked in
* Units! Should angles be degrees or radians? Should distance be measured in the steps of the motor or in cm/m?
* How should commands be represented? How large should one command be?

As far as implementation, my current plan is to have a class `Robot` that forwards messages to a singleton Robot object, where all functionality will actually be stored.

Some points that were not addressed in these examples: the representation of the map. I think it will probably be a class that is a thin wrapper over a 2d array. Unsure if it should be singleton, depending on how I handle loading and saving data.

Another consideration is the representation of the Raspberry Pi. By abstracting the pins to a seperate class, two benefits are gained. Attempting to assign multiple uses to the same pin can be stopped. More importantly, the class can have a virtual mode for debugging, that outputs information on how the pins are theoretically being used, and allows for "voltage readings" at the pins using a user-defined block of some sort.

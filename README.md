# Programming 3 Exercise project template


1. Make sure you have setup ssh-key for your GitLab account. https://course-gitlab.tuni.fi/profile/keys
2. Clone and add template repo as remote.
Address: git@course-gitlab.tuni.fi:tie-0240x-ohjelmointi-3-programming-3-2020-2021/group_template_project.git
3. Pull from template, and do git submodule update --init in repo. Check that Course now contains something.
4. Make sure you can build the project. (Should compile without issues if your environment is setup correctly)

## Submodule / CourseLib
Submodule for CourseLib is currently configured to use ssh. If you haven't yet setup an ssh-key. Go do it at  https://course-gitlab.tuni.fi/profile/keys

The page contains also instructions for generating and using existing ssh-keys.

Don't change anything in CourseLib ( You won't be able to submit changes made in it )

If you find any bugs and/or missing features you can report them in GitLab https://course-gitlab.tuni.fi/tie-0240x-ohjelmointi-3-programming-3-2020-2021/course/-/issues

## Doxygen documentation

No Doxyfile is provided with the project, but you may generate it using doxygen or doxywizard. For example, "doxygen -g" should generate configuration file named DoxyFile.

## Other notes

You should create your own code inside your own namespace :)


# You are allowed (and probably should) make changes to this file after you have started your project. :)

TIE-02402 Ohjelmointi 3: Tekniikat, Syksy 2020
TIE-02408 Programming 3: Techniques, fall 2020

# general about nysse project and us

Nysse project


The program is created by:
Teemu Mökkönen, teemu.mokkonen@tuni.fi,
Ville Tiljander, ville.tiljander@tuni.fi, 274523

This program has been created for educational purposes!

# Topic of the game

Introduction to game
People in Tampere has gone grazy and began to steal busses in Tampere and you need to stop that!

# Game rules
- The goal of the game is to stop people stealing busses by driving close to them and picking them up to the taxi.
- Points are given when stopping a person carrying a buss.
- You can choose the game type from 1 minute or 2 minutes if you want to get your scores to highscores. You can also choose infinite time game but then your score will not be saved to scores.

Controls:
- The taxi character can be moved with classic wasd-Controls. There is also action button e. The action button is made for special case where the player must pick up the nuke.
- After the nuke is picked try it yourself ;)
w: move up on the screen
a: move left on the screen
s: move down on the screen
d: move right on the screen
e: action button for the nuke



# The Mod Dev Experience

This is the repository for the first moderator project for the first server game jam.

## Platforms

Core platform compatibility should be maintained with HTML5 builds. Support has been extended to native Mac and Windows,
and there's no reason it shouldn't work on Linux. The core difference is that OSX doesnt support `300 es` profile
OpenGL shaders so all desktop platforms run with `330 core`.

## Structure

```
engine/     # This folder is where the main engine files live
assets/     # This folder contains any assets you want to access from the game (shaders, images, etc)
s/          # Script folder for setting up and managing the repository
main.cpp    # This is the file where the "appplication layer" utilizes the engine. Should likely be moved to its own app/ folder
```

## Set up

### To clone and set up dependencies

```bash
    git clone git@github.com:cshangout/gamejam01.git
    cd gamejam01
    python3 s/get_dependencies.py
```

### To build and run the HTML5 build

```bash
    python3 s/build_web.py
    python3 s/serve_web.py
```

### To develop the project

This project is built to be compatible as-is with CLion. It will likely open without issues in any other 
CMake compatible IDE but has not been tested with it.

# Sigma

A project to learn OpenGL, fancy 2D graphics and a more complex project architecture to build games in a stable, debuggable and efficient manner. <br/>
In the future its planned to contain the following features

- Event handling
- Layer abstraction
- Texture loading
- Transitions (as in value transitions)
  - Combined with Entity
- Component system
- Camera
- Tilesystem

#### Maybe-ish

- Sound
- Controller

# Installation

### Requirements

- cmake (https://cmake.org/download/)
- premake (https://premake.github.io/)
  - The premake executable is already contained in `vendor/premake` but in case you reaaally want to download it yourself and don't trust executable online (I wouldn't)
- Visual Studio

### Actual installation

Clone the repository to your desired location:

```
git clone https://github.com/Blackxes/Sigma.git <directory>
```

Navigate into the `scripts/<operating_system>` directory and execute the `GenerateProjectFiles` script. <br/>

Now all you need to do is opening up the `SigmaSolution.sln` and build `Sandbox`
As soon as that succeeded you are good to go and can use Sigma all you want.

Have fun!

### Having issues installing? <br/>

Raise an issue [here](https://github.com/Blackxes/Sigma/issues) but make sure its not already created

<h1> OpenGL Template Repository </h1>

> [!NOTE]
> This is still a work in progress; there are issues with the build that need to be fixed, and I plan to make several helper classes and modules for shaders, meshes, etc.

I am always eager to start working on new computer graphics projects; however, the boilerplate code required to initialize OpenGL always scares me away. Here is an IDE agnostic template that can be used to start any OpenGL project.

It comes with:

<ul> 
    <li> GLFW3 </li>
    <li> GLAD </li>
    <li> stb_image </li>
    <li> GLM </li>
</ul>

<h3> Cloning and Building </h3>

To run this repo, do the following:

```
git clone <repo>
cd <repo>

git submodule update --init --recursive

mkdir build
cd build
cmake ..
cmake --build .
```

Then to run do:

```
cd build
cmake --build .
.\Debug\OpenGLTemplate.exe
```

<h3> TODO </h3>

Need to figure out scene management, how all objects are rendered quickly.


<ul>
    <li> Renderer </li>
    <li> Shader Class </li>
    <li> Model/Mesh Class </li>
    <li> Texture Class </li>
</ul>
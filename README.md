# Dependencies required to compile under Ubuntu Trusty

```bash
$ sudo apt-get install libfreetype6-dev libelf-dev pkg-config libglu1-mesa-dev libtool freeglut3-dev libfontconfig1-dev libdevil-dev gcc-avr avr-libc
```

# Running under Vagrant

If like me you start from a bare-bones Vagrant box, you'll want to install an X
server as well : `sudo apt-get install xinit`, then `startx` and `export DISPLAY=:0`
in your `vagrant ssh` session.


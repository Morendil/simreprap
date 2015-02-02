# Using the Dockerfile

## Building the image

```bash
$ docker build -t simreprap .
```

## Building and running the code

```bash
$ docker run --rm -v $PWD:/simreprap -p 3000:3000 -i -t simreprap
```

## Accessing the simulated serial port

```bash
$ telnet $(boot2docker ip) 3000
Trying 192.168.59.103...
Connected to 192.168.59.103.
Escape character is '^]'.
start
echo:Marlin 1.0.0
...
```

This assumes `boot2docker`, you can just use `localhost` if running on the
Docker host. Also, feel free to replace `telnet` with `nc`.

## Exposing the simulated serial port as a virtual port on the host

```bash
$ socat pty,link=/tmp/simreprap tcp:$(boot2docker ip):3000
```

Then direct e.g. Pronterface to connect to the "port" at /tmp/simreprap.


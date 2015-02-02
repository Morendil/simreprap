FROM ubuntu

RUN apt-get update && apt-get install -y \
  build-essential \
  libelf-dev gcc-avr avr-libc \
  arduino-mk \
  socat

EXPOSE 3000

VOLUME ["/simreprap"]

CMD ["bash", "-c", "socat tcp-l:3000,reuseaddr,fork /tmp/simavr-uart0 & (cd /simreprap && make && ./obj-x86_64-linux-gnu/reprap.elf)"]

FROM ubuntu

RUN apt-get update
RUN apt-get install -y build-essential git
RUN apt-get install -y libelf-dev gcc-avr avr-libc
RUN apt-get install -y arduino-mk
RUN apt-get install -y socat
